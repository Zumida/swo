#
# Makefile for libswo.a
#

TARGET = ..\lib\libswo.a

SRCS = \
	application.cpp \
	form.cpp \
	dragdrop.cpp \
	canvas.cpp \
	rootcontrol.cpp \
	control.cpp \
	bitmap.cpp \
	cursor.cpp \
	icon.cpp \
	patternbrush.cpp \
	hatchbrush.cpp \
	solidbrush.cpp \
	stockbrush.cpp \
	syscolorbrush.cpp \
	brush.cpp \
	custompen.cpp \
	stockpen.cpp \
	pen.cpp \
	gdiobject.cpp \
	menuitem.cpp \
	menu.cpp \
	imagelist.cpp \
	image.cpp \
	treeview.cpp \
	eventlistener.cpp \
	windowclass.cpp \
	object.cpp \
	string.cpp

INCLUDE_DIRS = -I../include

CFLAGS = -Wall -O2 -g $(INCLUDE_DIRS) -DWIN32 -DUNICODE -D_UNICODE

CXXFLAGS = $(CFLAGS)

ARFLAGS = crsv

OBJS = $(SRCS:%.cpp=%.o)

DEPEND = depend

CPP = cpp
CC = gcc
AR = ar
RM = del /F

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CXXFLAGS) -c $<

.PHONY: all
all: $(DEPEND) $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY: clean
clean:
	- $(RM) $(TARGET)
	- $(RM) $(OBJS)
	- $(RM) $(DEPEND)

$(DEPEND): $(SRCS)
	-@ $(RM) $@
	-@ for %%i in ($^); do $(CPP) $(CFLAGS) -MM %%i >> $@

-include $(DEPEND)
