/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:56:50 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/02 19:45:45 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account()
{
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	std::cout << "index: " << _nbAccounts << "; amount: " << _amount << "; created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index: " << _nbAccounts << "; amount: " << _amount << "; closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "Accounts: " << _nbAccounts << "; Total: " << _totalAmount << "; Deposits: " << _totalNbDeposits << 
		"; Withdrawals: " << _totalNbWithdrawals <<std::endl;
}

void 	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	std::cout << "Index: " << _accountIndex << "; _Amount: " << _amount << "; Deposit: " << deposit
		<< "; amount: " << _amount + deposit << "; Deposits: " << _nbDeposits << std::endl;
		_totalAmount += deposit;
		_totalNbDeposits++;
		_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << "Index: " << _accountIndex << "; p_Amount: " << _amount << "; Withdrawal: refused" << std::endl;
		return (false);
	}
	_displayTimestamp();
	_nbWithdrawals++;
	std::cout << "Index: " << _accountIndex << "; p_amount: " << _amount << "; withdrawals: " <<
		withdrawal << "; amount: " << _amount - withdrawal << "; nbWithdrawals: " << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "Index: " << _accountIndex << "; Amount: " << _amount << "; Deposits: " <<
		_nbDeposits << "; Withdrawals: " << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t result = time(NULL);

	std::cout << std::setfill('0') << "[" << 1900 + localtime(&result)->tm_year
		<< std::setw(2) << 1 + localtime(&result)->tm_mon
		<< std::setw(2) << localtime(&result)->tm_mday
		<< "_"
		<< std::setw(2) << localtime(&result)->tm_hour
		<< std::setw(2) << localtime(&result)->tm_min
		<< std::setw(2) << localtime(&result)->tm_sec
		<< "] " << std::flush;
}