# 지정한 컴파일러
CXX = g++
# 컴파일러 옵션
CXXFLAGS = -std=c++11 -Wall

# 바이너리 파일들
TARGETS = DS083 DS082 DS092 Heaptree DS091 Arraytotree DS081

all: $(TARGETS)

DS083: DS083.cpp
	$(CXX) $(CXXFLAGS) -o DS083 DS083.cpp

DS082: DS082.cpp
	$(CXX) $(CXXFLAGS) -o DS082 DS082.cpp

DS092: DS092.cpp
	$(CXX) $(CXXFLAGS) -o DS092 DS092.cpp

Heaptree: Heaptree.cpp
	$(CXX) $(CXXFLAGS) -o Heaptree Heaptree.cpp

DS091: DS091.cpp
	$(CXX) $(CXXFLAGS) -o DS091 DS091.cpp

Arraytotree: Arraytotree.cpp
	$(CXX) $(CXXFLAGS) -o Arraytotree Arraytotree.cpp

DS081: DS081.cpp
	$(CXX) $(CXXFLAGS) -o DS081 DS081.cpp

clean:
	rm -f $(TARGETS)

.PHONY: all clean