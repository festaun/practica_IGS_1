// PracticaIGS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//Game Options
#define MAP_SIZE 30
#define FPS 20
#define FRAME_RATE = 1000/FPS
#define WORLD_ICON '_'
#define CHARACTER_ICON '0'
#define SHOT_ICON 'o'

//Keybindings
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define SHOOT_LEFT 'q'
#define SHOOT_RIGHT 'e'

int position = MAP_SIZE / 2;
int playerPos = MAP_SIZE / 2;
int shotPos;

void Paint()
{
	for (int i = 0; i <= MAP_SIZE; i++)	{
		if (i == playerPos)			printf("%c",CHARACTER_ICON);
		//if (i == shotPos)			printf("%c",SHOT_ICON);
		else						printf("%c",WORLD_ICON);
	}
}

void Shoot(char direccion)
{	
	if (direccion == 'q') shotPos = playerPos - 1;
	else shotPos = playerPos + 1;

	for (int i = 0; i <= MAP_SIZE; i++) {
		if (i == playerPos)			printf("%c", CHARACTER_ICON);
		if (i == shotPos)			printf("%c",SHOT_ICON);
		else						printf("%c", WORLD_ICON);
		printf("\r");
		Sleep(10);
		shotPos++;
	}
	printf("%c", SHOT_ICON);
}

void MovePlayer() 
{
	char ch;
	if (_kbhit)	{
		ch = _getch();
		switch (ch) {
			case MOVE_LEFT:   if (playerPos > 0)									playerPos--; break;
			case MOVE_RIGHT:  if (playerPos < MAP_SIZE)								playerPos++; break;
			case SHOOT_LEFT:  if (playerPos <= MAP_SIZE && playerPos > 0)			Shoot(ch); break;
			case SHOOT_RIGHT: if (playerPos >= 0		&& playerPos < MAP_SIZE)	Shoot(ch); break;
		}
	}
}

int main()
{
	printf("\n\n\n\n\n\n\n\n\n\n"); //Move map to the center of the screen
	while (1) {
		Paint();
		MovePlayer();
		printf("\r");
	}	
	return 0;
}


