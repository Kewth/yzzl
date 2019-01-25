dist/yzzl: \
	build/main.o build/begin_flash.o \
	build/color.o build/cursor.o build/pos.o build/ytime.o build/input.o \
	build/people.o build/player.o \
	build/map.o \
	build/floor.o build/base_floor.o
	g++ $^ -o $@ -lpthread -std=c++11
	# -I/usr/include/python2.7 -lpython2.7

# lib/build/lock: lib/*.cpp
	# cd lib ; make ; cd ..

build/main.o: source/main.cpp
	g++ -c $^ -o $@

build/begin_flash.o: source/begin_flash.cpp
	g++ -c $^ -o $@

build/color.o: lib/color.cpp
	g++ -c $^ -o $@

build/cursor.o: lib/cursor.cpp
	g++ -c $^ -o $@

build/pos.o: lib/pos.cpp
	g++ -c $^ -o $@

build/ytime.o: lib/ytime.cpp
	g++ -c $^ -o $@

build/people.o: source/people/people.cpp
	g++ -c $^ -o $@

build/player.o: source/people/player.cpp
	g++ -c $^ -o $@

build/map.o: source/map/map.cpp
	g++ -c $^ -o $@

build/floor.o: source/floor/floor.cpp
	g++ -c $^ -o $@

build/base_floor.o: source/floor/base_floor.cpp
	g++ -c $^ -o $@

build/input.o: lib/input.cpp
	g++ -c $^ -o $@

clean:
	rm build/* dist/yzzl
	# cd lib ; make clean ; cd ..
