#include "Vector2D.h"

Vector2D::Vector2D() : x(0), y(0){}

Vector2D::Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

const Vector2D Vector2D::ZERO(0.0f, 0.0f);

const Vector2D Vector2D::LEFT(-1.0f, 0.0f);

const Vector2D Vector2D::RIGHT(1.0f, 0.0f);

const Vector2D Vector2D::DOWN(0.0f, 1.0f);

const Vector2D Vector2D::UP(0.0f, -1.0f);