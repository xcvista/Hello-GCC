
ifeq ($(CC),)
ifeq ($(shell uname -s),Darwin)
CC := clang
else
CC := gcc
endif
endif

CCLD := $(CC)

EFFECTIVE_CPPFLAGS := $(CPPFLAGS) -Iinclude
EFFECTIVE_CFLAGS := $(CFLAGS) -std=gnu99
EFFECTIVE_LDFLAGS := $(LDFLAGS)

ifeq ($(DEBUG),YES)
EFFECTIVE_CFLAGS += -O0 -g
else
ifeq ($(CC),clang)
EFFECTIVE_CFLAGS += -Os
else
EFFECTIVE_CFLAGS += -O3
endif
endif

C_FILES := $(wildcard src/*.c)
HEADERS := $(wildcard include/*.h)
OBJS := $(subst .c,.c.o,$(C_FILES))
TARGET := rev

all: $(TARGET)

%.c.o: %.c $(HEADERS)
	@echo -e "  CC\t$<"
	@$(CC) $(EFFECTIVE_CPPFLAGS) $(EFFECTIVE_CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@echo -e "  CCLD\t$@"
	@$(CCLD) $(EFFECTIVE_LDFLAGS) -o $(TARGET) $(OBJS)

clean:
	@echo "  CLEAN"
	-@rm -f $(TARGET) $(OBJS) >& /dev/null

check: all
	@echo "  TEST"
	@cd test && ./check-all.sh ../$(TARGET) *.txt

