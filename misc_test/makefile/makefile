hello_world:hello_world.o
	g++ -o hello_world hello_world.o

hello_world.o:hello_world.cpp
	g++ -c hello_world.cpp

install:
	cp hello_world ~/bin/
	
clean:
	rm -f hello_world hello_world.o
