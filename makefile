all:
	gcc -c test.c -I ./
	gcc -c 8583.c -I ./
	gcc -o test test.o 8583.o
