#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Header.h"



    class clsLoginScreen :protected clsScreen
    {

    private:

        static  bool _Login()
        {
            bool LoginFaild = false;

            string Username, Password;
            int trials = 3;

            do
            {
                if (trials == 1)
                {
                    cout << "\nyou are locked after 3 trials failed\n\n";
                    return false;
                }
                if (LoginFaild)
                {
                    cout << "\nInvlaid Username/Password!\n\n";
                    cout << "you have " << --trials << " trials to Login .\n\n";
                }

                cout << "Enter Username? ";
                cin >> Username;

                cout << "Enter Password? ";
                cin >> Password;

                CurrentUser = clsUser::Find(Username, Password);

                LoginFaild = CurrentUser.IsEmpty();

            } while (LoginFaild);
            CurrentUser.RegisterLogIn();
            clsMainScreen::ShowMainMenue();
            return true;
        }

    public:


        static bool ShowLoginScreen()
        {
            system("cls");
            _DrawScreenHeader("\t  Login Screen");
            return _Login();

        }

    };



