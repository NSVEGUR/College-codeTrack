#include <iostream>
using namespace std;

//structure to store all the account numbers and int indicating their type
struct Accounts
{
  int accountNumber;
  int accountType;
  Accounts *link;
};

//header node for all the stored account numbers
Accounts *accountsHead = NULL;

//function to check the existense of the account
bool accountExist(int accountNumber)
{
  Accounts *temp = accountsHead;
  while (temp != NULL)
  {
    if (temp->accountNumber == accountNumber)
      return true;
    temp = temp->link;
  }
  return false;
}

//Parent Account object
class Account
{
public:
  double balance;
  int accountNumber;
  //default constructor which initialises balance for all the objects declared
  Account()
  {
    double balance;
    cout << "\033[1;32mENTER THE INITIAL BALANCE OF THE ACCOUNT : \033[0m";
    cin >> balance;
    //if balance is negetive initialise as 0
    if (balance < 0)
    {
      this->balance = 0;
      cout << "\033[1;31mBALANCE IS ASSIGNED TO 0.0 SINCE IT IS INVALID\033[0m" << endl;
    }
    else
      this->balance = balance;
    cout << "\033[1;34mACCOUNT CREATED SUCCESSFULLY\033[0m" << endl;
  }
  //creation of account number
  void createAccountNumber()
  {
    cout << "-----ACCOUNT NUMBER CREATION-----" << endl;
    int accountNumber;
    Accounts *temp = accountsHead;
    while (1)
    {
      cout << "\033[1;32mPLEASE ENTER A ACCOUNT NUMBER GREATER BETWEEN 100 AND 999: \033[0m";
      cin >> accountNumber;
      //checking whether the acc number is valid or not
      if (accountNumber < 100 || accountNumber > 999)
      {
        cout << "\033[1;31mINVALID ACCOUNT NUMBER\033[0m" << endl;
        continue;
      }
      //checking whether the acc number already exists or not
      if (accountExist(accountNumber))
      {
        cout << "\033[1;31mACCOUNT NUMBER ALREADY EXISTS\033[0m" << endl;
        continue;
      }
      this->accountNumber = accountNumber;
      break;
    }
    cout << "\033[1;34mACCOUNT NUMBER CREATED SUCCESSFULLY\033[0m" << endl;
  }
  //function to calculate the balance
  inline double getBalance()
  {
    return this->balance;
  }
  //function to credit money to the account
  double credit(double amount)
  {
    //if amount entered is negetive
    if (amount < 0)
      cout << "\033[1;31mENTERED AMOUNT IS INVALID PLEASE TRY AGAIN\033[0m" << endl;
    else
    {
      this->balance += amount;
      cout << "\033[1;34m" << amount << " IS CREDITED TO ACCOUNT NO. " << this->accountNumber << " SUCCESSFULLY\033[0m" << endl;
    }
    return this->balance;
  }
  //function to debit money from the account
  double debit(double amount)
  {
    //if entered amount is negetive
    if (amount < 0)
      cout << "\033[1;31mENTERED AMOUNT IS INVALID PLEASE TRY AGAIN\033[0m" << endl;
    //if entered amount exceeds the current balance
    else if (amount > this->getBalance())
      cout << "\033[1;31mENTERED AMOUNT EXCEEDS THE ACCOUNT BALANCE PLEASE TRY AGAIN\033[0m" << endl;
    else
    {
      this->balance -= amount;
      cout << "\033[1;34m" << amount << " IS DEBITED FROM ACCOUNT NO. " << this->accountNumber << " SUCCESSFULLY\033[0m" << endl;
    }
    return this->balance;
  }
};

//child inherited class savings account from parent Account
class SavingsAccount : public Account
{
public:
  double interestRate;
  //default constructor for child saving account which also runs parent constructor and then the child initialising the interest rate
  SavingsAccount()
  {
    double interestRate;
    cout << "\033[1;32mENTER THE Interest Rate(perMonth) OF THE Savings ACCOUNT : \033[0m";
    cin >> interestRate;
    //if interest rate is negetive it intialises to 3 which we can change later
    if (interestRate < 0)
    {
      this->interestRate = 3;
      cout << "\033[1;31mInterest rate(perMonth)  IS ASSIGNED TO 3.0 percent SINCE IT IS INVALID\n\033[1;35mYou can change it afterwards:)\033[0m" << endl;
    }
    else
      this->interestRate = interestRate;
    cout << "\033[1;34mSAVINGS ACCOUNT CREATED SUCCESSFULLY\033[0m" << endl;
  }
  //calculating the interest using ptr/100(per year)
  inline double calculateInterest()
  {
    return (this->balance * 12 * this->interestRate) / 100;
  }
};

