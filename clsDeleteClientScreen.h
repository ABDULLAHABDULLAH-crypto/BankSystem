#pragma once
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen: protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void ShowDeleteClinetScreen() {
       

        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient)) { return; }

        _DrawScreenHeader("\tClient Delete Screen");
        string Acc = "";
        cout << "Enter a Account Number : ";
        Acc = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExist(Acc)))
        {
            cout << "The Account does not exist , enter another one";
            Acc = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(Acc);
        _PrintClient(client);

        string ans = "";
        cout << "Are you sure to delete this client?";
        cin >> ans;
        if (ans == "Y" || ans == "y") {
            if (client.Delete()) {
                cout << "Client deleted successfully -)\n";
                _PrintClient(client);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};

