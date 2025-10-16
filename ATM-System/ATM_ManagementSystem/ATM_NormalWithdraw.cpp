#include "../includes/ATM_Simulation.hpp"

void    ShowNormalWithdrawScreen()
{
    system("clear");
    cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(2) << GREEN << "Normal Withdraw Screean" << NC << endl;
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
}

short   ReadWithDrawAmount()
{
    short Amount;
     do{

        cout << "Enter an mount multiple of 5's ? ";
        cin >> Amount;

    } while (fmod(Amount, 5.0) != 0);

    return Amount;
}

void    NormalWithdraw()
{
    short   WithDrawAmount;

    WithDrawAmount = ReadWithDrawAmount();


    if (WithDrawAmount  > GClient.AccountBalance){
        cout << "The amount exceeds your balance , make another chioce." << endl;
        return ;
    }

    DepositBalanceToClientByAccountNumber(GClient.AccountNumber, ClientsFileName, (double)WithDrawAmount * -1);
}
