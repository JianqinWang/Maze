OBJS = *.cpp
OBJ_NAME = maze

all: $(OBJS)
	g++ $(OBJS) -g -w -lSDL2 -o $(OBJ_NAME)
