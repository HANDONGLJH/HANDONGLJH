# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable names
EXEC1 = DS061
EXEC2 = DS062
EXEC3 = DS063

# Source files
SRC1 = DS061.cpp
SRC2 = DS062.cpp
SRC3 = DS063.cpp

# Library
LIB_HDR = MyLLQueue.h
LIB_TPP = MyLLQueue.cpp

# All target
all: $(EXEC1) $(EXEC2) $(EXEC3)

# Rules for executables
$(EXEC1): $(SRC1) $(LIB_HDR) $(LIB_TPP)
	$(CXX) $(CXXFLAGS) -o $(EXEC1) $(SRC1)

$(EXEC2): $(SRC2) $(LIB_HDR) $(LIB_TPP)
	$(CXX) $(CXXFLAGS) -o $(EXEC2) $(SRC2)

$(EXEC3): $(SRC3) $(LIB_HDR) $(LIB_TPP)
	$(CXX) $(CXXFLAGS) -o $(EXEC3) $(SRC3)

# Clean rule
clean:
	rm -f $(EXEC1) $(EXEC2) $(EXEC3)