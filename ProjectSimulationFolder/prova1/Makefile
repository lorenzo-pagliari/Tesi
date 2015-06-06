#
# OMNeT++/OMNEST Makefile for prova1
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = prova1$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -IiniFile \
    -IiniFile/D0008 \
    -IiniFile/D001 \
    -IiniFile/D002 \
    -IiniFile/noD \
    -Inet \
    -Inet/randomgeometricgraph \
    -Iresults \
    -Iresults/D0008 \
    -Iresults/D0008/r10D0008 \
    -Iresults/D0008/r10D0008/rgg10 \
    -Iresults/D0008/r10D0008/rgg100 \
    -Iresults/D0008/r10D0008/rgg1000 \
    -Iresults/D0008/r10D0008/rgg2 \
    -Iresults/D0008/r10D0008/rgg200 \
    -Iresults/D0008/r10D0008/rgg30 \
    -Iresults/D0008/r10D0008/rgg5 \
    -Iresults/D0008/r10D0008/rgg50 \
    -Iresults/D0008/r10D0008/rgg500 \
    -Iresults/D0008/r10D0008/rgg80 \
    -Iresults/D0008/r15D0008 \
    -Iresults/D0008/r15D0008/rgg10 \
    -Iresults/D0008/r15D0008/rgg100 \
    -Iresults/D0008/r15D0008/rgg1000 \
    -Iresults/D0008/r15D0008/rgg2 \
    -Iresults/D0008/r15D0008/rgg200 \
    -Iresults/D0008/r15D0008/rgg30 \
    -Iresults/D0008/r15D0008/rgg5 \
    -Iresults/D0008/r15D0008/rgg50 \
    -Iresults/D0008/r15D0008/rgg500 \
    -Iresults/D0008/r15D0008/rgg80 \
    -Iresults/D0008/r50D0008 \
    -Iresults/D0008/r50D0008/rgg10 \
    -Iresults/D0008/r50D0008/rgg100 \
    -Iresults/D0008/r50D0008/rgg1000 \
    -Iresults/D0008/r50D0008/rgg2 \
    -Iresults/D0008/r50D0008/rgg200 \
    -Iresults/D0008/r50D0008/rgg30 \
    -Iresults/D0008/r50D0008/rgg5 \
    -Iresults/D0008/r50D0008/rgg50 \
    -Iresults/D0008/r50D0008/rgg500 \
    -Iresults/D0008/r50D0008/rgg80 \
    -Iresults/D001 \
    -Iresults/D001/r10D001 \
    -Iresults/D001/r10D001/rgg10 \
    -Iresults/D001/r10D001/rgg100 \
    -Iresults/D001/r10D001/rgg1000 \
    -Iresults/D001/r10D001/rgg2 \
    -Iresults/D001/r10D001/rgg200 \
    -Iresults/D001/r10D001/rgg30 \
    -Iresults/D001/r10D001/rgg5 \
    -Iresults/D001/r10D001/rgg50 \
    -Iresults/D001/r10D001/rgg500 \
    -Iresults/D001/r10D001/rgg80 \
    -Iresults/D001/r15D001 \
    -Iresults/D001/r15D001/rgg10 \
    -Iresults/D001/r15D001/rgg100 \
    -Iresults/D001/r15D001/rgg1000 \
    -Iresults/D001/r15D001/rgg2 \
    -Iresults/D001/r15D001/rgg200 \
    -Iresults/D001/r15D001/rgg30 \
    -Iresults/D001/r15D001/rgg5 \
    -Iresults/D001/r15D001/rgg50 \
    -Iresults/D001/r15D001/rgg500 \
    -Iresults/D001/r15D001/rgg80 \
    -Iresults/D001/r50D001 \
    -Iresults/D001/r50D001/rgg10 \
    -Iresults/D001/r50D001/rgg100 \
    -Iresults/D001/r50D001/rgg1000 \
    -Iresults/D001/r50D001/rgg2 \
    -Iresults/D001/r50D001/rgg200 \
    -Iresults/D001/r50D001/rgg30 \
    -Iresults/D001/r50D001/rgg5 \
    -Iresults/D001/r50D001/rgg50 \
    -Iresults/D001/r50D001/rgg500 \
    -Iresults/D001/r50D001/rgg80 \
    -Iresults/D002 \
    -Iresults/D002/r10D002 \
    -Iresults/D002/r10D002/rgg10 \
    -Iresults/D002/r10D002/rgg100 \
    -Iresults/D002/r10D002/rgg1000 \
    -Iresults/D002/r10D002/rgg2 \
    -Iresults/D002/r10D002/rgg200 \
    -Iresults/D002/r10D002/rgg30 \
    -Iresults/D002/r10D002/rgg5 \
    -Iresults/D002/r10D002/rgg50 \
    -Iresults/D002/r10D002/rgg500 \
    -Iresults/D002/r10D002/rgg80 \
    -Iresults/D002/r15D002 \
    -Iresults/D002/r15D002/rgg10 \
    -Iresults/D002/r15D002/rgg100 \
    -Iresults/D002/r15D002/rgg1000 \
    -Iresults/D002/r15D002/rgg2 \
    -Iresults/D002/r15D002/rgg200 \
    -Iresults/D002/r15D002/rgg30 \
    -Iresults/D002/r15D002/rgg5 \
    -Iresults/D002/r15D002/rgg50 \
    -Iresults/D002/r15D002/rgg500 \
    -Iresults/D002/r15D002/rgg80 \
    -Iresults/D002/r50D002 \
    -Iresults/D002/r50D002/rgg10 \
    -Iresults/D002/r50D002/rgg100 \
    -Iresults/D002/r50D002/rgg1000 \
    -Iresults/D002/r50D002/rgg2 \
    -Iresults/D002/r50D002/rgg200 \
    -Iresults/D002/r50D002/rgg30 \
    -Iresults/D002/r50D002/rgg5 \
    -Iresults/D002/r50D002/rgg50 \
    -Iresults/D002/r50D002/rgg500 \
    -Iresults/D002/r50D002/rgg80 \
    -Iresults/noD \
    -Iresults/noD/r10 \
    -Iresults/noD/r10/RGG01 \
    -Iresults/noD/r10/RGG03 \
    -Iresults/noD/r10/RGG04 \
    -Iresults/noD/r10/RGG05 \
    -Iresults/noD/r10/RGG06 \
    -Iresults/noD/r10/RGG07 \
    -Iresults/noD/r10/RGG08 \
    -Iresults/noD/r10/RGG09 \
    -Iresults/noD/r10/RGG10 \
    -Iresults/noD/r10/RGG11 \
    -Iresults/noD/r15 \
    -Iresults/noD/r15/RGG01 \
    -Iresults/noD/r15/RGG03 \
    -Iresults/noD/r15/RGG04 \
    -Iresults/noD/r15/RGG05 \
    -Iresults/noD/r15/RGG06 \
    -Iresults/noD/r15/RGG07 \
    -Iresults/noD/r15/RGG08 \
    -Iresults/noD/r15/RGG09 \
    -Iresults/noD/r15/RGG10 \
    -Iresults/noD/r15/RGG11 \
    -Isrc \
    -Isrc/battery \
    -Isrc/bluetooth \
    -Isrc/coordinate \
    -Isrc/coordinate/bidimensional \
    -Isrc/message \
    -Isrc/message/bluetooth \
    -Isrc/node \
    -Isrc/node/models \
    -Isrc/protocol

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cpp and .msg files
OBJS = \
    $O/src/battery/BatteryManager.o \
    $O/src/bluetooth/BTFsaManager.o \
    $O/src/coordinate/bidimensional/Coordinate2D.o \
    $O/src/message/bluetooth/BTMessageGenerator.o \
    $O/src/node/models/RandomGeometricNode.o \
    $O/src/protocol/AdvertiseLimit.o \
    $O/src/protocol/Bound.o \
    $O/src/protocol/DynamicFanout.o \
    $O/src/protocol/ProtocolManager.o \
    $O/src/message/bluetooth/btmessage_m.o

