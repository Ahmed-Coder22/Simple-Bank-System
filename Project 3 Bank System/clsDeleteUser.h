#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
//#include "clsInputValidates.h"
#include <iomanip>


class clsDeleteUser :clsScreen
{
private :
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public :
    static void DeleteUser()
    {
        _DrawScreenHeader("Delete User  Screen");
        string UserName = "";
        cout << "Please Enter User Name ? ";
        UserName = clsInputValidate<string>::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not exist , choose another one: ";
            UserName = clsInputValidate<string>::ReadString();
        }
        clsUser DeleteUser = clsUser::Find(UserName);
        _PrintUser(DeleteUser);
        cout << "Are you sure want delete this client ? y/n ";
        char ansewr;
        cin >> ansewr;
        if (ansewr == 'y' || ansewr == 'Y')
        {
            clsUser::DeleteUser(DeleteUser);
            _PrintUser(DeleteUser);

            cout << "Delete Succefuly\n";
        }
        else
        {
            cout << "Error Client was not delete\n";
        }

    }

};

