#pragma once
#include "AEMath.h"
#include "Standard.h"

bool isWithinBoundary(AEVec2 v1, AEVec2 v2,	Size2D size);
bool RangeTest(AEVec2 v1, float v1_size, ShapeType v1_shape,
	AEVec2 v2, float v2_size, ShapeType v2_shape, Size2D rect_size);