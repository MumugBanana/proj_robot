/********
* ec2c version 0.67
* c file generated for node : Controller 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _Controller_EC2C_SRC_FILE
#include "Controller.h"
/*--------
 * the following ``constants'' must be defined:
extern _real kp_teta;
extern _real ki_teta;
extern _real T;
extern _real threshold_noir;
extern _real threshold_blanc;
extern _real threshold_distance;
extern _real pi;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _Cg;
   _real _Cd;
   _real _Collision_n;
   //OUTPUTS
   _real _v_d;
   _real _v_g;
   //REGISTERS
   _real M75;
   _boolean M75_nil;
   _real M68;
   _boolean M68_nil;
   _boolean M48;
   _boolean M48_nil;
   _boolean M43;
   _boolean M43_nil;
   _boolean M38;
   _boolean M38_nil;
   _boolean M33;
   _boolean M33_nil;
   _boolean M27;
   _boolean M27_nil;
   _boolean M20;
   _boolean M20_nil;
   _boolean M12;
   _boolean M12_nil;
   _boolean M9;
} Controller_ctx;

// Single Static Context
static Controller_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Controller_I_Cg(_real V){
   ctx._Cg = V;
}
void Controller_I_Cd(_real V){
   ctx._Cd = V;
}
void Controller_I_Collision_n(_real V){
   ctx._Collision_n = V;
}
extern void Controller_O_v_d(_real);
extern void Controller_O_v_g(_real);
#ifdef CKCHECK
extern void Controller_BOT_v_d();
extern void Controller_BOT_v_g();
#endif
/*--------
Internal reset input procedure
--------*/
static void Controller_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Controller_reset(){
   ctx.M75_nil = _true;
   ctx.M68_nil = _true;
   ctx.M48_nil = _true;
   ctx.M43_nil = _true;
   ctx.M38_nil = _true;
   ctx.M33_nil = _true;
   ctx.M27_nil = _true;
   ctx.M20_nil = _true;
   ctx.M12_nil = _true;
   ctx.M9 = _true;
   Controller_reset_input();
}
/*--------
Step procedure
--------*/
void Controller_step(){
//LOCAL VARIABLES
   _boolean L8;
   _boolean L14;
   _boolean L16;
   _boolean L13;
   _boolean L7;
   _boolean L19;
   _boolean L18;
   _boolean L6;
   _boolean L26;
   _boolean L32;
   _boolean L37;
   _boolean L42;
   _boolean L44;
   _boolean L41;
   _boolean L47;
   _boolean L46;
   _boolean L40;
   _boolean L52;
   _boolean L39;
   _boolean L36;
   _boolean L35;
   _boolean L34;
   _boolean L31;
   _boolean L30;
   _boolean L29;
   _boolean L28;
   _boolean L25;
   _boolean L24;
   _integer L23;
   _integer L5;
   _boolean L4;
   _real L55;
   _real L64;
   _real L67;
   _real L70;
   _real L73;
   _real L69;
   _real L66;
   _real L63;
   _real L74;
   _real L62;
   _real L60;
   _real L76;
   _real L59;
   _real L84;
   _boolean L83;
   _real L85;
   _real L82;
   _real L81;
   _real L88;
   _real L86;
   _real L80;
   _real L78;
   _real L58;
   _real L57;
   _real L3;
   _real L93;
   _real L92;
   _real L91;
   _real L90;
   _real T75;
   _real T68;
   _boolean L50;
   _boolean L49;
   _boolean T48;
   _boolean T43;
   _boolean T38;
   _boolean T33;
   _boolean T27;
   _boolean L21;
   _boolean T20;
   _boolean T12;
//CODE
   if (ctx.M9) {
      L8 = _false;
   } else {
      L8 = ctx.M12;
   }
   L14 = (0.000000 <= ctx._Collision_n);
   L16 = (ctx._Collision_n <= threshold_distance);
   L13 = (L14 && L16);
   L7 = (L8 || L13);
   if (ctx.M9) {
      L19 = _false;
   } else {
      L19 = ctx.M20;
   }
   L18 = (! L19);
   L6 = (L7 && L18);
   if (ctx.M9) {
      L26 = _false;
   } else {
      L26 = ctx.M27;
   }
   if (ctx.M9) {
      L32 = _false;
   } else {
      L32 = ctx.M33;
   }
   if (ctx.M9) {
      L37 = _false;
   } else {
      L37 = ctx.M38;
   }
   if (ctx.M9) {
      L42 = _false;
   } else {
      L42 = ctx.M43;
   }
   L44 = (ctx._Cd >= threshold_blanc);
   L41 = (L42 || L44);
   if (ctx.M9) {
      L47 = _false;
   } else {
      L47 = ctx.M48;
   }
   L46 = (! L47);
   L40 = (L41 && L46);
   L52 = (ctx._Cd <= threshold_noir);
   L39 = (L40 && L52);
   L36 = (L37 || L39);
   L35 = (L36 && L46);
   L34 = (L35 && L44);
   L31 = (L32 || L34);
   L30 = (L31 && L46);
   L29 = (L8 && L30);
   L28 = (L29 >= _true);
   L25 = (L26 || L28);
   L24 = (L25 && L18);
   if (L24) {
      L23 = 3;
   } else {
      L23 = 2;
   }
   if (L6) {
      L5 = L23;
   } else {
      L5 = 1;
   }
   L4 = (L5 > 1);
   L55 = (- 0.500000);
   L64 = (0.500000 * T);
   if (ctx.M9) {
      L67 = 0.000000;
   } else {
      L67 = ctx.M68;
   }
   L70 = (pi / 200.000000);
   L73 = (ctx._Cd - ctx._Cg);
   L69 = (L70 * L73);
   L66 = (L67 + L69);
   L63 = (L64 * L66);
   if (ctx.M9) {
      L74 = 0.000000;
   } else {
      L74 = ctx.M75;
   }
   L62 = (L63 + L74);
   L60 = (ki_teta * L62);
   L76 = (kp_teta * L69);
   L59 = (L60 + L76);
   L84 = (2.000000 * L59);
   L83 = (L84 < 0.000000);
   L85 = (- L84);
   if (L83) {
      L82 = L85;
   } else {
      L82 = L84;
   }
   L81 = (- L82);
   L88 = (ctx._Cd + ctx._Cg);
   L86 = (0.005000 * L88);
   L80 = (L81 + L86);
   L78 = (2.000000 * L80);
   L58 = (L59 + L78);
   L57 = (0.500000 * L58);
   if (L4) {
      L3 = L55;
   } else {
      L3 = L57;
   }
   Controller_O_v_d(L3);
   L93 = (- L59);
   L92 = (L93 + L78);
   L91 = (0.500000 * L92);
   if (L4) {
      L90 = 0.500000;
   } else {
      L90 = L91;
   }
   Controller_O_v_g(L90);
   T75 = L62;
   T68 = L69;
   L50 = (L5 == 2);
   L49 = (! L50);
   T48 = L49;
   T43 = L40;
   T38 = L35;
   T33 = L30;
   T27 = L24;
   L21 = (L5 == 3);
   T20 = L21;
   T12 = L6;
   ctx.M75 = T75;
   ctx.M75_nil = _false;
   ctx.M68 = T68;
   ctx.M68_nil = _false;
   ctx.M48 = T48;
   ctx.M48_nil = _false;
   ctx.M43 = T43;
   ctx.M43_nil = _false;
   ctx.M38 = T38;
   ctx.M38_nil = _false;
   ctx.M33 = T33;
   ctx.M33_nil = _false;
   ctx.M27 = T27;
   ctx.M27_nil = _false;
   ctx.M20 = T20;
   ctx.M20_nil = _false;
   ctx.M12 = T12;
   ctx.M12_nil = _false;
   ctx.M9 = ctx.M9 && !(_true);
}
