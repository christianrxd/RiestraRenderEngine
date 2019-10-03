
#include <vector>
#include <string>

#include "ModelCreator.h"
#include "Vertex.h"
#include "Plane.h"
#include "Model.h"

using namespace std;

ModelCreator::ModelCreator()
{
}

Model ModelCreator::CreateCube(double size)
{
	Vertex A = Vertex(-size, -size, -size);
	Vertex B = Vertex(-size, -size, size);
	Vertex C = Vertex(size, -size, size);
	Vertex D = Vertex(size, -size, -size);
	Vertex E = Vertex(-size, size, -size);
	Vertex F = Vertex(-size, size, size);
	Vertex G = Vertex(size, size, size);
	Vertex H = Vertex(size, size, -size);

	Model myCube;

	myCube.AddPlane(A, B, C, D);
	myCube.AddPlane(E, F, G, H);
	myCube.AddPlane(A, B, F, E);
	myCube.AddPlane(D, C, G, H);
	myCube.AddPlane(B, C, G, F);
	myCube.AddPlane(A, D, H, E);

	return myCube;
}

Model ModelCreator::CreateHeart(double size)
{

	Model myHeart;

	for (int lcv = -2; lcv <= 2; lcv += 1)
	{
		vector<Vertex> vertexList;

		vertexList.push_back(Vertex(0, 4,  lcv));
		vertexList.push_back(Vertex(2, 6,  lcv));
		vertexList.push_back(Vertex(5, 6,  lcv));
		vertexList.push_back(Vertex(7, 4,  lcv));
		vertexList.push_back(Vertex(7, 0,  lcv));
		vertexList.push_back(Vertex(0, -7, lcv));
		vertexList.push_back(Vertex(-7, 0, lcv));
		vertexList.push_back(Vertex(-7, 4, lcv));
		vertexList.push_back(Vertex(-5, 6, lcv));
		vertexList.push_back(Vertex(-2, 6, lcv));
		vertexList.push_back(Vertex(0, 4,  lcv));

		myHeart.AddPlane(vertexList);
	}
	
	return myHeart;
}