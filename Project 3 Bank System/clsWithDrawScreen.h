#pragma once
#include <iostream>
#include"clsString.h"
#include"clsPerson.h"
#include <fstream>
#include"clsScreen.h"
#include"clsTransaction.h"
using namespace std;

class clsWithDrawScreen
{
public :
	static void WithDraw()
	{
        clsScreen::_DrawScreenHeader("WithDraw Screen");
        string AccountNumber = "";
        cout << "Please Enter Client Account Number ? ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        Client1.Print();
        double Number = 0;
        cout << "Please Enter Withraw amonut ? ";
        Number = clsInputValidate<double>::ReadNumber();
        do
        {
            if (Number > Client1.AccountBalance)
            {
                cout << "Please Enter Correct Withraw  ? ";
                Number = clsInputValidate<double>::ReadNumber();

            }
        } while (Number > Client1.AccountBalance);

        string Ansewr = "";
        cout << "Are you sure want to perform this transactions ? y/n ";
        Ansewr = clsInputValidate<string>::ReadString();
        if (Ansewr == "y" || Ansewr == "Y")
        {
            Client1.WithDraw(Number);
            cout << "WithDraw  was Done \n";
            cout << "New Balance = " << Client1.GetAccountBalance() << endl;
        }
        else
        {
            cout << "operations was canceled\n";
        }

	}
};

