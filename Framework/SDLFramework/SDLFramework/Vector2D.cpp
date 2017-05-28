#include "Vector2D.h"
#include <Math.h>


Vector2D::Vector2D()
{
	m_x = 0;
	m_y = 0;
}

Vector2D::Vector2D(double x, double y)
{
	m_x = x;
	m_y = y;
}

double Vector2D::getX() const
{
	return m_x;
}

double Vector2D::getY() const
{
	return m_y;
}

void Vector2D::setX(double x)
{
	m_x = x;
}

void Vector2D::setY(double y)
{
	m_y = y;
}

void Vector2D::truncate(double maxValue)
{
	if (getLength() > maxValue)
	{
		Vector2D normalized = this->normalized();
		Vector2D scaled = normalized * maxValue;
		m_x = scaled.getX();
		m_y = scaled.getY();
	}
}

//unit vector
Vector2D Vector2D::normalized()
{
	Vector2D returnVal = Vector2D(m_x, m_y) / getLength();
	return returnVal;
}

Vector2D Vector2D::opposite()
{
	return Vector2D(-m_x, -m_y);
}

double Vector2D::getLength()
{
	double returnVal = sqrt(m_x * m_x + m_y * m_y);
	return  returnVal;
}

double Vector2D::distanceTo(const Vector2D & destination)
{
	double differenceX = m_x - destination.getX();
	double differenceY = m_y - destination.getY();
	//we dont use sqrt because it's expensive.
	//double distance = sqrt(differenceX*differenceX + differenceY * differenceY);
	double distance = differenceX*differenceX + differenceY * differenceY;
	return fabs(distance);
}

bool Vector2D::operator==(const Vector2D & other)
{
	return(m_x == other.getX() && m_y == other.getY());
}


Vector2D& Vector2D::operator+=(const Vector2D& toAdd)
{
	m_x += toAdd.getX();
	m_y += toAdd.getY();
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D & toAdd)
{
	int x = m_x + toAdd.getX();
	int y = m_y + toAdd.getY();
	return Vector2D(x, y);
}

Vector2D Vector2D::operator-(const Vector2D & toSubstract)
{
	int x = m_x - toSubstract.getX();
	int y = m_y - toSubstract.getY();
	return Vector2D(x, y);
}

Vector2D Vector2D::operator/(const double scalar)
{
	double x = m_x / scalar;
	double y = m_y / scalar;
	Vector2D returnVal = Vector2D(x, y);
	return returnVal;
}

Vector2D Vector2D::operator*(const double scalar)
{
	double x = m_x * scalar;
	double y = m_y * scalar;
	Vector2D returnVal = Vector2D(x, y);
	return returnVal;
}


Vector2D & Vector2D::operator*=(const double scalar)
{
	m_x = m_x * scalar;
	m_y = m_y * scalar;
	return *this;
}

std::ostream & Vector2D::operator<<(std::ostream & os)
{
	os.put(m_x);
	os.put(',');
	os.put(m_y);
	os.flush();
	return os;
}

std::ostream & operator<<(std::ostream & os, const Vector2D & vector)
{
	os << vector.m_x << " , " << vector.m_y;
	return os;
}