EXENAME = game
OBJS = bird.o pipe.o game.o

INCLUDES = -framework SFML -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lsfml-network
CXXFLAGS = -std=c++17 -stdlib=libc++ -g -O0 -Wall -Wextra -Werror -pedantic
CXX = clang++

LD = clang++
LDFLAGS = -std=c++17 -stdlib=libc++ -lc++abi -lm


$(EXENAME): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) main.o $(INCLUDES) -o $(EXENAME)

bird.o: bird.cpp bird.hpp  
	$(CXX) $(CXXFLAGS) -c bird.cpp

pipe.o: pipe.cpp pipe.hpp  
	$(CXX) $(CXXFLAGS) -c pipe.cpp

game.o: game.cpp game.hpp
	$(CXX) $(CXXFLAGS) -c game.cpp

main.o: main.cpp game.hpp bird.hpp pipe.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test: tests/tests.cc game.hpp bird.hpp pipe.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) tests/tests.cc -o test

clean:
	-rm -f *.o $(EXENAME) test

.PHONY: all test clean