//child inherited class checking account from parent account
class CheckingAccount : public Account
{
public:
  double feeChargePerTransaction;
  //default constructor for child checking account which also runs parent constructor and then the child initialising the fee charge per transaction
  CheckingAccount()
  {
    double feeChargePerTransaction;
    cout << "\033[1;32mENTER THE Fee Charge(perTransaction) OF THE Savings ACCOUNT : \033[0m";
    cin >> feeChargePerTransaction;
    if (feeChargePerTransaction < 0)
    {
      this->feeChargePerTransaction = 3;
      cout << "\033[1;31mFee Charge(perTransaction)  IS ASSIGNED TO 3 Rupees SINCE IT IS INVALID\n\033[1;35mYou can change it afterwards:)\033[0m" << endl;
    }
    else
      this->feeChargePerTransaction = feeChargePerTransaction;
    cout << "\033[1;34mCheckingAccount ACCOUNT CREATED SUCCESSFULLY\033[0m" << endl;
  }
  //function redesigned for checking account so as to deduct certain amount per transaction
  double credit(double amount)
  {
    if (amount < 0)
      cout << "\033[1;31mENTERED AMOUNT IS INVALID PLEASE TRY AGAIN\033[0m" << endl;
    else
    {
      this->balance += amount;
      //deducting fee charge
      this->balance -= this->feeChargePerTransaction;
      cout << "\033[1;34m" << amount << " - " << this->feeChargePerTransaction << " IS CREDITED TO ACCOUNT NO. " << this->accountNumber << " SUCCESSFULLY\033[0m" << endl;
    }
    return this->balance;
  }
  //function redesigned for checking account so as to deduct certain amount per transaction
  double debit(double amount)
  {
    if (amount < 0)
      cout << "\033[1;31mENTERED AMOUNT IS INVALID PLEASE TRY AGAIN\033[0m" << endl;
    else if (amount > this->balance)
      cout << "\033[1;31mENTERED AMOUNT EXCEEDS THE ACCOUNT BALANCE PLEASE TRY AGAIN\033[0m" << endl;
    else
    {
      this->balance -= amount;
      //deducting fee charge
      this->balance -= this->feeChargePerTransaction;
      cout << "\033[1;34m" << amount << " + " << this->feeChargePerTransaction << " IS DEBITED FROM ACCOUNT NO. " << this->accountNumber << " SUCCESSFULLY\033[0m" << endl;
    }
    return this->balance;
  }
};

//structure to store savings accounts
struct SavingsAccounts
{
  SavingsAccount savingsAccount;
  SavingsAccounts *link;
};
//structure to store checking accounts
struct CheckingAccounts
{
  CheckingAccount checkingAccount;
  CheckingAccounts *link;
};

//headers for saving and checking accounts
SavingsAccounts *savingsAccountsHead = NULL;
CheckingAccounts *checkingAccountsHead = NULL;

//creating new node for new account number and its type whenever new account is created
void updateAccounts(int accountNumber, int accountType)
{
  Accounts *current = new Accounts;
  current->accountNumber = accountNumber;
  current->accountType = accountType;
  current->link = NULL;
  if (accountsHead == NULL)
    accountsHead = current;
  else
  {
    Accounts *temp = accountsHead;
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = current;
  }
}

//updating saving accounts linked list for every savings account creation
double updateSavingsAccounts()
{
  SavingsAccounts *current = new SavingsAccounts;
  current->savingsAccount.createAccountNumber();
  current->link = NULL;
  //initiailising head
  if (savingsAccountsHead == NULL)
    savingsAccountsHead = current;
  else
  {
    SavingsAccounts *temp = savingsAccountsHead;
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = current;
  }
  return current->savingsAccount.accountNumber;
}

//updating checking accounts linked list for every checking account creation
double updateCheckingAccounts()
{
  CheckingAccounts *current = new CheckingAccounts;
  current->checkingAccount.createAccountNumber();
  current->link = NULL;
  //initiailising head
  if (checkingAccountsHead == NULL)
    checkingAccountsHead = current;
  else
  {
    CheckingAccounts *temp = checkingAccountsHead;
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = current;
  }
  return current->checkingAccount.accountNumber;
}

