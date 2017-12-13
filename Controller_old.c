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
 * the following ``constants'' must be defined:*/
extern _real kp_teta;
extern _real ki_teta;
extern _real T;
extern _real threshold_noir;
extern _real threshold_blanc;
extern _real threshold_distance;
extern _real pi;
/*--------*/
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
   _real M84;
   _boolean M84_nil;
   _real M77;
   _boolean M77_nil;
   _boolean M52;
   _boolean M52_nil;
   _boolean M47;
   _boolean M47_nil;
   _boolean M42;
   _boolean M42_nil;
   _boolean M37;
   _boolean M37_nil;
   _boolean M31;
   _boolean M31_nil;
   _boolean M24;
   _boolean M24_nil;
   _boolean M17;
   _boolean M17_nil;
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
extern void print_state(_real);

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
   ctx.M84_nil = _true;
   ctx.M77_nil = _true;
   ctx.M52_nil = _true;
   ctx.M47_nil = _true;
   ctx.M42_nil = _true;
   ctx.M37_nil = _true;
   ctx.M31_nil = _true;
   ctx.M24_nil = _true;
   ctx.M17_nil = _true;
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
   _boolean L13;
   _boolean L7;
   _boolean L16;
   _boolean L15;
   _boolean L6;
   _boolean L23;
   _boolean L26;
   _boolean L25;
   _boolean L22;
   _boolean L21;
   _boolean L30;
   _boolean L36;
   _boolean L41;
   _boolean L46;
   _boolean L48;
   _boolean L45;
   _boolean L51;
   _boolean L50;
   _boolean L44;
   _boolean L56;
   _boolean L43;
   _boolean L40;
   _boolean L39;
   _boolean L38;
   _boolean L35;
   _boolean L34;
   _boolean L33;
   _boolean L32;
   _boolean L29;
   _boolean L28;
   _integer L27;
   _integer L20;
   _integer L5;
   _boolean L4;
   _boolean L61;
   _real L62;
   _real L60;
   _real L73;
   _real L76;
   _real L79;
   _real L82;
   _real L78;
   _real L75;
   _real L72;
   _real L83;
   _real L71;
   _real L69;
   _real L85;
   _real L68;
   _real L93;
   _boolean L92;
   _real L94;
   _real L91;
   _real L90;
   _real L97;
   _real L95;
   _real L89;
   _real L87;
   _real L67;
   _real L65;
   _real L3;
   _real L100;
   _real L103;
   _real L102;
   _real L101;
   _real L99;
   _real T84;
   _real T77;
   _boolean L54;
   _boolean L53;
   _boolean T52;
   _boolean T47;
   _boolean T42;
   _boolean T37;
   _boolean T31;
   _boolean T24;
   _boolean L18;
   _boolean T17;
   _boolean T12;
//CODE
   if (ctx.M9) {
      L8 = _false;
   } else {
      L8 = ctx.M12;
   }
   L13 = (ctx._Collision_n >= threshold_distance);
   L7 = (L8 || L13);
   if (ctx.M9) {
      L16 = _false;
   } else {
      L16 = ctx.M17;
   }
   L15 = (! L16);
   L6 = (L7 && L15);
   if (ctx.M9) {
      L23 = _false;
   } else {
      L23 = ctx.M24;
   }
   L26 = (L8 && _true);
   L25 = (L26 >= _true);
   L22 = (L23 || L25);
   L21 = (L22 && L15);
   if (ctx.M9) {
      L30 = _false;
   } else {
      L30 = ctx.M31;
   }
   if (ctx.M9) {
      L36 = _false;
   } else {
      L36 = ctx.M37;
   }
   if (ctx.M9) {
      L41 = _false;
   } else {
      L41 = ctx.M42;
   }
   if (ctx.M9) {
      L46 = _false;
   } else {
      L46 = ctx.M47;
   }
   L48 = (ctx._Cd >= threshold_blanc);
   L45 = (L46 || L48);
   if (ctx.M9) {
      L51 = _false;
   } else {
      L51 = ctx.M52;
   }
   L50 = (! L51);
   L44 = (L45 && L50);
   L56 = (ctx._Cd <= threshold_noir);
   L43 = (L44 && L56);
   L40 = (L41 || L43);
   L39 = (L40 && L50);
   L38 = (L39 && L48);
   L35 = (L36 || L38);
   L34 = (L35 && L50);
   L33 = (L23 && L34);
   L32 = (L33 >= _true);
   L29 = (L30 || L32);
   L28 = (L29 && L15);
   if (L28) {
      L27 = 4;
   } else {
      L27 = 3;
   }
   if (L21) {
      L20 = L27;
   } else {
      L20 = 2;
   }
   if (L6) {
      L5 = L20;
   } else {
      L5 = 1;
   }
   L4 = (L5 > 1);
   L61 = (L5 > 2);
   L62 = (- 50.000000);
   if (L61) {
      L60 = L62;
   } else {
      L60 = 0.000000;
   }
   L73 = (0.500000 * T);
   if (ctx.M9) {
      L76 = 0.000000;
   } else {
      L76 = ctx.M77;
   }
   L79 = (pi / 200.000000);
   L82 = (ctx._Cd - ctx._Cg);
   L78 = (L79 * L82);
   L75 = (L76 + L78);
   L72 = (L73 * L75);
   if (ctx.M9) {
      L83 = 0.000000;
   } else {
      L83 = ctx.M84;
   }
   L71 = (L72 + L83);
   L69 = (ki_teta * L71);
   L85 = (kp_teta * L78);
   L68 = (L69 + L85);
   L93 = (2.000000 * L68);
   L92 = (L93 < 0.000000);
   L94 = (- L93);
   if (L92) {
      L91 = L94;
   } else {
      L91 = L93;
   }
   L90 = (- L91);
   L97 = (ctx._Cd + ctx._Cg);
   L95 = (0.005000 * L97);
   L89 = (L90 + L95);
   L87 = (2.000000 * L89);
   L67 = (L68 + L87);
   L65 = (0.500000 * L67);
   if (L4) {
      L3 = L60;
   } else {
      L3 = L65;
   }
   Controller_O_v_d(L3);
   if (L61) {
      L100 = 50.000000;
   } else {
      L100 = 0.000000;
   }
   L103 = (- L68);
   L102 = (L103 + L87);
   L101 = (0.500000 * L102);
   if (L4) {
      L99 = L100;
   } else {
      L99 = L101;
   }
   Controller_O_v_g(L99);
   print_state(L5);
   T84 = L71;
   T77 = L78;
   L54 = (L5 == 3);
   L53 = (! L54);
   T52 = L53;
   T47 = L44;
   T42 = L39;
   T37 = L34;
   T31 = L28;
   T24 = L21;
   L18 = (L5 == 4);
   T17 = L18;
   T12 = L6;
   ctx.M84 = T84;
   ctx.M84_nil = _false;
   ctx.M77 = T77;
   ctx.M77_nil = _false;
   ctx.M52 = T52;
   ctx.M52_nil = _false;
   ctx.M47 = T47;
   ctx.M47_nil = _false;
   ctx.M42 = T42;
   ctx.M42_nil = _false;
   ctx.M37 = T37;
   ctx.M37_nil = _false;
   ctx.M31 = T31;
   ctx.M31_nil = _false;
   ctx.M24 = T24;
   ctx.M24_nil = _false;
   ctx.M17 = T17;
   ctx.M17_nil = _false;
   ctx.M12 = T12;
   ctx.M12_nil = _false;
   ctx.M9 = ctx.M9 && !(_true);
}
