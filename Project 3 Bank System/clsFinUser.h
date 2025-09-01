#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
//#include "clsInputValidates.h"
#include <iomanip>

class clsFinUser :protected clsScreen
{
private:
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
public:
        static void FindUser()
    {
            _DrawScreenHeader("Find User  Screen");
            string UserName = "";
            cout << "Please Enter User Name ? ";
            UserName = clsInputValidate<string>::ReadString();
            while (!clsUser::IsUserExist(UserName))
            {
                cout << "\nAccount number is not exist , choose another one: ";
                UserName = clsInputValidate<string>::ReadString();
            }
            clsUser findUser = clsUser::Find(UserName);
            _PrintUser(findUser);

    }

};

