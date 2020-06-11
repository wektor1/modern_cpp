CCXX= g++
STD= -std=c++17
CXXFLAGS= -c -Wall -Wextra -Werror -Wpedantic
SRC=$(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all:modern

%.o : %.cpp %.hpp
	$(CCXX) $(STD) $(CXXFLAGS)  -o $@ $<

modern: $(OBJ)
	$(CCXX) $(OBJ) -o $@

clean:
	rm modern *.o
