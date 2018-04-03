Q           :=@
CC          :=gcc
SRCS        :=$(wildcard *.c)
TARGET      :=memleaktest
OBJECTS     :=
CFLAGS	    :=-lm
LDFLAGS     :=
LIBS        :=
MACROS			:=

.PHONY: all
all: clean $(TARGET)

$(TARGET):
	$(Q)echo "  Building 64-bit '$@' ..."
	$(Q)$(CC) $(SRCS) -o $@_64 $(LDFLAGS) $(LIBS) $(CFLAGS) $(MACROS)
	$(Q)echo "  Building 32-bit '$@' ..."
	$(Q)$(CC) -m32 $(SRCS) -o $@_32 $(LDFLAGS) $(LIBS_32) $(CFLAGS) $(MACROS)

.PHONY: clean
clean:
	$(Q)echo "  Cleaning '$(TARGET)' ..."
	$(Q)$(RM) $(TARGET)_*