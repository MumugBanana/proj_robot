
# Application name
TARGET=control_mult

# Where to find user C code
USR_PATH=.

# -----------
# user C code
# -----------
USR_CFILES=\
   decision.c \
   controle.c \
   control_mult_glue.c

include $(MDL2LUS2OSEK)/generic.mak

decision.lus: ExRobotAndEnvironmentControllerContPI.mdl
	mdl2lus -system decision ExRobotAndEnvironmentControllerContPI.mdl

controle.lus: ExRobotAndEnvironmentControllerContPI.mdl
	mdl2lus -system controle ExRobotAndEnvironmentControllerContPI.mdl

decision.c: decision.lus
	lus2c decision.lus decision -ctx-static

controle.c: controle.lus
	lus2c controle.lus controle -ctx-static

clear: clean
	rm -f controle.xml controle.c controle.h controle.lus controle.ec controle.mws decision.xml decision.c decision.h decision.lus decision.ec decision.mws
