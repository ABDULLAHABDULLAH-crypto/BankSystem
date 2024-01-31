#pragma once
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
   
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
       
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";

        cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName<<"\n";
        cout << "\t\t\t\t\tDate: "<<clsDate::DateToString(clsDate())<<"\n\n";
           
        
    }
    static bool CheckAccessRight(clsUser::enPermissions permission)
    {
        if (!CurrentUser.CheckAccessPermission(permission)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin";
            cout << "\n\t\t\t\t\t______________________________________\n";
            return false;
        }
        else
        {
            return true;
        }
    }


};

