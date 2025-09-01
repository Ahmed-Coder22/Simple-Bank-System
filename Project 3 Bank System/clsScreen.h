#pragma once
#include <iostream>
#include"clsBankClient.h"
#include <iomanip>
#include"clsUtil.h"
#include"clsInputValdiates.h"
#include"ClsUser.h"
#include"Header.h"
#include <ctime> 
using namespace std;

class clsScreen
{
public:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        PrintDateUser();
        //cout << endl << endl;
        cout << "\n\t\t\t\t\t______________________________________\n\n";


    }
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
    static void PrintDateUser()
    {
        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
        time_t now = time(0);
        tm localTime;
        localtime_s(&localTime, &now);

        int day = localTime.tm_mday;
        int month = localTime.tm_mon + 1;
        int year = localTime.tm_year + 1900;
        cout << "\t\t\t\t\tToday's date is: "
            << day << "/" << month << "/" << year << endl;
    }

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate<string>::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate<string>::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate<float>::ReadNumber();

    }
};

