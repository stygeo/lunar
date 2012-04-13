all:
	g++ src/*.cpp -g -Iheaders -framework opengl -framework GLUT `sdl-config --libs` -L/usr/local/Cellar/lua/5.1.4/lib -llua -lluabindd -o lunar
