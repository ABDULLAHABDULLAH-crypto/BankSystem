#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTransferScreen:protected clsScreen
{
private:
	static void PrintClient(clsBankClient client) {
		cout << "\n\nClint Card";
		cout << "\n__________________________\n\n";
		cout << "Full Name   :" << client.FirstName << endl;
		cout << "Acc. Number :" << client.AccountNumber() << endl;
		cout << "Balance       :" << client.AccountBalance << endl;
		cout << "\n\n__________________________\n\n";

	}

	static string GetAccountNumberFromUser(string mss)
	{

		string acc;
		cout << mss;
		cin >> acc;
		while (!clsBankClient::IsClientExist(acc)) {
			cout << "This Account does not exit, Please enter another one \n";
			cin >> acc;
		}
		return acc;
	}

	static float ReadAmount(clsBankClient client) {
		float amount = 0;
		cout << "Enter Transfer amount? ";
		cin >> amount;
		while (!client.WithDraw(amount))
		{
			cout << "\n\nThe amount exceeds your balance ,enter another amount? ";
			cin >> amount;

		};
		return amount;
	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");
		string acc = GetAccountNumberFromUser("Please enter an Account Number to Transfer From? ");

		clsBankClient Transferer = clsBankClient::Find(acc);
		PrintClient(Transferer);


		string acc2 = GetAccountNumberFromUser("Please enter an Account Number to Transfer to? ");

		clsBankClient Receiver = clsBankClient::Find(acc2);
		PrintClient(Receiver);

		float amount = ReadAmount(Transferer);

		
		string ans;
		cout << "\n\nAre you sure you want to perform this operation? y/n?";
		cin >> ans;
		
		if (ans == "y" || ans == "Y") 
		{
			if(Transferer.Transfer(amount,Receiver,CurrentUser.UserName))
			{

				cout << "\n Transfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Failed\n";
			}
		}


		PrintClient(Transferer);
		PrintClient(Receiver);

	}
};

