#pragma once
#include <iostream>
#include <vector>
#include <string>

#include"clsString.h"
#include"clsPerson.h"
#include <fstream>
#include"clsDate.h"
#include"Header.h"
using namespace std;


class clsBankClient :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode=2 };
	enMode _Mode;
	string _AccountNumber;
	string _Pincode;
	float _AccountBalance;
	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#$#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#$#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("BankAccount.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("BankAccount.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}
	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

	}
	void _AddNew()
	{

		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("BankAccount.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	struct stTrnsferLogRecord;

	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[5];

		return TrnsferLogRecord;

	}


	static string _PrepareTransactionsInRecord(clsBankClient Client1,clsBankClient Client2, string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += Client1.GetAccountNumber() + Seperator;
		LoginRecord += Client2.GetAccountNumber() + Seperator;
		LoginRecord += to_string(Client1.AccountBalance)+ Seperator;
		LoginRecord += to_string(Client2.AccountBalance)+ Seperator;
		LoginRecord += CurrentUser.GetUserName() ;
		return LoginRecord;
	}



public:
	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		//float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}



	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_Pincode = PinCode;
		_AccountBalance = AccountBalance;

	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(string Pincode)
	{
		_Pincode = Pincode;
	}
	string GetPinCode()
	{
		return _Pincode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << _FirstName;
		cout << "\nLastName    : " << _LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << _Email;
		cout << "\nPhone       : " << _Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _Pincode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}
	static clsBankClient Find(string AccountNumber)
	{

		fstream MyFile;
		MyFile.open("BankAccount.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();

		}
		return _GetEmptyClientObject();

	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{



		fstream MyFile;
		MyFile.open("BankAccount.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}
	static void DeleteClient(clsBankClient Clinet)
	{
		vector <clsBankClient> client = _LoadClientsDataFromFile();
		vector <clsBankClient>Vclient;
		for (clsBankClient C : client)
		{
			if (C.GetAccountNumber() != Clinet.GetAccountNumber())
			{
				Vclient.push_back(C);
			}
			//else
			//{
			//	_GetEmptyClientObject();
			//}
		}
		_SaveCleintsDataToFile(Vclient);
	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return(!Client.IsEmpty());
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalances()
	{
		vector <clsBankClient> vClient = clsBankClient::GetClientsList();
		double TotalBalances = 0;
		for (clsBankClient& C : vClient)
		{
			TotalBalances += C.GetAccountBalance();
		}
		return TotalBalances;
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{

			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}
		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}


		}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	void WithDraw(double Amount)
	{
		_AccountBalance -= Amount;
		Save();
	}


	static void TransferLogIn(clsBankClient &Client1,clsBankClient &Client2)
	{

		string stDataLine = _PrepareTransactionsInRecord(Client1,Client2);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}



};
