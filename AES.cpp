#pragma once
#include <iostream>
#include <string>
#include "conversions.cpp"


// Function to substitute 4 bits
char CharSubsitution(char charToSub)
{
	char subbedChar = '';
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


char XOR(char messageBin, char keyBin)
{
	char outputBin = '';
	if ((inputBin == '0' && keyBin == '0') || (inputBin == '1' && keyBin == '1'))
	{
		outputBin = '0';
	}
	else if (inputBin == '1' && keyBin == '0')
	{
		outputBin = '1';
	}

	return outputBin;
}


// The AES encryption itself (not actual AES implementation, thus less secure)
std::string AESEncrypt(std::string message, std::string key)
{
	std::string messageBlocks[] = {""};
	std::string result = "";

	// Create an array of 32 keywords, 4 bytes each (8 hex characters)
	std::string keyWords[32];
	for (int i = 0; i < 32; ++i)
	{
		keyWords[i] = key.substr(0 + 8*i, 8);
	}

	// Convert string to hex































	// Divide message string into 128 bit block size
	for (int i = 0; i < ceil(message.length() / 16); ++i)
	{
		messageBlocks[i] = message.substr(0 + i*32, 32);
	}

	// Pad the final block with bytes
	int padBytes = 32 - messageBlocks[-1].length();

	if (padBytes != 0)
	{
		for (int i = 0; i < padBytes; ++i)
		 {
		 	messageBlocks[-1] += '0';
		 } 
	}


	// Loop through the algorithm for each block
	for (int i = 0; i < length_of(messageBlocks); ++i)
	{
		std::string AESresult = "";
		std::string temporaryAESArray[4][4];
		
		// Create the AES 4x4 array
		std::string AESarray[4][4];
		int index = 0;

		// Fill the AES array
		for (int a = 0; a < 4; ++a)
		{
			for (int b = 0; b < 4; ++b)
			{
				AESarray[b][a] = messageBlocks[i].substr(0 + index*2, 2);
				index++; 
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
			temporaryAESArray = AESarray;
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

			// This part differs from the real AES algorithm
			temporaryAESArray = AESarray;
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
			AESarray[3][0] = temporaryAESArray[2][0];
			AESarray[3][1] = temporaryAESArray[3][1];
			AESarray[3][2] = temporaryAESArray[3][3];
			AESarray[3][3] = temporaryAESArray[2][2];


			// Convert array fields to binary
			temporaryAESArray = AESarray;
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					AESarray[b][a] = HexToBin(temporaryAESArray[b][a][0]);
					AESarray[b][a] += HexToBin(temporaryAESArray[b][a][1]);
				}
			}

			// XOR byte from keyword with column
			temporaryAESArray = AESarray;
			for (int a = 0; a < 4; ++a)
			{
				for (int b = 0; b < 4; ++b)
				{
					for (int c = 0; c < 8; ++c)
					{
						AESarray[b][a][c] = XOR(temporaryAESArray[b][a][c], keyWords[roundNum][8*a+c]);
					}
				}
			}

			// Convert array fields to HEX
			temporaryAESArray = AESarray;
			AESarray = {
				{"00", "00", "00", "00"},
				{"00", "00", "00", "00"},
				{"00", "00", "00", "00"}
				{"00", "00", "00", "00"},
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

		// Append the result to the result string variable
		result += AESresult;
	}

	return result;
}
