#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "plain.h"

#define mapWidth 24
#define mapHeight 24

const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 384;

// Window we'll be rendering to
SDL_Window* window = NULL;

// Surface contained by the window
SDL_Surface* screenSurface = NULL;


int worldMap[mapWidth][mapHeight] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


int main(void)
{
	double posX = 22, posY = 12; // x and y starting position
	double dirX = -1, dirY = 0; // initial direction vector
	double planeX = 0, planeY = 0.66; //camera plane (view)

	double time = 0; // time of current frame
	double oldTime = 0; // time of previous frame

	// generate a screen
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// create window
		window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_UNDEFINED,
					  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
					  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);

			while (1)
			{
				for (int x = 0; x < w; x++)
				{
					double cameraX = 2 * x / double(w) - 1;
					double rayPosX = posX;
					double rayPosY = posY;
					double rayDirX = dirX + planeX * cameraX;
					double rayDirY = dirY + planeY * cameraY;

					// plot box we're in on the map
					int mapX = int(rayPosX);
					int mapY = int(rayPosY);

					// Length of ray from current position to next side
					double sideDistX;
					double sideDistY;

					// length of ray from one side to next side
					double deltaDistX = sqrt(1 + (rayDirY * rayDirY) /
								 (rayDirX * rayDirX));
					double deltaDistY = sqrt(1 + (rayDirX * rayDirX) /
								 (rayDirY * rayDirY));
					double perpWallDist;

					int stepX;
					int stepY;

					int hit = 0;
					int side;
				}
			};
			SDL_UpdateWindowSurface(window);
		}
	}

	return (0);
}
