#
# Makefile for libswo.a
#
TARGET   := ..\lib\libswo.a
SOURCES  := ./
DEPEND   := depend
SRCS     := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
OBJS     := $(SRCS:%.cpp=%.o)

INCLUDE_DIRS := -I../include
CFLAGS   := -Wall -O2 -g $(INCLUDE_DIRS) -DWIN32 -DUNICODE -D_UNICODE
ARFLAGS  := crsv

CPP := cpp
CX  := g++
AR  := ar
RM  := del /F

.SUFFIXES:
.SUFFIXES: .cpp .o

.cpp.o:
	$(CX) $(CFLAGS) -c $<

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
	-@ for %%i in ($^); do $(CPP) $(CFLAGS) -MM %%i >> $@

-include $(DEPEND)
