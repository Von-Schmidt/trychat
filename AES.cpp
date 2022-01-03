#include <iostream>
#include <string>
#include "conversions.h"
#include "AES.h"
#include <cmath>
#include <vector>


// Function to substitute 4 bits
char CharSubsitution(char charToSub)
{
	char subbedChar = '\0';
	if (charToSub == '0')
	{
		subbedChar = '3';
	}
	else if (charToSub == '1')
	{
		subbedChar = 'c';
	}
	else if (charToSub == '2')
	{
		subbedChar = 'b';
	}
	else if (charToSub == '3')
	{
		subbedChar = '8';
	}
	else if (charToSub == '4')
	{
		subbedChar = '0';
	}
	else if (charToSub == '5')
	{
		subbedChar = '9';
	}
	else if (charToSub == '6')
	{
		subbedChar = '6';
	}
	else if (charToSub == '7')
	{
		subbedChar = 'e';
	}
	else if (charToSub == '8')
	{
		subbedChar = 'f';
	}
	else if (charToSub == '9')
	{
		subbedChar = '1';
	}
	else if (charToSub == 'a')
	{
		subbedChar = '5';
	}
	else if (charToSub == 'b')
	{
		subbedChar = '7';
	}
	else if (charToSub == 'c')
	{
		subbedChar = '2';
	}
	else if (charToSub == 'd')
	{
		subbedChar = 'a';
	}
	else if (charToSub == 'e')
	{
		subbedChar = '4';
	}
	else if (charToSub == 'f')
	{
		subbedChar = 'd';
	}

	return subbedChar;
}


// Function to reverse 4 bit substitution
char ReverseCharSubsitution(char charToSub)
{
	char subbedChar = '\0';
	if (charToSub == '0')
	{
		subbedChar = '4';
	}
	else if (charToSub == '1')
	{
		subbedChar = '9';
	}
	else if (charToSub == '2')
	{
		subbedChar = 'c';
	}
	else if (charToSub == '3')
	{
		subbedChar = '0';
	}
	else if (charToSub == '4')
	{
		subbedChar = 'e';
	}
	else if (charToSub == '5')
	{
		subbedChar = 'a';
	}
	else if (charToSub == '6')
	{
		subbedChar = '6';
	}
	else if (charToSub == '7')
	{
		subbedChar = 'b';
	}
	else if (charToSub == '8')
	{
		subbedChar = '3';
	}
	else if (charToSub == '9')
	{
		subbedChar = '5';
	}
	else if (charToSub == 'a')
	{
		subbedChar = 'd';
	}
	else if (charToSub == 'b')
	{
		subbedChar = '2';
	}
	else if (charToSub == 'c')
	{
		subbedChar = '1';
	}
	else if (charToSub == 'd')
	{
		subbedChar = 'f';
	}
	else if (charToSub == 'e')
	{
		subbedChar = '7';
	}
	else if (charToSub == 'f')
	{
		subbedChar = '8';
	}

	return subbedChar;
}


char XOR(char messageBin, char keyBin)
{
	char outputBin = '\0';
	if ((messageBin == '0' && keyBin == '0') || (messageBin == '1' && keyBin == '1'))
	{
		outputBin = '0';
	}
	else if ((messageBin == '1' && keyBin == '0') || (messageBin == '0' && keyBin == '1'))
	{
		outputBin = '1';
	}

	return outputBin;
}


