COMPILER=g++
CXXFLAGS=-Wall -Werror -I ./include/
OBJECT=build/begin_flash.o build/color.o build/cursor.o build/pos.o \
       build/ytime.o build/input.o build/people.o build/player.o build/map.o \
       build/floor.o build/base_floor.o build/users.o build/maincity.o \
	   build/ascii_flash.o

dist/yzzl: build dist ${OBJECT} build/main_yzzl.o
	${COMPILER} ${OBJECT} build/main_yzzl.o -o $@ -lpthread -std=c++11 -I/usr/include/python3.10 -lpython3.10

# lib/build/lock: lib/*.cpp
	# cd lib ; make ; cd ..

dist:
	mkdir -p dist

build:
	mkdir -p build

build/main_yzzl.o: main/yzzl.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/begin_flash.o: source/begin_flash.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/color.o: lib/color.cpp
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/cursor.o: lib/cursor.cpp
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/pos.o: lib/pos.cpp
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/ytime.o: lib/ytime.cpp
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/people.o: source/people/people.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/player.o: source/people/player.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/map.o: source/map/map.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/floor.o: source/floor/floor.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/base_floor.o: source/floor/base_floor.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/input.o: lib/input.cpp
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/users.o: source/users.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/maincity.o: source/map/maincity.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

build/ascii_flash.o: source/ascii_flash.cpp include/*
	${COMPILER} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f build/*.o dist/yzzl
	# cd lib ; make clean ; cd ..

dist/yfl: build dist ${OBJECT} build/main_yfl.o
	${COMPILER} ${OBJECT} build/main_yfl.o -o $@ -lpthread -std=c++11 -I/usr/include/python3.10 -lpython3.10

build/main_yfl.o: main/yfl.cpp
	${COMPILER} ${CXXFLAGS} -c $< -o $@

/usr/bin/yzzl: dist/yzzl
	echo '#!/bin/bash' > $<_sys
	echo cd `pwd` '&&' ./$< >> $<_sys
	chmod +x $<_sys
	sudo mv $<_sys $@

/usr/bin/yfl: dist/yfl
	echo '#!/bin/bash' > $<_sys
	echo cd `pwd` '&&' ./$< >> $<_sys
	chmod +x $<_sys
	sudo mv $<_sys $@

all: /usr/bin/yfl /usr/bin/yzzl
	@echo
	@echo installed!

