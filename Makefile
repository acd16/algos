q: queue.c queue.h
	gcc -c queue.c -g

cleanq:
	rm -f q

main: llist.o queue.o
	gcc llist.o queue.o main.c -I ./ -g -o main

llist.o: llist.c llist.h
	gcc -c llist.c -g -I ./

queue.o: queue.c queue.h
	gcc -c queue.c -g -I ./

clean:
	rm -f llist.o queue.o main

graph: graph.c graph.h llist.o queue.o
	gcc llist.o queue.o graph.c -I ./ -g -o graph

