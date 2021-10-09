#ifndef Register_H
#define Register_H
#include "User.h"

class Register {
private:
	User user;
	//registers a user with admin privlages
	bool registerAdmin();
public:
	//runs register screen. Returns true if attempt is successful and false otherwise
	bool run();
};

#endif