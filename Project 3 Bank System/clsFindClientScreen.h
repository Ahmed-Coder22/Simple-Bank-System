#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValdiates.h"
#include <iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsScreen.h"

class clsFindClientScreen :protected clsScreen
{
public :
	static void FindClient()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

		clsScreen::_DrawScreenHeader("Find Client Screen");
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
	}
};

