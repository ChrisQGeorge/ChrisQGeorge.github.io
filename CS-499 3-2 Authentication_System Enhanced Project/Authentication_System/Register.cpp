#include <iostream>
#include "Register.h"
#include "Login.h"
#include "User.h"
#include "cryptoPP/cryptlib.h"
#include "cryptoPP/modes.h"



bool Register::run() {
	std::string userInput;
	std::string username;
	std::string password;

	//Inititially clears values in user object
	user.clear();

	//runs while user chooses not to exit program
	while (userInput != "q" || userInput != "Q") {

		//prompts for user registration type (admin or user)
		std::cout << "Would you like to register a new (U)ser, (A)dmin, or (Q)uit the program?\n";
		std::cin >> userInput;

		//if usertype is user
		if (userInput == "u" || userInput == "U") {

			//prompt for new user credentials
			std::cout << "Please enter username:";
			std::cin >> username;
			std::cout << "\n";
			std::cout << "Please enter password:";
			std::cin >> password;
			std::cout << "\n";

			//tries to create new user with usertype "user"
			//returns true if successful and false if not
			if (user.createAcc(username, password, "user")) {
				//clears password variable from memory
				CryptoPP::memset_z(&password[0], 0, password.size());

				//user registration confirmation
				std::cout << "succesfully registered new user!\n";

				//return true if successful
				return true;
			} else {
				//clears password variable from memory
				CryptoPP::memset_z(&password[0], 0, password.size());

				//user registration error message
				std::cout << "Error: Something went wrong\nPlease try again with a different username.\n\n";

				//tries again if not successful
			}

		}
		//if usertype is admin
		else if (userInput == "a" || userInput == "A") {

			//tries to create new user with usertype "admin"
			//returns true if successful and false if not
			if (registerAdmin()) {
				//admin registration confirmation
				std::cout << "succesfully registered new admin!\n";

				//return true if successful
				return true;
			} else {
				//user registration error message
				std::cout << "Error: Something went wrong\nPlease try again with a different username.\n\n";

				//tries again if not successful
			}
		}

		//returns false to quit the program if user chooses to quit
		else if (userInput == "q" || userInput == "Q") {
			return false;
		}
		else { std::cout << "Error: That is not a valid response\n"; }

	}

	//returns false to quit the program
	return false;
}


//tries to register admin
bool Register::registerAdmin() {
	Login login;
	std::string username;
	std::string password;

	//requires a previous admin login to register new admin
	std::cout << "To register a new admin, please loggin with an existing admin account.\n";
	if (login.run()) {
		//checks if login was succesful and account logged into was an admin account
		if (login.isAdmin) {
			//prompt for new admin credentials
			std::cout << "admin login successful, please enter new credentials.\n";
			std::cout << "Please enter username:";
			std::cin >> username;
			std::cout << "Please enter password:";
			std::cin >> password;
			std::cout << "\n";

			//return true if successful
			if (user.createAcc(username, password, "admin")) {
				CryptoPP::memset_z(&password[0], 0, password.size());
				return true;
			}
		}
	}
	//returns false and displays error message if registration not successful
	return false;
}

