#ifndef Plane_H
#define Plane_H

#include <vector> 
#include "Vertex.h"

using namespace std;



class Plane
{
public:
	vector<Vertex> vertexList;
	int size;
	int r;
	int g;
	int b;

	Plane();

	void SetVertex(int index, double inputX, double inputY, double inputZ);

	void SetVertex(int index, Vertex inputVertex);
};
#endif Plane_H

