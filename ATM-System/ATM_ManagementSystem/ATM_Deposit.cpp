#include "../includes/ATM_Simulation.hpp"

void	ShowATMDepositScreen()
{
	system("clear");
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(2) << YELLOW << "Deposit Screan" << NC << endl;
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;

}

bool	ChangeClientBalance(vector <stDataClient> &vClients, double	BalanceToAdd, stDataClient &Client)
{
	for (stDataClient &C : vClients)
	{
		if (C.MarkForUpdate)
		{
			C.AccountBalance += BalanceToAdd;
			Client = C;
			GClient = C;
			return true;
		}
	}
	return false;
}

bool	MarkClientForUpdateByAccountnumber(string AccountNumber, vector <stDataClient> &_vClient)
{
	for (stDataClient &C : _vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForUpdate = true;
			GClient = C;
			return true;
		}
	}
	return false;
}

string	CounvertRecordToLine(stDataClient Client, string Dilem)
{
	vector <string>	_vStr;

	_vStr.push_back(Client.AccountNumber);
	_vStr.push_back(Client.PinCode);
	_vStr.push_back(Client.Name);
	_vStr.push_back(Client.Phone);
	_vStr.push_back(to_string(Client.AccountBalance));

	return StringUtils::JoinString(_vStr, Dilem);
}

void	SaveClientDataToFile(string FileName, vector <stDataClient> vClients)
{
	fstream DataFile;
	string	Line;

	DataFile.open(FileName, ios::out); // write in file
	if (DataFile.is_open())
	{
		for (stDataClient Client : vClients)
		{
		
			Line = CounvertRecordToLine(Client, "#//#");

			DataFile << Line << endl;
		}
		
		DataFile.close();
	}
}

void	DepositBalanceToClientByAccountNumber(string AccountNumber, string FileName, double Deposit)
{
	vector <stDataClient> vClients;
	stDataClient	Client;
	char 			Answer;

	vClients = LoadDataCleintFromFile(FileName);

	cout << WHITE  << "Are you sur you want perform this transation? [Y/n]: " << NC;
	cin >>  Answer;

	if (toupper(Answer) == 'Y')
	{
		MarkClientForUpdateByAccountnumber(AccountNumber, vClients);

		ChangeClientBalance(vClients, Deposit, Client);

		SaveClientDataToFile(FileName, vClients);

		cout << GREEN << "Done Successfuly, new balance is: " << NC << Client.AccountBalance << endl;
	}
}

double ReadDepositAmount()
{
	double	Amount;

	do{
		cout << WHITE << "Enter a positive Deposit Amount? " << NC;
    	cin >> Amount;
	} while (Amount <= 0);

	return Amount;
}

void	DepositByAccountNumber()
{
	double			Amount;

	Amount = ReadDepositAmount();

	DepositBalanceToClientByAccountNumber(GClient.AccountNumber, ClientsFileName, Amount);
}
