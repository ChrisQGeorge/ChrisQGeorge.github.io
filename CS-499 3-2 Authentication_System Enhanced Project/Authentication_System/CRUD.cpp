#include "CRUD.h"
/*
	This file contains credential data for testing purposes without a database.
	When a database is implemented, this file will send queries to the database as requested.
*/

void CRUD::initializeTest() {
	if (initialized != true) {
		passHashTest = "37268335DD6931045BDCDF92623FF819A64244B53D0E746D438797349D4DA578";
		usernameTest = "test";
		passSaltTest = "test";
		accTypeTest = "admin";
		initialized = true;
	}

	return;
}

std::string CRUD::getPassHash(std::string username) {
	initializeTest();
	return passHashTest;
}

std::string CRUD::getSalt(std::string username) {
	initializeTest();
	return passSaltTest;
}

std::string CRUD::getAccType(std::string username) {
	initializeTest();
	return accTypeTest;
}

bool CRUD::readUser(std::string name) {
	initializeTest();

	bool result = (name == usernameTest);

	return result;
}

bool CRUD::createUser(
	std::string username,
	std::string passHash,
	std::string salt,
	std::string accType){
	initializeTest();
	if (username != usernameTest) {
		return true;
	}
	return false;
}