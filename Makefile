.PHONY: all, clean

all : build/computingcubes

rebuild : clean all

clean :
	-rm build/*

build/computingcubes :  build/computingcubes.o build/application.o build/display.o build/error.o build/eventmanager.o build/font.o build/glapplication.o build/gldisplay.o build/gltexture.o build/utils.o build/main.o
	g++ -o build/computingcubes   build/computingcubes.o build/application.o build/display.o build/error.o build/eventmanager.o build/font.o build/glapplication.o build/gldisplay.o build/gltexture.o build/utils.o build/main.o -lSDL2 -lSDL2_image -lGL -L/usr/lib/x86_64-linux-gnu -lfreetype -lz

build/computingcubes.o : src/computingcubes.cpp
	g++ -o build/computingcubes.o -I./src -I/usr/include/freetype2 -c src/computingcubes.cpp

build/application.o : src/framework/application.cpp
	g++ -o build/application.o -I./src -I/usr/include/freetype2 -c src/framework/application.cpp

build/display.o : src/framework/display.cpp
	g++ -o build/display.o -I./src -I/usr/include/freetype2 -c src/framework/display.cpp

build/error.o : src/framework/error.cpp
	g++ -o build/error.o -I./src -I/usr/include/freetype2 -c src/framework/error.cpp

build/eventmanager.o : src/framework/eventmanager.cpp
	g++ -o build/eventmanager.o -I./src -I/usr/include/freetype2 -c src/framework/eventmanager.cpp

build/font.o : src/framework/font.cpp
	g++ -o build/font.o -I./src -I/usr/include/freetype2 -c src/framework/font.cpp

build/glapplication.o : src/framework/opengl/glapplication.cpp
	g++ -o build/glapplication.o -I./src -I/usr/include/freetype2 -c src/framework/opengl/glapplication.cpp

build/gldisplay.o : src/framework/opengl/gldisplay.cpp
	g++ -o build/gldisplay.o -I./src -I/usr/include/freetype2 -c src/framework/opengl/gldisplay.cpp

build/gltexture.o : src/framework/opengl/gltexture.cpp
	g++ -o build/gltexture.o -I./src -I/usr/include/freetype2 -c src/framework/opengl/gltexture.cpp

build/utils.o : src/framework/utils.cpp
	g++ -o build/utils.o -I./src -I/usr/include/freetype2 -c src/framework/utils.cpp

build/main.o : src/main.cpp
	g++ -o build/main.o -I./src -I/usr/include/freetype2 -c src/main.cpp


