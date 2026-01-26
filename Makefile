noter: main.o logic.o
	gcc -Wall main.o logic.o -o noter

main.o: main.c logic.h
	gcc -Wall -c main.c

logic.o: logic.c logic.h
	gcc -Wall -c logic.c

clean:
	rm -f *.o
