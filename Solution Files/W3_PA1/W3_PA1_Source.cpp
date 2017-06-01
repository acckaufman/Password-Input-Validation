//This program validates a password entered by the user.
//It confirms that the password is at least 6 characters in length,
//contains at least one uppercase and one lowercase letter, and
//includes at least one digit.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Function prototype
void validatePassword(char[], int);

bool valid = true;	//Here we assume that the password is valid by default, unless one of the requirements isn't met.

int main()
{
	//The instructions state that this program is part of a larger program.
	//As such, no introductory message is included.

	do {
		//Define variables.
		char *ptr = nullptr;
		string strPassword;
		int passwordSize;

		//Edit by instructor: must reset valid each time the loop completes
		valid = true;

		//State the password requirements.
		cout << endl << "Password must be at least 6 characters in length," << endl
			<< "contain at least one uppercase and one lowercase letter," << endl
			<< "and include at least one digit (0-9)." << endl << endl;

		//Get the password from the user.
		cout << "Please enter a password now, then press [Enter]: ";
		getline(cin, strPassword);

		//Determine how long the password was that the user entered.
		passwordSize = strPassword.length();

		//For testing purposes only:
		cout << endl << "The password you entered is: " << strPassword << endl << endl;
		//cout << "Password length is " << passwordSize << " characters" << endl;

		//Dynamically allocate an array that is the size of the password entered, plus 1 for the null terminator
		ptr = new char[passwordSize + 1];

		//Copy the password string to the character array for use in the validation function.
		for (int count = 0; count < passwordSize; count++)
		{
			*(ptr + count) = strPassword[count];
		}
		*(ptr + passwordSize) = '\0';	//Edit by instructor: tag to end of array

		//For testing purposes only
		//cout << "The copied password is ";
		//for (int index = 0; index < passwordSize; index++)
		//	cout << *(ptr + index);
		//cout << endl;

		//Validate password
		validatePassword(ptr, passwordSize);

	} while (valid == false);

	cout << "Congratulations, you have entered a valid password." << endl << endl;
	system("pause");	//Edit by instructor: hold the program window open

	return 0;
}

void validatePassword(char array[], int passwordSize)	//Edit by instructor: added password size to the function
{
	const int MIN_LENGTH = 6;	//Minimum password length
	int count = 0;				//Accumulator for the number of characters entered
	int upperTotal = 0;			//Accumulator for the number of uppercase letters in the password
	int lowerTotal = 0;			//Accumulator for the number of lowercase letters in the password
	int digitTotal = 0;			//Accumulator for the number of digits in the password

	while (array[count] != '\0')
	{
		//for ( ; ; count++)
		//{
			if (isupper(array[count]))
				upperTotal++;
			if (islower(array[count]))
				lowerTotal++;
			if (isdigit(wchar_t(array[count])))		//Edit by instructor: static cast the characters into digit format
				digitTotal++;

			count++;		//Edit by instructor: no for loop needed
		//}
	}

	//For debugging purposes only:
	//cout << endl << endl << "Upper Total is " << upperTotal << endl << "Lower Total is " << lowerTotal << endl << "Digit Total is " << digitTotal << endl << endl;
	//cout << "Press a key to continue...";
	//char c;
	//cin.get(c);
	//cin.ignore();

	if (passwordSize < MIN_LENGTH)	//Correction by instructor: need to use passwordSize and not count (will be 1 less)
	{
		valid = false;
		cout << "Error! You must enter a password of at least 6 digits." << endl;
	}
	if (upperTotal == 0)
	{
		valid = false;
		cout << "Error! Your password must include at least one uppercase letter." << endl;
	}
	if (lowerTotal == 0)
	{
		valid = false;
		cout << "Error! Your password must include at least one lowercase letter." << endl;
	}
	if (digitTotal == 0)
	{
		valid = false;
		cout << "Error! Your password must include at least one digit." << endl;
	}
}