dist/yzzl: bulid/main.o bulid/begin_flash.o lib/bulid/lock
	g++ bulid/*.o lib/bulid/*.o -o $@ -lpthread -std=c++11
	# -I/usr/include/python2.7 -lpython2.7

lib/bulid/lock:
	cd lib ; make ; cd -1

bulid/main.o: source/main.cpp
	g++ -c $^ -o $@

bulid/begin_flash.o: source/begin_flash.cpp
	g++ -c $^ -o $@

clean:
	rm bulid/* dist/yzzl
	cd lib ; make clean ; cd -1
