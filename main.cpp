// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.

#include <tchar.h>
#include "myString.h"
#include <iostream>
#include "Shape.h"
#include "Byte.h"

#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	//Задание 1.Массив объектов класса.
	{
		//Объявите и проинициализируйте массив ar из объектов
		// типа MyString. 
		std::cout << "\nTask #1\n";
		const int N = 3;
		MyString str1[N] = { MyString("Hello,"), MyString("my"), MyString("friend.") };

		//Проверка - печать строк-членов класса

		for (int i = 0; i < N; i++)
			std::cout << str1[i].GetString() << " ";
		std::cout << std::endl;
		//Замените размер const int N=5; , не изменяя список инициализаторов.

		const int M = 3;
		MyString str2[M] = { MyString("Hello,"), MyString("my"), MyString("friend.") };

		//Проверка - печать строк-членов класса

		for (int i = 0; i < M; i++)
			std::cout << str2[i].GetString() << " ";
		std::cout << std::endl;

	}
	stop


		//Задание 2.Массив указателей на объекты класса.
	{
		std::cout << "\nTask #2\n";
	//Объявите и проинициализируйте массив arPtr из N
	//указателей на объекты типа MyString (сами объекты 
	//создаются динамически!).
	const int N = 3;
	MyString* arPtr[N] = { new MyString("What a"), new MyString("woderful"), new MyString("world") };


	//Печать строк-членов класса

	for (int i = 0; i < N; i++)
		std::cout << arPtr[i]->GetString() << " ";
	std::cout << std::endl;

	//Замените размер const int N=5; , не изменяя список инициализаторов.


	const int M = 5;
	MyString* arPtr2[M] = { new MyString("What a"), new MyString("woderful"), new MyString("world") };


	//Печать строк-членов класса

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


		//Задание 3.Простое наследование.Аргументы конструктора,
		// передаваемые в базовый класс.
		std::cout << "\nTask #3\n";
	//Создайте иерархию классов:
	//базовый класс Shape (который описывает любую фигуру)
	//и два производных класса Rect и Circle.
	//Подумайте: какие данные и методы нужно ввести в базовый
	//и производные классы (например, любую фигуру можно сделать
	//цветной => в базовом классе можно ввести переменную, которая
	//будет определять цвет фигуры.
	//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);



	//В конструкторах производных классов предусмотрите передачу
	//параметра-цвета конструктору базового класса.
	//При создании и уничтожении объекта производного типа определите
	//последовательность вызовов конструкторов и деструкторов базового
	//и производного классов




	stop
		//////////////////////////////////////////////////////////////////////

			//Задание 4.Виртуальные функции.

			//4а) Модифицируйте классы Shape,Rect и Circle:
			//добавьте в каждый класс public метод void WhereAmI().
			//Реализация каждой функции должна выводить сообщение 
			//следующего вида "Now I am in class Shape(Rect или Circle)".
			//Выполните приведенный фрагмент, объясните результат.

		std::cout << "\nTask #4a\n";

	{
		Shape s(BLUE);
		Rect r(0, 0, 45, 50, GREEN);
		Circle c(10, 10, 15, BROWN);

		//Метод какого класса вызывается в следующих строчках???

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

			//Заполните ... согласно комментариям

			Shape& rShape = s; //псевдоним s
		Shape& rRect = r; //псевдоним r
		Shape& rCircle = c; //псевдоним c
		rShape.WhereAmI();	//вызов посредством rShape	/ Shape
		rRect.WhereAmI();	//вызов посредством	rRect	/ Shape
		rCircle.WhereAmI(); //вызов посредством rCircle	/ Shape
		stop
	}

	//4б) Добавьте в базовый и производные классы виртуальный
	// метод WhereAmIVirtual(). По аналогии с 4а вызовите
	// виртуальный метод посредством объектов, указателей и
	// ссылок, определенных в предыдущем фрагменте.
	//Выполните новый фрагмент, объясните разницу.
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

			Shape& rShape = s; //псевдоним s
		Shape& rRect = r; //псевдоним r
		Shape& rCircle = c; //псевдоним c

		rShape.WhereAmIVirtual();	//вызов посредством rShape	/ Shape
		rRect.WhereAmIVirtual();	//вызов посредством	rRect	/ Rect
		rCircle.WhereAmIVirtual(); //вызов посредством rCircle	/ Circle
		stop
	}

	//////////////////////////////////////////////////////////////////////

		//Задание 5.Виртуальные деструкторы.
	{
	std::cout << "\nTask #5\n";

	//Модифицируйте классы:
	//a) введите соответствующие
	// деструкторы (без ключевого слова virtual).
	//Реализация каждого деструктора
	//должна выводить сообщение следующего вида
	// "Now I am in Shape's destructor!" или
	// "Now I am in Rect's destructor!"
	//Выполните фрагмент. Объясните результат.		//деструкторы только для Shape части

	// b) Добавьте в объявление деструкторов ключевое слово virtual 
	//Выполните фрагмент.Объясните разницу.


	//Подумайте: какие конструкторы вызываются в следующей строке?
		//Если в разработанных классов каких-то конструкторов
		//не хватает - реализуйте
		//Если Вы считаете, что в приведенном фрагменте чего-то
		//не хватает - добавьте

	Rect r;
	Shape* ar[] = { new Shape(r), new Rect(r), new Circle(r), new Circle() };
	//Вызовите для каждого элемента массива метод WhereAmIVirtual()
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
		ar[i]->WhereAmIVirtual();
	//на выходе получили вызовы виртуальной функции из
	// Shape
	// Rect
	// Circle
	// Circle

	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
		delete ar[i];

	// c виртуальными деструкторами вызывались деструкторы сначала для дочерней части, потом для базовой.
	stop
	}


	//Задание 6*. В чем заключается отличие 1) и 2)
	{
		std::cout << "\nTask #6\n";

		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)		

		//Попробуйте вызвать метод WhereAmIVirtual() для каждого элемента обоих массивов -
		//в чем заключается проблема???

		for (int i = 0; i < 10; i++)
			pRects[i].WhereAmIVirtual();
		
		for (int i = 0; i < 10; i++)
			static_cast<Rect*>(pShapes)[i].WhereAmIVirtual();		//в массиве Rect[10] при смещении от начала на Shape* попадаем не в то место

		//Освободите динамически захваченную память

		delete[] pShapes;
		delete[] pRects;
		stop
	}



