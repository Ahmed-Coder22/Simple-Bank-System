#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsInputValdiates.h"
#include <iomanip>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalances.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;

class clsTransaction :public clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTransfer = 4 ,eTransferLog =5,eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
    //static  void _GoBackToMainMenue()
    //{
    //    cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

    //    system("pause>0");
    //    clsMainScreen::ShowMainMenue();
    //}



    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::DepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
       // cout << "\n Withdraw Screen will be here.\n";
      clsWithDrawScreen::WithDraw();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Balances Screen will be here.\n";
        clsTotalBalances::ShowTotalBalances();
    }
    static void _Transfer()
    {
        clsTransferScreen::Transfer();
    }
    static void _TransferLog()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _Transfer();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _TransferLog();
            _GoBackToTransactionsMenue();
            break;

        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
        }
        }


    }



public:


    static void ShowTransactionsMenue()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};


