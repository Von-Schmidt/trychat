#include <iostream>
#include "AES.h"

int main()
{
	std::string key = "bd45f32a6592c492bd4d36a6e64ae25b783e63c363d1bd20dc8e9b26abc2f8a5e29d9d537bf85d9495b75668f65986a026cb2582219ba2a4b30467f16bbf691013bfb04ef5ed54a1f988ddd5b0f541ddefe91b5daa2208b03ece296e17a399b927ee93f0c60ed1700ab094148f8218311775a28eceaa64eab7175fa2d1e57af6";
	std::string msg = "0000";

	std::string encrypted = AESEncrypt(msg, key);
	std::string decrypted = AESDecrypt(encrypted, key);

	std::cout << encrypted << "\n" << "\n";
	std::cout << decrypted << "\n";


	return 0;
}
