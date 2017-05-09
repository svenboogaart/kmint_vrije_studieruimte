#pragma once
#include <iostream>

class Vector2D
{
private:
	double m_x, m_y;
public:
	Vector2D();
	Vector2D(double x, double y);
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	void truncate(double maxValue);
	Vector2D normalized();
	Vector2D opposite();
	double getLength();
	double distanceTo(const Vector2D&);
	Vector2D& operator+=(const Vector2D&);
	Vector2D operator+(const Vector2D&);
	Vector2D operator-(const Vector2D&);
	Vector2D operator/(const double);
	Vector2D operator*(const double);
	Vector2D& operator *=(const double);
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector);
	std::ostream& operator<<(std::ostream&);
};