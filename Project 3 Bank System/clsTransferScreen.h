#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValdiates.h"
#include <iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsScreen.h"


class clsTransferScreen :public clsScreen
{
private :
    static void PrintTrClient(clsBankClient &Client)
    {
        cout << "Client Card : \n";
        cout << "___________________________________\n";
        cout <<"Full Name : " << Client.FullName() << endl;
        cout << "Acc.Number : " << Client.GetAccountNumber() << endl;
        cout << "Balance : " << Client.AccountBalance << endl;
        cout << "___________________________________\n";

    }
public :
	static void Transfer()
	{
        PrintDateUser();
        string AccountNumber = "";
        cout << "Please Enter  Account Number to transfer from ? ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        PrintTrClient(Client1);
        string AccountNumber2 = "";
        cout << "Please Enter  Account Number to transfer TO ? ";
        AccountNumber2 = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber2))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber2 = clsInputValidate<string>::ReadString();
        }
        clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
        PrintTrClient(Client2);

        cout << "Please Enter Transfer amonut ? ";
        double Number = clsInputValidate<double>::ReadNumber();
        do
        {
            if (Number > Client1.AccountBalance)
            {
                cout << "Please Enter Correct Transfer amount  ? ";
                Number = clsInputValidate<double>::ReadNumber();

            }
        } while (Number > Client1.AccountBalance);

        string Ansewr = "";
        cout << "Are you sure want to perform this transactions ? y/n ";
        Ansewr = clsInputValidate<string>::ReadString();
        if (Ansewr == "y" || Ansewr == "Y")
        {
            Client1.WithDraw(Number);
            Client2.Deposit(Number);
            cout << "Transfer Done Succefuly \n";
            PrintTrClient(Client1);
            PrintTrClient(Client2);
            clsBankClient::TransferLogIn(Client1,Client2);
        }
        else
        {
            cout << "operations was canceled\n";
        }


	}

};

