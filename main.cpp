// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.

#include <tchar.h>
#include "myString.h"
#include <iostream>
#include "Shape.h"
#include "Byte.h"

#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	//������� 1.������ �������� ������.
	{
		//�������� � ������������������ ������ ar �� ��������
		// ���� MyString. 
		std::cout << "\nTask #1\n";
		const int N = 3;
		MyString str1[N] = { MyString("Hello,"), MyString("my"), MyString("friend.") };

		//�������� - ������ �����-������ ������

		for (int i = 0; i < N; i++)
			std::cout << str1[i].GetString() << " ";
		std::cout << std::endl;
		//�������� ������ const int N=5; , �� ������� ������ ���������������.

		const int M = 3;
		MyString str2[M] = { MyString("Hello,"), MyString("my"), MyString("friend.") };

		//�������� - ������ �����-������ ������

		for (int i = 0; i < M; i++)
			std::cout << str2[i].GetString() << " ";
		std::cout << std::endl;

	}
	stop


		//������� 2.������ ���������� �� ������� ������.
	{
		std::cout << "\nTask #2\n";
	//�������� � ������������������ ������ arPtr �� N
	//���������� �� ������� ���� MyString (���� ������� 
	//��������� �����������!).
	const int N = 3;
	MyString* arPtr[N] = { new MyString("What a"), new MyString("woderful"), new MyString("world") };


	//������ �����-������ ������

	for (int i = 0; i < N; i++)
		std::cout << arPtr[i]->GetString() << " ";
	std::cout << std::endl;

	//�������� ������ const int N=5; , �� ������� ������ ���������������.


	const int M = 5;
	MyString* arPtr2[M] = { new MyString("What a"), new MyString("woderful"), new MyString("world") };


	//������ �����-������ ������

	for (int i = 0; i < M; i++)
		std::cout << arPtr2[i]->GetString() << " ";
	std::cout << std::endl;


	for (int i = 0; i < N; i++)
	{
		delete arPtr[i];
	}

	for (int i = 0; i < M; i++)
	{
		delete arPtr2[i];
	}

	}
		stop


		//������� 3.������� ������������.��������� ������������,
		// ������������ � ������� �����.
		std::cout << "\nTask #3\n";
	//�������� �������� �������:
	//������� ����� Shape (������� ��������� ����� ������)
	//� ��� ����������� ������ Rect � Circle.
	//���������: ����� ������ � ������ ����� ������ � �������
	//� ����������� ������ (��������, ����� ������ ����� �������
	//������� => � ������� ������ ����� ������ ����������, �������
	//����� ���������� ���� ������.
	//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);



	//� ������������� ����������� ������� ������������� ��������
	//���������-����� ������������ �������� ������.
	//��� �������� � ����������� ������� ������������ ���� ����������
	//������������������ ������� ������������� � ������������ ��������
	//� ������������ �������




	stop
		//////////////////////////////////////////////////////////////////////

			//������� 4.����������� �������.

			//4�) ������������� ������ Shape,Rect � Circle:
			//�������� � ������ ����� public ����� void WhereAmI().
			//���������� ������ ������� ������ �������� ��������� 
			//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
			//��������� ����������� ��������, ��������� ���������.

		std::cout << "\nTask #4a\n";

	{
		Shape s(BLUE);
		Rect r(0, 0, 45, 50, GREEN);
		Circle c(10, 10, 15, BROWN);

		//����� ������ ������ ���������� � ��������� ��������???

		s.WhereAmI();	//	Shape
		r.WhereAmI();	//	Rect
		c.WhereAmI();	//	Circle

		stop

			Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;

		pShape->WhereAmI();	 // Shape
		pRect->WhereAmI();	 //	Shape
		pCircle->WhereAmI(); //	Shape
		stop

			//��������� ... �������� ������������

			Shape& rShape = s; //��������� s
		Shape& rRect = r; //��������� r
		Shape& rCircle = c; //��������� c
		rShape.WhereAmI();	//����� ����������� rShape	/ Shape
		rRect.WhereAmI();	//����� �����������	rRect	/ Shape
		rCircle.WhereAmI(); //����� ����������� rCircle	/ Shape
		stop
	}

	//4�) �������� � ������� � ����������� ������ �����������
	// ����� WhereAmIVirtual(). �� �������� � 4� ��������
	// ����������� ����� ����������� ��������, ���������� �
	// ������, ������������ � ���������� ���������.
	//��������� ����� ��������, ��������� �������.
	std::cout << "\nTask #4b\n";

	{
		Shape s(BLUE);
		Rect r(0, 0, 45, 50, GREEN);
		Circle c(10, 10, 15, BROWN);

		s.WhereAmIVirtual();	//	Shape
		r.WhereAmIVirtual();	//	Rect
		c.WhereAmIVirtual();	//	Circle

		stop

			Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;

		pShape->WhereAmIVirtual();	 // Shape
		pRect->WhereAmIVirtual();	 //	Rect
		pCircle->WhereAmIVirtual(); //	Circle
		stop

			Shape& rShape = s; //��������� s
		Shape& rRect = r; //��������� r
		Shape& rCircle = c; //��������� c

		rShape.WhereAmIVirtual();	//����� ����������� rShape	/ Shape
		rRect.WhereAmIVirtual();	//����� �����������	rRect	/ Rect
		rCircle.WhereAmIVirtual(); //����� ����������� rCircle	/ Circle
		stop
	}

	//////////////////////////////////////////////////////////////////////

		//������� 5.����������� �����������.
	{
	std::cout << "\nTask #5\n";

	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.		//����������� ������ ��� Shape �����

	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������.


	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������

	Rect r;
	Shape* ar[] = { new Shape(r), new Rect(r), new Circle(r), new Circle() };
	//�������� ��� ������� �������� ������� ����� WhereAmIVirtual()
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
		ar[i]->WhereAmIVirtual();
	//�� ������ �������� ������ ����������� ������� ��
	// Shape
	// Rect
	// Circle
	// Circle

	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
		delete ar[i];

	// c ������������ ������������� ���������� ����������� ������� ��� �������� �����, ����� ��� �������.
	stop
	}


	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		std::cout << "\nTask #6\n";

		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)		

		//���������� ������� ����� WhereAmIVirtual() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???

		for (int i = 0; i < 10; i++)
			pRects[i].WhereAmIVirtual();
		
		for (int i = 0; i < 10; i++)
			static_cast<Rect*>(pShapes)[i].WhereAmIVirtual();		//� ������� Rect[10] ��� �������� �� ������ �� Shape* �������� �� � �� �����

		//���������� ����������� ����������� ������

		delete[] pShapes;
		delete[] pRects;
		stop
	}



