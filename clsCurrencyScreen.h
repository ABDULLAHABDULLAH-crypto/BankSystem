#pragma once
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculator.h"

class clsCurrencyScreen:protected clsScreen
{
private:

	enum enCurrencyOptions {
		eListCurrencies=1,eFindCurrency=2,eUpdateRate=3,
		CurrencyCalculator=4,eMainMenu=5
	};
	static short ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        cout <<"Enter Number between 1 to 5? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5);
		return Choice;
	}

    static void _ShowListCurrencies()
    {
        clsListCurrencyScreen::ShowListCurrency();
    }
    static void _ShowFindCurrency()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRate()
    {
        clsUpdateCurrencyRate::ShowUpdateRateScreen();
    }
    static void _ShowCurrencyCalculator()
    {
        clsCurrencyCalculator::ShowCurrencyCalculator();
    }

    static void _GoBackToCurrencyMenue() 
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowCurrencyMenue();
    }
    static void _PerformCurrencyMenueOption(enCurrencyOptions choice)
    {
    
        switch (choice)
        {
        case clsCurrencyScreen::eListCurrencies:
            system("cls");
            _ShowListCurrencies();
            _GoBackToCurrencyMenue();
            break;
        case clsCurrencyScreen::eFindCurrency:
            system("cls");
            _ShowFindCurrency();
            _GoBackToCurrencyMenue();

            break;
        case clsCurrencyScreen::eUpdateRate:
            system("cls");
            _ShowUpdateRate();
            _GoBackToCurrencyMenue();
            break;
        case clsCurrencyScreen::CurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackToCurrencyMenue();
            break;
        case clsCurrencyScreen::eMainMenu:
            
            break;
        default:
            break;
        }
    
    }
public:
    static void ShowCurrencyMenue()
    {
        
        if (!CheckAccessRight(clsUser::enPermissions::pShowCurrency)) { return; }

        system("cls");
        _DrawScreenHeader("\t  Currency Exchange Main Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenueOption((enCurrencyOptions)ReadCurrencyMenueOption());
    }

};

