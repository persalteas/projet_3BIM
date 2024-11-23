CC = g++

UNAME := $(shell uname)
CFLAGS = -g -Wall -Wextra --std=c++20
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
ifeq ($(UNAME), Linux)
    CFLAGS += -DLINUX -O2
    LDFLAGS += -lm
else ifeq ($(UNAME), Darwin)
    CFLAGS += -I/opt/homebrew/Cellar/sfml/2.6.2/include -DMACOS -O2
    LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system -framework CoreFoundation
else ifeq ($(UNAME), Windows)
    CFLAGS += -DWINDOWS -O2
    LDFLAGS += -lws2_32
endif

all: escape

escape: obj/main.o obj/Pedest.o obj/Building.o
	$(CC) $(CFLAGS) obj/main.o obj/Pedest.o obj/Building.o $(LDFLAGS)  -o escape

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp -o obj/main.o

obj/Pedest.o: src/Pedest.cpp src/Pedest.h
	$(CC) $(CFLAGS) -c src/Pedest.cpp -o obj/Pedest.o

obj/Building.o: src/Building.cpp src/Building.h
	$(CC) $(CFLAGS) -c src/Building.cpp -o obj/Building.o

clean:
	rm obj/*.o
 
