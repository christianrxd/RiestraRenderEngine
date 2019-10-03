
#include <vector>
#include <string>
#include <cmath>

#include "ModelFunctions.h"
#include "Vertex.h"
#include "Plane.h"
#include "Model.h"

using namespace std;

ModelFunctions::ModelFunctions()
{
}

string ModelFunctions::PrintModelCoordinates(Model myModel)
{
	string printString = "";

	for (Plane myPlane : myModel.planeList)
	{
		for (Vertex myVertex : myPlane.vertexList)
		{
			printString += std::to_string(myVertex.x) + " " + std::to_string(myVertex.y) + " " + std::to_string(myVertex.z) + "\n";
		}
		printString += "\n";
	}
	return printString;
}

vector<vector<Point>> ModelFunctions::GetPrintCoordinates(Model myModel)
{
	return GetPrintCoordinates(myModel, 0, 0, 0, 1, 0, 0, 0);
}

//vector<Point> ModelFunctions::GetPrintCoordinates(Model myModel, double transformX, double transformY, double transformZ, double sizeScale, double alpha, double beta, double gamma)
//{
//	const double PI = 3.14259;
//
//	//todo create Degree to Pi function
//	alpha = (alpha * PI) / 180;
//	beta  = (beta * PI ) / 180;
//	gamma = (gamma * PI) / 180;
//
//	double p1, p2, q1, q2, r1, r2;
//
//	p1 = (cos(beta)) * (cos(gamma));
//	p2 = (cos(gamma)) * (-sin(beta)) * (-sin(alpha)) + (sin(gamma)) * (cos(alpha));
//	q1 = (-sin(gamma)) * (cos(beta));
//	q2 = (-sin(gamma)) * (-sin(beta)) * (-sin(alpha)) + (cos(gamma)) * (cos(alpha));
//	r1 = (sin(beta));
//	r2 = (cos(beta)) * (-sin(alpha));
//
//	vector<Point> pointList;
//
//	for (Plane myPlane : myModel.planeList)
//	{
//		for (Vertex myVertex : myPlane.vertexList)
//		{
//			//model (3d) values
//			double mX, mY, mZ;
//			//graph (2d) values
//			double gX, gY;
//			
//			mX = (myVertex.x + transformX) * sizeScale;
//			mY = (myVertex.y + transformX) * sizeScale;
//			mZ = (myVertex.z + transformX) * sizeScale;
//			
//			gX = (p1 * mX) + (q1 * mY) + (r1 * mZ);
//			gY = (p2 * mX) + (q2 * mY) + (r2 * mZ);
//
//			Point myPoint(gX, gY);
//			pointList.push_back(myPoint);
//		}
//	}
//
//	return pointList;
//}

vector<vector<Point>> ModelFunctions::GetPrintCoordinates(Model myModel, double transformX, double transformY, double transformZ, double sizeScale, double alpha, double beta, double gamma)
{
	const double PI = 3.14259;

	//todo create Degree to Pi function
	alpha = (alpha * PI) / 180;
	beta = (beta * PI) / 180;
	gamma = (gamma * PI) / 180;

	double p1 = (cos(beta)) * (cos(gamma));
	double p2 = (cos(gamma)) * (-sin(beta)) * (-sin(alpha)) + (sin(gamma)) * (cos(alpha));
	double q1 = (-sin(gamma)) * (cos(beta));
	double q2 = (-sin(gamma)) * (-sin(beta)) * (-sin(alpha)) + (cos(gamma)) * (cos(alpha));
	double r1 = (sin(beta));
	double r2 = (cos(beta)) * (-sin(alpha));

	vector<vector<Point>> planeList;

	for (Plane myPlane : myModel.planeList)
	{
		vector<Point> pointList;
		for (Vertex myVertex : myPlane.vertexList)
		{
			//model (3d) values
			double mX, mY, mZ;
			//graph (2d) values
			double gX, gY;

			mX = (myVertex.x + transformX) * sizeScale;
			mY = (myVertex.y + transformX) * sizeScale;
			mZ = (myVertex.z + transformX) * sizeScale;

			gX = (p1 * mX) + (q1 * mY) + (r1 * mZ);
			gY = (p2 * mX) + (q2 * mY) + (r2 * mZ);

			Point myPoint(gX, gY);
			pointList.push_back(myPoint);
		}
		planeList.push_back(pointList);
	}

	return planeList;
}