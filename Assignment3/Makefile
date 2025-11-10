CXX = g++
CXXFLAGS = -Wall -Wextra
OBJS = Transformer.o Autobot.o Decepticon.o Minicon.o

Assignment3: main.o $(OBJS)
	$(CXX) $(CXXFLAGS) main.o $(OBJS) -o Assignment3

main.o: main.cpp Transformer.h Autobot.h Decepticon.h Minicon.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Transformer.o: Transformer.cpp Transformer.h
	$(CXX) $(CXXFLAGS) -c Transformer.cpp

Autobot.o: Autobot.cpp Autobot.h Transformer.h
	$(CXX) $(CXXFLAGS) -c Autobot.cpp

Decepticon.o: Decepticon.cpp Decepticon.h Transformer.h
	$(CXX) $(CXXFLAGS) -c Decepticon.cpp

Minicon.o: Minicon.cpp Minicon.h Transformer.h
	$(CXX) $(CXXFLAGS) -c Minicon.cpp

test:
	$(CXX) $(CXXFLAGS) test_transformer.cpp Transformer.cpp Autobot.cpp Decepticon.cpp Minicon.cpp -lgtest -lgtest_main -lpthread -o test_transformer
	./test_transformer

clean:
	rm -f *.o Assignment3 test_transformer

