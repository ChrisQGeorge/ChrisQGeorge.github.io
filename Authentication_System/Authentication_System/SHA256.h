#ifndef SHA256_H
#define SHA256_H
#include <string>

class SHA256{
public:
	//hashes password using SHA256
	std::string digestPass(std::string password, std::string salt);

	//generates random salt using OS entropy
	std::string generateSalt();
};
#endif
