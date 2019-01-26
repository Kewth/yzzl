OBJECT=color.o cursor.o ytime.o pos.o
COMPILER=g++
CXXFLAGS=-Wall -Werror -Wshadow -O2 -DNDEBUG

all: ${OBJECT}

color.o: color.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

cursor.o: cursor.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

ytime.o: ytime.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

pos.o: pos.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

clean:
	rm -f *.o
