#include	"../includes/ATM_Simulation.hpp"

void	ShowLoginClientScreen()
{
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(2) << GREEN << "Login Screean" << NC << endl;
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
}

bool	LoadClientInfo(string AccountNumber, string PinCode)
{
	return (FindCleintByAccountNumberAndPinCode(AccountNumber, PinCode, GClient));
}

void	LoginCleint()
{
	string	AccountNumber, PinCode;
	bool	LoginFaild = false;

	do
	{
		system("clear");
		ShowLoginClientScreen();
		if (LoginFaild)
			cout <<  RED << "Invlaid Account Number/PinCode!" << NC << endl;
		cout << "Enter Accont number: ";
		getline(cin >> ws, AccountNumber);

		cout << "Enter PinCode: ";
		getline(cin >> ws,PinCode);

		if (AccountNumber.empty() || PinCode.empty())
		{
			cout << RED << "\nInput ended or error occurred. Exiting login.\n" << NC;
			return	;
		}
		LoginFaild = !LoadClientInfo(AccountNumber, PinCode);
	} while (LoginFaild);

	ShowATMMainMenue();
}
