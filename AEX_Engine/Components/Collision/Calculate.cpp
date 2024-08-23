#include "Calculate.h"

#include <cmath>

bool isWithinBoundary(AEVec2 v1, AEVec2 v2, Size2D size)
// v1이 base, v2가 target
{
    return (v1.x >= v2.x && v1.x <= v2.x + size.w) && 
        (v1.y >= v2.y && v1.y <= v2.y + size.h);
}

bool RangeTest(AEVec2 v1, float v1_size, ShapeType v1_shape,
	AEVec2 v2, float v2_size, ShapeType v2_shape, Size2D rect_size)
    // v1이 base, v2가 target
{
	bool res = false;

	if (v1_shape == Square && v2_shape == Square)
	{
		AEVec2 coord[4];

		coord[0] = v2;

		coord[1].x = v2.x + v2_size;
		coord[1].y = v2.y;

		coord[2].x = v2.x;
		coord[2].y = v2.y + v2_size;

		coord[3].x = v2.x + v2_size;
		coord[3].y = v2.y + v2_size;

		for (int i = 0; i < 4; i++) {
			if (coord[i].x >= v1.x && coord[i].x <= v1.x + v1_size &&
				coord[i].y >= v1.y && coord[i].y <= v1.y + v1_size)
				res = true;
		}
	}
	else if (v1_shape == Square && v2_shape == Rect)
	{
		/*
		(AEVec2 v1, float v1_size, ShapeType v1_shape,
		AEVec2 v2, float v2_size, ShapeType v2_shape, Size2D rect_size)
		*/
		enum dir {
			right = 0,
			left = 1,
			bottom = 2,
			top = 3
		};
		float square[4];
		square[left] =		v1.x - v1_size / 2;
		square[right] =		v1.x + v1_size / 2;
		square[top] =		v1.y - v1_size / 2;
		square[bottom] =	v1.y + v1_size / 2;
		float rect[4];
		rect[left] =		v2.x - rect_size.w / 2;
		rect[right] =		v2.x + rect_size.w / 2;
		rect[top] =			v2.y - rect_size.h / 2;
		rect[bottom] =		v2.y + rect_size.h / 2;

		// 충돌하지 않는 조건을 모두 확인
		if (rect[right] < square[left] ||   // rect가 square의 왼쪽에 있음
			rect[left] > square[right] ||   // rect가 square의 오른쪽에 있음
			rect[bottom] < square[top] ||   // rect가 square의 위쪽에 있음
			rect[top] > square[bottom]) {   // rect가 square의 아래쪽에 있음
			return false; // 충돌 없음
		}
		return true; // 충돌 있음
	}
	else if (v1_shape == Square && v2_shape == Circle)
	{
		// 사각형의 가장 가까운 점 찾기
		float closestX = fmax(v1.x, fmin(v2.x, v1.x + v1_size));
		float closestY = fmax(v1.y, fmin(v2.y, v1.y + v1_size));

		// 가장 가까운 점과 원의 중심 사이의 거리 계산
		float distanceX = v2.x - closestX;
		float distanceY = v2.y - closestY;

		// 유클리드 거리 계산
		float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

		// 거리가 원의 반지름보다 작거나 같으면 충돌
		if (distance <= v2_size / 2) {
			res = true;
		}
	}
	else if (v1_shape == Circle && v2_shape == Rect)
	{
		// 기존 코드 유지
		float x = fabs(v1.x - v2.x) <= 
			fabs(v1.x - (v2.x + rect_size.w)) ? 
			v2.x : v2.x + rect_size.w;
		float y = fabs(v1.y - v2.y) <= 
			fabs(v1.y - (v2.y + rect_size.h)) ? 
			v2.y : v2.y + rect_size.h;
		float diffX = v1.x >= x ? v1.x - x : x - v1.x;
		float diffy = v1.y >= y ? v1.y - y : y - v1.y;
		float diffF = sqrtf((diffX * diffX) + (diffy * diffy));

		// 새로운 조건 추가
		if (v1_size / 2 >= diffF || isWithinBoundary(v1, v2, rect_size))
			res = true;
	}
	else if (v1_shape == Circle && v2_shape == Circle)
	{
		float diffX = v1.x >= v2.x ? v1.x - v2.x : v2.x - v1.x;
		float diffy = v1.y >= v2.y ? v1.y - v2.y : v2.y - v1.y;
		float diffF = sqrtf((diffX * diffX) + (diffy * diffy));
		if ((v1_size / 2) + (v2_size / 2) >= diffF)
			res = true;
	}

	return res;
}
