
#include <vector>

#include "Plane.h"
#include "Vertex.h"

using namespace std;

vector<Vertex> vertexList;
int size;
int r;
int g;
int b;

Plane::Plane()
{
	size = 3;
	r = 255;
	g = 255;
	b = 255;

	for (int lcv = 0; lcv < size; lcv++)
	{
		vertexList.push_back(Vertex());
	}
}

void Plane :: SetVertex(int index, double inputX, double inputY, double inputZ)
{
	vertexList[index].x = inputX;
	vertexList[index].y = inputY;
	vertexList[index].z = inputZ;
}

void Plane::SetVertex(int index, Vertex inputVertex)
{
	vertexList[index].x = inputVertex.x;
	vertexList[index].y = inputVertex.y;
	vertexList[index].z = inputVertex.z;
}
