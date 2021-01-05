CC = gcc 
FLAGS = -Wall -g

all: isort txtfind

isort: main.o isort.o
	$(CC) $(FLAGS) -o isort main.o isort.o 

main.o: main.c isort.h
	$(CC) $(FLAGS) -c main.c 

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c 


txtfind: main_txt_find.o txtfind.o
	$(CC) $(FLAGS) -o txtfind main_txt_find.o txtfind.o 

main_txt_find.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c main_txt_find.c 

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind