#include "User.h"
#include "crypt.h"
#include "CRUD.h"
#include "cryptoPP/cryptlib.h"
#include "cryptoPP/modes.h"
#include <string>

//returns account type user or admin
std::string User::getAccType() {
	return accType;
}

//authenticates user login attempt
bool User::authUser(std::string credName, std::string credPass) {
	std::string credPassHash;

	//if username exists in database, populate user object
	if (crud.readUser(credName)) {
		popUser(credName);

		//hash user given password with salt for authentication
		credPassHash = crypt.digestPass(credPass, salt);

		//clears credPass string 
		CryptoPP::memset_z(&credPass[0], 0, credPass.size());

		//authenticates password and returs a validation bool
		if (authPass(credPassHash)){
			return true;
		}
	}
	
	//authentication attempt fail, return false bool
	return false;
}

//varifies user password hash against old password hash for account
bool User::authPass(std::string newPassHash) {
	//gets old password hash from database for the given username
	std::string oldPassHash = crud.getPassHash(username);

	//compares new hash and old hash, returns validation bool
	if (oldPassHash == newPassHash) {
		return true;
	}

	//password hash incorrect, return false
	return false;
}

//creates new db account entry
bool User::createAcc(std::string username, std::string password,std::string accType) {
	std::string newSalt = crypt.generateSalt();
	std::string newPassHash = crypt.digestPass(password, newSalt);

	//clears credPass string 
	CryptoPP::memset_z(&password[0], 0, password.size());

	//Sends credentials to CRUD class and database to create new user entry
	if (crud.createUser(username, newPassHash, newSalt, accType)) {
		//returns true if user is succesfuly added to database
		return true;
	}
	//returns false if user added to database already exists
	return false;
}

//populates user object with data from database given a particular username
void User::popUser(std::string credUser){
	username = credUser;
	accType = crud.getAccType(username);
	salt = crud.getSalt(username);
}

//sets private variables back to defaults
void User::clear(){
	accType = "";
	username = "";
	salt = "";
}


