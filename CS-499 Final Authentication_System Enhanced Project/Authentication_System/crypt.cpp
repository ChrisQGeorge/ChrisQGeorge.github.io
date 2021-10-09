#include "crypt.h"
#include "sha256.h"
#include <iostream>

static const char alph[] ="0123456789abcdefghijklmnopqrstuvwxyz";
int alphLen = sizeof(alph) - 1;


//digests password and salt with SHA256 hashing algorithm and returs hash string in hexidecimal
std::string crypt::digestPass(std::string password, std::string salt) {
    //Create SHA256 instance
    SHA256 sha256;

    //hash salted password
    std::string result = sha256(password + salt);

    //clears password variable
    password.clear();

    return result;
};

//generates random salt with inharent randomness in the hosted computer
std::string crypt::generateSalt() {
    std::string salt;
    SHA256 sha256;

    //appends random character to string
    for (int i = 0; i < 64; i++) {
        salt.push_back(alph[rand() % alphLen]);
    }

    //hash salt to add randomness and to convert to hex
    salt = sha256(salt);

    return salt;

}
