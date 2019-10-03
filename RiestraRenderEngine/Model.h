#ifndef Model_H
#define Model_H

#include <vector> 

#include "Vertex.h"
#include "Plane.h"
#include <string>

using namespace std;

class Model
{
public:
	vector<Plane> planeList;

	Model();

	//Adds a 3 point plane using coorinates
	void AddPlane(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);

	//Adds a 3 point plane using premade Vertexes
	void AddPlane(Vertex vA, Vertex vB, Vertex vC);

	//Divides 4 point plane into 2 triangles. 
	void AddPlane(Vertex vA, Vertex vB, Vertex vC, Vertex vD);

	// Divides any number of vertexes into triangles. 
	// This method makes point A touch every other point. Will have issues with shapes that come into themselves, such as a heart. 
	void AddPlane(vector<Vertex> inputVertex);
};
#endif Model_H