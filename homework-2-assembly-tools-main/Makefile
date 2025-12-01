ASFLAGS = -g -c

LDFLAGS = -g

ASM_SRCS = $(wildcard *.s)
C_SRCS = $(wildcard *.c)

OBJS = $(subst .s,.o,$(ASM_SRCS)) $(subst .c,.o,$(C_SRCS))

default: build
build: test

.PHONY: clean
clean:
	rm -f $(OBJS) test *~ a.out core

# Note that we use $(CC) to do the assembly. We could use $(AS), but
# this would require setting a bunch of confusing flags.
%.o: %.s
	$(CC) $(ASFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^

test: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

test.log: test
	./test | tee test.log