// The AES encryption itself (not actual AES implementation, thus less secure)
std::string AESEncrypt(std::string message, std::string key)
{
	std::vector<std::string> messageBlocks;
	std::string result = "";

	// Create an array of 32 keywords, 4 bytes each (8 hex characters, 32 bin char)
	std::string keyWords[32];
	std::string keyWord;
	for (int a = 0; a < 32; ++a)
	{
		keyWord = key.substr(0 + 8 * a, 8);

		keyWords[a] = "";

		for (int b = 0; b < 8; b++)
		{
			std::string bin_keyword = HexToBin(keyWord[b]);
			keyWords[a] += bin_keyword;
		}
	}

	// Pad the with bytes
	if (message.length() / 16 != ceil(double(message.length()) / 16.0))
	{
		for (int i = 0; i < ((double(message.length()) / 16.0) - message.length() / 16) * 16; i++)
		{
			message += '0';
		}
	}

	int message_length = int(message.length()) / 16;

	// Divide message string into 16 byte block size
	for (int i = 0; i < message_length; ++i)
	{
		messageBlocks.push_back(message.substr(0 + i * 16, 16));
	}


	// Convert string to hex
	std::vector<std::string> temporaryMessageBlocks;
	for (int a = 0; a < message_length; ++a)
	{
		temporaryMessageBlocks.push_back(messageBlocks[a]);
		messageBlocks.at(a) = "";
	}
	for (int p = 0; p < message_length; ++p)
	{
		for (int q = 0; q < 16; ++q)
		{
			messageBlocks.at(p) += CharToHex(temporaryMessageBlocks.at(p)[q]);
		}
		temporaryMessageBlocks.at(p) = "";
	}


	// Loop through the algorithm for each block
	for (int block_num = 0; block_num < message_length; ++block_num)
	{
		int index = 0;
		std::string AESresult = "";
		std::string temporaryAESArray[4][4];

		// Create the AES 4x4 array
		std::string AESarray[4][4];

		// Fill the AES array
		for (int a = 0; a < 4; ++a)
		{
			for (int b = 0; b < 4; ++b)
			{
				AESarray[b][a] = messageBlocks.at(block_num).substr(index * 2, 2);
				index++;
			}
		}


		// Fill temporary vector
		for (int a = 0; a < 4; ++a)
		{
			for (int b = 0; b < 4; ++b)
			{
				temporaryAESArray[b][a] = AESarray[b][a];
			}
		}
		// Convert string to hex
		for (int a = 0; a < 4; ++a)
		{
			for (int b = 0; b < 4; ++b)
			{
				AESarray[b][a] = CharToHex(AESarray[b][a][0]);
			}
		}

		// Do the AES algorithm rn-1 times
		for (int roundNum = 0; roundNum < 32; ++roundNum)
		{
			// SUBSTITUTION
			// Iterate through array and sub 4 bit blocks
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a][0] = CharSubsitution(AESarray[b][a][0]);
					AESarray[b][a][1] = CharSubsitution(AESarray[b][a][1]);
				}
			}

			// LINE TRANSFORMATIONS
			// Iterate through the AES array and shift rows
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			// Row 2
			AESarray[1][0] = temporaryAESArray[1][1];
			AESarray[1][1] = temporaryAESArray[1][2];
			AESarray[1][2] = temporaryAESArray[1][3];
			AESarray[1][3] = temporaryAESArray[1][0];
			// Row 3
			AESarray[2][0] = temporaryAESArray[2][2];
			AESarray[2][1] = temporaryAESArray[2][3];
			AESarray[2][2] = temporaryAESArray[2][0];
			AESarray[2][3] = temporaryAESArray[2][1];
			// Row 4
			AESarray[3][0] = temporaryAESArray[3][3];
			AESarray[3][1] = temporaryAESArray[3][0];
			AESarray[3][2] = temporaryAESArray[3][1];
			AESarray[3][3] = temporaryAESArray[3][2];

			// SHUFFLE
			// This part differs from the real AES algorithm
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			/*
			0  4  8  12
			1  5  9  13
			2  6  10 14
			3  7  11 15

			6  14 1  8
			3  5  12 4
			9  0  13 11
			2  7  15 10
			*/
			// Row 1
			AESarray[0][0] = temporaryAESArray[2][1];
			AESarray[0][1] = temporaryAESArray[1][3];
			AESarray[0][2] = temporaryAESArray[0][3];
			AESarray[0][3] = temporaryAESArray[1][2];
			// Row 2
			AESarray[1][0] = temporaryAESArray[0][2];
			AESarray[1][1] = temporaryAESArray[1][1];
			AESarray[1][2] = temporaryAESArray[2][0];
			AESarray[1][3] = temporaryAESArray[2][2];
			// Row 3
			AESarray[2][0] = temporaryAESArray[3][0];
			AESarray[2][1] = temporaryAESArray[0][0];
			AESarray[2][2] = temporaryAESArray[3][3];
			AESarray[2][3] = temporaryAESArray[0][1];
			// Row 4
			AESarray[3][0] = temporaryAESArray[1][0];
			AESarray[3][1] = temporaryAESArray[3][1];
			AESarray[3][2] = temporaryAESArray[2][3];
			AESarray[3][3] = temporaryAESArray[3][2];

			// Convert array fields to binary
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a] = HexToBin(temporaryAESArray[b][a][0]);
					AESarray[b][a] += HexToBin(temporaryAESArray[b][a][1]);
				}
			}

			// XOR byte from keyword with column
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				int keyword_index = 8 * a;
				int keyword_num_index;

				for (int b = 0; b < 4; ++b)
				{
					for (int c = 0; c < 8; ++c)
					{
						keyword_num_index = keyword_index + c;

						AESarray[b][a] += XOR(temporaryAESArray[b][a][c], keyWords[roundNum][keyword_num_index]);
					}
				}
			}

			// Convert array fields to HEX
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a] = "";
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a] = BinToHex(temporaryAESArray[b][a].substr(0, 4));
					AESarray[b][a] += BinToHex(temporaryAESArray[b][a].substr(4, 4));
				}
			}
		}
		// Create one long string
		for (int a = 0; a < 4; ++a)
		{
			for (int b = 0; b < 4; ++b)
			{
				AESresult += AESarray[b][a];
			}
		}

		// Append the result to the result string variable
		result += AESresult;
	}

	return result;
}

