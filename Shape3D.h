#pragma once
#include "Material.h"

class Shape3D
{
protected:
	Material *material;
public:
	Shape3D();
	Shape3D(Material *material);
	~Shape3D();
};

