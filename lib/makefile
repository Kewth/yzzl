OBJECT=build/color.o build/cursor.o build/ytime.o build/pos.o
COMPILER=g++
CXXFLAGS=-Wall -Werror -Wshadow -O2 -DNDEBUG -I ../include/
TESTCASE=test/input test/ytime

all: build-dir ${OBJECT}

test: build-dir ${OBJECT} test-dir ${TESTCASE}

build-dir:
	mkdir -p build

build/color.o: color.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/cursor.o: cursor.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/ytime.o: ytime.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/pos.o: pos.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/input.o: input.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

test-dir:
	mkdir -p test

test/input: build/input.o test-input.cpp
	${COMPILER} ${CXXFLAGS} $^ -o $@

test/ytime: build/input.o build/ytime.o test-ytime.cpp
	${COMPILER} ${CXXFLAGS} $^ -o $@

clean:
	rm -rf test build
