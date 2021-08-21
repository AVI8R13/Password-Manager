#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class loginManager
{
	public:
		
		loginManager()
		{
			accessGranted = 0;
		}
		void login()
		{
			cout << "Enter your username.\nUsername: ";
			cin >> usernameAttempt;

			username = getFile("usernames.txt");

			if (usernameAttempt == username)
			{
				cout << "Password: ";
				cin >> passwordAttempt;

				password = getFile("passwords.txt");

				if (passwordAttempt == password)
				{
					cout << "Logged in!\n \nPress any button...";
				}
			}
		}
		string getFile(const char* p_fileName)
		{
			string line;
			fstream file;

			file.open(p_fileName, ios::in);
			if (file.is_open())
			{
				getline(file, line);
			}

			file.close();

			return line;
		}

	private:
		string usernameAttempt;
		string passwordAttempt;
		string password = "password";
		string username = "user@email.com";
		bool accessGranted;
};

int main()
{
	loginManager app;
	app.login();

	cin.get();
}