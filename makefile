fileio: stat.c
	gcc stat.c -o stat

run: stat
	./stat