//function to check the account type from accounts linked list
int checkAccountType(int accountNumber)
{
  Accounts *temp = accountsHead;
  while (temp != NULL)
  {
    if (temp->accountNumber == accountNumber)
      return temp->accountType;
    temp = temp->link;
  }
  return temp->accountType;
}

//function which includes all the sub operations for saving account
void savingAccountOps(int accountNumber, int work)
{
  SavingsAccounts *temp = savingsAccountsHead;
  //travelling upto the node where input acc number can be found
  while (temp != NULL)
  {
    if (temp->savingsAccount.accountNumber == accountNumber)
      break;
    temp = temp->link;
  }
  //based on the work number that work is executed
  switch (work)
  {
  case 2:
  {
    double amount;
    cout << "Enter the amount you need to credit into your account: ";
    cin >> amount;
    amount = temp->savingsAccount.credit(amount);
    cout << "Balance after the credit: " << amount << endl;
  }
  break;
  case 3:
  {
    double amount;
    cout << "Enter the amount you need to debit from your account: ";
    cin >> amount;
    amount = temp->savingsAccount.debit(amount);
    cout << "Balance after the debit: " << amount << endl;
  }
  break;
  case 4:
  {
    double interestRate;
    cout << "Enter the new interestRate: ";
    cin >> interestRate;
    temp->savingsAccount.interestRate = interestRate;
    cout << "\033[1;34mINTEREST RATE SUCCESSFULLY CHANGED TO " << interestRate << " per month\033[0m" << endl;
  }
  break;
  case 5:
  {
    cout << "\033[1;35mInterest for acc no. " << accountNumber << " is " << temp->savingsAccount.calculateInterest() << " Per Year\033[0m" << endl;
  }
  break;
  case 6:
  {
    cout << "\033[1;35mInterest for acc no. " << accountNumber << " is " << temp->savingsAccount.calculateInterest() << " Per Year\033[0m" << endl;
    double interestRate;
    cout << "Enter the new interestRate: ";
    cin >> interestRate;
    temp->savingsAccount.interestRate = interestRate;
    cout << "\033[1;34mINTEREST RATE SUCCESSFULLY CHANGED TO " << interestRate << " per month\033[0m" << endl;
  }
  break;
  }
}

//function which includes all the sub operations for checking account
void checkingAccountOps(int accountNumber, int work)
{
  CheckingAccounts *temp = checkingAccountsHead;
  //travelling upto the node where input acc number can be found
  while (temp != NULL)
  {
    if (temp->checkingAccount.accountNumber == accountNumber)
      break;
    temp = temp->link;
  }
  //based on the work number that work is executed
  switch (work)
  {
  case 2:
  {
    double amount;
    cout << "Enter the amount you need to credit into your account: ";
    cin >> amount;
    amount = temp->checkingAccount.credit(amount);
    cout << "Balance after the credit: " << amount << endl;
  }
  break;
  case 3:
  {
    double amount;
    cout << "Enter the amount you need to debit from your account: ";
    cin >> amount;
    amount = temp->checkingAccount.debit(amount);
    cout << "Balance after the credit: " << amount << endl;
  }
  break;
  case 7:
  {
    double feeChargePerTransaction;
    cout << "Enter the new interestRate: ";
    cin >> feeChargePerTransaction;
    temp->checkingAccount.feeChargePerTransaction = feeChargePerTransaction;
    cout << "\033[1;34mFEE CHARGE SUCCESSFULLY CHANGED TO " << feeChargePerTransaction << " per transaction\033[0m" << endl;
  }
  break;
  case 8:
  {
    cout << "\033[1;35mFee Charge for acc no. " << accountNumber << " is " << temp->checkingAccount.feeChargePerTransaction << " Per Transaction\033[0m" << endl;
  }
  break;
  }
}

