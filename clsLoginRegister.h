#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsString.h"
class clsLoginRegister:protected clsScreen
{
private:
	
    static void _PrintUserRecordLine(clsUser::stLoginRegisterRecord Client)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << Client.DateTime;
        cout << "| " << setw(15) << left << Client.UserName;
        cout << "| " << setw(15) << left << Client.Password;
        cout << "| " << setw(10) << left << Client.Permission;

    }
public:
    static void LogInRegisterScreen()
    {

        if (!CheckAccessRight(clsUser::enPermissions::pShowLoginRegister)) { return; }

        vector<clsUser::stLoginRegisterRecord> vUser = clsUser::GetLogInRegisterList();
        string sub = "(" + to_string(vUser.size()) + ") Record(s).";
        _DrawScreenHeader("Login Register List Screen",sub);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(10) << "Permission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUser.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Client : vUser)
            {

                _PrintUserRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

