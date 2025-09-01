#pragma once
#include <iostream>
#include"clsBankClient.h"
#include <iomanip>
#include"clsMainScreen.h"
#include"clsScreen.h"
#include"clsInputValdiates.h"
#include"ClsUser.h"
using namespace std;
class clsUpdateClientScreen :public clsScreen
{
public:
   static void UpdateClient()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
       {
           return;
       }

        _DrawScreenHeader("Update Screen");

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
        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";


        ReadClientInfo(Client1);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            Client1.Print();
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
    }

};

