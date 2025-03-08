#include "Database.h"
#include "Users.h"
int main() {
	Database user1("Artem", "argfgdhj@gmail.com", "6654123");
	Database user2("Vlad", "gfjha123@gmail.com", "ghbjaj23");
	Database user3;
	user3.InputData();
	Users users = { user1, user2, user3 };
	users.GetUsers();
}