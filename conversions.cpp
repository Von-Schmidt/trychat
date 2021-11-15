#pragma once
#include <iostream>

string BinToHex(string bin)
{
	if (bin == "0000")
	{
		return "0";
	}
	else if (bin == "0001")
	{
		return "1";
	}
	else if (bin == "0010")
	{
		return "2";
	}
	else if (bin == "0011")
	{
		return "3";
	}
	else if (bin == "0100")
	{
		return "4";
	}
	else if (bin == "0101")
	{
		return "5";
	}
	else if (bin == "0110")
	{
		return "6";
	}
	else if (bin == "0111")
	{
		return "7";
	}
	else if (bin == "1000")
	{
		return "8";
	}
	else if (bin == "1001")
	{
		return "9";
	}
	else if (bin == "1010")
	{
		return "a";
	}
	else if (bin == "1011")
	{
		return "b";
	}
	else if (bin == "1100")
	{
		return "c";
	}
	else if (bin == "1101")
	{
		return "d";
	}
	else if (bin == "1110")
	{
		return "e";
	}
	else if (bin == "1111")
	{
		return "f";
	}
}

string HexToBin(string hex)
{
	if (bin == "0")
	{
		return "0000";
	}
	else if (bin == "1")
	{
		return "0001";
	}
	else if (bin == "2")
	{
		return "0010";
	}
	else if (bin == "3")
	{
		return "0011";
	}
	else if (bin == "4")
	{
		return "0100";
	}
	else if (bin == "5")
	{
		return "0101";
	}
	else if (bin == "6")
	{
		return "0110";
	}
	else if (bin == "7")
	{
		return "0111";
	}
	else if (bin == "8")
	{
		return "1000";
	}
	else if (bin == "9")
	{
		return "1001";
	}
	else if (bin == "a")
	{
		return "1010";
	}
	else if (bin == "b")
	{
		return "1011";
	}
	else if (bin == "c")
	{
		return "1100";
	}
	else if (bin == "d")
	{
		return "1101";
	}
	else if (bin == "e")
	{
		return "1110";
	}
	else if (bin == "f")
	{
		return "1111";
	}	
}

string DecToHex (uint dec)
{
	int divisors[] = {0};

	int remainder = dec;

	int index = 0;

	std::string results;

	while (remainder != 0)
	{
		divisors[index] = remainder % 16;

		remainder = remainder / 16;

		index++;
	}

	for (int i = 1; i <= size_of(divisors); ++i)
	{
		results[i-1] = divisors[-i];
	}

	return results;
}

uint HexToDec (string hex)
{
	uint result = 0;
	char character;
	uint dec;

	for (int i = 0; i < hex.length(); ++i)
	{
		character = hex[-(i + 1)];

		if (character == "0")
		{
			dec = 0;
		}
		else if (character == "1")
		{
			dec = 1;
		}
		else if (character == "2")
		{
			dec = 2;
		} 
		else if (character == "3")
		{
			dec = 3;
		} 
		else if (character == "4")
		{
			dec = 4;
		} 
		else if (character == "5")
		{
			dec = 5;
		} 
		else if (character == "6")
		{
			dec = 6;
		} 
		else if (character == "7")
		{
			dec = 7;
		} 
		else if (character == "8")
		{
			dec = 8;
		} 
		else if (character == "9")
		{
			dec = 9;
		} 
		else if (character == "a")
		{
			dec = 10;
		} 
		else if (character == "b")
		{
			dec = 11;
		} 
		else if (character == "c")
		{
			dec = 12;
		} 
		else if (character == "d")
		{
			dec = 13;
		} 
		else if (character == "e")
		{
			dec = 14;
		} 
		else if (character == "f")
		{
			dec = 15;
		}

		result += dec * (16 ** i);
	}

	return result;
}
