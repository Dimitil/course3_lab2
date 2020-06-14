#include "Shape.h"

Rect::Rect(int x1, int y1, int x2, int y2, color c) : Shape(c)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;

	normalize();
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Rect::normalize()
{
	int x1 = m_x1;
	int y1 = m_y1;
	int x2 = m_x2;
	int y2 = m_y2;

	m_x1 = std::min(x1, x2);
	m_y1 = std::min(y1, y2);
	m_x2 = std::max(x1, x2);
	m_y2 = std::max(y1, y2);
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Rect::setPoints(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Rect::getPoints(int& x1, int& y1, int& x2, int& y2) const
{
	x1 = m_x1;
	y1 = m_y1;
	x2 = m_x2;
	y2 = m_y2;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Rect::Inflate(int dl)
{
	m_x1 -= dl / 2;
	m_y1 -= dl / 2;
	m_x2 += dl / 2;
	m_y2 += dl / 2;

	normalize();
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Circle::Circle(int x, int y, int radius, color c) : Shape(c)
{
	m_centerX = x;
	m_centerY = y;
	m_radius = radius;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

Circle::Circle(Rect r)				//конструктор принимает прямоугольник, получаем вписанный в него круг
{
	int x1, y1, x2, y2;
	r.getPoints(x1, y1, x2, y2);

	m_centerX = x1 + (x2 - x1) / 2;
	m_centerY = y1 + (y2 - y1) / 2;
	m_radius = std::min((x2 - x1) / 2, (y2 - y1) / 2); // R - половина минимальной стороны прямоугольника
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Circle::setCenter(int newCenterX, int newCenterY)
{
	m_centerX = newCenterX;
	m_centerY = newCenterY;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Circle::getCenter(int& centerX, int& centerY) const
{
	centerX = m_centerX;
	centerY = m_centerY;
}