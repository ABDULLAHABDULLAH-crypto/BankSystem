#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
class clsListCurrencyScreen:protected clsScreen
{

private:

	static void PrintCurrency(clsCurrency currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << currency.Country();
		cout << "| " << setw(10) << left <<currency.CurrencyCode();
		cout << "| " << setw(20) << left << currency.CurrencyName();
		cout << "| " << setw(10) << left << currency.Rate();

	}

public:
	static void ShowListCurrency()
	{
        vector <clsCurrency> Currencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(Currencies.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(10) << "Rate(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (Currencies.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsCurrency currency : Currencies)
            {

                PrintCurrency(currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


	



};

