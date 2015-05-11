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
    -Inet \
    -Inet/randomgeometricgraph \
    -Iresults \
    -Isrc \
    -Isrc/coordinate \
    -Isrc/coordinate/bidimensional \
    -Isrc/message \
    -Isrc/node \
    -Isrc/node/models \
    -Isrc/pkgprova

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cpp and .msg files
OBJS = $O/src/coordinate/bidimensional/Coordinate2D.o $O/src/message/OPCode.o $O/src/node/models/RandomGeometricNode.o $O/src/pkgprova/Host.o $O/src/message/btmessage_m.o

# Message files
MSGFILES = \
    src/message/btmessage.msg

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
	$(Q)-rm -f net/*_m.cpp net/*_m.h
	$(Q)-rm -f net/randomgeometricgraph/*_m.cpp net/randomgeometricgraph/*_m.h
	$(Q)-rm -f results/*_m.cpp results/*_m.h
	$(Q)-rm -f src/*_m.cpp src/*_m.h
	$(Q)-rm -f src/coordinate/*_m.cpp src/coordinate/*_m.h
	$(Q)-rm -f src/coordinate/bidimensional/*_m.cpp src/coordinate/bidimensional/*_m.h
	$(Q)-rm -f src/message/*_m.cpp src/message/*_m.h
	$(Q)-rm -f src/node/*_m.cpp src/node/*_m.h
	$(Q)-rm -f src/node/models/*_m.cpp src/node/models/*_m.h
	$(Q)-rm -f src/pkgprova/*_m.cpp src/pkgprova/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cpp net/*.cpp net/randomgeometricgraph/*.cpp results/*.cpp src/*.cpp src/coordinate/*.cpp src/coordinate/bidimensional/*.cpp src/message/*.cpp src/node/*.cpp src/node/models/*.cpp src/pkgprova/*.cpp

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/coordinate/bidimensional/Coordinate2D.o: src/coordinate/bidimensional/Coordinate2D.cpp \
	src/coordinate/bidimensional/Coordinate2D.h
$O/src/message/OPCode.o: src/message/OPCode.cpp \
	src/message/OPCode.h
$O/src/node/models/RandomGeometricNode.o: src/node/models/RandomGeometricNode.cpp \
	src/message/OPCode.h \
	src/message/btmessage_m.h \
	src/node/models/RandomGeometricNode.h
$O/src/pkgprova/Host.o: src/pkgprova/Host.cpp

