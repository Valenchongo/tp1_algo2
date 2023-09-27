CXX = g++
CXXFLAGS = -Wall -Werror -Wconversion
NAME = TP1

all:
	$(CXX) -o $(NAME) *.cpp $(CXXFLAGS)

noFlags:
	$(CXX) -o $(NAME) *.cpp

clean:
	rm*.o

cleanAll:
	rm -f $(NAME) *.o