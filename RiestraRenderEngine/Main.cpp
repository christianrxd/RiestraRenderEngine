
#include "SDL.h"
#include <iostream> 
#include <vector> 

#include "Point.h"
#include "Vertex.h"
#include "Plane.h"
#include "Model.h"
#include "ModelCreator.h"
#include "ModelFunctions.h"

using namespace std;

void InitSDL(SDL_Window* Window, SDL_Renderer* Renderer);
SDL_Renderer* StartGraphics();
void DrawModel(SDL_Renderer* Renderer, Model myModel, double transformX, double transformY, double transformZ, double sizeScale, double alpha, double beta, double gamma);
void CubeDemo(SDL_Renderer* Renderer);
void HeartDemo(SDL_Renderer* Renderer);

int main(int argc, char* argv[])
{
	SDL_Renderer* Renderer = StartGraphics();
	HeartDemo(Renderer);

	return 0;
}

SDL_Renderer* StartGraphics()
{
	int windowLength = 1000;
	int windowHeight = 1000;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* Window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowLength, windowHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, 0);

	InitSDL(Window, Renderer);

	return Renderer;
}

void InitSDL(SDL_Window* Window, SDL_Renderer* Renderer)
{
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);

	SDL_RenderClear(Renderer);

	SDL_RenderPresent(Renderer);

	SDL_Delay(3000);
}

void DrawModel(SDL_Renderer* Renderer, Model myModel, double transformX, double transformY, double transformZ, double sizeScale, double alpha, double beta, double gamma)
{
	int offsetX = 350;
	int offsetY = 350;
	
	ModelFunctions myModelFunctions;

	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	SDL_RenderClear(Renderer);

	vector<Plane> planeList = myModel.planeList;

	for (Plane myPlane : planeList)
	{
		int r, g, b;
		r = myPlane.r;
		g = myPlane.g;
		b = myPlane.b;

		int aX, aY, bX, bY, cX, cY;

		vector<Point> pointList = myModelFunctions.GetPrintCoordinates(myPlane, transformX, transformY, transformZ, sizeScale, alpha, beta, gamma);

		aX = pointList[0].pX + offsetX;
		aY = pointList[0].pY + offsetY;

		bX = pointList[1].pX + offsetX;
		bY = pointList[1].pY + offsetY;

		cX = pointList[2].pX + offsetX;
		cY = pointList[2].pY + offsetY;

		SDL_SetRenderDrawColor(Renderer, r, g, b, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(Renderer, aX, aY, bX, bY);
		SDL_RenderDrawLine(Renderer, bX, bY, cX, cY);
		SDL_RenderDrawLine(Renderer, aX, aY, cX, cY);
	}

	SDL_RenderPresent(Renderer);
	SDL_Delay(25);
}

void CubeDemo(SDL_Renderer* Renderer)
{
	ModelCreator myModelCreator;
	ModelFunctions myModelFunctions;

	Model myModel = myModelCreator.CreateCube(2);

	double tX = 0;
	double tY = 0;
	double tZ = 0;

	double alpha = 0;
	double beta = 0;
	double gamma = 0;
	double sizeScale = 75;

	for (int index = 0; index < 720; index += 10)
	{
		DrawModel(Renderer, myModel, tX, tY, tZ, sizeScale, alpha, beta, gamma);
		beta -= 2;
		gamma += 2;
	}

	/*for (int index = 0; index < 720; index += 10)
	{
		vector<vector<Point>> pointList = myModelFunctions.GetPrintCoordinates(myModel, 0, 0, 0, sizeScale, tX, tY, tZ);
		DrawModel(Renderer, pointList);
		tX -= 2;
		tY += 2;
	}

	for (int index = 0; index < 720; index += 10)
	{
		vector<vector<Point>> pointList = myModelFunctions.GetPrintCoordinates(myModel, 0, 0, 0, sizeScale, tX, tY, tZ);
		DrawModel(Renderer, pointList);
		tY -= 2;
		tZ += 2;
	}*/
}

void HeartDemo(SDL_Renderer* Renderer)
{
	ModelCreator myModelCreator;
	

	Model myModel = myModelCreator.CreateHeart(2);

	double tX = 0;
	double tY = 0;
	double tZ = 0;
	double sizeScale = 25;

	/*for (int index = 0; index < 720; index += 10)
	{
		vector<vector<Point>> pointList = myModelFunctions.GetPrintCoordinates(myModel, 0, 0, 0, sizeScale, tX, tY, tZ);
		DrawModel(Renderer, pointList);
		tY -= 2;
		tZ += 2;
	}

	for (int index = 0; index < 720; index += 10)
	{
		vector<vector<Point>> pointList = myModelFunctions.GetPrintCoordinates(myModel, 0, 0, 0, sizeScale, tX, tY, tZ);
		DrawModel(Renderer, pointList);
		tX -= 2;
		tY += 2;
	}

	for (int index = 0; index < 720; index += 10)
	{
		vector<vector<Point>> pointList = myModelFunctions.GetPrintCoordinates(myModel, 0, 0, 0, sizeScale, tX, tY, tZ);
		DrawModel(Renderer, pointList);
		tY -= 2;
		tZ += 2;
	}*/

}