#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <string.h>

class MyString
{
	int   m_len;
    char* m_pStr;	//������-���� ������
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString &MyStr);
	~MyString();
	const char* GetString() const { if (this) return m_pStr; else return ""; }
	void SetNewString(const char* NewString);
};

MyString* MyStringCat(const char* str, ...);  //��� ������� 0 - ����� �����?