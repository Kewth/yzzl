COMPILER=g++
CXXFLAGS=-Wall -Werror -I ./include/
OBJECT=build/main.o build/begin_flash.o build/color.o build/cursor.o build/pos.o \
       build/ytime.o build/input.o build/people.o build/player.o build/map.o \
       build/floor.o build/base_floor.o build/users.o build/maincity.o

dist/yzzl: build dist ${OBJECT}
	${COMPILER} ${OBJECT} -o $@ -lpthread -std=c++11 -I/usr/include/python3.6m -lpython3.6m

# lib/build/lock: lib/*.cpp
	# cd lib ; make ; cd ..

dist:
	mkdir -p dist

build:
	mkdir -p build

build/main.o: source/main.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/begin_flash.o: source/begin_flash.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/color.o: lib/color.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/cursor.o: lib/cursor.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/pos.o: lib/pos.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/ytime.o: lib/ytime.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/people.o: source/people/people.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/player.o: source/people/player.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/map.o: source/map/map.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/floor.o: source/floor/floor.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/base_floor.o: source/floor/base_floor.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/input.o: lib/input.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/users.o: source/users.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/maincity.o: source/map/maincity.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

clean:
	rm -f build/*.o dist/yzzl
	# cd lib ; make clean ; cd ..
