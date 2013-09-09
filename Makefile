.PHONY: all, clean

all : build/computingcubes

rebuild : clean all

clean :
	-rm build/*

build/computingcubes :  build/computingcubes.o build/firstpersoncamera.o build/framework_font.o build/framework_utils.o build/framework_eventmanager.o build/framework_thread.o build/framework_application.o build/framework_stage.o build/framework_opengl_objects_wirecube.o build/framework_opengl_objects_glcoordaxis.o build/framework_opengl_objects_crosshairs.o build/framework_opengl_objects_vbocomposite.o build/framework_opengl_gltexture.o build/framework_opengl_glfont.o build/framework_opengl_perspectivecamera.o build/framework_opengl_glapplication.o build/framework_opengl_gldisplay.o build/framework_error.o build/framework_display.o build/ingamestage.o build/main.o build/world_voxeltypemap.o build/world_defs.o build/world_chunk.o build/world_chunkmap.o
	g++ -o build/computingcubes   build/computingcubes.o build/firstpersoncamera.o build/framework_font.o build/framework_utils.o build/framework_eventmanager.o build/framework_thread.o build/framework_application.o build/framework_stage.o build/framework_opengl_objects_wirecube.o build/framework_opengl_objects_glcoordaxis.o build/framework_opengl_objects_crosshairs.o build/framework_opengl_objects_vbocomposite.o build/framework_opengl_gltexture.o build/framework_opengl_glfont.o build/framework_opengl_perspectivecamera.o build/framework_opengl_glapplication.o build/framework_opengl_gldisplay.o build/framework_error.o build/framework_display.o build/ingamestage.o build/main.o build/world_voxeltypemap.o build/world_defs.o build/world_chunk.o build/world_chunkmap.o -lSDL2 -lSDL2_image -lGL -lGLU $(shell freetype-config  --libs)

build/computingcubes.o : src/computingcubes.cpp src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/ingamestage.h src/framework/stage.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/opengl/gldisplay.h src/framework/display.h src/framework/opengl/glfont.h src/framework/font.h src/framework/utils.h
	g++ -o build/computingcubes.o -I./src $(shell freetype-config --cflags) -c src/computingcubes.cpp

build/firstpersoncamera.o : src/firstpersoncamera.cpp src/firstpersoncamera.h src/framework/opengl/perspectivecamera.h src/framework/opengl/camera.h src/framework/display.h src/framework/eventmanager.h src/framework/utils.h
	g++ -o build/firstpersoncamera.o -I./src $(shell freetype-config --cflags) -c src/firstpersoncamera.cpp

build/framework_font.o : src/framework/font.cpp src/framework/font.h src/framework/utils.h src/framework/error.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h
	g++ -o build/framework_font.o -I./src $(shell freetype-config --cflags) -c src/framework/font.cpp

build/framework_utils.o : src/framework/utils.cpp src/framework/utils.h
	g++ -o build/framework_utils.o -I./src $(shell freetype-config --cflags) -c src/framework/utils.cpp

build/framework_eventmanager.o : src/framework/eventmanager.cpp src/framework/eventmanager.h
	g++ -o build/framework_eventmanager.o -I./src $(shell freetype-config --cflags) -c src/framework/eventmanager.cpp

build/framework_thread.o : src/framework/thread.cpp src/framework/thread.h src/framework/utils.h
	g++ -o build/framework_thread.o -I./src $(shell freetype-config --cflags) -c src/framework/thread.cpp

build/framework_application.o : src/framework/application.cpp src/framework/application.h src/framework/eventmanager.h src/framework/utils.h src/framework/error.h src/framework/stage.h
	g++ -o build/framework_application.o -I./src $(shell freetype-config --cflags) -c src/framework/application.cpp

build/framework_stage.o : src/framework/stage.cpp src/framework/stage.h src/framework/utils.h
	g++ -o build/framework_stage.o -I./src $(shell freetype-config --cflags) -c src/framework/stage.cpp

build/framework_opengl_objects_wirecube.o : src/framework/opengl/objects/wirecube.cpp src/framework/opengl/objects/wirecube.h src/framework/utils.h
	g++ -o build/framework_opengl_objects_wirecube.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/objects/wirecube.cpp

build/framework_opengl_objects_glcoordaxis.o : src/framework/opengl/objects/glcoordaxis.cpp src/framework/opengl/objects/glcoordaxis.h src/framework/opengl/gldrawable.h src/framework/utils.h
	g++ -o build/framework_opengl_objects_glcoordaxis.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/objects/glcoordaxis.cpp

build/framework_opengl_objects_crosshairs.o : src/framework/opengl/objects/crosshairs.cpp src/framework/opengl/objects/crosshairs.h src/framework/utils.h
	g++ -o build/framework_opengl_objects_crosshairs.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/objects/crosshairs.cpp

build/framework_opengl_objects_vbocomposite.o : src/framework/opengl/objects/vbocomposite.cpp src/framework/opengl/objects/vbocomposite.h src/framework/utils.h
	g++ -o build/framework_opengl_objects_vbocomposite.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/objects/vbocomposite.cpp

build/framework_opengl_gltexture.o : src/framework/opengl/gltexture.cpp src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/error.h src/framework/utils.h
	g++ -o build/framework_opengl_gltexture.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/gltexture.cpp

build/framework_opengl_glfont.o : src/framework/opengl/glfont.cpp src/framework/opengl/glfont.h src/framework/font.h src/framework/utils.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h
	g++ -o build/framework_opengl_glfont.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/glfont.cpp

build/framework_opengl_perspectivecamera.o : src/framework/opengl/perspectivecamera.cpp src/framework/opengl/perspectivecamera.h src/framework/opengl/camera.h src/framework/display.h src/framework/eventmanager.h src/framework/utils.h
	g++ -o build/framework_opengl_perspectivecamera.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/perspectivecamera.cpp

build/framework_opengl_glapplication.o : src/framework/opengl/glapplication.cpp src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h src/framework/opengl/gldisplay.h src/framework/display.h
	g++ -o build/framework_opengl_glapplication.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/glapplication.cpp

build/framework_opengl_gldisplay.o : src/framework/opengl/gldisplay.cpp src/framework/opengl/gldisplay.h src/framework/display.h src/framework/eventmanager.h src/framework/opengl/camera.h src/framework/error.h src/framework/utils.h
	g++ -o build/framework_opengl_gldisplay.o -I./src $(shell freetype-config --cflags) -c src/framework/opengl/gldisplay.cpp

build/framework_error.o : src/framework/error.cpp src/framework/error.h
	g++ -o build/framework_error.o -I./src $(shell freetype-config --cflags) -c src/framework/error.cpp

build/framework_display.o : src/framework/display.cpp src/framework/display.h src/framework/eventmanager.h
	g++ -o build/framework_display.o -I./src $(shell freetype-config --cflags) -c src/framework/display.cpp

build/ingamestage.o : src/ingamestage.cpp src/ingamestage.h src/framework/eventmanager.h src/framework/stage.h src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/firstpersoncamera.h src/framework/opengl/perspectivecamera.h src/framework/opengl/camera.h src/framework/display.h src/framework/utils.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h src/framework/opengl/gldisplay.h src/framework/opengl/glfont.h src/framework/font.h src/framework/opengl/objects/glcoordaxis.h src/framework/opengl/objects/wirecube.h src/framework/opengl/objects/crosshairs.h src/world/chunkmap.h src/world/defs.h src/world/chunk.h src/world/voxeltypemap.h
	g++ -o build/ingamestage.o -I./src $(shell freetype-config --cflags) -c src/ingamestage.cpp

build/main.o : src/main.cpp src/framework/error.h src/framework/utils.h src/computingcubes.h src/framework/opengl/glapplication.h src/framework/application.h src/framework/eventmanager.h
	g++ -o build/main.o -I./src $(shell freetype-config --cflags) -c src/main.cpp

build/world_voxeltypemap.o : src/world/voxeltypemap.cpp src/world/voxeltypemap.h src/world/defs.h src/framework/utils.h
	g++ -o build/world_voxeltypemap.o -I./src $(shell freetype-config --cflags) -c src/world/voxeltypemap.cpp

build/world_defs.o : src/world/defs.cpp src/world/defs.h
	g++ -o build/world_defs.o -I./src $(shell freetype-config --cflags) -c src/world/defs.cpp

build/world_chunk.o : src/world/chunk.cpp src/world/chunk.h src/world/defs.h src/world/chunkmap.h src/world/voxeltypemap.h src/framework/utils.h src/framework/opengl/gltexture.h src/framework/opengl/gldrawable.h
	g++ -o build/world_chunk.o -I./src $(shell freetype-config --cflags) -c src/world/chunk.cpp

build/world_chunkmap.o : src/world/chunkmap.cpp src/world/chunkmap.h src/world/defs.h src/world/chunk.h src/world/voxeltypemap.h src/framework/utils.h src/firstpersoncamera.h src/framework/opengl/perspectivecamera.h src/framework/opengl/camera.h src/framework/display.h src/framework/eventmanager.h
	g++ -o build/world_chunkmap.o -I./src $(shell freetype-config --cflags) -c src/world/chunkmap.cpp


