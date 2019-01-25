dist/yzzl: \
	build/main.o build/begin_flash.o \
	build/color.o build/cursor.o build/pos.o build/ytime.o
	g++ build/*.o -o $@ -lpthread -std=c++11
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

clean:
	rm build/* dist/yzzl
	# cd lib ; make clean ; cd ..
