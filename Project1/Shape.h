#pragma once

#include <iostream>
#include <algorithm>

enum color { RED, GREEN, BLUE, BLACK, BROWN, YELLOW, GRAY, MAX_COLOR };

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

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

class Rect : public Shape
{

		int m_x1, m_y1, m_x2, m_y2;	// point coordinates (left top(x1, y1), right down(x2, y2))

	public:

		Rect(int x1 = 0, int y1 = 0, int x2 = 100, int y2 = 100, color c = RED);

		virtual ~Rect() { std::cout << "\nNow I am in Rect's destructor!\n"; }

		void normalize();

		void setPoints(int x1, int y1, int x2, int y2);

		void getPoints(int& x1, int& y1, int& x2, int& y2) const;

		void WhereAmI() const				 { std::cout << "\nNow I am in class Rect\n"; }

		virtual void WhereAmIVirtual() const { std::cout << "\nNow I am in class Rect\n"; }

		virtual void Inflate(int dl);
};

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

class Circle : public Shape {

		int m_centerX;
		int m_centerY;
		int m_radius;

	public:

		Circle(int x = 200, int y = 200, int radius = 25, color c = RED);

		Circle(const Rect &r);				//конструктор принимает прямоугольник, получаем вписанный в него круг
		
		virtual ~Circle()						{ std::cout << "\nNow I am in Circle's destructor!\n"; }

		void setCenter(int newCenterX, int newCenterY);
		
		void getCenter(int& centerX, int& centerY) const;

		void WhereAmI() const					{ std::cout << "\nNow I am in class Circle\n"; }

		virtual void WhereAmIVirtual() const	{ std::cout << "\nNow I am in class Circle\n"; }

		virtual void Inflate(int dR)			{ m_radius += dR; }
};