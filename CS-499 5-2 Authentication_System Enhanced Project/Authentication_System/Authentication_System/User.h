#ifndef User_H
#define User_H
#include <string>
#include "CRUD.h"
#include "crypt.h"



class User {
private:
	//user account data imported from db
	std::string accType;
	std::string username;
	std::string salt;

	//creating crud and sha256 class instances
	CRUD crud;
	crypt crypt;

	//varifies password
	bool authPass(std::string newPassHash);

	//populates user object
	void popUser(std::string userInput);

public:
	//returns account type for currently populated account
	std::string getAccType();

	//varifies and user credentials
	bool authUser(std::string credName, std::string credPass);

	//creates new user account
	bool createAcc(
		std::string username,
		std::string password,
		std::string accType
	);

	//clears user object values
	void clear();
};

#endif