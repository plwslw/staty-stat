all: stat.c
	gcc -o stat stat.c -lm

clean:
	rm *.o
	rm *~

run: all
	./stat
