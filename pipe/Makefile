CC=gcc
CFLAGS=-c -Wall

all:sec  kofak  determinant

sec: satsutsec.c
	$(CC) satsutsec.c -lm -o sec

kofak: kofakhesap2x2.c
	$(CC) kofakhesap2x2.c -lm -o kofak

determinant: determinant3x3.c
	$(CC) determinant3x3.c -lm -o determinant
clean: 
	rm -rf *o myshell
