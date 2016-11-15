// Practica IGS: Juego en una dimension

#include "stdafx.h"
#include <iostream>

//Game Options
#define MAP_SIZE 40
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

//Game Variables
int playerPos = MAP_SIZE / 2;
int shotPos;
int shotDir = 0;


void Shoot(char direccion)
{
	if (direccion == SHOOT_LEFT) {
		shotDir = -1;
		shotPos = playerPos - 1;
	}else if (direccion == SHOOT_RIGHT) {
		shotDir = 1;
		shotPos = playerPos + 1;
	}
}

void MoveBullet() 
{
	if (shotDir == 1 && shotPos<MAP_SIZE) {
		shotPos++;
	}
	else if (shotDir == -1 && shotPos>0) {
		shotPos--;
	}
}

void MovePlayer() 
{
	char key;
	if (_kbhit())	{
		key = _getch();
		switch (key) {
			case MOVE_LEFT:   if (playerPos > 0)													playerPos--; break;
			case MOVE_RIGHT:  if (playerPos < MAP_SIZE)												playerPos++; break;
			case SHOOT_LEFT:  if (playerPos <= MAP_SIZE && playerPos > 0		&& shotDir == 0)	Shoot(key); break;
			case SHOOT_RIGHT: if (playerPos >= 0		&& playerPos < MAP_SIZE && shotDir == 0)	Shoot(key); break;
		}
	}
}

//Paint the game world using each item's position
void Paint()
{
	for (int i = 0; i <= MAP_SIZE; i++) {
		if (i == playerPos)						printf("%c", CHARACTER_ICON);
		else if (i == shotPos && shotDir != 0)	printf("%c", SHOT_ICON);
		else									printf("%c", WORLD_ICON);
	}

	if (shotPos == MAP_SIZE || shotPos == 0) {
		shotDir = 0;
	}
	printf("\r");
}

int main()
{
	printf("\n\n\n\n\n\n\n\n\n\n"); //Move map to the center of the screen
	while (1) {
		MovePlayer();
		MoveBullet();
		Paint();
		Sleep(1000/FPS);
	}	
	return 0;
}