# Message files
MSGFILES = \
    src/message/bluetooth/btmessage.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cpp

$O/%.o: %.cpp $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cpp %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cpp $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f prova1 prova1.exe libprova1.so libprova1.a libprova1.dll libprova1.dylib
	$(Q)-rm -f ./*_m.cpp ./*_m.h
	$(Q)-rm -f iniFile/*_m.cpp iniFile/*_m.h
	$(Q)-rm -f iniFile/D0008/*_m.cpp iniFile/D0008/*_m.h
	$(Q)-rm -f iniFile/D001/*_m.cpp iniFile/D001/*_m.h
	$(Q)-rm -f iniFile/D002/*_m.cpp iniFile/D002/*_m.h
	$(Q)-rm -f iniFile/noD/*_m.cpp iniFile/noD/*_m.h
	$(Q)-rm -f net/*_m.cpp net/*_m.h
	$(Q)-rm -f net/randomgeometricgraph/*_m.cpp net/randomgeometricgraph/*_m.h
	$(Q)-rm -f results/*_m.cpp results/*_m.h
	$(Q)-rm -f results/D0008/*_m.cpp results/D0008/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/*_m.cpp results/D0008/r10D0008/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg10/*_m.cpp results/D0008/r10D0008/rgg10/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg100/*_m.cpp results/D0008/r10D0008/rgg100/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg1000/*_m.cpp results/D0008/r10D0008/rgg1000/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg2/*_m.cpp results/D0008/r10D0008/rgg2/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg200/*_m.cpp results/D0008/r10D0008/rgg200/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg30/*_m.cpp results/D0008/r10D0008/rgg30/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg5/*_m.cpp results/D0008/r10D0008/rgg5/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg50/*_m.cpp results/D0008/r10D0008/rgg50/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg500/*_m.cpp results/D0008/r10D0008/rgg500/*_m.h
	$(Q)-rm -f results/D0008/r10D0008/rgg80/*_m.cpp results/D0008/r10D0008/rgg80/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/*_m.cpp results/D0008/r15D0008/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg10/*_m.cpp results/D0008/r15D0008/rgg10/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg100/*_m.cpp results/D0008/r15D0008/rgg100/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg1000/*_m.cpp results/D0008/r15D0008/rgg1000/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg2/*_m.cpp results/D0008/r15D0008/rgg2/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg200/*_m.cpp results/D0008/r15D0008/rgg200/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg30/*_m.cpp results/D0008/r15D0008/rgg30/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg5/*_m.cpp results/D0008/r15D0008/rgg5/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg50/*_m.cpp results/D0008/r15D0008/rgg50/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg500/*_m.cpp results/D0008/r15D0008/rgg500/*_m.h
	$(Q)-rm -f results/D0008/r15D0008/rgg80/*_m.cpp results/D0008/r15D0008/rgg80/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/*_m.cpp results/D0008/r50D0008/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg10/*_m.cpp results/D0008/r50D0008/rgg10/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg100/*_m.cpp results/D0008/r50D0008/rgg100/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg1000/*_m.cpp results/D0008/r50D0008/rgg1000/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg2/*_m.cpp results/D0008/r50D0008/rgg2/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg200/*_m.cpp results/D0008/r50D0008/rgg200/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg30/*_m.cpp results/D0008/r50D0008/rgg30/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg5/*_m.cpp results/D0008/r50D0008/rgg5/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg50/*_m.cpp results/D0008/r50D0008/rgg50/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg500/*_m.cpp results/D0008/r50D0008/rgg500/*_m.h
	$(Q)-rm -f results/D0008/r50D0008/rgg80/*_m.cpp results/D0008/r50D0008/rgg80/*_m.h
	$(Q)-rm -f results/D001/*_m.cpp results/D001/*_m.h
	$(Q)-rm -f results/D001/r10D001/*_m.cpp results/D001/r10D001/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg10/*_m.cpp results/D001/r10D001/rgg10/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg100/*_m.cpp results/D001/r10D001/rgg100/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg1000/*_m.cpp results/D001/r10D001/rgg1000/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg2/*_m.cpp results/D001/r10D001/rgg2/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg200/*_m.cpp results/D001/r10D001/rgg200/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg30/*_m.cpp results/D001/r10D001/rgg30/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg5/*_m.cpp results/D001/r10D001/rgg5/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg50/*_m.cpp results/D001/r10D001/rgg50/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg500/*_m.cpp results/D001/r10D001/rgg500/*_m.h
	$(Q)-rm -f results/D001/r10D001/rgg80/*_m.cpp results/D001/r10D001/rgg80/*_m.h
	$(Q)-rm -f results/D001/r15D001/*_m.cpp results/D001/r15D001/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg10/*_m.cpp results/D001/r15D001/rgg10/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg100/*_m.cpp results/D001/r15D001/rgg100/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg1000/*_m.cpp results/D001/r15D001/rgg1000/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg2/*_m.cpp results/D001/r15D001/rgg2/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg200/*_m.cpp results/D001/r15D001/rgg200/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg30/*_m.cpp results/D001/r15D001/rgg30/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg5/*_m.cpp results/D001/r15D001/rgg5/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg50/*_m.cpp results/D001/r15D001/rgg50/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg500/*_m.cpp results/D001/r15D001/rgg500/*_m.h
	$(Q)-rm -f results/D001/r15D001/rgg80/*_m.cpp results/D001/r15D001/rgg80/*_m.h
	$(Q)-rm -f results/D001/r50D001/*_m.cpp results/D001/r50D001/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg10/*_m.cpp results/D001/r50D001/rgg10/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg100/*_m.cpp results/D001/r50D001/rgg100/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg1000/*_m.cpp results/D001/r50D001/rgg1000/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg2/*_m.cpp results/D001/r50D001/rgg2/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg200/*_m.cpp results/D001/r50D001/rgg200/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg30/*_m.cpp results/D001/r50D001/rgg30/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg5/*_m.cpp results/D001/r50D001/rgg5/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg50/*_m.cpp results/D001/r50D001/rgg50/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg500/*_m.cpp results/D001/r50D001/rgg500/*_m.h
	$(Q)-rm -f results/D001/r50D001/rgg80/*_m.cpp results/D001/r50D001/rgg80/*_m.h
	$(Q)-rm -f results/D002/*_m.cpp results/D002/*_m.h
	$(Q)-rm -f results/D002/r10D002/*_m.cpp results/D002/r10D002/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg10/*_m.cpp results/D002/r10D002/rgg10/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg100/*_m.cpp results/D002/r10D002/rgg100/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg1000/*_m.cpp results/D002/r10D002/rgg1000/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg2/*_m.cpp results/D002/r10D002/rgg2/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg200/*_m.cpp results/D002/r10D002/rgg200/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg30/*_m.cpp results/D002/r10D002/rgg30/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg5/*_m.cpp results/D002/r10D002/rgg5/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg50/*_m.cpp results/D002/r10D002/rgg50/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg500/*_m.cpp results/D002/r10D002/rgg500/*_m.h
	$(Q)-rm -f results/D002/r10D002/rgg80/*_m.cpp results/D002/r10D002/rgg80/*_m.h
	$(Q)-rm -f results/D002/r15D002/*_m.cpp results/D002/r15D002/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg10/*_m.cpp results/D002/r15D002/rgg10/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg100/*_m.cpp results/D002/r15D002/rgg100/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg1000/*_m.cpp results/D002/r15D002/rgg1000/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg2/*_m.cpp results/D002/r15D002/rgg2/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg200/*_m.cpp results/D002/r15D002/rgg200/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg30/*_m.cpp results/D002/r15D002/rgg30/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg5/*_m.cpp results/D002/r15D002/rgg5/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg50/*_m.cpp results/D002/r15D002/rgg50/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg500/*_m.cpp results/D002/r15D002/rgg500/*_m.h
	$(Q)-rm -f results/D002/r15D002/rgg80/*_m.cpp results/D002/r15D002/rgg80/*_m.h
	$(Q)-rm -f results/D002/r50D002/*_m.cpp results/D002/r50D002/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg10/*_m.cpp results/D002/r50D002/rgg10/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg100/*_m.cpp results/D002/r50D002/rgg100/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg1000/*_m.cpp results/D002/r50D002/rgg1000/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg2/*_m.cpp results/D002/r50D002/rgg2/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg200/*_m.cpp results/D002/r50D002/rgg200/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg30/*_m.cpp results/D002/r50D002/rgg30/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg5/*_m.cpp results/D002/r50D002/rgg5/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg50/*_m.cpp results/D002/r50D002/rgg50/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg500/*_m.cpp results/D002/r50D002/rgg500/*_m.h
	$(Q)-rm -f results/D002/r50D002/rgg80/*_m.cpp results/D002/r50D002/rgg80/*_m.h
	$(Q)-rm -f results/noD/*_m.cpp results/noD/*_m.h
	$(Q)-rm -f results/noD/r10/*_m.cpp results/noD/r10/*_m.h
	$(Q)-rm -f results/noD/r10/RGG01/*_m.cpp results/noD/r10/RGG01/*_m.h
	$(Q)-rm -f results/noD/r10/RGG03/*_m.cpp results/noD/r10/RGG03/*_m.h
	$(Q)-rm -f results/noD/r10/RGG04/*_m.cpp results/noD/r10/RGG04/*_m.h
	$(Q)-rm -f results/noD/r10/RGG05/*_m.cpp results/noD/r10/RGG05/*_m.h
	$(Q)-rm -f results/noD/r10/RGG06/*_m.cpp results/noD/r10/RGG06/*_m.h
	$(Q)-rm -f results/noD/r10/RGG07/*_m.cpp results/noD/r10/RGG07/*_m.h
	$(Q)-rm -f results/noD/r10/RGG08/*_m.cpp results/noD/r10/RGG08/*_m.h
	$(Q)-rm -f results/noD/r10/RGG09/*_m.cpp results/noD/r10/RGG09/*_m.h
	$(Q)-rm -f results/noD/r10/RGG10/*_m.cpp results/noD/r10/RGG10/*_m.h
	$(Q)-rm -f results/noD/r10/RGG11/*_m.cpp results/noD/r10/RGG11/*_m.h
	$(Q)-rm -f results/noD/r15/*_m.cpp results/noD/r15/*_m.h
	$(Q)-rm -f results/noD/r15/RGG01/*_m.cpp results/noD/r15/RGG01/*_m.h
	$(Q)-rm -f results/noD/r15/RGG03/*_m.cpp results/noD/r15/RGG03/*_m.h
	$(Q)-rm -f results/noD/r15/RGG04/*_m.cpp results/noD/r15/RGG04/*_m.h
	$(Q)-rm -f results/noD/r15/RGG05/*_m.cpp results/noD/r15/RGG05/*_m.h
	$(Q)-rm -f results/noD/r15/RGG06/*_m.cpp results/noD/r15/RGG06/*_m.h
	$(Q)-rm -f results/noD/r15/RGG07/*_m.cpp results/noD/r15/RGG07/*_m.h
	$(Q)-rm -f results/noD/r15/RGG08/*_m.cpp results/noD/r15/RGG08/*_m.h
	$(Q)-rm -f results/noD/r15/RGG09/*_m.cpp results/noD/r15/RGG09/*_m.h
	$(Q)-rm -f results/noD/r15/RGG10/*_m.cpp results/noD/r15/RGG10/*_m.h
	$(Q)-rm -f results/noD/r15/RGG11/*_m.cpp results/noD/r15/RGG11/*_m.h
	$(Q)-rm -f src/*_m.cpp src/*_m.h
	$(Q)-rm -f src/battery/*_m.cpp src/battery/*_m.h
	$(Q)-rm -f src/bluetooth/*_m.cpp src/bluetooth/*_m.h
	$(Q)-rm -f src/coordinate/*_m.cpp src/coordinate/*_m.h
	$(Q)-rm -f src/coordinate/bidimensional/*_m.cpp src/coordinate/bidimensional/*_m.h
	$(Q)-rm -f src/message/*_m.cpp src/message/*_m.h
	$(Q)-rm -f src/message/bluetooth/*_m.cpp src/message/bluetooth/*_m.h
	$(Q)-rm -f src/node/*_m.cpp src/node/*_m.h
	$(Q)-rm -f src/node/models/*_m.cpp src/node/models/*_m.h
	$(Q)-rm -f src/protocol/*_m.cpp src/protocol/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cpp iniFile/*.cpp iniFile/D0008/*.cpp iniFile/D001/*.cpp iniFile/D002/*.cpp iniFile/noD/*.cpp net/*.cpp net/randomgeometricgraph/*.cpp results/*.cpp results/D0008/*.cpp results/D0008/r10D0008/*.cpp results/D0008/r10D0008/rgg10/*.cpp results/D0008/r10D0008/rgg100/*.cpp results/D0008/r10D0008/rgg1000/*.cpp results/D0008/r10D0008/rgg2/*.cpp results/D0008/r10D0008/rgg200/*.cpp results/D0008/r10D0008/rgg30/*.cpp results/D0008/r10D0008/rgg5/*.cpp results/D0008/r10D0008/rgg50/*.cpp results/D0008/r10D0008/rgg500/*.cpp results/D0008/r10D0008/rgg80/*.cpp results/D0008/r15D0008/*.cpp results/D0008/r15D0008/rgg10/*.cpp results/D0008/r15D0008/rgg100/*.cpp results/D0008/r15D0008/rgg1000/*.cpp results/D0008/r15D0008/rgg2/*.cpp results/D0008/r15D0008/rgg200/*.cpp results/D0008/r15D0008/rgg30/*.cpp results/D0008/r15D0008/rgg5/*.cpp results/D0008/r15D0008/rgg50/*.cpp results/D0008/r15D0008/rgg500/*.cpp results/D0008/r15D0008/rgg80/*.cpp results/D0008/r50D0008/*.cpp results/D0008/r50D0008/rgg10/*.cpp results/D0008/r50D0008/rgg100/*.cpp results/D0008/r50D0008/rgg1000/*.cpp results/D0008/r50D0008/rgg2/*.cpp results/D0008/r50D0008/rgg200/*.cpp results/D0008/r50D0008/rgg30/*.cpp results/D0008/r50D0008/rgg5/*.cpp results/D0008/r50D0008/rgg50/*.cpp results/D0008/r50D0008/rgg500/*.cpp results/D0008/r50D0008/rgg80/*.cpp results/D001/*.cpp results/D001/r10D001/*.cpp results/D001/r10D001/rgg10/*.cpp results/D001/r10D001/rgg100/*.cpp results/D001/r10D001/rgg1000/*.cpp results/D001/r10D001/rgg2/*.cpp results/D001/r10D001/rgg200/*.cpp results/D001/r10D001/rgg30/*.cpp results/D001/r10D001/rgg5/*.cpp results/D001/r10D001/rgg50/*.cpp results/D001/r10D001/rgg500/*.cpp results/D001/r10D001/rgg80/*.cpp results/D001/r15D001/*.cpp results/D001/r15D001/rgg10/*.cpp results/D001/r15D001/rgg100/*.cpp results/D001/r15D001/rgg1000/*.cpp results/D001/r15D001/rgg2/*.cpp results/D001/r15D001/rgg200/*.cpp results/D001/r15D001/rgg30/*.cpp results/D001/r15D001/rgg5/*.cpp results/D001/r15D001/rgg50/*.cpp results/D001/r15D001/rgg500/*.cpp results/D001/r15D001/rgg80/*.cpp results/D001/r50D001/*.cpp results/D001/r50D001/rgg10/*.cpp results/D001/r50D001/rgg100/*.cpp results/D001/r50D001/rgg1000/*.cpp results/D001/r50D001/rgg2/*.cpp results/D001/r50D001/rgg200/*.cpp results/D001/r50D001/rgg30/*.cpp results/D001/r50D001/rgg5/*.cpp results/D001/r50D001/rgg50/*.cpp results/D001/r50D001/rgg500/*.cpp results/D001/r50D001/rgg80/*.cpp results/D002/*.cpp results/D002/r10D002/*.cpp results/D002/r10D002/rgg10/*.cpp results/D002/r10D002/rgg100/*.cpp results/D002/r10D002/rgg1000/*.cpp results/D002/r10D002/rgg2/*.cpp results/D002/r10D002/rgg200/*.cpp results/D002/r10D002/rgg30/*.cpp results/D002/r10D002/rgg5/*.cpp results/D002/r10D002/rgg50/*.cpp results/D002/r10D002/rgg500/*.cpp results/D002/r10D002/rgg80/*.cpp results/D002/r15D002/*.cpp results/D002/r15D002/rgg10/*.cpp results/D002/r15D002/rgg100/*.cpp results/D002/r15D002/rgg1000/*.cpp results/D002/r15D002/rgg2/*.cpp results/D002/r15D002/rgg200/*.cpp results/D002/r15D002/rgg30/*.cpp results/D002/r15D002/rgg5/*.cpp results/D002/r15D002/rgg50/*.cpp results/D002/r15D002/rgg500/*.cpp results/D002/r15D002/rgg80/*.cpp results/D002/r50D002/*.cpp results/D002/r50D002/rgg10/*.cpp results/D002/r50D002/rgg100/*.cpp results/D002/r50D002/rgg1000/*.cpp results/D002/r50D002/rgg2/*.cpp results/D002/r50D002/rgg200/*.cpp results/D002/r50D002/rgg30/*.cpp results/D002/r50D002/rgg5/*.cpp results/D002/r50D002/rgg50/*.cpp results/D002/r50D002/rgg500/*.cpp results/D002/r50D002/rgg80/*.cpp results/noD/*.cpp results/noD/r10/*.cpp results/noD/r10/RGG01/*.cpp results/noD/r10/RGG03/*.cpp results/noD/r10/RGG04/*.cpp results/noD/r10/RGG05/*.cpp results/noD/r10/RGG06/*.cpp results/noD/r10/RGG07/*.cpp results/noD/r10/RGG08/*.cpp results/noD/r10/RGG09/*.cpp results/noD/r10/RGG10/*.cpp results/noD/r10/RGG11/*.cpp results/noD/r15/*.cpp results/noD/r15/RGG01/*.cpp results/noD/r15/RGG03/*.cpp results/noD/r15/RGG04/*.cpp results/noD/r15/RGG05/*.cpp results/noD/r15/RGG06/*.cpp results/noD/r15/RGG07/*.cpp results/noD/r15/RGG08/*.cpp results/noD/r15/RGG09/*.cpp results/noD/r15/RGG10/*.cpp results/noD/r15/RGG11/*.cpp src/*.cpp src/battery/*.cpp src/bluetooth/*.cpp src/coordinate/*.cpp src/coordinate/bidimensional/*.cpp src/message/*.cpp src/message/bluetooth/*.cpp src/node/*.cpp src/node/models/*.cpp src/protocol/*.cpp

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/battery/BatteryManager.o: src/battery/BatteryManager.cpp \
	src/battery/BatteryManager.h
$O/src/bluetooth/BTFsaManager.o: src/bluetooth/BTFsaManager.cpp \
	src/bluetooth/BTFsaManager.h \
	src/bluetooth/BTState.h
$O/src/coordinate/bidimensional/Coordinate2D.o: src/coordinate/bidimensional/Coordinate2D.cpp \
	src/coordinate/bidimensional/Coordinate2D.h
$O/src/message/bluetooth/BTMessageGenerator.o: src/message/bluetooth/BTMessageGenerator.cpp \
	src/message/OPCode.h \
	src/message/UnityMeasureCode.h \
	src/message/bluetooth/BTMessageGenerator.h \
	src/message/bluetooth/btmessage_m.h
$O/src/node/models/RandomGeometricNode.o: src/node/models/RandomGeometricNode.cpp \
	src/battery/BatteryManager.h \
	src/bluetooth/BTFsaManager.h \
	src/bluetooth/BTState.h \
	src/message/OPCode.h \
	src/message/UnityMeasureCode.h \
	src/message/bluetooth/BTMessageGenerator.h \
	src/message/bluetooth/btmessage_m.h \
	src/node/models/RandomGeometricNode.h \
	src/protocol/AdvertiseLimit.h \
	src/protocol/Bound.h \
	src/protocol/DynamicFanout.h \
	src/protocol/ProtocolManager.h
$O/src/protocol/AdvertiseLimit.o: src/protocol/AdvertiseLimit.cpp \
	src/battery/BatteryManager.h \
	src/protocol/AdvertiseLimit.h \
	src/protocol/Bound.h
$O/src/protocol/Bound.o: src/protocol/Bound.cpp \
	src/battery/BatteryManager.h \
	src/protocol/Bound.h
$O/src/protocol/DynamicFanout.o: src/protocol/DynamicFanout.cpp \
	src/battery/BatteryManager.h \
	src/protocol/Bound.h \
	src/protocol/DynamicFanout.h
$O/src/protocol/ProtocolManager.o: src/protocol/ProtocolManager.cpp \
	src/battery/BatteryManager.h \
	src/protocol/AdvertiseLimit.h \
	src/protocol/Bound.h \
	src/protocol/DynamicFanout.h \
	src/protocol/ProtocolManager.h

