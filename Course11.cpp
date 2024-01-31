#include <iostream>
#include "clsLogInScreen.h"
#include "clsCurrency.h"


int main()
{
	
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())break;
	}


    return 0;
}