# User Test
#------------------------------------------
TEST_CXX        = ./test_HYPERBUS.cpp

# If you do not want to use RTOS, comment it.
# If you want use RTOS then uncomment it.
MBED_FLAGS     += -DMBED_CONF_RTOS_PRESENT=1

# For RTOS Jenkins test, it will never finished so add a jenkins test Flag to exit().
MBED_FLAGS     +=-DJENKINS_TEST_FLAG=1

vsimPadMuxMode=TB_PADMUX_ALT3_HYPERBUS

# RTL Simulation
#------------------------------------------
# recordWlf=YES
# vsimDo="-do ~/wave/wave_hyper.do"

include $(GAP_SDK_HOME)/tools/rules/mbed_rules.mk