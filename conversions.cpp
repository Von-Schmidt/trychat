#include <iostream>
#include <string>
#include "conversions.h"

char BinToHex(std::string bin)
{
	if (bin == "0000")
	{
		return '0';
	}
	else if (bin == "0001")
	{
		return '1';
	}
	else if (bin == "0010")
	{
		return '2';
	}
	else if (bin == "0011")
	{
		return '3';
	}
	else if (bin == "0100")
	{
		return '4';
	}
	else if (bin == "0101")
	{
		return '5';
	}
	else if (bin == "0110")
	{
		return '6';
	}
	else if (bin == "0111")
	{
		return '7';
	}
	else if (bin == "1000")
	{
		return '8';
	}
	else if (bin == "1001")
	{
		return '9';
	}
	else if (bin == "1010")
	{
		return 'a';
	}
	else if (bin == "1011")
	{
		return 'b';
	}
	else if (bin == "1100")
	{
		return 'c';
	}
	else if (bin == "1101")
	{
		return 'd';
	}
	else if (bin == "1110")
	{
		return 'e';
	}
	else if (bin == "1111")
	{
		return 'f';
	}
	else
	{
		return '\0';
	}
}

std::string HexToBin(char hex)
{
	char bin = hex;

	if (bin == '0')
	{
		return "0000";
	}
	else if (bin == '1')
	{
		return "0001";
	}
	else if (bin == '2')
	{
		return "0010";
	}
	else if (bin == '3')
	{
		return "0011";
	}
	else if (bin == '4')
	{
		return "0100";
	}
	else if (bin == '5')
	{
		return "0101";
	}
	else if (bin == '6')
	{
		return "0110";
	}
	else if (bin == '7')
	{
		return "0111";
	}
	else if (bin == '8')
	{
		return "1000";
	}
	else if (bin == '9')
	{
		return "1001";
	}
	else if (bin == 'a')
	{
		return "1010";
	}
	else if (bin == 'b')
	{
		return "1011";
	}
	else if (bin == 'c')
	{
		return "1100";
	}
	else if (bin == 'd')
	{
		return "1101";
	}
	else if (bin == 'e')
	{
		return "1110";
	}
	else if (bin == 'f')
	{
		return "1111";
	}
	else
	{
		return "";
	}
}

