#pragma once
#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
#include "glut.h"
#include <vector>
#include <math.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <algorithm>

#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "models.h"
int Map[30][30] = { //our map
	{1,1,1,1},
	{0,1,1,0},
	{0,1,1,0},
	{0,1,1,0},
	{0,1,1,1}
};

void LoadMap( double heightc)
{
	for (int i = 0; i < 10; i++)
	{

		for (int j = 1; j < 10; j++)
		{
			if(Map[i][j] == 1) {
			glPushMatrix();
			glTranslatef(j, -i, 0);
			drawBox();
			glPopMatrix();
		}
		}
	}
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			if (Map[i][j] == 0) {
				glPushMatrix();
	
			glPopMatrix();
			}
		}

	}
}



