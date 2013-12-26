main: clean llist.o
	gcc llist.o listsort.c -I ./ -g -o main

llist.o:
	gcc -c llist.c -g -I ./

clean:
	rm -f llist.o main
