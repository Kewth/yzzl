yzzl: color.o cursor.o main.o begin_flash.o ytime.o
	g++ -o $@ $^ -lpthread -std=c++11
	# -I/usr/include/python2.7 -lpython2.7

.c.o:
	g++ -c $<

clean:
	rm *.o yzzl
