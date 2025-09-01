#include <iostream>
#include"clsBankClient.h"
#include <iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
void ReadClientInfo(clsBankClient& Client)
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
int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
       }

        //system("pause>0");
        //return 0;

    }



