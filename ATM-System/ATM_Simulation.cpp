
#include "./includes/ATM_Simulation.hpp"

stDataClient GClient;

void    PrintMainMenueATMScreen()
{
	system("clear");
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(2) << YELLOW << "ATM Main Menue Screen" << NC << endl;
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(1) << WHITE << "[1] Quick Withdraw.\n";
	cout << StringUtils::Tabs(1) << "[2] Normal Withdraw.\n";
	cout << StringUtils::Tabs(1) << "[3] Deposit.\n";
	cout << StringUtils::Tabs(1) << "[4] Check Balance.\n";
	cout << StringUtils::Tabs(1) << "[5] Logout.\n";
	cout << StringUtils::Tabs(1) << "[6] Exit.\n";
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;

}

short	ReadMainMenueATM_Option()
{
	short	Answer;

	cout << "Choose what do you want to do? [1 to 6] ?";
	cin >> Answer;

	return Answer;
}

void	PerfromMainMenueATMOption(enATMMainMenueOptions Choice)
{
	switch (Choice)
	{
	case enATMMainMenueOptions::enQuickWithdraw:
		ShowATMQuickWithdrawScreen();
		GoBackATMMainMenue();
		break;
	case enATMMainMenueOptions::enNormalWithdraw:
		ShowNormalWithdrawScreen();
		NormalWithdraw();
		GoBackATMMainMenue();
		break;
	case enATMMainMenueOptions::enDeposit:
		ShowATMDepositScreen();
		DepositByAccountNumber();
		GoBackATMMainMenue();
		break;
	case enATMMainMenueOptions::enCheckBalance:
		ShowCheckBalanceScreen();
		CheckBalanceCleint();
		GoBackATMMainMenue();
		break;
	case enATMMainMenueOptions::enLogout:
		LoginCleint();
		break;
	case enATMMainMenueOptions::enExit:
		exit(EXIT_SUCCESS);
		//ShowATMExitScreen();
		break;
	}
}

void	GoBackATMMainMenue()
{
	cout << "\nPress any Key to go back to ATM Main Manue...";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	ShowATMMainMenue();
}

void	ShowATMMainMenue()
{
	system("clear");
	PrintMainMenueATMScreen();
	PerfromMainMenueATMOption((enATMMainMenueOptions)ReadMainMenueATM_Option());
}

int main()
{
	LoginCleint();
	return (0);
}
