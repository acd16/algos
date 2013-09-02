main: llist.o
	gcc llist.o listsort.c -I ./ -o main

llist.o:
	gcc -c llist.c -I ./
