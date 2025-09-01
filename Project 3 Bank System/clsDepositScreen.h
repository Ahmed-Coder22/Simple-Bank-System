#pragma once
#include <iostream>
#include"clsString.h"
#include"clsPerson.h"
#include <fstream>
#include"clsScreen.h"
#include"clsTransaction.h"
using namespace std;

class clsDepositScreen :public clsScreen
{
public :
	static void DepositScreen()
	{
        clsScreen::_DrawScreenHeader("Deposit Screen");
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
        cout << "Please Enter Deposit amonut ? ";
       Number = clsInputValidate<double>::ReadNumber();
      
      
       string Ansewr = "";
       cout << "Are you sure want to perform this transactions ? y/n ";
       Ansewr = clsInputValidate<string>::ReadString();
       if (Ansewr == "y" || Ansewr == "Y")
       {
           Client1.Deposit(Number);
           cout << "Amount add succefuly \n";
           cout << "New Balance = " << Client1.GetAccountBalance() << endl;
      }
       else
       {
           cout << "operations was canceled\n";
       }
      
	}
};

