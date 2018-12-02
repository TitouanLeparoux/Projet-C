CC = gcc
CFLAGS = #-Wall
SDL=`sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image

# MAKE ---------------------------------------------------------
all : PROJET cleanFileO EXECUTION cleanGame

# MAIN FILE & EXECUTION ----------------------------------------
PROJET :  #main.o
	gcc $(CFLAGS) main.c $(SDL) -o TANKGAME
EXECUTION : 
	./TANKGAME

# MAKE CLEAN ---------------------------------------------------
cleanFileO:
	rm -rf *.o
cleanGame:
	rm TANKGAME