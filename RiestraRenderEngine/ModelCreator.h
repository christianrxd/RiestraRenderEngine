#ifndef ModelCreator_H
#define ModelCreator_H

#include <vector> 

#include "Vertex.h"
#include "Plane.h"
#include "Model.h"
#include <string>

using namespace std;

class ModelCreator
{
public:
	ModelCreator();
	
	Model CreateCube(double size);
	Model CreateHeart(double size);
};
#endif ModelCreator_H