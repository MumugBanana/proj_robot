#ifndef _Controller_EXT_H_FILE
#define _Controller_EXT_H_FILE
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
_real l = 0.25;
_real alpha=1/0.25;
_real omega=1;
_real ksi=1;

_real ki_teta = 1*1/(1/0.25);
_real kp_teta = 3*1*1/(1/0.25);
_real T = 0.017;
_real threshold_noir = 25;
_real threshold_blanc = 25;
_real threshold_distance = 10;
_real pi = 3.14159;

#endif
