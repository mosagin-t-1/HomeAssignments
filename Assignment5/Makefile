CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17

SRCS = main.cpp Rational.cpp
OBJS = Rational.o main.o

all: Assignment5

Assignment5: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o Assignment5

Rational.o: Rational.cpp Rational.h
	$(CXX) $(CXXFLAGS) -c Rational.cpp

main.o: main.cpp Matrix.h Rational.h
	$(CXX) $(CXXFLAGS) -c main.cpp

test_rational:
	$(CXX) $(CXXFLAGS) test_rational.cpp Rational.cpp -lgtest -lgtest_main -lpthread -o test_rational
	./test_rational

test_matrix:
	$(CXX) $(CXXFLAGS) test_matrix.cpp Rational.cpp -lgtest -lgtest_main -lpthread -o test_matrix
	./test_matrix

clean:
	rm -f *.o Assignment5 test_rational test_matrix

