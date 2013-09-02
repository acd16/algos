main: clean llist.o
	gcc llist.o listsort.c -I ./ -o main

llist.o:
	gcc -c llist.c -I ./

clean:
	rm -f llist.o main
