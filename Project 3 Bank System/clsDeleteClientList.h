#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValdiates.h"
#include <iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsScreen.h"
class clsDeleteClientList :public clsScreen
{
public :
    static void DeleteClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("Delete Screen");
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
        cout << "Are you sure want delete this client ? y/n ";
        char ansewr;
        cin >> ansewr;
        if (ansewr == 'y' || ansewr == 'Y')
        {
            clsBankClient::DeleteClient(Client1);
            Client1.Print();
            cout << "Delete Succefuly\n";
        }
        else
        {
            cout << "Error Client was not delete\n";
        }
    }

};

