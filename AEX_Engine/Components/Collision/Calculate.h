#pragma once

#include "Standard.h"

bool isWithinBoundary(Vector2D v1, Vector2D v2,	Size2D size);
bool RangeTest(Vector2D v1, float v1_size, ShapeType v1_shape, 
	Vector2D v2, float v2_size, ShapeType v2_shape, Size2D rect_size);