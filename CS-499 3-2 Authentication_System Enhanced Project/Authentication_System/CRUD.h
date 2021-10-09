#ifndef CRUD_H
#define CRUD_H
#include <string>
class CRUD {
private:
	//test variables to simulate database
	std::string passHashTest;
	std::string usernameTest;
	std::string passSaltTest;
	std::string accTypeTest;

	//initialize test variables with a initilization bool
	bool initialized;
	void initializeTest();
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