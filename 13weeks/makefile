# 컴파일러 설정
CC = g++
CFLAGS = -Wall -std=c++11

# 타겟 정의
TARGETS = prg_DS031 prg_DS032 prg_DS033 prg_DS041 prg_DS042 prg_DS043

all: $(TARGETS)

# DS031: MyStack 만들기
prg_DS031: main_DS031.o MyStack.o
	$(CC) $(CFLAGS) -o prg_DS031 main_DS031.o MyStack.o

main_DS031.o: main_DS031.cpp MyStack.h
	$(CC) $(CFLAGS) -c main_DS031.cpp

MyStack.o: MyStack.cpp MyStack.h
	$(CC) $(CFLAGS) -c MyStack.cpp

# DS032: GPA 분석하기
prg_DS032: main_DS032.o StringStack.o
	$(CC) $(CFLAGS) -o prg_DS032 main_DS032.o StringStack.o

main_DS032.o: main_DS032.cpp StringStack.h
	$(CC) $(CFLAGS) -c main_DS032.cpp

StringStack.o: StringStack.cpp StringStack.h
	$(CC) $(CFLAGS) -c StringStack.cpp

# DS033: 쿠폰 관리기
prg_DS033: main_DS033.o CouponStack.o
	$(CC) $(CFLAGS) -o prg_DS033 main_DS033.o CouponStack.o

main_DS033.o: main_DS033.cpp CouponStack.h
	$(CC) $(CFLAGS) -c main_DS033.cpp

CouponStack.o: CouponStack.cpp CouponStack.h
	$(CC) $(CFLAGS) -c CouponStack.cpp

# DS041: MyLinkedStack 만들기
prg_DS041: main_DS041.o MyLinkedStack.o
	$(CC) $(CFLAGS) -o prg_DS041 main_DS041.o MyLinkedStack.o

main_DS041.o: main_DS041.cpp MyLinkedStack.h
	$(CC) $(CFLAGS) -c main_DS041.cpp

MyLinkedStack.o: MyLinkedStack.cpp MyLinkedStack.h
	$(CC) $(CFLAGS) -c MyLinkedStack.cpp

# DS042: MyLinkedStack을 이용한 계산기
prg_DS042: main_DS042.o MyLinkedStack.o
	$(CC) $(CFLAGS) -o prg_DS042 main_DS042.o MyLinkedStack.o

main_DS042.o: main_DS042.cpp MyLinkedStack.h
	$(CC) $(CFLAGS) -c main_DS042.cpp

# DS043: 사용자가 입력한 문자열 알아내기
prg_DS043: main_DS043.o MyLinkedStack.o
	$(CC) $(CFLAGS) -o prg_DS043 main_DS043.o MyLinkedStack.o

main_DS043.o: main_DS043.cpp MyLinkedStack.h
	$(CC) $(CFLAGS) -c main_DS043.cpp

# Clean 명령어 정의
clean:
	rm -f *.o $(TARGETS)