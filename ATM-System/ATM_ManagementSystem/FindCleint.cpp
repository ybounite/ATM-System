#include "../includes/ATM_Simulation.hpp"

stDataClient	ConvertLineToRecord(string	line, string Delim = "#//#")
{
	vector	<string>	_vString;
	stDataClient		Client;

	_vString = StringUtils::SplitString(line, Delim);

	Client.AccountNumber = _vString[0];
	Client.PinCode = _vString[1];
	Client.Name = _vString[2];
	Client.Phone = _vString[3];
	Client.AccountBalance = stod(_vString[4]);

	return	Client;
}

// void	PrintClientCard(stDataClient DataClient)
// {
// 	cout << YELLOW << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
//     cout << WHITE << "Accout number  : " << DataClient.AccountNumber << endl;
//     cout << "Pin Code       : " << DataClient.PinCode << endl;
//     cout << "Name           : " << DataClient.Name << endl;
//     cout << "Phone          : " << DataClient.Phone << endl;
//     cout << "Account Balance: " << DataClient.AccountBalance << NC << endl;
// 	cout << YELLOW << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;

// }

vector <stDataClient> LoadDataCleintFromFile(string FileName)
{
	fstream					FileClient;
	vector <stDataClient>	_vClients;
	stDataClient			Client;
	string					Line;

	FileClient.open(FileName, ios::in); // read in file 
	if (FileClient.is_open())
	{
		while (getline(FileClient, Line))
		{
			Client = ConvertLineToRecord(Line);
			_vClients.push_back(Client);
		}
		
		FileClient.close();
	}

	return _vClients;
}

bool	FindCleintByAccountNumberAndPinCode(string AccountNumber, string PinCode, stDataClient &Client)
{
	vector <stDataClient> _vClients;

	_vClients = LoadDataCleintFromFile(ClientsFileName);

	for (stDataClient &C : _vClients)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{
			Client = C;
			return true;
		}
	}

	return false;
}
