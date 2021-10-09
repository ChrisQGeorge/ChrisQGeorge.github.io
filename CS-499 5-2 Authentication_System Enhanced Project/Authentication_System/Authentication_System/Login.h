#ifndef Login_H
#define Login_H

class Login {
public:
	//true if logged in user is admin, false otherwise
	bool isAdmin;

	//runs login screen. Returns true if attempt is successful and false otherwise
	bool run();
};
#endif