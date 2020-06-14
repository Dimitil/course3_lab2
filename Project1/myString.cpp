#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <iostream>


// Определение конструктора.

MyString::MyString()
{
m_len=0;
m_pStr = new char[1];
*m_pStr =  0;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString::MyString(const char* str)
{
	m_len  = strlen(str);
	m_pStr = new char[m_len+1];
	strcpy(m_pStr, str);
}
// Определение деструктора


//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--



MyString::~MyString()
{
	m_len = 0;
	delete[] m_pStr;

	m_pStr = nullptr;

}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--



MyString::MyString(const MyString &MyStr)
{
	m_len = strlen(MyStr.m_pStr);
	m_pStr=new char[m_len+1];
	strcpy(m_pStr, MyStr.m_pStr);
}




//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--


void MyString::SetNewString(const char*  NewString)
{

	 if(m_len<strlen(NewString))
		{
		delete[] m_pStr;
		m_len = strlen(NewString);
		m_pStr = new char[m_len+1];
		}

	 strcpy(m_pStr, NewString);
}

MyString* MyStringCat(int count, const MyString* str1, ...)
{
	va_list  argptr;
	va_start(argptr, str1);

	char buf1[80];
	strcpy(buf1, str1->GetString());
	count--;

	char buf2[80];
	while (count)
	{
		strcpy(buf2, va_arg(argptr, MyString*)->GetString());
		strcat(buf1, buf2);
		count--;
	}
	


	buf1[79] = 0;
	MyString* Res = new MyString(buf1);

	return Res;
}
