#include "Standard.h"

Vector2D Vector2D::operator=(const Vector2D& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& other)
{
    Vector2D res;
    res.x = this->x + other.x;
    res.y = this->y + other.y;
    return res;
}

Vector2D Vector2D::operator+(const float& value)
{
    Vector2D res;
    res.x = this->x + value;
    res.y = this->y + value;
    return res;
}

Vector2D Vector2D::operator+=(const Vector2D& other)
{
    this->x = this->x + other.x;
    this->y = this->y + other.y;
    return *this;
}

Vector2D Vector2D::operator+=(const float& value)
{
    this->x = this->x + value;
    this->y = this->y + value;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& other)
{
    Vector2D res;
    res.x = this->x - other.x;
    res.y = this->y - other.y;
    return res;
}

Vector2D Vector2D::operator-(const float& value)
{
    Vector2D res;
    res.x = this->x - value;
    res.y = this->y - value;
    return res;
}

Vector2D Vector2D::operator-=(const Vector2D& other)
{
    this->x = this->x - other.x;
    this->y = this->y - other.y;
    return *this;
}

Vector2D Vector2D::operator-=(const float& value)
{
    this->x = this->x - value;
    this->y = this->y - value;
    return *this;;
}

Vector2D Vector2D::operator*(const Vector2D& other)
{
    Vector2D res;
    res.x = this->x * other.x;
    res.y = this->y * other.y;
    return res;
}

Vector2D Vector2D::operator*(const float& value)
{
    Vector2D res;
    res.x = this->x * value;
    res.y = this->y * value;
    return res;
}

Vector2D Vector2D::operator*=(const Vector2D& other)
{
    this->x = this->x * other.x;
    this->y = this->y * other.y;
    return *this;
}

Vector2D Vector2D::operator*=(const float& value)
{
    this->x = this->x * value;
    this->y = this->y * value;
    return *this;
}

Vector2D Vector2D::operator/(const Vector2D& other)
{
    Vector2D res;
    res.x = this->x / other.x;
    res.y = this->y / other.y;
    return res;
}

Vector2D Vector2D::operator/(const float& value)
{
    Vector2D res;
    res.x = this->x / value;
    res.y = this->y / value;
    return res;
}

Vector2D Vector2D::operator/=(const Vector2D& other)
{
    this->x = this->x / other.x;
    this->y = this->y / other.y;
    return *this;
}

Vector2D Vector2D::operator/=(const float& value)
{
    this->x = this->x / value;
    this->y = this->y / value;
    return *this;;
}

Size2D Size2D::operator=(const Size2D& other)
{
    this->w = other.w;
    this->h = other.h;
    return *this;
}

Size2D Size2D::operator+(const Size2D& other)
{
    Size2D res;
    res.w = this->w + other.w;
    res.h = this->h + other.h;
    return res;
}

Size2D Size2D::operator+(const float& value)
{
    Size2D res;
    res.w = this->w + value;
    res.h = this->h + value;
    return res;
}

Size2D Size2D::operator+=(const Size2D& other)
{
    this->w = this->w + other.w;
    this->h = this->h + other.h;
    return *this;
}

Size2D Size2D::operator+=(const float& value)
{
    this->w = this->w + value;
    this->h = this->h + value;
    return *this;
}

Size2D Size2D::operator-(const Size2D& other)
{
    Size2D res;
    res.w = this->w - other.w;
    res.h = this->h - other.h;
    return res;
}

Size2D Size2D::operator-(const float& value)
{
    Size2D res;
    res.w = this->w - value;
    res.h = this->h - value;
    return res;
}

Size2D Size2D::operator-=(const Size2D& other)
{
    this->w = this->w - other.w;
    this->h = this->h - other.h;
    return *this;
}

Size2D Size2D::operator-=(const float& value)
{
    this->w = this->w - value;
    this->h = this->h - value;
    return *this;;
}

Size2D Size2D::operator*(const Size2D& other)
{
    Size2D res;
    res.w = this->w * other.w;
    res.h = this->h * other.h;
    return res;
}

Size2D Size2D::operator*(const float& value)
{
    Size2D res;
    res.w = this->w * value;
    res.h = this->h * value;
    return res;
}

Size2D Size2D::operator*=(const Size2D& other)
{
    this->w = this->w * other.w;
    this->h = this->h * other.h;
    return *this;
}

Size2D Size2D::operator*=(const float& value)
{
    this->w = this->w * value;
    this->h = this->h * value;
    return *this;
}

Size2D Size2D::operator/(const Size2D& other)
{
    Size2D res;
    res.w = this->w / other.w;
    res.h = this->h / other.h;
    return res;
}

Size2D Size2D::operator/(const float& value)
{
    Size2D res;
    res.w = this->w / value;
    res.h = this->h / value;
    return res;
}

Size2D Size2D::operator/=(const Size2D& other)
{
    this->w = this->w / other.w;
    this->h = this->h / other.h;
    return *this;
}

Size2D Size2D::operator/=(const float& value)
{
    this->w = this->w / value;
    this->h = this->h / value;
    return *this;;
}