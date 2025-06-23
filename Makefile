CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = -lsqlite3

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = mtb_cli

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regra para compilar .cpp em .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)


