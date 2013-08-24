.PHONY: all, clean

all : build/computingcubes

rebuild : clean all

clean :
	-rm build/*

build/computingcubes :  build/computingcubes.o build/application.o build/display.o build/error.o build/eventmanager.o build/main.o
	g++ -o build/computingcubes   build/computingcubes.o build/application.o build/display.o build/error.o build/eventmanager.o build/main.o -lSDL2 -lGL

build/computingcubes.o : src/computingcubes.cpp
	g++ -o build/computingcubes.o -I./src -c src/computingcubes.cpp

build/application.o : src/framework/application.cpp
	g++ -o build/application.o -I./src -c src/framework/application.cpp

build/display.o : src/framework/display.cpp
	g++ -o build/display.o -I./src -c src/framework/display.cpp

build/error.o : src/framework/error.cpp
	g++ -o build/error.o -I./src -c src/framework/error.cpp

build/eventmanager.o : src/framework/eventmanager.cpp
	g++ -o build/eventmanager.o -I./src -c src/framework/eventmanager.cpp

build/main.o : src/main.cpp
	g++ -o build/main.o -I./src -c src/main.cpp


