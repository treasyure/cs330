a8: a8.o List.o node.o Airport.o
	gcc -o a8 a8.o List.o node.o Airport.o
a8.o: List.h Airport.h a8.c
	gcc -c a8.c
List.o: List.h List.c
	gcc -c List.c
node.o: node.h node.c
	gcc -c node.c
Airport.o: Airport.h Airport.c
	gcc -c Airport.c
