# Makefile for DS051.cpp, DS052.cpp, DS053.cpp

CXX = g++
CXXFLAGS = -Wall -std=c++11

# Executable names
EXE1 = DS051
EXE2 = DS052
EXE3 = DS053

# Source files
SRC1 = DS051.cpp
SRC2 = DS052.cpp
SRC3 = DS053.cpp
SRC_LIB = MyCircularQueue.cpp MyCircularStringQueue.cpp

# Header files
HEADERS = MyCircularQueue.h MyCircularStringQueue.h

# Targets
all: $(EXE1) $(EXE2) $(EXE3)

$(EXE1): $(SRC1) $(SRC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC1) $(SRC_LIB)

$(EXE2): $(SRC2) $(SRC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC2) $(SRC_LIB)

$(EXE3): $(SRC3) $(SRC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC3) $(SRC_LIB)

# Clean up the build
clean:
	rm -f $(EXE1) $(EXE2) $(EXE3)

# Phony targets
.PHONY: all clean