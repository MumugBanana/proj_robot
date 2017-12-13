/********
* ec2c version 0.67
* c file generated for node : controle 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _controle_EC2C_SRC_FILE
#include "controle.h"
/*--------
 * the following ``constants'' must be defined:
extern _real threshold_noir;
extern _real threshold_blanc;
extern _real threshold_distance;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _Collision_n;
   _real _Cd_in;
   //OUTPUTS
   _boolean _state_switch_n;
   //REGISTERS
   _boolean M46;
   _boolean M46_nil;
   _boolean M41;
   _boolean M41_nil;
   _boolean M36;
   _boolean M36_nil;
   _boolean M31;
   _boolean M31_nil;
   _boolean M25;
   _boolean M25_nil;
   _boolean M18;
   _boolean M18_nil;
   _boolean M10;
   _boolean M10_nil;
   _boolean M7;
} controle_ctx;

// Single Static Context
static controle_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void controle_I_Collision_n(_real V){
   ctx._Collision_n = V;
}
void controle_I_Cd_in(_real V){
   ctx._Cd_in = V;
}
extern void controle_O_state_switch_n(_boolean);
#ifdef CKCHECK
extern void controle_BOT_state_switch_n();
#endif
/*--------
Internal reset input procedure
--------*/
static void controle_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void controle_reset(){
   ctx.M46_nil = _true;
   ctx.M41_nil = _true;
   ctx.M36_nil = _true;
   ctx.M31_nil = _true;
   ctx.M25_nil = _true;
   ctx.M18_nil = _true;
   ctx.M10_nil = _true;
   ctx.M7 = _true;
   controle_reset_input();
}
/*--------
Step procedure
--------*/
void controle_step(){
//LOCAL VARIABLES
   _boolean L6;
   _boolean L12;
   _boolean L14;
   _boolean L11;
   _boolean L5;
   _boolean L17;
   _boolean L16;
   _boolean L4;
   _boolean L24;
   _boolean L30;
   _boolean L35;
   _boolean L40;
   _boolean L42;
   _boolean L39;
   _boolean L45;
   _boolean L44;
   _boolean L38;
   _boolean L50;
   _boolean L37;
   _boolean L34;
   _boolean L33;
   _boolean L32;
   _boolean L29;
   _boolean L28;
   _boolean L27;
   _boolean L26;
   _boolean L23;
   _boolean L22;
   _integer L21;
   _integer L3;
   _boolean L2;
   _boolean L48;
   _boolean L47;
   _boolean T46;
   _boolean T41;
   _boolean T36;
   _boolean T31;
   _boolean T25;
   _boolean L19;
   _boolean T18;
   _boolean T10;
//CODE
   if (ctx.M7) {
      L6 = _false;
   } else {
      L6 = ctx.M10;
   }
   L12 = (0.000000 <= ctx._Collision_n);
   L14 = (ctx._Collision_n <= threshold_distance);
   L11 = (L12 && L14);
   L5 = (L6 || L11);
   if (ctx.M7) {
      L17 = _false;
   } else {
      L17 = ctx.M18;
   }
   L16 = (! L17);
   L4 = (L5 && L16);
   if (ctx.M7) {
      L24 = _false;
   } else {
      L24 = ctx.M25;
   }
   if (ctx.M7) {
      L30 = _false;
   } else {
      L30 = ctx.M31;
   }
   if (ctx.M7) {
      L35 = _false;
   } else {
      L35 = ctx.M36;
   }
   if (ctx.M7) {
      L40 = _false;
   } else {
      L40 = ctx.M41;
   }
   L42 = (ctx._Cd_in >= threshold_blanc);
   L39 = (L40 || L42);
   if (ctx.M7) {
      L45 = _false;
   } else {
      L45 = ctx.M46;
   }
   L44 = (! L45);
   L38 = (L39 && L44);
   L50 = (ctx._Cd_in <= threshold_noir);
   L37 = (L38 && L50);
   L34 = (L35 || L37);
   L33 = (L34 && L44);
   L32 = (L33 && L42);
   L29 = (L30 || L32);
   L28 = (L29 && L44);
   L27 = (L6 && L28);
   L26 = (L27 >= _true);
   L23 = (L24 || L26);
   L22 = (L23 && L16);
   if (L22) {
      L21 = 3;
   } else {
      L21 = 2;
   }
   if (L4) {
      L3 = L21;
   } else {
      L3 = 1;
   }
   L2 = (L3 > 1);
   controle_O_state_switch_n(L2);
   L48 = (L3 == 2);
   L47 = (! L48);
   T46 = L47;
   T41 = L38;
   T36 = L33;
   T31 = L28;
   T25 = L22;
   L19 = (L3 == 3);
   T18 = L19;
   T10 = L4;
   ctx.M46 = T46;
   ctx.M46_nil = _false;
   ctx.M41 = T41;
   ctx.M41_nil = _false;
   ctx.M36 = T36;
   ctx.M36_nil = _false;
   ctx.M31 = T31;
   ctx.M31_nil = _false;
   ctx.M25 = T25;
   ctx.M25_nil = _false;
   ctx.M18 = T18;
   ctx.M18_nil = _false;
   ctx.M10 = T10;
   ctx.M10_nil = _false;
   ctx.M7 = ctx.M7 && !(_true);
}
