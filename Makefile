.PHONY: all, clean

all : build/computingcubes

rebuild : clean all

clean :
	-rm build/*

build/computingcubes :  build/computingcubes.o build/application.o build/display.o build/error.o build/eventmanager.o build/font.o build/glapplication.o build/gldisplay.o build/glfont.o build/gltexture.o build/utils.o build/main.o
	g++ -o build/computingcubes   build/computingcubes.o build/application.o build/display.o build/error.o build/eventmanager.o build/font.o build/glapplication.o build/gldisplay.o build/glfont.o build/gltexture.o build/utils.o build/main.o -lSDL2 -lSDL2_image -lGL $(shell freetype-config  --libs)

build/computingcubes.o : src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/opengl/gldisplay.h src/framework/display.h src/framework/opengl/glfont.h src/framework/font.h src/framework/utils.h
	g++ -o build/computingcubes.o -I./src $(shell freetype-config --cflags) -c src/computingcubes.cpp

build/application.o : src/framework/application.h src/framework/eventmanager.h src/framework/utils.h src/framework/error.h
	g++ -o build/application.o -I./src $(shell freetype-config --cflags) -c src/framework/application.cpp

build/display.o : src/framework/display.h src/framework/eventmanager.h
	g++ -o build/display.o -I./src $(shell freetype-config --cflags) -c src/framework/display.cpp

build/error.o : src/framework/error.h
	g++ -o build/error.o -I./src $(shell freetype-config --cflags) -c src/framework/error.cpp

build/eventmanager.o : src/framework/eventmanager.h
	g++ -o build/eventmanager.o -I./src $(shell freetype-config --cflags) -c src/framework/eventmanager.cpp

build/font.o : src/framework/font.h src/framework/utils.h src/framework/error.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h
	g++ -o build/font.o -I./src $(shell freetype-config --cflags) -c src/framework/font.cpp

build/glapplication.o : src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/framework/opengl/gldisplay.h src/framework/display.h
	g++ -o build/glapplication.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/glapplication.cpp

build/gldisplay.o : src/framework/opengl/gldisplay.h src/framework/display.h src/framework/eventmanager.h src/framework/error.h src/framework/utils.h
	g++ -o build/gldisplay.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/gldisplay.cpp

build/glfont.o : src/framework/opengl/glfont.h src/framework/font.h src/framework/utils.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h
	g++ -o build/glfont.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/glfont.cpp

build/gltexture.o : src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/error.h src/framework/utils.h
	g++ -o build/gltexture.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/gltexture.cpp

build/utils.o : src/framework/utils.h
	g++ -o build/utils.o -I./src $(shell freetype-config --cflags) -c src/framework/utils.cpp

build/main.o : src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/framework/error.h src/framework/utils.h
	g++ -o build/main.o -I./src $(shell freetype-config --cflags) -c src/main.cpp


