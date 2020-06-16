#pragma once
#include <iostream>

class Bin
{
		unsigned char m_bin0: 1;
		unsigned char m_bin1: 1;
		unsigned char m_bin2: 1;
		unsigned char m_bin3: 1;
		unsigned char m_bin4: 1;
		unsigned char m_bin5: 1;
		unsigned char m_bin6: 1;
		unsigned char m_bin7: 1;

	protected:

		void Show() const;
		void ShowPos(int pos) const;	//выводим цифру в позиции 
		void Edit(int pos, int val);	//изменяем цифру в позиции
		friend union Bytes;
};

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

class Oct {
		unsigned char m_oct0 : 3; 
		unsigned char m_oct1 : 3; 
		unsigned char m_oct2 : 2;
	
	protected:

		void Show() const; //выводим все восьмеричные цифры 
		void ShowPos(int pos) const; //выводим цифру в позиции
		void Edit(int pos, int val); //изменяем цифру в позиции
		friend union Bytes;
};

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

class Hex {

		unsigned char m_hex0 : 4; 
		unsigned char m_hex1 : 4;

	protected:

		void Show() const; //выводим все шестнадцатеричные цифры 
		void ShowPos(int pos) const; //выводим цифру в позиции 
		void Edit(int pos, int val); //изменяем цифру в позиции
		friend union Bytes;
};

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

union Bytes {
	private:    //спецификатор доступа? 

		Bin m_bin; 
		Oct m_oct;
		Hex m_hex;

	protected:

		unsigned char m_dec; 

	public: 

		Bytes(unsigned char byte)		{ m_dec = byte; }			//конструктор

		void ShowDec()	const			{ std::cout << static_cast<int>(m_dec); }
		void ShowChar()	const			{ std::cout << m_dec; }

		void ShowBin()	const			{ m_bin.Show(); }
		void ShowBinPos(int pos) const		{ m_bin.ShowPos(pos); }		
		void EditBin(int pos, int val)	{ m_bin.Edit(pos, val); }
	
		void ShowOct()	const			{ m_oct.Show(); }
		void ShowOctPos(int pos) const	{ m_oct.ShowPos(pos); }
		void EditOct(int pos, int val)	{ m_oct.Edit(pos, val); }

		void ShowHex()	const			{ m_hex.Show(); }
		void ShowHexPos(int pos) const	{ m_hex.ShowPos(pos); }
		void EditHex(int pos, int val)	{ m_hex.Edit(pos, val); }
	
};
