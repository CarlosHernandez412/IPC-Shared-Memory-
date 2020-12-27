# Makefile for week03

all:	shared_mem shm_io sigset sigset2 strings

shared_mem:	shared_mem.c
	gcc -o shared_mem shared_mem.c

shm_io:	shm_io.c
	gcc -o shm_io shm_io.c

sigset:	sigset.c
	gcc -o sigset sigset.c

sigset2:	sigset2.c
	gcc -o sigset2 sigset2.c

strings:	strings.c
	gcc -o strings strings.c

clean:
	rm -f shared_mem shm_io sigset sigset2 strings
