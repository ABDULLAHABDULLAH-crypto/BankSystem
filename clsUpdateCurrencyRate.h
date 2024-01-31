#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsUpdateCurrencyRate:protected clsScreen
{

private:
	static void PrintCurrencyCard(clsCurrency currency)
	{

		cout << "\nCurrency Card:\n";
		cout << "\n______________________________\n";
		cout << "\nCountry	: " << currency.Country();
		cout << "\nCode		: " << currency.CurrencyCode();
		cout << "\nName		: " << currency.CurrencyName();
		cout << "\nRate($1)	: " << currency.Rate();
		cout << "\n______________________________\n";


	}

	static float ReadNewRate()
	{
		float rate = 0;

		cout << "Update Currency Rate:\n";
		cout << "\n___________________________\n";
		cout << "Enter New Rate ";
		cin >> rate;
		return rate;
	}
public:
	static void ShowUpdateRateScreen()
	{
		string currency;
		_DrawScreenHeader("Update Currency Screen");
		cout << "Please enter Currency Code: ";
		cin >> currency;
		while (!clsCurrency::IsCurrencyExist(currency))
		{
			cout << "This Currency does not exist, so please enter another Currency Code: ";
			cin >> currency;
		}
		clsCurrency curr = clsCurrency::FindByCode(currency);

		PrintCurrencyCard(curr);
		string ans;
		cout << "Are you sure you want to update the rate of this Currency y/n? ";
		cin >> ans;

		if (ans == "y" || ans == "Y") {
			float rate= ReadNewRate();
			curr.UpdateRate(rate);
			cout << "\nCurrency Rate Updated Successfully :-)\n";
			PrintCurrencyCard(curr);
		}
		
	}

};

