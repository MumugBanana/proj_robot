/********
* ec2c version 0.67
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : decision 
* to be used with : decision.c 
********/
#ifndef _decision_EC2C_H_FILE
#define _decision_EC2C_H_FILE
/* This program needs external declarations */
#include "decision_ext.h"
/*-------- Predefined types ---------*/
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
/*--------- Pragmas ----------------*/
//MODULE: decision 3 3
//IN: _real Cg
//IN: _real Cd
//IN: _real state_bool_n
//OUT: _real v_d
//OUT: _real v_g
//OUT: _real Cd_out
#ifndef _decision_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void decision_I_Cg(_real);
extern void decision_I_Cd(_real);
extern void decision_I_state_bool_n(_real);
/*-------- Reset procedure -----------*/
extern void decision_reset();
/*--------Context init = context reset --------*/
#define decision_init decision_reset
/*-------- Step procedure -----------*/
extern void decision_step();
#endif
#endif
