#pragma once

#include<iostream>

class Vector2D {
public:
	float x; //x���W
	float y; //y���W

	Vector2D();

	Vector2D(float x, float y);

	//���ς����߂�
	float dot(const Vector2D& other) const {
		return (x * other.x) + (y * other.y);
	}

	//�O�ς����߂�
	float cross(const Vector2D& other) const {
		return (x * other.x) - (y * other.y);
	}

	//���������߂�
	float length() const {
		return std::sqrt(dot(*this));
	}

	//���������߂�
	float distance(const Vector2D& other) const {
		return (*this - other).length();
	}

	//���K��
	Vector2D normalize() const {
		const float len = length();
		if (len < FLT_EPSILON) {
			return Vector2D::ZERO;
		}
		return *this / len;
	}

	//�[���x�N�g����
	bool isZero() const {
		return *this == Vector2D::ZERO;
	}

	//���Z�q�I�[�o�[���[�h
	Vector2D& operator += (const Vector2D& other) {
		return *this = *this + other;
	}

	Vector2D& operator -= (const Vector2D& other) {
		return *this = *this - other;
	}
	
	Vector2D& operator *= (float scalar) { 
		return *this = *this * scalar;
	}

	Vector2D& operator /= (float scalar) {
		return *this = *this / scalar;
	}

	const Vector2D& operator + (const Vector2D& other) const {
		return Vector2D(x + other.x, y + other.y);
	}

	const Vector2D& operator - (const Vector2D& other) const {
		return Vector2D(x - other.x, y - other.y);
	}

	const Vector2D& operator * (float scalar) const {
		return Vector2D(x * scalar, y * scalar);
	}

	const Vector2D& operator / (float scalar) const {
		return Vector2D(x / scalar, y / scalar);
	}

	const Vector2D operator - () const {
		return Vector2D(-x, -y);
	}

	bool operator == (const Vector2D& other) const {
		return (x == other.x) && (y == other.y);
	}

	bool operator != (const Vector2D& other) const {
		return !(*this == other);
	}

	bool operator < (const Vector2D& other) const {
		if (x < other.x) return true;
		if (y < other.y) return true;
		return false;
	}


	//�萔
		static const Vector2D ZERO; //�[���x�N�g��
		static const Vector2D LEFT;
		static const Vector2D RIGHT;
		static const Vector2D DOWN;
		static const Vector2D UP;
};