std::string CharToHex(char character)
{
	std::string result;

	if (character == 'a')
	{
		result = "00";
	}
	else if (character == 'b')
	{
		result = "01";
	}
	else if (character == 'c')
	{
		result = "02";
	}
	else if (character == 'd')
	{
		result = "03";
	}
	else if (character == 'e')
	{
		result = "04";
	}
	else if (character == 'f')
	{
		result = "05";
	}
	else if (character == 'g')
	{
		result = "06";
	}
	else if (character == 'h')
	{
		result = "07";
	}
	else if (character == 'i')
	{
		result = "08";
	}
	else if (character == 'j')
	{
		result = "09";
	}
	else if (character == 'k')
	{
		result = "0a";
	}
	else if (character == 'l')
	{
		result = "0b";
	}
	else if (character == 'm')
	{
		result = "0c";
	}
	else if (character == 'n')
	{
		result = "0d";
	}
	else if (character == 'o')
	{
		result = "0e";
	}
	else if (character == 'p')
	{
		result = "0f";
	}
	else if (character == 'q')
	{
		result = "10";
	}
	else if (character == 'r')
	{
		result = "11";
	}
	else if (character == 's')
	{
		result = "12";
	}
	else if (character == 't')
	{
		result = "13";
	}
	else if (character == 'u')
	{
		result = "14";
	}
	else if (character == 'v')
	{
		result = "15";
	}
	else if (character == 'w')
	{
		result = "16";
	}
	else if (character == 'x')
	{
		result = "17";
	}
	else if (character == 'y')
	{
		result = "18";
	}
	else if (character == 'z')
	{
		result = "19";
	}
	else if (character == 'A')
	{
		result = "1a";
	}
	else if (character == 'B')
	{
		result = "1b";
	}
	else if (character == 'C')
	{
		result = "1c";
	}
	else if (character == 'D')
	{
		result = "1d";
	}
	else if (character == 'E')
	{
		result = "1e";
	}
	else if (character == 'F')
	{
		result = "1f";
	}
	else if (character == 'G')
	{
		result = "20";
	}
	else if (character == 'H')
	{
		result = "21";
	}
	else if (character == 'I')
	{
		result = "22";
	}
	else if (character == 'J')
	{
		result = "23";
	}
	else if (character == 'K')
	{
		result = "24";
	}
	else if (character == 'L')
	{
		result = "25";
	}
	else if (character == 'M')
	{
		result = "26";
	}
	else if (character == 'N')
	{
		result = "27";
	}
	else if (character == 'O')
	{
		result = "28";
	}
	else if (character == 'P')
	{
		result = "29";
	}
	else if (character == 'Q')
	{
		result = "2a";
	}
	else if (character == 'R')
	{
		result = "2b";
	}
	else if (character == 'S')
	{
		result = "2c";
	}
	else if (character == 'T')
	{
		result = "2d";
	}
	else if (character == 'U')
	{
		result = "2e";
	}
	else if (character == 'V')
	{
		result = "2f";
	}
	else if (character == 'W')
	{
		result = "30";
	}
	else if (character == 'X')
	{
		result = "31";
	}
	else if (character == 'Y')
	{
		result = "32";
	}
	else if (character == 'Z')
	{
		result = "33";
	}
	else if (character == '0')
	{
		result = "34";
	}
	else if (character == '1')
	{
		result = "35";
	}
	else if (character == '2')
	{
		result = "36";
	}
	else if (character == '3')
	{
		result = "37";
	}
	else if (character == '4')
	{
		result = "38";
	}
	else if (character == '5')
	{
		result = "39";
	}
	else if (character == '6')
	{
		result = "3a";
	}
	else if (character == '7')
	{
		result = "3b";
	}
	else if (character == '8')
	{
		result = "3c";
	}
	else if (character == '9')
	{
		result = "3d";
	}
	else if (character == ',')
	{
		result = "3e";
	}
	else if (character == '.')
	{
		result = "3f";
	}
	else if (character == '/')
	{
		result = "40";
	}
	else if (character == ';')
	{
		result = "41";
	}
	else if (character == '\'')
	{
		result = "42";
	}
	else if (character == '#')
	{
		result = "43";
	}
	else if (character == '[')
	{
		result = "44";
	}
	else if (character == ']')
	{
		result = "45";
	}
	else if (character == '-')
	{
		result = "46";
	}
	else if (character == '=')
	{
		result = "47";
	}
	else if (character == '<')
	{
		result = "48";
	}
	else if (character == '>')
	{
		result = "49";
	}
	else if (character == '?')
	{
		result = "4a";
	}
	else if (character == ':')
	{
		result = "4b";
	}
	else if (character == '@')
	{
		result = "4c";
	}
	else if (character == '~')
	{
		result = "4d";
	}
	else if (character == '{')
	{
		result = "4e";
	}
	else if (character == '}')
	{
		result = "4f";
	}
	else if (character == '_')
	{
		result = "50";
	}
	else if (character == '+')
	{
		result = "51";
	}
	else if (character == '!')
	{
		result = "52";
	}
	else if (character == '"')
	{
		result = "53";
	}
	else if (character == '$')
	{
		result = "55";
	}
	else if (character == '%')
	{
		result = "56";
	}
	else if (character == '^')
	{
		result = "57";
	}
	else if (character == '&')
	{
		result = "58";
	}
	else if (character == '*')
	{
		result = "59";
	}
	else if (character == '(')
	{
		result = "5a";
	}
	else if (character == ')')
	{
		result = "5b";
	}
	else if (character == '`')
	{
		result = "5c";
	}
	else if (character == '\\')
	{
		result = "5e";
	}
	else if (character == '|')
	{
		result = "5f";
	}
	else if (character == ' ')
	{
		result = "6e";
	}
	else
	{
		result = "70";
	}

	return result;
}