//////////////////////////////////////////////////////////////////////


	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		std::cout << "\nTask #7\n";

		Rect r;
		Shape* p = &r;	
		p->WhereAmIVirtual();//������� �� Rect

		stop


			// �������� ���������� ������� ���������.
			//����������� ������� r � ��������� p �������� ����������� �������
			//WhereAmIVirtual()������ Shape

			r .Shape::WhereAmIVirtual();	//������� �� Shape
			p->Shape::WhereAmIVirtual();	//������� �� Shape

			stop
		
		
	}


//////////////////////////////////////////////////////////////////////

	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		std::cout << "\nTask #8\n";

		Rect r;
		Shape* p = &r;
		p->Inflate(5);				//����� ����������� ������� ������, ������ ��� � ���������� ��������
		Circle c;					//��������� ������� Shape, � ������� ������������ ������ ������ ���������
		p = &c;
		p->Inflate(5);

		stop
	}



//////////////////////////////////////////////////////////////////////
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������
	std::cout << "\nTask #9\n";

	MyString str1("Hello");
	MyString str2("My");
	MyString str3("World");

	MyString* str4 = MyStringCat(3, &str1, &str2, &str3);
	std::cout<<str4->GetString();
	delete str4;


////////////////////////////////////////////////////////////////////////

	//������� 10.����������� (union) C++. ������� ����.
	//1.
	std::cout << std::endl;
	std::cout << "\nTask #10\n";
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	char num=0x22;
	Bytes byte(num);
	std::cout << "\nbyte = 0x" << std::hex; 
	byte.ShowDec();

	std::cout << std::endl << "ShowBin(): ";
	byte.ShowBin();

	std::cout << "ShowBinPos(1): ";
	byte.ShowBinPos(1);

	std::cout << "ShowBinPos(2): ";
	byte.ShowBinPos(2);

	std::cout << "EditBin(2, 1).";
	byte.EditBin(2, 1);
	std::cout << std::endl;

	std::cout << "ShowBinPos(2): ";
	byte.ShowBinPos(2);

	std::cout << "EditBin(2, 0).";
	byte.EditBin(2, 0);



	std::cout << std::endl << "ShowOct(): ";
	byte.ShowOct();

	std::cout << std::endl << "ShowOctPos(1): ";
	byte.ShowOctPos(1);

	std::cout << std::endl << "EditOct(1, 3);";
	byte.EditOct(1, 3);

	std::cout << std::endl << "ShowOct() : ";
	byte.ShowOct();

	std::cout << std::endl << "EditOct(1, 4);";
	byte.EditOct(1, 4);



	std::cout << std::endl << "ShowHex();";
	byte.ShowHex();

	std::cout << std::endl << "ShowHexPos(1): ";
	byte.ShowHexPos(1);

	std::cout << std::endl << "EditHex(1, 10);";
	byte.EditHex(1, 10);

	std::cout << std::endl << "ShowHex();";
	byte.ShowHex();

	std::cout << std::endl << "ShowHexPos(1): ";
	byte.ShowHexPos(1);
	return 0;
}//endmain

