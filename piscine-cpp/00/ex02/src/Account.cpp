/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:53:19 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 14:37:19 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
}

Account::~Account( void ) {
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

void Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    if ( this->_amount < withdrawal ) {
        Account::_displayTimestamp();
        std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
        return false;
    } else {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        Account::_displayTimestamp();
        std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:"
                  << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    }
}

void Account::_displayTimestamp( void ) {
    char timestamp[ 16 ];
    std::time_t timer;
    std::time( &timer );
    std::tm * local_timer = std::localtime( &timer );

    strftime( timestamp, sizeof( timestamp ), "%Y%m%d_%H%M%S", local_timer );
    std::cout << "[" << timestamp << "]";
}

int Account::checkAmount( void ) const {
    return this->_amount;
}

void Account::makeDeposit( int deposit ) {
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:"
              << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}
int Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}
int Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:"
              << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}
