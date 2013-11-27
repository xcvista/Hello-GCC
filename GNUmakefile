
ifeq ($(CC),)
ifeq ($(shell uname -s),Darwin)
CC := clang
else
CC := gcc
endif
endif

CCLD := $(CC)
ECHO := /bin/echo

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

all: before_all $(TARGET)

before_all:
	@echo -e "Building version $(shell git log --pretty=format:'%h' -n 1)..."
	@$(ECHO) -e "  CC\t\t= $(CC)"
	@$(ECHO) -e "  CCLD\t\t= $(CCLD)"
	@$(ECHO) -e "  CFLAGS\t= $(EFFECTIVE_CFLAGS)"
	@$(ECHO) -e "  LDFLAGS\t= $(EFFECTIVE_LDFLAGS)"

%.c.o: %.c $(HEADERS)
	@$(ECHO) -e "  CC\t\t$<"
	@$(CC) $(EFFECTIVE_CPPFLAGS) $(EFFECTIVE_CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@$(ECHO) -e "  CCLD\t\t$@"
	@$(CCLD) $(EFFECTIVE_LDFLAGS) -o $(TARGET) $(OBJS)

clean:
	@$(ECHO) -e "  CLEAN"
	-@rm -f $(TARGET) $(OBJS) >& /dev/null

check: all
	@$(ECHO) -e "  TEST"
	@cd test && ./check-all.sh ../$(TARGET) *.txt

profile: all
	@$(ECHO) -e "  PROFILE"
	@time { for each in {1..100}; do ./$(TARGET) < src/main.c > /dev/null; done }
