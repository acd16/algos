q: cleanq
	gcc queue.c -g -o q

cleanq:
	rm -f q

main: clean llist.o queue.o
	gcc llist.o queue.o main.c -I ./ -g -o main

llist.o: llist.c llist.h
	gcc -c llist.c -g -I ./

queue.o: queue.c queue.h
	gcc -c queue.c -g -I ./

clean:
	rm -f llist.o queue.o main

graph: graph.c graph.h
	gcc graph.c -I ./ -g -o graph

