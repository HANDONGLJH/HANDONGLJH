# 컴파일러 지정
CC=gcc
# 컴파일 옵션 지정 sdsdsd
CFLAGS=-I.

# 최종 대상 파일
myprogram: main.o file1.o file2.o
	$(CC) -o myprogram main.o file1.o file2.o

# 각 .o 파일은 각각의 .c 파일과 .h 파일에 의존
main.o: main.c main.h
	$(CC) -c main.c $(CFLAGS)

file1.o: file1.c file1.h
	$(CC) -c file1.c $(CFLAGS)

file2.o: file2.c file2.h
	$(CC) -c file2.c $(CFLAGS)
clean:
	rm -f *.o myprogram