#pragma once
#include "safety/md5.h"
class Database {
private:
	int id;
	string email;
	string name;
	string hashPassword;

public:
	Database() {}
	Database(string name, string email, string hashPassword) :
		name{ name }, email{ email }, hashPassword{ hashPassword } {}

	~Database() {}
	string getHashPassword() const {
		return hashPassword;
	}
	void setHashPassword(const string& password) {
		hashPassword = password;
	}
	void InputData() {
		string inputEmail, inputName, inputPassword;
		cout << "\nEnter name, email, password: \n";
		cin >> inputName >> inputEmail >> inputPassword;
		this->email = inputEmail;
		this->name = inputName;
		this->hashPassword = MD5(inputPassword);
		transform(this->hashPassword.begin(), this->hashPassword.end(), this->hashPassword.begin(), ::tolower);

	}
	void PrintData() const {
		cout << "\nName user: " << name << "\nEmail: " << email << "\nPassword: " << hashPassword;
	}

};