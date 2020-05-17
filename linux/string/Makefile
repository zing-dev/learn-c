CC=gcc
CFLAGS = -Wall

LISTS = $$(ls *.c)

all:
	@for i in $(LISTS); do \
		$(CC) -o $$i.out $$i; \
	done


.PHONY:clear
clear:
	@echo "delete ... "
	@rm -rf *.out *.o