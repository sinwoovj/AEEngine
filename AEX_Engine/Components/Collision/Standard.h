#pragma once

typedef enum ShapeType {
	Square,
	Rect,
	Circle
}ShapeType;

class Vector2D
{
public:
	float x;
	float y;

	Vector2D() { x = 0; y = 0; }
	Vector2D(int px, int py) { x = px; y = py; }

	Vector2D operator=(const Vector2D& other);
	Vector2D operator+(const Vector2D& other);
	Vector2D operator+(const float& value);
	Vector2D operator+=(const Vector2D& other);
	Vector2D operator+=(const float& value);
	Vector2D operator-(const Vector2D& other);
	Vector2D operator-(const float& value);
	Vector2D operator-=(const Vector2D& other);
	Vector2D operator-=(const float& value);
	Vector2D operator*(const Vector2D& other);
	Vector2D operator*(const float& value);
	Vector2D operator*=(const Vector2D& other);
	Vector2D operator*=(const float& value);
	Vector2D operator/(const Vector2D& other);
	Vector2D operator/(const float& value);
	Vector2D operator/=(const Vector2D& other);
	Vector2D operator/=(const float& value);
};

class Size2D
{
public:
	float w;
	float h;

	Size2D() { w = 0; h = 0; }
	Size2D(int px, int py) { w = px; h = py; }

	Size2D operator=(const Size2D& other);
	Size2D operator+(const Size2D& other);
	Size2D operator+(const float& value);
	Size2D operator+=(const Size2D& other);
	Size2D operator+=(const float& value);
	Size2D operator-(const Size2D& other);
	Size2D operator-(const float& value);
	Size2D operator-=(const Size2D& other);
	Size2D operator-=(const float& value);
	Size2D operator*(const Size2D& other);
	Size2D operator*(const float& value);
	Size2D operator*=(const Size2D& other);
	Size2D operator*=(const float& value);
	Size2D operator/(const Size2D& other);
	Size2D operator/(const float& value);
	Size2D operator/=(const Size2D& other);
	Size2D operator/=(const float& value);
};