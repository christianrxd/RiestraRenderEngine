
#include <vector>
#include <string>

#include "Vertex.h"
#include "Plane.h"
#include "Model.h"

using namespace std;

vector<Plane> planeList;

Model::Model()
{
}

//Adds a 3 point plane using coorinates
void Model::AddPlane(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
	Plane pA;

	pA.SetVertex(0, x1, y1, z1);
	pA.SetVertex(1, x2, y2, z2);
	pA.SetVertex(2, x3, y3, z3);

	planeList.push_back(pA);
}

//Adds a 3 point plane using premade Vertexes
void Model::AddPlane(Vertex vA, Vertex vB, Vertex vC)
{
	Plane pA;

	pA.SetVertex(0, vA);
	pA.SetVertex(1, vB);
	pA.SetVertex(2, vC);

	planeList.push_back(pA);
}

//Divides 4 point plane into 2 triangles. 
void Model::AddPlane(Vertex vA, Vertex vB, Vertex vC, Vertex vD)
{
	Plane pA, pB;

	pA.SetVertex(0, vA);
	pA.SetVertex(1, vB);
	pA.SetVertex(2, vC);

	pB.SetVertex(0, vD);
	pB.SetVertex(1, vC);
	pB.SetVertex(2, vA);

	pA.SetColor(255, 0, 0);
	pB.SetColor(255, 0, 0);

	planeList.push_back(pA);
	planeList.push_back(pB);
}

// Divides any number of vertexes into triangles. 
// This method makes point A touch every other point. Will have issues with shapes that come into themselves, such as a heart. 
void Model::AddPlane(vector<Vertex> inputVertex)
{
	for (int index = 0; index < inputVertex.size() - 2; index++)
	{
		Plane pA;

		pA.SetVertex(0, inputVertex[0]);
		pA.SetVertex(1, inputVertex[index + 1]);
		pA.SetVertex(2, inputVertex[index + 2]);

		planeList.push_back(pA);
	}
}