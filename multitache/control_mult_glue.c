
/*

Sample user code for 2 tasks :

- one fast/high rate  HighTask
- one slow/low rate   LowTask

Periods are in ms (see periods.h)

*/

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include <stdio.h>
#include "controle.h"
#include "decision.h"

#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif

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
/*-----------------------------
   OSEK declarations
-------------------------------
DON'T MODIFY
------------------------------*/
DeclareCounter(SysTimerCnt);
DeclareResource(lcd);
DeclareTask(LowTask);
DeclareTask(HighTask);


/*------------------------------
 Function to be invoked from a category 2 interrupt
--------------------------------
DON'T MODIFY
------------------------------*/
void user_1ms_isr_type2(void)
{
	StatusType ercd;

	/*
	 *  Increment OSEK Alarm System Timer Count
     */
	ercd = SignalCounter( SysTimerCnt );
	if( ercd != E_OK ){
		ShutdownOS( ercd );
	}
}

/* ---- HERE BEGINS YOUR CODE ----*/

/* Init and terminate OSEK */
void ecrobot_device_initialize() {
	ecrobot_set_light_sensor_active(NXT_PORT_S1);
	ecrobot_set_light_sensor_active(NXT_PORT_S2);
	ecrobot_init_sonar_sensor(NXT_PORT_S3);
}

void ecrobot_device_terminate() {
	ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
	ecrobot_set_light_sensor_inactive(NXT_PORT_S2);
	ecrobot_term_sonar_sensor(NXT_PORT_S2);
}

/*------------------------------
  Definitions
--------------------------------
shared vars, functions etc
------------------------------*/

_real var_cd = 0;
_boolean var_switch = false;
/* Global user initialization:
   put here any code to be executed:
   - ONCE
   - AFTER devices (and brick) initialization
   - BEFORE the start of reactive loop
*/
void usr_init(){
  controle_init();
	decision_init();
}

void show_var(char* what, UINT line, UINT var) {
   //display_clear(0);
   GetResource(lcd);     //forbids preemption ...

   display_goto_xy(0, line);
   display_string(what);
   display_int(var, 10);
   display_update();

   ReleaseResource(lcd); //... re-allow preemption
}

void decision_O_v_d(_real i){
   i = speed_adapted(MIN_SPEED,MAX_SPEED, i);
	 show_var("vd:",4,i);
   nxt_motor_set_speed(NXT_PORT_A, i, 0);

}

void decision_O_Cd_out(_real i){
	 var_cd = i;
}

void decision_O_v_g(_real i){
   i = speed_adapted(MIN_SPEED,MAX_SPEED, i);
	 show_var("vg:",5,i);
   nxt_motor_set_speed(NXT_PORT_B, i, 0);

}

void controle_O_state_switch_n(_boolean b)
{
  var_switch = b;
}
/*------------------------------
  Tasks definition
--------------------------------
- MUST be declared with the
  OSEK macro "TASK"
- The last instruction MUST be
  TerminateTask()
------------------------------*/

TASK(LowTask) {
	if(ecrobot_get_sonar_sensor(NXT_PORT_S3)==0)
  {
    controle_I_Collision_n(255);
  }
  else{
    controle_I_Collision_n(ecrobot_get_sonar_sensor(NXT_PORT_S3));
  }
	show_var("col:",3,ecrobot_get_sonar_sensor(NXT_PORT_S3));
	controle_I_Cd_in(var_cd);
	controle_step();

	TerminateTask();
}

TASK(HighTask) {
	show_var("Cg:",0,light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S1)));
	decision_I_Cg(light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S1)));
	show_var("Cd:",1,light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S2)));
	decision_I_Cd(light_pc(WHITE_MIN,BLACK_MAX,ecrobot_get_light_sensor(NXT_PORT_S2)));
	UINT val_state = var_switch ? 1 : 0;
	show_var("St:",2,val_state);
	decision_I_state_bool_n(var_switch);
	decision_step();

	TerminateTask();
}
