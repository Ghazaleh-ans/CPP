// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"

/*
* STATIC MEMBER INITIALIZATION:
* These must be defined outside the class definition
* They are shared by ALL Account objects
*/

// Initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
* STATIC MEMBER EXPLANATION:
* - _nbAccounts: Total number of accounts that currently exist
* - _totalAmount: Sum of all account balances
* - _totalNbDeposits: Total number of deposits made across all accounts
* - _totalNbWithdrawals: Total number of withdrawals made across all accounts
*/

// Constructor with initial deposit
Account::Account(int initial_deposit)
{
	/*
	* CONSTRUCTOR LOGIC:
	* 1. Set account index (before incrementing counter)
	* 2. Initialize instance variables
	* 3. Update static counters
	* 4. Log account creation
	*/

	// Set this account's index to current count (0-based indexing)
	this->_accountIndex = Account::_nbAccounts;

	// Initialize instance variables
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	/*
	* INSTANCE VARIABLE INITIALIZATION:
	* - _accountIndex: Unique identifier for this account
	* - _amount: Current balance (starts with initial deposit)
	* - _nbDeposits: Number of deposits made to THIS account
	* - _nbWithdrawals: Number of withdrawals made from THIS account
	*/

	// Update static counters
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	/*
	* STATIC COUNTER UPDATES:
	* - Increment total account count
	* - Add initial deposit to global total
	* - Note: deposit/withdrawal counters not updated (no transaction yet)
	*/

	// Log account creation with timestamp
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;

	/*
	* LOGGING FORMAT (from log file):
	* [timestamp] index:0;amount:42;created
	* - Shows account index and initial amount
	* - "created" indicates this is constructor output
	*/
}

// Destructor
Account::~Account(void)
{
	/*
	* DESTRUCTOR LOGIC:
	* 1. Log account closure
	* 2. Update static counters
	*
	* Note: The order matters! Log first, then update counters
	* (though in this case it doesn't affect the output)
	*/

	// Log account closure with timestamp
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;

	/*
	* CLOSURE LOGGING:
	* Shows final state before destruction
	* Format matches log file: [timestamp] index:0;amount:47;closed
	*/

	// Update static counters
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;

	/*
	* STATIC COUNTER CLEANUP:
	* - Decrement account count
	* - Remove this account's balance from global total
	* - Deposit/withdrawal counters remain (historical data)
	*/
}

// Static getter methods
int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

// Static method to display summary of all accounts
void Account::displayAccountsInfos(void)
{
	/*
	* GLOBAL ACCOUNT SUMMARY:
	* Shows statistics for ALL accounts combined
	* Called as Account::displayAccountsInfos() (static method)
	*/

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
			<< ";total:" << Account::_totalAmount
			<< ";deposits:" << Account::_totalNbDeposits
			<< ";withdrawals:" << Account::_totalNbWithdrawals
			<< std::endl;

	/*
	* FORMAT FROM LOG FILE:
	* [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	*
	* Shows:
	* - accounts: Current number of accounts
	* - total: Sum of all account balances
	* - deposits: Total number of deposit transactions
	* - withdrawals: Total number of withdrawal transactions
	*/
}

// Instance method to make a deposit
void Account::makeDeposit(int deposit)
{
	/*
	* DEPOSIT PROCESS:
	* 1. Store previous amount for logging
	* 2. Update account balance and counters
	* 3. Update global counters
	* 4. Log the transaction
	*/

	int p_amount = this->_amount;  // Store previous amount

	// Update account state
	this->_amount += deposit;
	this->_nbDeposits++;

	// Update global counters
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	/*
	* UPDATE SEQUENCE:
	* 1. Instance variables: _amount, _nbDeposits
	* 2. Static variables: _totalAmount, _totalNbDeposits
	*
	* Both instance and global statistics are updated
	*/

	// Log deposit transaction
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";deposit:" << deposit
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;

	/*
	* DEPOSIT LOG FORMAT (from log file):
	* [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	*
	* Shows:
	* - index: Account identifier
	* - p_amount: Previous amount (before deposit)
	* - deposit: Amount being deposited
	* - amount: New amount (after deposit)
	* - nb_deposits: Total deposits for THIS account
	*/
}

