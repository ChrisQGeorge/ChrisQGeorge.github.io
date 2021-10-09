#include "CRUD.h"
#include <cstdint>
#include <iostream>
#include <vector>
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

mongocxx::instance instance{};

mongocxx::uri uri("mongodb://localhost:27017");
mongocxx::client client(uri);

mongocxx::database db = client["authenticate"];
mongocxx::collection accounts = db["accounts"];

std::string CRUD::getVal(std::string username, std::string attribute) {
	std::string result;
	int i = 0;
	//get documents that match search
	auto foundDoc = accounts.find({ document{} << "username" << username << finalize });;

	for (auto&& singleDoc : foundDoc) {
		bsoncxx::document::element element = singleDoc[attribute];

		bsoncxx::stdx::string_view view = element.get_utf8().value;

		result = std::string(view).c_str();

		i++;
	}
	if (i == 1) {return result;}
	std::cout << "Error: More then one user with the same username found!" << "\n";
	return "";
}


std::string CRUD::getPassHash(std::string username) {
	return getVal(username, "passHash");
}

std::string CRUD::getSalt(std::string username) {
	return getVal(username, "salt");
}

std::string CRUD::getAccType(std::string username) {
	return getVal(username, "accountType");
}

bool CRUD::readUser(std::string name) {
	//queries database for username, returns true if found, false otherwise
	bsoncxx::stdx::optional<bsoncxx::document::value> query = accounts.find_one({ document{} << "username" << name << finalize });
	if (query) {
		return true;
	}
	return false;
}

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
	
	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value newDoc = builder
		<< "username"    << username
		<< "accountType" << accType
		<< "passHash"    << passHash
		<< "salt"        << salt
		<< bsoncxx::builder::stream::finalize;
	bsoncxx::stdx::optional<mongocxx::result::insert_one> result = accounts.insert_one(newDoc.view());

	if (result) {
		return true;
	}
	return false;
}