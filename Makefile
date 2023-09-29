CXX = g++
CXXFLAGS = -Wall -Werror -Wconversion
NAME = TP1
SRC_DIR = src

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

all:
	$(CXX) -o $(NAME) *.cpp $(SOURCES) $(CXXFLAGS)

noFlags:
	$(CXX) -o $(NAME) *.cpp

clean:
	rm*.o

cleanAll:
	rm -f $(NAME) *.o