#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValdiates.h"
#include <iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsReadClientInfo.h"
#include"clsScreen.h"
class clsAddNewClientScreen : public clsScreen
{
public :
   static void AddNewClient()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
       {
           return;
       }

       clsScreen::_DrawScreenHeader("Add Screen");
        string AccountNumber = "";
        cout << "Please Enter Client Account Number ? ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is already  uesd, choose another one: ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        clsScreen::ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            NewClient.Print();
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }


    }


};

