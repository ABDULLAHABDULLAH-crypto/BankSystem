#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen:protected clsScreen
{
	static short AskForToEnterCodeOrCountry()
	{
		cout << "\n Find By [1] Code or [2] Country ?";
		return clsInputValidate::ReadNumberBetween<short>(1, 2);
		

	}


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

	static string AskForToEnterCountry()
	{
		cout << "\n Please enter a Country ?";
		string value = clsInputValidate::ReadString();
		return value;

	}
	static string AskForToEnterCode()
	{
		cout << "\n Please enter a Code ?";
		string value = clsInputValidate::ReadString();
		return value;

	}

	static void ShowResult(clsCurrency currency){
		if (!currency.IsEmpty()) {
			cout << "Currency found -)\n";
			PrintCurrencyCard(currency);
		}
		else
		{
			cout << "Currency not found -(\n";
		}

	}
public:
	static void ShowFindCurrencyScreen() 
	{
		_DrawScreenHeader("Find Currency Screen");
		short Answer = AskForToEnterCodeOrCountry();

		if (Answer == 1) {
			clsCurrency currency =clsCurrency::FindByCode(AskForToEnterCode());
			ShowResult(currency);
		}
		else if(Answer==2){
			clsCurrency currency = clsCurrency::FindByCountry(AskForToEnterCountry());
			ShowResult(currency);
		}



		
			
		
	}



};

