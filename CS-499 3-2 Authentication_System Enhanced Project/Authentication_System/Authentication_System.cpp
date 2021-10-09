#include <iostream>
#include "Login.h"
#include "Register.h"


void main()
{
    std::string userInput;
    Login login;
    Register newUser;

    //runs program while user input is not q
    while (userInput != "q" && userInput != "Q") {

        //get user command
        std::cout << "Would you like to (L)ogin, (R)egister, or (Q)uit?\n";
        std::cin >> userInput;

        //tries to login user, and exits program if login fails
        if      (userInput == "l" || userInput == "L") { if (!login.run()) { break; } }
        //tries to register user, and exits program if registration fails
        else if (userInput == "r" || userInput == "R") { if (!newUser.run()) { break; } }
        //exits program if user inputs q
        else if (userInput == "q" || userInput == "Q") { break; }
        //default in case of invalid user input
        else {std::cout << "Error: That is not a valid response\n";}

    }

    std::cout << "Exiting\n";
    return;
}


