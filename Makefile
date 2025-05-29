noter: main.o logic.o
	gcc main.o logic.o -o noter

main.o: main.c logic.h
	gcc -c main.c

logic.o: logic.c logic.h
	gcc -c logic.c

clean:
	rm -f *.o