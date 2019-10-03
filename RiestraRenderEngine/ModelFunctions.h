#ifndef ModelFunctions_H
#define ModelFunctions_H

#include <vector> 

#include "Point.h"
#include "Vertex.h"
#include "Plane.h"
#include "Model.h"
#include <string>

using namespace std;

class ModelFunctions
{
public:
	ModelFunctions();

	string PrintModelCoordinates(Model myModel);

	vector<Point> GetPrintCoordinates(Plane myPlane);

	vector<Point> GetPrintCoordinates(Plane myPlane, double transformX, double transformY, double transformZ, double sizeScale, double alpha, double beta, double gamma);
};
#endif ModelFunctions_H