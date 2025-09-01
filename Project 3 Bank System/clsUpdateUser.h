#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
//#include "clsInputValidates.h"
#include <iomanip>

class clsUpdateUser :clsScreen
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
    static int _ReadPermissionsToSet()
    {
        char Answer = 'n';
        int Permissions = 0;
        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;


    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate<string>::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate<string>::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

public :
    static void UpdateUser()
    {
        _DrawScreenHeader("Update User  Screen");
        string UserName = "";
        cout << "Please Enter User Name ? ";
        UserName = clsInputValidate<string>::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not exist , choose another one: ";
            UserName = clsInputValidate<string>::ReadString();
        }
        clsUser UpdateUser = clsUser::Find(UserName);
        _PrintUser(UpdateUser);
        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";
        clsUser::enSaveResults  vUpdateUser;
        _ReadUserInfo(UpdateUser);
        vUpdateUser = UpdateUser.Save();
        switch (vUpdateUser)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintUser(UpdateUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }


    }

};

