#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "periods.h"

// GLUE CODE: include the Lustre generated header
#include "Controller.h"
#define BLACK_MAX 650
#define WHITE_MIN 450
#define MIN_SPEED 55
#define MAX_SPEED 90

_real light_pc(int min, int max, int raw)
{
  return ((float)(max-raw)/(float)(max-min))*100;
}

_real speed_adapted(int min, int max, _real speed)
{
  int sign = 1;
  if (speed < 0)
  {
    sign = -1;
    speed = speed * -1;
  }
  return (min+((max-min)*speed))*sign;
}

// extern _real l = .25;
// extern _real alpha=1/l;
// extern _real omega=1;
// extern _real ksi=1;
//
// extern _real ki_teta=omega*omega/alpha;
// extern _real kp_teta=3*ksi*omega/alpha;
// extern _real T = 0.017;
// extern _real threshold_noir = 90;
// extern _real threshold_blanc = 25;
// extern _real threshold_distance = 85;
// extern _real pi = 3.14159;

/* OSEK specific code, DO NOT CHANGE */
DeclareCounter(SysTimerCnt);
DeclareTask(Task1);
void user_1ms_isr_type2(void) {
  StatusType ercd;
  ercd = SignalCounter(SysTimerCnt);
  /* Increment OSEK Alarm Counter */
  if(ercd != E_OK) { ShutdownOS(ercd); }
}
/* END OF OSEK specific code */

/* Init and terminate OSEK */
void ecrobot_device_initialize() {
   /* GLUE CODE:
		light sensor are ACTIVE devices and must be initialized
		(conversely to buttons, for instance)
   */
	ecrobot_set_light_sensor_active(NXT_PORT_S1);
	ecrobot_set_light_sensor_active(NXT_PORT_S2);
  ecrobot_init_sonar_sensor(NXT_PORT_S3);
}

void ecrobot_device_terminate() {
   /* GLUE CODE:
		light sensor must be switched off
   */
	ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
	ecrobot_set_light_sensor_inactive(NXT_PORT_S2);
  ecrobot_term_sonar_sensor(NXT_PORT_S2);
}


/* UsrTask */

/* GLUE CODE
	Since a SINGLE instance of teh Lustre gen. code is used,
	we can compile it using "-ctx-static" (cf. Makefile)
   making the interface simpler:
		- In particular, we don't have to "alocate" the node context:
   	the global, unique instance is declared in the generated.
		- all the "methods" (init, step input, output) have NO parameters
*/


/* GLUE CODE
	IMPORTANT !!!
	All used Lustre nodes MUST be initialized HERE
	using the procedure provided in the generated code
*/
void usr_init(void) {
	Controller_init();
}

/* GLUE CODE
	Output procedures
	Note: we directly use here the functions from
	the "ecrobot" library (display_goto_xy, display_string etc)
*/
// void Controller_O_state(_boolean b){
//    /* displays on 1st line */
//    display_goto_xy(0,0);
//    if (b) display_string("Sensor 1");
//    else display_string("Sensor 2");
// }
// void Controller_O_val(_integer i){
//    /* displays on 2nd line */
//    display_goto_xy(0,1);
//    display_int(i,5);
// }
//
// void Controller_O_cmp(_integer i){
//    /* displays on 2nd line */
//    display_goto_xy(0,2);
//    display_int(i,5);
// }

void Controller_O_v_d(_real i){
   i = speed_adapted(MIN_SPEED,MAX_SPEED, i);
   nxt_motor_set_speed(NXT_PORT_A, i, 0);
   display_goto_xy(0,0);
   display_string("Speed d : ");
   display_int(i,5);
}


void print_state(_real i)
{
  display_goto_xy(0,6);
  display_string("state : ");
  display_int(i,5);
}
void Controller_O_v_g(_real i){
   i = speed_adapted(MIN_SPEED,MAX_SPEED, i);
   nxt_motor_set_speed(NXT_PORT_B, i, 0);
   display_goto_xy(0,1);
   display_string("Speed g : ");
   display_int(i,5);
}


/*
	GLUE CODE
	The "core" of a step:
   - read inputs from sensors and copy them to Lustre code
     using the corresponding input procedures
	- calls the step proc.
*/
TASK(UsrTask)
{

	/* read and set inputs */
	Controller_I_Cg(light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S1)));
  display_goto_xy(0,3);
  display_string("Light g : ");
  display_int(light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S1)),5);
  Controller_I_Cd(light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S2)));
  display_goto_xy(0,4);
  display_string("Light d : ");
  display_int(light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S2)),5);
  display_goto_xy(0,5);
  display_string("rld : ");
  display_int(ecrobot_get_light_sensor(NXT_PORT_S2),5);
  display_goto_xy(0,7);
  display_string("sens : ");
  display_int(ecrobot_get_sonar_sensor(NXT_PORT_S3),5);
  if(ecrobot_get_sonar_sensor(NXT_PORT_S3)==0)
  {
    Controller_I_Collision_n(255);
  }
  else{
    Controller_I_Collision_n(ecrobot_get_sonar_sensor(NXT_PORT_S3));
  }


	/* performs a Lustre step
		output procs are called within the step
	*/
	Controller_step();

	/* refresh screen (ecrobot library)
	*/
	display_update();

	TerminateTask();
}
