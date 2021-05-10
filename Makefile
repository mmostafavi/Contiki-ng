CONTIKI_PROJECT = demo-counter
all: $(CONTIKI_PROJECT)
PROJECT_SOURCEFILES += my_counter.c
CONTIKI = ../../..
include $(CONTIKI)/Makefile.include
