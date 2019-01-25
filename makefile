dist/yzzl: \
	bulid/main.o bulid/begin_flash.o \
	bulid/color.o bulid/cursor.o bulid/pos.o bulid/ytime.o
	g++ bulid/*.o -o $@ -lpthread -std=c++11
	# -I/usr/include/python2.7 -lpython2.7

# lib/bulid/lock: lib/*.cpp
	# cd lib ; make ; cd ..

bulid/main.o: source/main.cpp
	g++ -c $^ -o $@

bulid/begin_flash.o: source/begin_flash.cpp
	g++ -c $^ -o $@

bulid/color.o: lib/color.cpp
	g++ -c $^ -o $@

bulid/cursor.o: lib/cursor.cpp
	g++ -c $^ -o $@

bulid/pos.o: lib/pos.cpp
	g++ -c $^ -o $@

bulid/ytime.o: lib/ytime.cpp
	g++ -c $^ -o $@

clean:
	rm bulid/* dist/yzzl
	# cd lib ; make clean ; cd ..
