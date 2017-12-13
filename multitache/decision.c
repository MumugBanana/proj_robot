/********
* ec2c version 0.67
* c file generated for node : decision 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _decision_EC2C_SRC_FILE
#include "decision.h"
/*--------
 * the following ``constants'' must be defined:
extern _real kp_teta;
extern _real ki_teta;
extern _real T;
extern _real pi;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _Cg;
   _real _Cd;
   _real _state_bool_n;
   //OUTPUTS
   _real _v_d;
   _real _v_g;
   _real _Cd_out;
   //REGISTERS
   _real M28;
   _boolean M28_nil;
   _real M21;
   _boolean M21_nil;
   _boolean M19;
} decision_ctx;

// Single Static Context
static decision_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void decision_I_Cg(_real V){
   ctx._Cg = V;
}
void decision_I_Cd(_real V){
   ctx._Cd = V;
}
void decision_I_state_bool_n(_real V){
   ctx._state_bool_n = V;
}
extern void decision_O_v_d(_real);
extern void decision_O_v_g(_real);
extern void decision_O_Cd_out(_real);
#ifdef CKCHECK
extern void decision_BOT_v_d();
extern void decision_BOT_v_g();
extern void decision_BOT_Cd_out();
#endif
/*--------
Internal reset input procedure
--------*/
static void decision_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void decision_reset(){
   ctx.M28_nil = _true;
   ctx.M21_nil = _true;
   ctx.M19 = _true;
   decision_reset_input();
}
/*--------
Step procedure
--------*/
void decision_step(){
//LOCAL VARIABLES
   _boolean L4;
   _real L6;
   _real L15;
   _real L18;
   _real L23;
   _real L26;
   _real L22;
   _real L17;
   _real L14;
   _real L27;
   _real L13;
   _real L11;
   _real L29;
   _real L10;
   _real L37;
   _boolean L36;
   _real L38;
   _real L35;
   _real L34;
   _real L41;
   _real L39;
   _real L33;
   _real L31;
   _real L9;
   _real L8;
   _real L3;
   _real L46;
   _real L45;
   _real L44;
   _real L43;
   _real T28;
   _real T21;
//CODE
   L4 = (ctx._state_bool_n != 0.000000);
   L6 = (- 0.500000);
   L15 = (0.500000 * T);
   if (ctx.M19) {
      L18 = 0.000000;
   } else {
      L18 = ctx.M21;
   }
   L23 = (pi / 200.000000);
   L26 = (ctx._Cd - ctx._Cg);
   L22 = (L23 * L26);
   L17 = (L18 + L22);
   L14 = (L15 * L17);
   if (ctx.M19) {
      L27 = 0.000000;
   } else {
      L27 = ctx.M28;
   }
   L13 = (L14 + L27);
   L11 = (ki_teta * L13);
   L29 = (kp_teta * L22);
   L10 = (L11 + L29);
   L37 = (2.000000 * L10);
   L36 = (L37 < 0.000000);
   L38 = (- L37);
   if (L36) {
      L35 = L38;
   } else {
      L35 = L37;
   }
   L34 = (- L35);
   L41 = (ctx._Cd + ctx._Cg);
   L39 = (0.005000 * L41);
   L33 = (L34 + L39);
   L31 = (2.000000 * L33);
   L9 = (L10 + L31);
   L8 = (0.500000 * L9);
   if (L4) {
      L3 = L6;
   } else {
      L3 = L8;
   }
   decision_O_v_d(L3);
   L46 = (- L10);
   L45 = (L46 + L31);
   L44 = (0.500000 * L45);
   if (L4) {
      L43 = 0.500000;
   } else {
      L43 = L44;
   }
   decision_O_v_g(L43);
   decision_O_Cd_out(ctx._Cd);
   T28 = L13;
   T21 = L22;
   ctx.M28 = T28;
   ctx.M28_nil = _false;
   ctx.M21 = T21;
   ctx.M21_nil = _false;
   ctx.M19 = ctx.M19 && !(_true);
}
