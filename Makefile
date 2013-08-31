.PHONY: all, clean

all : build/computingcubes

rebuild : clean all

clean :
	-rm build/*

build/computingcubes :  build/computingcubes.o build/firstpersoncamera.o build/application.o build/display.o build/error.o build/eventmanager.o build/font.o build/glapplication.o build/gldisplay.o build/glfont.o build/gltexture.o build/glcoordaxis.o build/perspectivecamera.o build/stage.o build/thread.o build/utils.o build/ingamestage.o build/main.o build/chunk.o
	g++ -o build/computingcubes   build/computingcubes.o build/firstpersoncamera.o build/application.o build/display.o build/error.o build/eventmanager.o build/font.o build/glapplication.o build/gldisplay.o build/glfont.o build/gltexture.o build/glcoordaxis.o build/perspectivecamera.o build/stage.o build/thread.o build/utils.o build/ingamestage.o build/main.o build/chunk.o -lSDL2 -lSDL2_image -lGL -lGLU $(shell freetype-config  --libs)

build/computingcubes.o : src/computingcubes.cpp src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/ingamestage.h src/framework/stage.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/opengl/gldisplay.h src/framework/display.h src/framework/opengl/glfont.h src/framework/font.h src/framework/utils.h
	g++ -o build/computingcubes.o -I./src $(shell freetype-config --cflags) -c src/computingcubes.cpp

build/firstpersoncamera.o : src/firstpersoncamera.cpp src/firstpersoncamera.h src/framework/opengl/perspectivecamera.h src/framework/opengl/camera.h src/framework/display.h src/framework/eventmanager.h src/framework/utils.h
	g++ -o build/firstpersoncamera.o -I./src $(shell freetype-config --cflags) -c src/firstpersoncamera.cpp

build/application.o : src/framework/application.cpp src/framework/application.h src/framework/eventmanager.h src/framework/utils.h src/framework/error.h src/framework/stage.h
	g++ -o build/application.o -I./src $(shell freetype-config --cflags) -c src/framework/application.cpp

build/display.o : src/framework/display.cpp src/framework/display.h src/framework/eventmanager.h
	g++ -o build/display.o -I./src $(shell freetype-config --cflags) -c src/framework/display.cpp

build/error.o : src/framework/error.cpp src/framework/error.h
	g++ -o build/error.o -I./src $(shell freetype-config --cflags) -c src/framework/error.cpp

build/eventmanager.o : src/framework/eventmanager.cpp src/framework/eventmanager.h
	g++ -o build/eventmanager.o -I./src $(shell freetype-config --cflags) -c src/framework/eventmanager.cpp

build/font.o : src/framework/font.cpp src/framework/font.h src/framework/utils.h src/framework/error.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h
	g++ -o build/font.o -I./src $(shell freetype-config --cflags) -c src/framework/font.cpp

build/glapplication.o : src/framework/opengl/glapplication.cpp src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/framework/opengl/gldisplay.h src/framework/display.h
	g++ -o build/glapplication.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/glapplication.cpp

build/gldisplay.o : src/framework/opengl/gldisplay.cpp src/framework/opengl/gldisplay.h src/framework/display.h src/framework/eventmanager.h src/framework/opengl/camera.h src/framework/error.h src/framework/utils.h
	g++ -o build/gldisplay.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/gldisplay.cpp

build/glfont.o : src/framework/opengl/glfont.cpp src/framework/opengl/glfont.h src/framework/font.h src/framework/utils.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h
	g++ -o build/glfont.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/glfont.cpp

build/gltexture.o : src/framework/opengl/gltexture.cpp src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/error.h src/framework/utils.h
	g++ -o build/gltexture.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/gltexture.cpp

build/glcoordaxis.o : src/framework/opengl/objects/glcoordaxis.cpp src/framework/opengl/objects/glcoordaxis.h src/framework/opengl/gldrawable.h src/framework/utils.h
	g++ -o build/glcoordaxis.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/objects/glcoordaxis.cpp

build/perspectivecamera.o : src/framework/opengl/perspectivecamera.cpp src/framework/opengl/perspectivecamera.h src/framework/opengl/camera.h src/framework/display.h src/framework/eventmanager.h src/framework/utils.h
	g++ -o build/perspectivecamera.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/perspectivecamera.cpp

build/stage.o : src/framework/stage.cpp src/framework/stage.h src/framework/utils.h
	g++ -o build/stage.o -I./src $(shell freetype-config --cflags) -c src/framework/stage.cpp

build/thread.o : src/framework/thread.cpp src/framework/thread.h src/framework/utils.h
	g++ -o build/thread.o -I./src $(shell freetype-config --cflags) -c src/framework/thread.cpp

build/utils.o : src/framework/utils.cpp src/framework/utils.h
	g++ -o build/utils.o -I./src $(shell freetype-config --cflags) -c src/framework/utils.cpp

build/ingamestage.o : src/ingamestage.cpp src/ingamestage.h src/framework/stage.h src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/firstpersoncamera.h src/framework/opengl/perspectivecamera.h src/framework/opengl/camera.h src/framework/display.h src/framework/utils.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/opengl/gldisplay.h src/framework/opengl/glfont.h src/framework/font.h src/framework/opengl/objects/glcoordaxis.h
	g++ -o build/ingamestage.o -I./src $(shell freetype-config --cflags) -c src/ingamestage.cpp

build/main.o : src/main.cpp src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/framework/error.h src/framework/utils.h
	g++ -o build/main.o -I./src $(shell freetype-config --cflags) -c src/main.cpp

build/chunk.o : src/voxels/chunk.cpp src/voxels/chunk.h src/framework/utils.h
	g++ -o build/chunk.o -I./src $(shell freetype-config --cflags) -c src/voxels/chunk.cpp