// The AES decryption itself (not actual AES implementation, thus less secure)
std::string AESDecrypt(std::string message, std::string key)
{
	std::vector<std::string> messageBlocks;
	std::string result = "";

	// Create an array of 32 keywords, 4 bytes each (8 hex characters, 32 bin char)
	std::string keyWords[32];
	std::string keyWord;
	for (int a = 0; a < 32; ++a)
	{
		keyWord = key.substr(0 + 8 * a, 8);

		keyWords[a] = "";

		for (int b = 0; b < 8; b++)
		{
			std::string bin_keyword = HexToBin(keyWord[b]);
			keyWords[a] += bin_keyword;
		}
	}

	// Pad the with bytes
	if (message.length() / 32 != ceil(double(message.length()) / 32.0))
	{
		for (int i = 0; i < ((double(message.length()) / 32.0) - message.length() / 32) * 32; i++)
		{
			message += '0';
		}
	}

	int message_length = int(message.length()) / 32;

	// Divide message string into 128 bit block size
	for (int i = 0; i < message_length; ++i)
	{
		messageBlocks.push_back(message.substr(0 + i * 32, 32));
	}

	// Loop through the algorithm for each block
	for (int block_num = 0; block_num < message_length; ++block_num)
	{
		int index = 0;
		std::string AESresult = "";
		std::string temporaryAESArray[4][4];

		// Create the AES 4x4 array
		std::string AESarray[4][4];

		// Fill the AES array
		for (int a = 0; a < 4; ++a)
		{
			for (int b = 0; b < 4; ++b)
			{
				AESarray[b][a] = messageBlocks.at(block_num).substr(index * 2, 2);
				index++;
			}
		}


		// Do the AES algorithm rn-1 times
		for (int roundNum = 0; roundNum < 32; ++roundNum)
		{
			// Convert array fields to binary
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a] = HexToBin(temporaryAESArray[b][a][0]);
					AESarray[b][a] += HexToBin(temporaryAESArray[b][a][1]);
				}
			}

			// XOR byte from keyword with column
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				int keyword_index = 8 * a;
				int keyword_num_index;

				for (int b = 0; b < 4; ++b)
				{
					for (int c = 0; c < 8; ++c)
					{
						keyword_num_index = keyword_index + c;

						AESarray[b][a] += XOR(temporaryAESArray[b][a][c], keyWords[roundNum][keyword_num_index]);
					}
				}
			}


			// Convert array fields to HEX
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a] = "";
				}
			}
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a] = BinToHex(temporaryAESArray[b][a].substr(0, 4));
					AESarray[b][a] += BinToHex(temporaryAESArray[b][a].substr(4, 4));
				}
			}


			// SHUFFLE
			// This part differs from the real AES algorithm
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			/*
			0  4  8  12
			1  5  9  13
			2  6  10 14
			3  7  11 15

			6  14 1  8
			3  5  12 4
			9  0  13 11
			2  7  15 10

			6  13 12 9
			8  5  2  10
			3  0  15 4
			1  7  14 11
			*/
			// Row 1
			AESarray[0][0] = temporaryAESArray[2][1];
			AESarray[0][1] = temporaryAESArray[2][3];
			AESarray[0][2] = temporaryAESArray[1][0];
			AESarray[0][3] = temporaryAESArray[0][2];
			// Row 2
			AESarray[1][0] = temporaryAESArray[3][0];
			AESarray[1][1] = temporaryAESArray[1][1];
			AESarray[1][2] = temporaryAESArray[0][3];
			AESarray[1][3] = temporaryAESArray[0][1];
			// Row 3
			AESarray[2][0] = temporaryAESArray[1][2];
			AESarray[2][1] = temporaryAESArray[0][0];
			AESarray[2][2] = temporaryAESArray[1][3];
			AESarray[2][3] = temporaryAESArray[3][2];
			// Row 4
			AESarray[3][0] = temporaryAESArray[2][2];
			AESarray[3][1] = temporaryAESArray[3][1];
			AESarray[3][2] = temporaryAESArray[3][3];
			AESarray[3][3] = temporaryAESArray[2][3];



			// LINE TRANSFORMATIONS
			// Iterate through the AES array and shift rows
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					temporaryAESArray[b][a] = AESarray[b][a];
				}
			}
			// Row 2
			AESarray[1][0] = temporaryAESArray[1][3];
			AESarray[1][1] = temporaryAESArray[1][0];
			AESarray[1][2] = temporaryAESArray[1][1];
			AESarray[1][3] = temporaryAESArray[1][2];
			// Row 3
			AESarray[2][0] = temporaryAESArray[2][2];
			AESarray[2][1] = temporaryAESArray[2][3];
			AESarray[2][2] = temporaryAESArray[2][0];
			AESarray[2][3] = temporaryAESArray[2][1];
			// Row 4
			AESarray[3][0] = temporaryAESArray[3][1];
			AESarray[3][1] = temporaryAESArray[3][2];
			AESarray[3][2] = temporaryAESArray[3][3];
			AESarray[3][3] = temporaryAESArray[3][0];


			// SUBSTITUTION
			// Iterate through array and sub 4 bit blocks
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a][0] = CharSubsitution(AESarray[b][a][0]);
					AESarray[b][a][1] = CharSubsitution(AESarray[b][a][1]);
				}
			}
		}

		// Create one long string
		for (int a = 0; a < 4; ++a)
		{
			for (int b = 0; b < 4; ++b)
			{
				AESresult += HexToChar(AESarray[b][a]);
			}
		}
		// Append the result to the result string variable
		result += AESresult;
	}

	return result;
}
