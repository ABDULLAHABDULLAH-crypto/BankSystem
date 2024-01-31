#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculator:protected clsScreen
{
	static float ReadAmount()
	{
		float amount;
		cout << "Enter amount to exchange:";
		amount=clsInputValidate::ReadNumber<float>();
		return amount;
	
	}
	static clsCurrency _AskForCurrency(string mss)
	{
		string currency;
		cout << mss;
		cin >> currency;
		while (!clsCurrency::IsCurrencyExist(currency))
		{
			cout << "This Currency does not exist, so please enter another Currency Code: ";
			cin >> currency;
		}
		clsCurrency curr = clsCurrency::FindByCode(currency);
		return curr;

	}
	
	static void PrintCurrencyCard(clsCurrency currency,string mss)
	{
		cout << mss;
		cout << "\n______________________________\n";
		cout << "\nCountry	: " << currency.Country();
		cout << "\nCode		: " << currency.CurrencyCode();
		cout << "\nName		: " << currency.CurrencyName();
		cout << "\nRate($1)	: " << currency.Rate();
		cout << "\n______________________________\n";
	}
	static void _PrintCalculationResult(float amount,clsCurrency currencyFrom,clsCurrency currencyTo)
	{
		PrintCurrencyCard(currencyFrom, "Convert From:");
		float amountInUSD = currencyFrom.ConvertToUSD(amount);
		cout << amount << " " << currencyFrom.CurrencyCode() <<
			" = " << amountInUSD << " USD\n";

		if(currencyTo.CurrencyCode()=="USD")
		{
			return;
		}
		cout << "Converting  from USD to:\n";

		PrintCurrencyCard(currencyTo,"To:");
		float AmountInCurrency2=currencyFrom.ConvertToOtherCurrency(amount, currencyTo);
		cout << amount << " " << currencyFrom.CurrencyCode() <<
			" = " << AmountInCurrency2 <<" " << currencyTo.CurrencyCode() << endl;

	
	}
public:
	static void ShowCurrencyCalculator()
	{
		char contiue = 'y';
		while (contiue=='Y'|| contiue=='y')
		{
			_DrawScreenHeader("Currency Calculator");
			clsCurrency currency1 = _AskForCurrency("\nPlease enter Currency1 Code: ");
			clsCurrency currency2 = _AskForCurrency("\nPlease enter Currency2 Code: ");
			float amount = ReadAmount();
	
		

			_PrintCalculationResult(amount, currency1, currency2);
			cout << "do you want to countuie y/n?";
			cin >> contiue;
		}
	
	}
};

