#include "../includes/ATM_Simulation.hpp"

void    ShowCheckBalanceScreen()
{
    system("clear");
    cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
	cout << StringUtils::Tabs(2) << GREEN << "Check Balance Screean" << NC << endl;
	cout << BLUE << ":::::::::::::::::::::::::::::::::::::::::::" << NC << endl;
}

void    CheckBalanceCleint()
{
    cout << GREEN << "Your Balance is : " << WHITE <<  GClient.AccountBalance << NC << endl;
}