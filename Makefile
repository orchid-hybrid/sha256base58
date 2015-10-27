main: crypto-algorithms/sha256.o libbase58/base58.o
	gcc crypto-algorithms/sha256.o libbase58/base58.o main.c -o main

crypto-algorithms/sha256.o:
	gcc -I crypto-algorithms -c crypto-algorithms/sha256.c -o crypto-algorithms/sha256.o

libbase58/base58.o:
	gcc -I libbase58 -c libbase58/base58.c -o libbase58/base58.o

