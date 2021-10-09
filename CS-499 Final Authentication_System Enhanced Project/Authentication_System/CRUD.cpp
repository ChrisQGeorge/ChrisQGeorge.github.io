#include "CRUD.h"
#include <cstdint>
#include <iostream>
#include <vector>

//MongoDB C++ Driver
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;


//Creates new instance of MongoDB connection
mongocxx::instance instance{};

//Connects to MongoDB server with URI connected to localhost
//Can be changed for centralized server connection
mongocxx::uri uri("mongodb://localhost:27017");
mongocxx::client client(uri);

//Gets collection "accounts" from database "authenticate"
mongocxx::database db = client["authenticate"];
mongocxx::collection accounts = db["accounts"];


//Returns some value requested from database
std::string CRUD::getVal(std::string username, std::string attribute) {
	std::string result;
	int i = 0;
	//get documents that match search
	auto foundDoc = accounts.find({ document{} << "username" << username << finalize });;

	//Gets and loops through results to determine if multiple results exist
	for (auto&& singleDoc : foundDoc) {
		//Gets desired value of found document and converts it to an element
		bsoncxx::document::element element = singleDoc[attribute];

		//Converts element to string_view
		bsoncxx::stdx::string_view view = element.get_utf8().value;

		//Returns string from string_view
		result = std::string(view).c_str();

		//Counts number of matching succesful matches
		i++;
	}
	//If only 1 result in database is found, return desired attribute, otherwise display error
	if (i == 1) {return result;}
	std::cout << "Error: More then one user with the same username found!" << "\n";
	return "";
}


//Get password hash from database given a specific username
std::string CRUD::getPassHash(std::string username) {
	return getVal(username, "passHash");
}

//Get salt from database given a specific username
std::string CRUD::getSalt(std::string username) {
	return getVal(username, "salt");
}

//Get account type from database given a specific username
std::string CRUD::getAccType(std::string username) {
	return getVal(username, "accountType");
}

//Checks if username exists in database
bool CRUD::readUser(std::string name) {
	//queries database for username, returns true if found, false otherwise
	bsoncxx::stdx::optional<bsoncxx::document::value> query = accounts.find_one({ document{} << "username" << name << finalize });
	if (query) {
		return true;
	}
	return false;
}

//Creates user with new credentials and inserts the new account into the database
bool CRUD::createUser(
	std::string username,
	std::string passHash,
	std::string salt,
	std::string accType){

	//queries database for username, returns true if found, false otherwise
	bsoncxx::stdx::optional<bsoncxx::document::value> query = accounts.find_one({ document{} << "username" << username << finalize });
	if (query) {
		return false;
	}
	
	//Builds the new document with given credentials.
	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value newDoc = builder
		<< "username"    << username
		<< "accountType" << accType
		<< "passHash"    << passHash
		<< "salt"        << salt
		<< bsoncxx::builder::stream::finalize;

	//Inserts newly created document into database
	bsoncxx::stdx::optional<mongocxx::result::insert_one> result = accounts.insert_one(newDoc.view());

	//Returns true if the database insert was a success, false otherwise
	if (result) {
		return true;
	}
	return false;
}