//////////////////////////////////////////////////////////////////////


	//Задание 7.Виртуальные функции и оператор разрешения области видимости. 

	{
		std::cout << "\nTask #7\n";

		Rect r;
		Shape* p = &r;	
		p->WhereAmIVirtual();//вызвали из Rect

		stop


			// Оператор разрешения области видимости.
			//Посредством объекта r и указателя p вызовите виртуальную функцию
			//WhereAmIVirtual()класса Shape

			r .Shape::WhereAmIVirtual();	//вызвали из Shape
			p->Shape::WhereAmIVirtual();	//вызвали из Shape

			stop
		
		
	}


//////////////////////////////////////////////////////////////////////

	//Задание 8.Чисто виртуальные функции. 
	//Введите в базовый класс метод void Inflate(int); Подумайте:
	//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
	//Реализуйте этот метод для производных классов.
	{
		std::cout << "\nTask #8\n";

		Rect r;
		Shape* p = &r;
		p->Inflate(5);				//чисто виртуальной сделать нельзя, потому что в предыдущих заданиях
		Circle c;					//создаются объекты Shape, а объекты абстрактного класса нельзя создавать
		p = &c;
		p->Inflate(5);

		stop
	}



//////////////////////////////////////////////////////////////////////
	//Задание 9. Создайте глобальную функцию, которая будет принимать любое
	//количество указателей на строки, а возвращать объект MyString,
	//в котором строка будет конкатенацией параметров
	std::cout << "\nTask #9\n";

	MyString str1("Hello");
	MyString str2("My");
	MyString str3("World");

	MyString* str4 = MyStringCat(3, &str1, &str2, &str3);
	std::cout<<str4->GetString();
	delete str4;


////////////////////////////////////////////////////////////////////////

	//Задание 10.Объединения (union) C++. Битовые поля.
	//1.
	std::cout << std::endl;
	std::cout << "\nTask #10\n";
	//Создайте следующие классы для различных представлений значений байта:
	//Bin - для двоичного представления
	//Hex - для шестнадцатерчного представления
	//Oct - для восьмеричного представления.
	//Подсказка 1: - для удобства используйте битовые поля.
	//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
	//так как все они будут членами объединения (union).
	//2.
	//В каждом классе введите метод Show, который должен выводить значение в
	//соответствующем виде
	//3.
	//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
	//одним и тем же значением по-разному:
	//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта 
	//          а также символ, соответствующий хранимому значению (если есть соответствие);
	//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
	//			восьмеричные, двоичные цифры;
	//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;

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

