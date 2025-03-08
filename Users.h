#pragma once

#include <string>
#include <map>
#include <list>
#include "Database.h"

struct Users {
	map<int, Database>users;
	Users() {}
	Users(const map<int, Database>users) : users{ users } {}

	Users(const initializer_list<Database>& userList) {
		int id = 1;
		for (const auto& user : userList) {
			users[id++] = user;
		}
	}

	void GetUsers() {


		for (auto& it : users) {
			if (!it.second.getHashPassword().empty()) {
				string hashedPassword = MD5(it.second.getHashPassword());
				transform(hashedPassword.begin(), hashedPassword.end(), hashedPassword.begin(), ::tolower);
				if (it.second.getHashPassword() != hashedPassword) {
					it.second.setHashPassword(hashedPassword);
				}
				cout << "\nUser ID: " << it.first << endl;
				it.second.PrintData();
				cout << endl;
			}

		}

	}

};