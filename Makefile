export NAME:=big_num
EXE:=.exe
export TESTS
export CFLAGS:=-Wall -std=c11 -pedantic -Wextra -I../include $(CFLAGS)

ifdef DEBUG
  CFLAGS:=$(CFLAGS) -g -DDEBUG
else
  CFLAGS:=$(CFLAGS) -O3 -DNDEBUG
endif

.PHONY: build
build:
	$(MAKE) -C src

.PHONY: example
example:
	$(MAKE) -C src $(NAME)
	cp src/$(NAME) $(NAME)$(EXE)

.PHONY: test
test: build
	$(MAKE) -C test

.PHONY: clean
clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean
	$(RM) $(NAME)$(EXE)