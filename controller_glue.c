#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "periods.h"

// GLUE CODE: include the Lustre generated header
#include "Controller.h"

_real l = .25;
_real alpha=1/l;
_real omega=1;
_real ksi=1;

_real ki_teta=omega*omega/alpha;
_real kp_teta=3*ksi*omega/alpha;
_real T = 0.017;
_real threshold_noir = 90;
_real threshold_blanc = 25;
_real threshold_distance = 85;
_real pi = 3.14159;

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

}

void ecrobot_device_terminate() {
   /* GLUE CODE:
		light sensor must be switched off
   */
	ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
	ecrobot_set_light_sensor_inactive(NXT_PORT_S2);
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
   nxt_motor_set_speed(NXT_PORT_A, i, 0);
}

void Controller_O_v_g(_real i){
   nxt_motor_set_speed(NXT_PORT_B, i, 0);
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
	Controller_I_Cg(ecrobot_get_light_sensor(NXT_PORT_S1));
	Controller_I_Cd(ecrobot_get_light_sensor(NXT_PORT_S2));
	Controller_I_Collision_n(ecrobot_get_touch_sensor(NXT_PORT_S3));

	/* performs a Lustre step
		output procs are called within the step
	*/
	Controller_step();

	/* refresh screen (ecrobot library)
	*/
	display_update();

	TerminateTask();
}
