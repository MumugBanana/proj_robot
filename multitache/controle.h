/********
* ec2c version 0.67
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : controle 
* to be used with : controle.c 
********/
#ifndef _controle_EC2C_H_FILE
#define _controle_EC2C_H_FILE
/* This program needs external declarations */
#include "controle_ext.h"
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
//MODULE: controle 2 1
//IN: _real Collision_n
//IN: _real Cd_in
//OUT: _boolean state_switch_n
#ifndef _controle_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void controle_I_Collision_n(_real);
extern void controle_I_Cd_in(_real);
/*-------- Reset procedure -----------*/
extern void controle_reset();
/*--------Context init = context reset --------*/
#define controle_init controle_reset
/*-------- Step procedure -----------*/
extern void controle_step();
#endif
#endif
