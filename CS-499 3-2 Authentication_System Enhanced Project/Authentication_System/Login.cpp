#include <iostream>
#include "Login.h"
#include "User.h"
#include "cryptoPP/cryptlib.h"
#include "cryptoPP/modes.h"


bool Login::run() {
	User user;
	isAdmin = false;
	std::string username;
	std::string password;
	std::string userInput;
	int attempts = 3;

	//clears user object
	user.clear();

	//runs while login attempts remaining is greater then 0
	while (attempts > 0) {
		//prompt for username and password
		std::cout << "Please enter username:";
		std::cin >> username;
		std::cout << "Please enter password:";
		std::cin >> password;
		std::cout << "\n";

		//validates username and password and returns a confirmation bool
		if (user.authUser(username, password)) {
			//clears password string
			CryptoPP::memset_z(&password[0], 0, password.size());

			//login confirmation and data retreival
			std::cout << "Successful Login\n";

			//gets and displays user type in message
			std::cout << "Welcome " << user.getAccType() << "!\n\n";

			if (user.getAccType() == "admin") { isAdmin = true; }

			//clears user object
			user.clear();
			return true;
		}
		//clears password string
		CryptoPP::memset_z(&password[0], 0, password.size());

		//subtract 1 attempt on failed login attempt
		attempts--;

		//prompts user to quit or try to login again
		std::cout << "Incorrect username, \n" << attempts << " attempts remain before lockout.\n\n";
		if (attempts != 0) {
			std::cout << "Press Q to quit or any other key to try again.\n";
			std::cin >> userInput;
		}
		//quits program
		if (userInput == "q" || userInput == "Q") {
			return false;
		}

	}

	//display message of user runs out of login attempts
	if (attempts == 0) {
		std::cout << "No more attempts remain.\n";
	}
	//clears user object
	user.clear();
	return false;
	
}
