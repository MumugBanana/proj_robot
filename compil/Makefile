
# Application name
TARGET=testlight

# Where to find user C code
USR_PATH=.

# -----------
# user C code
# -----------
USR_CFILES=\
	testlight.c \
	testlight_glue.c \

# generic makefile ...
include $(MDL2LUS2OSEK)/generic.mak


# -----------
# mdl -> lustre -> c rules
# -----------

# c code is obtained by compiling Lustre code ...
# (note the "-ctx-static": it influences the way GLUE must be written)
testlight.c: testlight.lus
	lus2c testlight.lus testlight -ctx-static


# Lustre code is obtained from mdl
testlight.lus: testlight.mdl
	mdl2lus testlight.mdl 

clear: clean
	rm -f testlight.xml testlight.c testlight.h testlight.lus testlight.ec testlight.mws
