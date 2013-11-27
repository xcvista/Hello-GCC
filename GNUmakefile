
ifeq ($(shell uname -s),Darwin)
	CC := clang
else
	CC := gcc
endif

CCLD := $(CC)

EFFECTIVE_CPPFLAGS := $(CPPFLAGS) -Iinclude
EFFECTIVE_CFLAGS := $(CFLAGS) -std=gnu99
EFFECTIVE_LDFLAGS := $(LDFLAGS)

C_FILES := $(wildcard src/*.c)
HEADERS := $(wildcard include/*.h)
OBJS := $(subst .c,.c.o,$(C_FILES))
TARGET := rev

all: $(TARGET)

%.c.o: %.c $(HEADERS)
	$(CC) $(EFFECTIVE_CPPFLAGS) $(EFFECTIVE_CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CCLD) $(EFFECTIVE_LDFLAGS) -o $(TARGET) $(OBJS)

clean:
	-rm -f $(TARGET) $(OBJS)

check: all
	cd test && ./check-all.sh ../$(TARGET) *.txt

