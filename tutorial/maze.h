#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

bool init();

bool loadMedia();

void close();

SDL_Surface *loadSurface(std::string path);


#endif
