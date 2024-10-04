CXX = g++
CXXFLAGS = -Wall -std=c++17
OBJ = Products.o main.o
EXEC = products_app

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

Products.o: Products.cpp Products.h
	$(CXX) $(CXXFLAGS) -c Products.cpp

main.o: main.cpp Products.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o $(EXEC)
