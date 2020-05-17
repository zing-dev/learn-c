CC=gcc
CFLAGS = -Wall

TARGETS = bzero.out inet_ntop.out
SRC = bzero.c inet_ntop.c
#LISTS = bzero inet_ntop
LISTS = $$(ls *.c)

#<target> : <prerequisites>
#[tab]  <commands>

all:
	@for i in $(LISTS); do \
		$(CC) -o $$i.out $$i; \
	done


bzero.out:bzero.c
	$(CC) -o bzero.out $^

inet_ntop.out:inet_ntop.c
	$(CC) -o inet_ntop.out $^

test:
	@echo $$HOME
	@echo $$SHELL
	@echo $(CC)
	@pwd

#$(TARGETS):$(SRC)
#	$(CC) -o $(TARGETS) $^


#all:$(SRC)
#	$(CC) -o $(TARGETS) $^

#bzero.o:bzero.c
#	$(CC) $(CFLAGS) -c $^

#bzero.out:bzero.o
#	$(CC) -o bzero.out $^


#bzero.out: $(SRC)
#	$(CC) $(CFLAGS) $(SRC)

#%.o: %.c
#	$(CC) -c $(CFLAGS) $?


#target:依赖关系表
#1.out:1.c
#	$(CC) $(CFLAGS) $?


.PHONY:clear
clear:
	@echo "delete ... "
	@rm -rf *.out *.o