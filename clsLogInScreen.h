#pragma once

#include <iostream>
#include "clsScreen.h"
#include "fstream"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:
 
   

  
    static bool _Login()
    {
        bool LoginFaild = false;
        short number = 3;
        string Username, Password;
      
        do
        {

            if(number<=1){
                cout << "\n\nLogIn Failed and The Account has been stoped due to many logIn attempts, so please contact the Bank Support\n";
                system("pause>0");
                return false;
            }

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                cout << "remaining attempt number is  " << number<<"\n\n";
                number--;
                
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

