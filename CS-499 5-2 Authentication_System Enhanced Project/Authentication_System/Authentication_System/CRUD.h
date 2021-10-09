#ifndef CRUD_H
#define CRUD_H
#include <string>
class CRUD {
private:
	std::string getVal(std::string username, std::string attribute);

public:
	//returns pasword hash for account with username
	std::string getPassHash(std::string username);

	//returns salt for account with username
	std::string getSalt(std::string username);

	//returns account type for account with username
	std::string getAccType(std::string username);

	//tries to find user in db and returns a false on fail and true on success
	bool readUser(std::string name);

	//creates user and sends new user data to database
	bool createUser(
		std::string username,
		std::string passHash,
		std::string salt,
		std::string accType
	);
};
#endif