char HexToChar(std::string hex)
{
	std::string character = hex;
	char result;

	if (character == "00")
	{
		result = 'a';
	}
	else if (character == "01")
	{
		result = 'b';
	}
	else if (character == "02")
	{
		result = 'c';
	}
	else if (character == "03")
	{
		result = 'd';
	}
	else if (character == "04")
	{
		result = 'e';
	}
	else if (character == "05")
	{
		result = 'f';
	}
	else if (character == "06")
	{
		result = 'g';
	}
	else if (character == "07")
	{
		result = 'h';
	}
	else if (character == "08")
	{
		result = 'i';
	}
	else if (character == "09")
	{
		result = 'j';
	}
	else if (character == "0a")
	{
		result = 'k';
	}
	else if (character == "0b")
	{
		result = 'l';
	}
	else if (character == "0c")
	{
		result = 'm';
	}
	else if (character == "0d")
	{
		result = 'n';
	}
	else if (character == "0e")
	{
		result = 'o';
	}
	else if (character == "0f")
	{
		result = 'p';
	}
	else if (character == "10")
	{
		result = 'q';
	}
	else if (character == "11")
	{
		result = 'r';
	}
	else if (character == "12")
	{
		result = 's';
	}
	else if (character == "13")
	{
		result = 't';
	}
	else if (character == "14")
	{
		result = 'u';
	}
	else if (character == "15")
	{
		result = 'v';
	}
	else if (character == "16")
	{
		result = 'w';
	}
	else if (character == "17")
	{
		result = 'x';
	}
	else if (character == "18")
	{
		result = 'y';
	}
	else if (character == "19")
	{
		result = 'z';
	}
	else if (character == "1a")
	{
		result = 'A';
	}
	else if (character == "1b")
	{
		result = 'B';
	}
	else if (character == "1c")
	{
		result = 'C';
	}
	else if (character == "1d")
	{
		result = 'D';
	}
	else if (character == "1e")
	{
		result = 'E';
	}
	else if (character == "1f")
	{
		result = 'F';
	}
	else if (character == "20")
	{
		result = 'G';
	}
	else if (character == "21")
	{
		result = 'H';
	}
	else if (character == "22")
	{
		result = 'I';
	}
	else if (character == "23")
	{
		result = 'J';
	}
	else if (character == "24")
	{
		result = 'K';
	}
	else if (character == "25")
	{
		result = 'L';
	}
	else if (character == "26")
	{
		result = 'M';
	}
	else if (character == "27")
	{
		result = 'N';
	}
	else if (character == "28")
	{
		result = 'O';
	}
	else if (character == "29")
	{
		result = 'P';
	}
	else if (character == "2a")
	{
		result = 'Q';
	}
	else if (character == "2b")
	{
		result = 'R';
	}
	else if (character == "2c")
	{
		result = 'S';
	}
	else if (character == "2d")
	{
		result = 'T';
	}
	else if (character == "2e")
	{
		result = 'U';
	}
	else if (character == "2f")
	{
		result = 'V';
	}
	else if (character == "30")
	{
		result = 'W';
	}
	else if (character == "31")
	{
		result = 'X';
	}
	else if (character == "32")
	{
		result = 'Y';
	}
	else if (character == "33")
	{
		result = 'Z';
	}
	else if (character == "34")
	{
		result = '0';
	}
	else if (character == "35")
	{
		result = '1';
	}
	else if (character == "36")
	{
		result = '2';
	}
	else if (character == "37")
	{
		result = '3';
	}
	else if (character == "38")
	{
		result = '4';
	}
	else if (character == "39")
	{
		result = '5';
	}
	else if (character == "3a")
	{
		result = '6';
	}
	else if (character == "3b")
	{
		result = '7';
	}
	else if (character == "3c")
	{
		result = '8';
	}
	else if (character == "3d")
	{
		result = '9';
	}
	else if (character == "3e")
	{
		result = ',';
	}
	else if (character == "3f")
	{
		result = '.';
	}
	else if (character == "40")
	{
		result = '/';
	}
	else if (character == "41")
	{
		result = ';';
	}
	else if (character == "42")
	{
		result = '\'';
	}
	else if (character == "43")
	{
		result = '#';
	}
	else if (character == "44")
	{
		result = '[';
	}
	else if (character == "45")
	{
		result = ']';
	}
	else if (character == "46")
	{
		result = '-';
	}
	else if (character == "47")
	{
		result = '=';
	}
	else if (character == "48")
	{
		result = '<';
	}
	else if (character == "49")
	{
		result = '>';
	}
	else if (character == "4a")
	{
		result = '?';
	}
	else if (character == "4b")
	{
		result = ':';
	}
	else if (character == "4c")
	{
		result = '"';
	}
	else if (character == "4d")
	{
		result = '~';
	}
	else if (character == "4e")
	{
		result = '{';
	}
	else if (character == "4f")
	{
		result = '}';
	}
	else if (character == "50")
	{
		result = '_';
	}
	else if (character == "51")
	{
		result = '+';
	}
	else if (character == "52")
	{
		result = '!';
	}
	else if (character == "53")
	{
		result = '"';
	}
	else if (character == "55")
	{
		result = '$';
	}
	else if (character == "56")
	{
		result = '%';
	}
	else if (character == "57")
	{
		result = '^';
	}
	else if (character == "58")
	{
		result = '&';
	}
	else if (character == "59")
	{
		result = '*';
	}
	else if (character == "5a")
	{
		result = '(';
	}
	else if (character == "5b")
	{
		result = ')';
	}
	else if (character == "5c")
	{
		result = '`';
	}
	else if (character == "5e")
	{
		result = '\\';
	}
	else if (character == "5f")
	{
		result = '|';
	}
	else if (character == "6e")
	{
		result = ' ';
	}
	else
	{
		result = '\0';
	}

	return result;
}
