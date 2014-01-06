q: cleanq
	gcc queue.c -g -o q

cleanq:
	rm -f q

main: clean llist.o queue.o
	gcc llist.o queue.o listsort.c -I ./ -g -o main

llist.o:
	gcc -c llist.c -g -I ./

queue.o:
	gcc -c queue.c -g -I ./

clean:
	rm -f llist.o queue.o main

