# TODO: add java/python/ruby stages
CC = g++

CFLAGS = -g -Wall -std=gnu++11 -lc -lm -fpermissive -mcmodel=medium

CCFILES = $(wildcard *.cc)
JAVAFILES = $(wildcard *.java)
PYFILES = $(wildcard *.py)
RBFILES = $(wildcard *.rb)

CCTARGETS = $(patsubst %.cc, %, $(CCFILES))
TESTTARGETS = $(patsubst %.cc, %.test, $(CCFILES))

PROBLEMA = $(wildcard *_square-detector.*)
PROBLEMB = $(wildcard *_basketball-game.*)
PROBLEMC = $(wildcard *_tennison.*)

TARGETS = $(CCTARGETS)

.PHONY: all clean test
.DEFAULT: all


all: $(TARGETS)

test: $(TARGETS) $(TESTTARGETS)


%_square-detector.test: %_square-detector
	$(eval PROBLEM := square-detector)
	@./$< < ../$(PROBLEM).in > $@
	@diff -wruN ../$(PROBLEM).out $@ || (echo Failed $<; rm $@)


%_basketball-game.test: %_basketball-game
	$(eval PROBLEM := basketball-game)
	@./$< < ../$(PROBLEM).in > $@
	@diff -wruN ../$(PROBLEM).out $@ || (echo Failed $<; rm $@)


%_tennison.test: %_tennison
	$(eval PROBLEM := tennison)
	@./$< < ../$(PROBLEM).in > $@
	@diff -wruN ../$(PROBLEM).out $@ || (echo Failed $<; rm $@)


%: %.cc
	$(CC) $(CFLAGS) -o $@ $<


clean:
	-rm -f $(TARGETS)
