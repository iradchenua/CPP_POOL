#include <iostream>
#include "Account.class.hpp"

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_displayTimestamp();
	this->_accountIndex = Account::getNbAccounts();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount\
	<< ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->checkAmount() \
	<< ";closed" \
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	char 		buffer[80];

	struct 		tm *timeinfo;
	std::time_t time_now;

	std::time(&time_now);
	timeinfo = std::localtime(&time_now);
	std::strftime(buffer, sizeof(buffer), "%Y%d%m_%s", timeinfo);
	buffer[15] = 0;
	std::cout << "[" << buffer << "] ";
}

int	Account::getNbDeposits( void ) 
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) 
{
	return (Account::_totalNbWithdrawals);
}

int 	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int 	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->checkAmount() \
	<< ";deposits:" << this->_nbDeposits \
	<< ";withdrawals:" << this->_nbWithdrawals \
	<< std::endl;
}

int		Account::getTotalAmount(void) {
		return (Account::_totalAmount);
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() \
	<< ";total:" << Account::getTotalAmount() \
	<<";deposits:" << Account::getNbDeposits() \
	<<";withdrawals:" << Account::getNbWithdrawals()
	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << this->checkAmount() \
	<< ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused"
		<< std::endl;
		return (0);
	}
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << withdrawal \
	<< ";amount:" << this->checkAmount() \
	<< ";nb_withdrawals:" << this->_nbWithdrawals \
	<< std::endl;
	return (1);
}

void	Account::makeDeposit( int deposit)
{
	Account::_displayTimestamp();
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << this->checkAmount() \
	<< ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->checkAmount() \
	<< ";nb_deposits:" << this->_nbDeposits \
	<<std::endl;
	Account::_totalAmount += deposit;
}

int Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
