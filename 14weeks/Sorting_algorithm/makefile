# Makefile to compile and run DS071, DS072, DS074, and DS075

# 컴파일러 설정
CXX = g++
CXXFLAGS = -Wall -g

# 각 실행 파일 이름 정의
EXECS = DS071 DS072 DS074	DS075

# all 타겟: 모든 실행 파일 빌드
all: $(EXECS)

# 각 실행 파일별 빌드 규칙
DS071: DS071.cpp
	$(CXX) $(CXXFLAGS) -o DS071 DS071.cpp

DS072: DS072.cpp
	$(CXX) $(CXXFLAGS) -o DS072 DS072.cpp

DS073: DS074.cpp
	$(CXX) $(CXXFLAGS) -o DS074 DS074.cpp

DS074: DS075.cpp
	$(CXX) $(CXXFLAGS) -o DS075 DS075.cpp

# clean 타겟: 빌드된 실행 파일 및 중간 파일 제거
clean:
	rm -f $(EXECS)