//main function which works on menu driven based programming
int main()
{
  cout << "-----Welcome to Institue Bank of IIITDM Kancheepuram-----" << endl;
  int choice = 1, accountType = 1, accountNumber;
  while (choice != 10)
  {
    cout << "\033[1;33m1. Open Account (Savings or Checking Account)" << endl;
    cout << "2. Credit (Savings or Checking Account)" << endl;
    cout << "3. Debit (Savings or Checking Account)" << endl;
    cout << "4. Change/Update Interest rate (Savings Account)" << endl;
    cout << "5. Calculate Interest (Savings Account - Print)" << endl;
    cout << "6. Calculate and Update Interest (Savings Account - Credit)" << endl;
    cout << "7. Change/Update Fee Amount (Checking Account)" << endl;
    cout << "8. Print Checking Fee (Checking Account)" << endl;
    cout << "9. Transact and Update (Checking Account - Debit)" << endl;
    cout << "10. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    //based on the choice of user that work is executed
    switch (choice)
    {
    case 1:
    {
      cout << "-----Account creation-----" << endl;
      while (1)
      {
        cout << "What type of account do you wanna create!?" << endl;
        cout << "\033[1;32m1. Savings account" << endl;
        cout << "2. Checking account\033[0m" << endl;
        cout << "Enter your choice: ";
        cin >> accountType;
        if (accountType == 1 || accountType == 2)
          break;
        cout << "\033[1;31mENTER A VALID CHOICE\033[0m" << endl;
      }
      if (accountType == 1)
      {
        updateAccounts(updateSavingsAccounts(), 1);
      }
      else
      {
        updateAccounts(updateCheckingAccounts(), 2);
      }
    }
    break;
    case 2:
    {
      cout << "-----CREDENTIALS for CREDIT-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else
      {
        accountType = checkAccountType(accountNumber);
        if (accountType == 1)
          savingAccountOps(accountNumber, choice);
        else
          checkingAccountOps(accountNumber, choice);
      }
    }
    break;
    case 3:
    {

      cout << "-----CREDENTIALS for DEBIT-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else
      {
        accountType = checkAccountType(accountNumber);
        if (accountType == 1)
          savingAccountOps(accountNumber, choice);
        else
          checkingAccountOps(accountNumber, choice);
      }
    }
    break;
    case 4:
    {
      cout << "-----CREDENTIALS for changing INTEREST RATE-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else if (checkAccountType(accountNumber) == 1)
        savingAccountOps(accountNumber, choice);
      else
        cout << "\033[1;31mACCOUNT EXIST BUT IT'S NOT A SAVING ACCOUNT\033[0m" << endl;
    }
    break;
    case 5:
    {
      cout << "-----CREDENTIALS for calculating Interest-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else if (checkAccountType(accountNumber) == 1)
        savingAccountOps(accountNumber, choice);
      else
        cout << "\033[1;31mACCOUNT EXIST BUT IT'S NOT A SAVING ACCOUNT\033[0m" << endl;
    }
    break;
    case 6:
    {
      cout << "-----CREDENTIALS for calculating interest and changing Interest rate-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else if (checkAccountType(accountNumber) == 1)
        savingAccountOps(accountNumber, choice);
      else
        cout << "\033[1;31mACCOUNT EXIST BUT IT'S NOT A SAVING ACCOUNT\033[0m" << endl;
    }
    break;
    case 7:
    {
      cout << "-----CREDENTIALS for changing Fee amount for checking account-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else if (checkAccountType(accountNumber) == 2)
        checkingAccountOps(accountNumber, choice);
      else
        cout << "\033[1;31mACCOUNT EXIST BUT IT'S NOT A CHECKING ACCOUNT\033[0m" << endl;
    }
    break;
    case 8:
    {
      cout << "-----CREDENTIALS for printing Fee amount for checking account-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else if (checkAccountType(accountNumber) == 2)
        checkingAccountOps(accountNumber, choice);
      else
        cout << "\033[1;31mACCOUNT EXIST BUT IT'S NOT A CHECKING ACCOUNT\033[0m" << endl;
    }
    break;
    case 9:
    {
      cout << "-----CREDENTIALS for transaction and update for checking account(debit)-----" << endl;
      cout << "Enter the account number: " << endl;
      cin >> accountNumber;
      if (!accountExist(accountNumber))
        cout << "\033[1;31mACCOUNT DOESN'T EXIST\033[0m" << endl;
      else if (checkAccountType(accountNumber) == 2)
        checkingAccountOps(accountNumber, 3);
      else
        cout << "\033[1;31mACCOUNT EXIST BUT IT'S NOT A CHECKING ACCOUNT\033[0m" << endl;
    }
    break;
    case 10:
      cout << "\033[1;31m-----PROGRAM EXITED BY THE USER-----\033[0m" << endl;
      break;
    default:
      cout << "\033[1;31m-----ENTER A VALID CHOICE-----\033[0m" << endl;
      break;
    }
  }
  return 0;
}