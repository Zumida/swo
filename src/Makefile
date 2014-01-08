#
# Makefile for libswo.a
#
TARGET   := ..\lib\libswo.a
SOURCES  := ./
DEPEND   := depend
SRCS     := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
OBJS     := $(SRCS:%.cpp=%.o)

INCLUDE_DIRS := -I../include
CXFLAGS  := -std=c++11 -Wall -O2 -g $(INCLUDE_DIRS)
ARFLAGS  := crsv

CPP := cpp
CX  := g++
AR  := ar
RM  := del /F

.SUFFIXES:
.SUFFIXES: .cpp .o

.cpp.o:
	$(CX) $(CXFLAGS) -c $<

.PHONY: all
all: $(DEPEND) $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY: clean
clean:
	- $(RM) $(TARGET)
	- $(RM) *.o
	- $(RM) $(DEPEND)

$(DEPEND): $(SRCS)
	-@ $(RM) $@
	@ echo Create $@ ...
	@ for %%i in ($^); do echo %%i && $(CPP) $(CXFLAGS) -MM %%i >> $@
	@ echo Done.

-include $(DEPEND)
