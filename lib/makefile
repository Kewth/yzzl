build/lock: build/color.o build/cursor.o build/ytime.o build/pos.o
	touch build/lock

build/color.o: color.cpp
	g++ -c $^ -o $@

build/cursor.o: cursor.cpp
	g++ -c $^ -o $@

build/ytime.o: ytime.cpp
	g++ -c $^ -o $@

build/pos.o: pos.cpp
	g++ -c $^ -o $@

