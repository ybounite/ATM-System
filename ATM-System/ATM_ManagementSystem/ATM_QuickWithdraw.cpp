#include	"../includes/ATM_Simulation.hpp"

void	PrintATMQuickWithdrawScreen()
{
	system("clear");
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(2) << GREEN << "Quik withdraw Screean" << NC << endl;
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(1) << WHITE << "[1] 20  \t [2] 50\n" ;
	cout << StringUtils::Tabs(1) << "[3] 100 \t [4] 200\n";
	cout << StringUtils::Tabs(1) << "[5] 400 \t [6] 600\n";
	cout << StringUtils::Tabs(1) << "[7] 800 \t [8] 1000\n";
	cout << StringUtils::Tabs(2) << "[9] Cancle\n";
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << GREEN << "Your Balace is : " << WHITE << GClient.AccountBalance << NC << endl;
}

short	GetQuickWithdrawAmount(short QuickWithdrawOption)
{
	switch (QuickWithdrawOption)
	{
	case 1:
		return 20;
	case 2:
		return 50;
	case 3:
		return 100;
	case 4:
		return 200;
	case 5:
		return 400;
	case 6:
		return 600;
	case 7:
		return 800;
	case 8:
		return 1000;
	}
	return 0;
}

short	ReadQuikWithdrawOption()
{
	short	Chios;

	do
	{
		cout << WHITE << "Choos what to do from [1]to[9]: " << NC;
    	cin >> Chios;
	} while (Chios < 0 && Chios > 9);

	return Chios;
}

void	PerformQuickWithdrawOption(short QuickWithdrawOption)
{
	short	WithDrawBalance;

	if (QuickWithdrawOption == 9)
		return ;
	WithDrawBalance = GetQuickWithdrawAmount(QuickWithdrawOption);
	if (WithDrawBalance  > GClient.AccountBalance){
        cout << "The amount exceeds your balance , make another chioce." << endl;
        return ;
    }
	cout << GREEN << "Balance is : " << WHITE << GClient.AccountBalance << NC << endl;

	DepositBalanceToClientByAccountNumber(GClient.AccountNumber, ClientsFileName, -1 * WithDrawBalance);
}

void	ShowATMQuickWithdrawScreen()
{
	PrintATMQuickWithdrawScreen();

	PerformQuickWithdrawOption(ReadQuikWithdrawOption());
}
