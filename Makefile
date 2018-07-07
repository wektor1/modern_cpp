CCXX= g++
STD= -std=c++14
CXXFLAGS= -c -Wall -Wextra -Werror -Wpedantic
SRC= *.cpp
OBJ= $(SRC:.cpp=.o)

all:modern

%.o : %.cpp %.hpp
	$(CCXX) $(STD) $(CXXFLAGS)  -o $@ $<

modern: $(OBJ)
	$(CCXX) $(OBJ) -o $@

clean:
	rm *.o modern
