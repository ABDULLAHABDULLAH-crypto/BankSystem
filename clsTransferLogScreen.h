#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include "clsBankClient.h"
class clsTransferLogScreen:protected clsScreen
{
    
    static void _PrintUserRecordLine(clsBankClient::stTransferLogIn User)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << User.DateTime;
        cout << "| " << setw(10) << left << User.sender;
        cout << "| " << setw(10) << left << User.receiver;
        cout << "| " << setw(15) << left << to_string(User.amount);
        cout << "| " << setw(15) << left << to_string(User.S_balance);
        cout << "| " << setw(15) << left << to_string(User.R_balance);
        cout << "| " << setw(10) << left << User.UserName;


    }
public:
	static void TransferLogScreen() {

        vector<clsBankClient::stTransferLogIn> transferLog = clsBankClient::GetTransferLogClient();

        string sub = to_string(transferLog.size())+ " Record(s).";
		_DrawScreenHeader("Transfer Log List Screen",sub);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date&Time";
        cout << "| " << left << setw(10) << "Sender ";
        cout << "| " << left << setw(10) << "Receiver";
        cout << "| " << left << setw(15) << "amount";
        cout << "| " << left << setw(15) << "s.balance";
        cout << "| " << left << setw(15) << "r.balance";
        cout << "| " << left << setw(10) << "UserName";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (transferLog.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankClient::stTransferLogIn User : transferLog)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


	


};

