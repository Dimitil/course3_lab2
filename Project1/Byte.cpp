#include "Byte.h"

void Bin::Show() const
{
	std::cout << std::endl;
	
	std::cout << static_cast<int>(m_bin7);
	std::cout << static_cast<int>(m_bin6);
	std::cout << static_cast<int>(m_bin5);
	std::cout << static_cast<int>(m_bin4);
	std::cout << static_cast<int>(m_bin3);
	std::cout << static_cast<int>(m_bin2);
	std::cout << static_cast<int>(m_bin1);
	std::cout << static_cast<int>(m_bin0);

	std::cout << std::endl;
}; //выводим все двоичные цифры 


//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--


void Bin::ShowPos(int pos) const //выводим цифру в позиции 
{
	std::cout << std::endl;

	int ar_num[8] = { m_bin0, m_bin1, m_bin2, m_bin3, m_bin4, m_bin5, m_bin6, m_bin7 };

	std::cout << ar_num[pos];

	std::cout << std::endl;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Bin::Edit(int pos, int val)
{
	if (val == 1 || val == 0)
	{
		switch (pos)
		{
		case 0:
			m_bin0 = val;
			break;
		case 1:
			m_bin1 = val;
			break;
		case 2:
			m_bin2 = val;
			break;
		case 3:
			m_bin3 = val;
			break;
		case 4:
			m_bin4 = val;
			break;
		case 5:
			m_bin5 = val;
			break;
		case 6:
			m_bin6 = val;
			break;
		case 7:
			m_bin7 = val;
			break;
		default:
			std::cout << "\nError. enter pos in range [0 to 7]\n";
		}
	}
	else std::cout << "\nval can be only '1' or '0'\n";
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Oct::Show() const //выводим все восьмеричные цифры 
{
	std::cout << std::endl;
	
	std::cout << '0';
	std::cout << static_cast<int>(m_oct2);
	std::cout << static_cast<int>(m_oct1);
	std::cout << static_cast<int>(m_oct0);
	
	std::cout << std::endl;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Oct::ShowPos(int pos) const //выводим цифру в позиции
{
	std::cout << std::endl;
	switch (pos)
	{
	case 0:
		std::cout << static_cast<int>(m_oct0);
		break;
	case 1:
		std::cout << static_cast<int>(m_oct1);
		break;
	case 2:
		std::cout << static_cast<int>(m_oct2);
		break;
	default:
		std::cout << "\nError. enter pos in range [0 to 2]\n";
	}
	std::cout << std::endl;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Oct::Edit(int pos, int val) //изменяем цифру в позиции
{
	if (val >=0 && val < 8)
	{
		switch (pos)
		{
		case 0:
			m_oct1 = val;
			break;
		case 1:
			m_oct1 = val;
			break;
		case 2:
			if (val > 3)
			{
				std::cout << "\nError third oct may be in range [0:3]\n";
			}
			else	m_oct2 = val;
			break;
		
		default:
			std::cout << "\nError. enter pos in range [0:2]\n";
		}
	}
	else {
		
		std::cout << "\nError. first and second oct may be in range [0:7]\n";
		std::cout << "\nAnd third oct may be in range [0:3]\n";
	}
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Hex::Show() const //выводим все шестнадцатеричные цифры 
{
	std::cout << std::endl;

	std::cout << "0x";
	std::cout << static_cast<int>(m_hex1);
	std::cout << static_cast<int>(m_hex0);
	
	std::cout << std::endl;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Hex::ShowPos(int pos) const //выводим цифру в позиции 
{
	std::cout << std::endl;
	switch (pos)
	{
	case 0:
		std::cout << static_cast<int>(m_hex0);
		break;
	case 1:
		std::cout << static_cast<int>(m_hex1);
		break;
	default:
		std::cout << "\nError. enter pos: 0 or 1\n";
	}
	std::cout << std::endl;
}

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

void Hex::Edit(int pos, int val) //изменяем цифру в позиции
{
	if (val >= 0 && val < 15)
	{
		switch (pos)
		{
		case 0:
			m_hex0 = val;
			break;
		case 1:
			m_hex1 = val;
			break;
		default:
			std::cout << "\nError. enter pos 0 or 1\n";
		}
	}
	else {

		std::cout << "\nError. val may be in range [0:15]\n";
		}
}