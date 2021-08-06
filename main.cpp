#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

class loginManager
{
public:
	
	loginManager()
	{
		accessGranted = false;
	}
	void login()
	{
		cout << "Enter your username and password.\nUsername: ";
		cin >> usernameAttempt;

		username = getFile("username.dat");

		if (usernameAttempt == username)
		{
			cout << "Password: ";
			cin >> passwordAttempt;

			password = getFile("passwords.dat");

			if (passwordAttempt == password)
			{
				cout << "Logged in!";
				cin.get();
			}
			else
			{
				cout << "Incorrect password\n";
				login();
			}
		}
		else
		{
			cout << "Incorrect username\n";
			login();

		}
	}
	string getFile(const char* p_fileName)
	{
		
		string line;
		fstream file;

		int eChar;

		file.open(p_fileName, ios::in);
		while(1)
		{
			file >> eChar;
			if (eChar == 0)
			{
				file.close();
				return line;
			}
			line += (char)decrypt(eChar);
		}
		file.close();

		return line;
	}

	void saveFile(string p_line, const char* p_fileName)
	{

		fstream file;
		file.open(p_fileName, ios::out);

		for (int i = 0; i < p_line.length(); i++)
		{
			file << encrypt (p_line[i]);
			file << "\n";
		}

		file << "0";
		file.close();

	}

	int encrypt(int p_letter)
	{

		return powf(p_letter, 4);

	}

	int decrypt(int p_letter)
	{

		return powf(p_letter, 1/4.f);

	}

	private:
		string password;
		string username;
		string usernameAttempt;
		string passwordAttempt;
		bool accessGranted;
};

int main()
{
	loginManager app;
	app.saveFile("user@email.com","username.dat");
	app.saveFile("password", "passwords.dat");
	app.login();
	cin.get();
}
