#ifndef CRYPT_H
#define CRYPT_H
#include <string>

class crypt{
public:
	//hashes password using SHA256
	std::string digestPass(std::string password, std::string salt);

	//generates random salt using OS entropy
	std::string generateSalt();
};
#endif
