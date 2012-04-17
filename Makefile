#CC=g++
#CFLAGS=-Wall -Iheaders -pedantic -D_GNU_SOURCE
#LDFLAGS=-framework opengl -framework GLUT `sdl-config --libs` -L/usr/local/Cellar/lua/5.1.4/lib -llua -lluabindd
#OBJS=src/engine.o src/main.o src/node.o src/renderer.o src/scene.o src/script.o src/vector3f.o src/window.o

#prtunnel: $(OBJS)
#	$(CC) $(LDFLAGS) $(OBJS) -o lunar

#clean:
#	rm -f lunar
#	rm -f $(OBJS)

#src/engine.o: src/engine.cpp
#src/main.o: src/main.cpp
#src/node.o: src/node.cpp
#src/renderer.o: src/renderer.cpp
#src/scene.o: src/scene.cpp
#src/script.o: src/script.cpp
#src/vector3f.o: src/vector3f.cpp
#src/window.o: src/window.cpp

all:
	g++ src/*.cpp -g -Iheaders -framework opengl -framework GLUT `sdl-config --libs` -L/usr/local/Cellar/lua/5.1.4/lib -llua -lluabindd -o lunar

