#pragma once

#include <iostream>
#include <algorithm>

enum color{RED, GREEN, BLUE, BLACK, BROWN, YELLOW, GRAY, MAX_COLOR};

class Shape
{
		color m_color;

	public:

		Shape(color c = RED)	{ setColor(c); }

		virtual ~Shape()		{ std::cout << "\nNow I am in Shape's destructor!\n"; }

		void setColor(color c)  { m_color = c; }

		color getColor() const  { return m_color; }

		void WhereAmI()  const  { std::cout << "\nNow I am in class Shape\n"; }

		virtual void WhereAmIVirtual() const { std::cout << "\nNow I am in class Shape\n"; }

		virtual void Inflate(int) {};
};

//////////////////////////////////////////////////////////////////////////////

class Rect : public Shape
{

		int m_x1, m_y1, m_x2, m_y2;	// point coordinates (left top(x1, y1), right down(x2, y2))

	public:

		Rect(int x1 = 0, int y1 = 0, int x2 = 100, int y2 = 100, color c = RED) : Shape(c)
		{
			m_x1 = x1;
			m_y1 = y1;
			m_x2 = x2;
			m_y2 = y2;

			normalize();
		}

		virtual ~Rect() { std::cout << "\nNow I am in Rect's destructor!\n"; }

		void normalize()
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

		void setPoints(int x1, int y1, int x2, int y2)
		{
			m_x1 = x1;
			m_y1 = y1;
			m_x2 = x2;
			m_y2 = y2;
		}

		void getPoints(int& x1, int& y1, int& x2, int& y2) const
		{
			x1 = m_x1;
			y1 = m_y1;
			x2 = m_x2;
			y2 = m_y2;
		}

		void WhereAmI() const				 { std::cout << "\nNow I am in class Rect\n"; }

		virtual void WhereAmIVirtual() const { std::cout << "\nNow I am in class Rect\n"; }

		virtual void Inflate(int dl)
		{
			m_x1 -= dl / 2;
			m_y1 -= dl / 2;
			m_x2 += dl / 2;
			m_y2 += dl / 2;

			normalize();
		}
};

//////////////////////////////////////////////////////////////////////////////

class Circle : public Shape {

		int m_centerX;
		int m_centerY;
		int m_radius;

	public:



		Circle(int x = 200, int y= 200, int radius = 25, color c = RED) : Shape(c)
		{
			m_centerX = x;
			m_centerY = y;
			m_radius  = radius;
		}

		Circle(Rect r)				//конструктор принимает прямоугольник, получаем вписанный в него круг
		{
			int x1, y1, x2, y2;
			r.getPoints(x1, y1, x2, y2);

			m_centerX = x1 + (x2 - x1)/2;
			m_centerY = y1 + (y2 - y1)/2;
			m_radius  = std::min((x2-x1)/2, (y2-y1)/2); // R - половина минимальной стороны прямоугольника
		}

		virtual ~Circle() { std::cout << "\nNow I am in Circle's destructor!\n"; }

		void setCenter(int newCenterX, int newCenterY)
		{
			m_centerX = newCenterX;
			m_centerY = newCenterY;
		}

		void getCenter(int &centerX, int &centerY) const
		{
			centerX = m_centerX;
			centerY = m_centerY;
		}

		void WhereAmI() const { std::cout << "\nNow I am in class Circle\n"; }

		virtual void WhereAmIVirtual() const { std::cout << "\nNow I am in class Circle\n"; }

		virtual void Inflate(int dR)
		{
			m_radius += dR;
		}
};