// Instance method to make a withdrawal
bool Account::makeWithdrawal(int withdrawal)
{
	/*
	* WITHDRAWAL PROCESS:
	* 1. Store previous amount for logging
	* 2. Check if sufficient funds
	* 3a. If insufficient: log refusal, return false
	* 3b. If sufficient: update balances, log success, return true
	*/

	int p_amount = this->_amount;  // Store previous amount

	// Check for sufficient funds
	if (withdrawal > this->_amount)
	{
		/*
		* INSUFFICIENT FUNDS CASE:
		* - Don't modify any balances or counters
		* - Log the refusal
		* - Return false to indicate failure
		*/

		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:refused"
				<< std::endl;

		/*
		* REFUSAL LOG FORMAT (from log file):
		* [19920104_091532] index:0;p_amount:47;withdrawal:refused
		*
		* Note: No amount or counter updates shown
		*/

		return false;
	}

	/*
	* SUFFICIENT FUNDS CASE:
	* Update all relevant counters and balances
	*/

	// Update account state
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	// Update global counters
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	// Log successful withdrawal
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;

	/*
	* SUCCESSFUL WITHDRAWAL LOG FORMAT (from log file):
	* [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	*
	* Shows:
	* - index: Account identifier
	* - p_amount: Previous amount (before withdrawal)
	* - withdrawal: Amount being withdrawn
	* - amount: New amount (after withdrawal)
	* - nb_withdrawals: Total withdrawals for THIS account
	*/

	return true;  // Indicate successful withdrawal
}

// Instance method to check current balance
int Account::checkAmount(void) const
{
	/*
	* SIMPLE GETTER:
	* Returns current account balance
	* const method - doesn't modify object state
	*/
	return this->_amount;
}

// Instance method to display account status
void Account::displayStatus(void) const
{
	/*
	* INDIVIDUAL ACCOUNT STATUS:
	* Shows complete information for this specific account
	* const method - read-only operation
	*/

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;

	/*
	* STATUS LOG FORMAT (from log file):
	* [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	*
	* Shows complete state of individual account:
	* - index: Account identifier
	* - amount: Current balance
	* - deposits: Number of deposits made to this account
	* - withdrawals: Number of withdrawals made from this account
	*/
}

// Private static method to display timestamp
void Account::_displayTimestamp(void)
{
	/*
	* TIMESTAMP FORMATTING:
	* Creates timestamp in format: [YYYYMMDD_HHMMSS]
	* Used by all logging methods
	*
	* Note: The actual timestamp will differ from the log file
	* since we're running at a different time
	*/

	// Get current time
	std::time_t rawtime;
	std::tm* timeinfo;

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	/*
	* TIME STRUCTURE:
	* std::tm contains:
	* - tm_year: years since 1900
	* - tm_mon: months since January (0-11)
	* - tm_mday: day of month (1-31)
	* - tm_hour: hours since midnight (0-23)
	* - tm_min: minutes after hour (0-59)
	* - tm_sec: seconds after minute (0-60)
	*/

	// Output formatted timestamp
	std::cout << "["
			<< (1900 + timeinfo->tm_year)
			<< std::setfill('0') << std::setw(2) << (1 + timeinfo->tm_mon)
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			<< "_"
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_min
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			<< "] ";

	/*
	* FORMATTING EXPLANATION:
	* - std::setfill('0'): Pad with zeros
	* - std::setw(2): Minimum width of 2 characters
	* - +1900 to tm_year: Convert to actual year
	* - +1 to tm_mon: Convert 0-11 to 1-12
	*
	* Result format: [20240618_143022] (example)
	* Matches log file format: [19920104_091532]
	*/
}

/*
* UNDERSTANDING THE COMPLETE FLOW:
*
* 1. tests.cpp creates 8 Account objects with specific amounts
* 2. Each constructor logs creation and updates static counters
* 3. displayAccountsInfos() shows global summary
* 4. displayStatus() called on each account (via std::for_each)
* 5. makeDeposit() called on each account with specific amounts
* 6. displayAccountsInfos() shows updated global summary
* 7. displayStatus() called on each account again
* 8. makeWithdrawal() called on each account with specific amounts
* 9. Some withdrawals succeed, some are refused (insufficient funds)
* 10. Final displayAccountsInfos() and displayStatus() calls
* 11. All destructors called when accounts go out of scope
*
* The key is that ALL logging must match the exact format in the log file!
*/
