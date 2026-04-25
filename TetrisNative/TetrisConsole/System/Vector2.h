#pragma once


struct Vector2
{
	int X;
	int Y;

	Vector2() : X(0), Y(0) {}
	Vector2(int X, int Y) : X(X), Y(Y) {}

	Vector2 operator+(const Vector2& other) const {
		return Vector2(X + other.X, Y + other.Y);
	}
	Vector2 operator-(const Vector2& other) const {
		return Vector2(X - other.X, Y - other.Y);
	}
	bool operator==(const Vector2& other) const {
		return X == other.X && Y == other.Y;
	}
	bool operator!=(const Vector2& other) const {
		return !(*this == other);
	}

	const Vector2& operator+=(const Vector2& other) {
		X += other.X;
		Y += other.Y;
		return *this;
	}

	const Vector2& operator-=(const Vector2& other) {
		X -= other.X;
		Y -= other.Y;
		return *this;
	}
};