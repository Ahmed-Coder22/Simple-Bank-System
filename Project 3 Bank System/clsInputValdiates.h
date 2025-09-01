#pragma once
#include <iostream>

#include <string>
using namespace std;
#include "clsString.h"
template <class T>
class clsInputValidate
{
public:
	static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static T ReadNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber();
		}
		return Number;
	}
	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

};

