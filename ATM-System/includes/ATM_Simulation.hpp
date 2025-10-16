#pragma once

//#ifndef ATM_SYSTEM_H
//# define ATM_SYSTEM_H

# include <iostream>
# include <string>
# include <vector>
# include <fstream>
# include <iomanip>
# include <limits>
# include <cmath>

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define BLUE "\e[1;34m"
# define WHITE "\e[1;37m"

using namespace	std;

enum enATMMainMenueOptions
{
	enQuickWithdraw = 1,
	enNormalWithdraw = 2,
	enDeposit = 3,
	enCheckBalance = 4,
	enLogout = 5,
	enExit = 6
};

struct stDataClient
{
    string	AccountNumber;
    string	PinCode;
    string	Name;
    string	Phone;
    double	AccountBalance;
	bool	MarkForUpdate = false;
};

extern stDataClient GClient;

const string ClientsFileName = "../DataClient/Clients.txt";


bool			FindCleintByAccountNumberAndPinCode(string AccountNumber,
			string PinCode, stDataClient &Client);

namespace StringUtils
{

string					Tabs(short Counter);
vector <string>			SplitString(string str, string delim);
string 					JoinString(vector<string> vString, string delim);

}

// logint client 
void					LoginCleint();
void					ShowLoginClientScreen();
bool					LoadClientInfo(string AccountNumber, string PinCode);


// Goback ATM Main Menue 
void					GoBackATMMainMenue();
void					ShowATMMainMenue();

// Show ATM Quick Withdraw
void					ShowATMQuickWithdrawScreen();

// Normal Withdraw
void   					ShowNormalWithdrawScreen();
void					NormalWithdraw();


// Deposit 
void					ShowATMDepositScreen();
void					DepositByAccountNumber();
void					DepositBalanceToClientByAccountNumber(string AccountNumber,
							string FileName, double Deposit);


//	Show ATM Deposit
void					ShowATMDepositScreen();

// 
vector <stDataClient>	LoadDataCleintFromFile(string FileName);

// check Balance 
void   					ShowCheckBalanceScreen();
void    				CheckBalanceCleint();
//#endif