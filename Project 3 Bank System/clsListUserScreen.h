#pragma once
#include <iostream>
#include"clsBankClient.h"
#include"clsInputValdiates.h"
#include <iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsScreen.h"
#include"ClsUser.h"
class clsListUserScreen :clsScreen
{
private:
    static void PrintClientRecordLine(clsUser User)
    {

        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(15) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }
public:
    static void ShowUserList()
    {
        vector <clsUser> vUser = clsUser::GetUsersList();

        cout << "\n\t\t\t\t\tUser List (" << vUser.size() << ") User(s).";
        cout << endl << endl;
        PrintDateUser();
       // cout << endl << endl;
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUser.size() == 0)
            cout << "\t\t\t\tNo User Available In the System!";
        else

            for (clsUser User : vUser)
            {

                PrintClientRecordLine(User);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;


    }


};


