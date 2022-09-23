import pandas as pd

class Aadhar():
	def __init__(self):
		self.file_name = "Aadhar_DB.csv"
		table = pd.DataFrame({
		"Name": ["Ram", "Sam", "Prabhu", "Nagasai", "Bhanu"],
		"AadharNo": [959389389173, 959389389179, 959389389159, 123456789012, 324516897642],
		"ContactNumber": [8912347868, 1279287456, 4567389274, 8743892888, 9972784874],
		"DOB": ["12-2-1990", "12-2-2000", "12-2-2010", "13-9-2002", "14-9-1984"],
		"Address": ["No 23, Kandigai, Chennai 127", "No 27, Melakottaiyur, Chennai 127", "No 43, Anna Nagar, Chennai 102", "No 20, HiredinniCamp, Raichur 120", "No 20, HiredinniCamp, Raichur 120"]
		})
		table.to_csv(self.file_name, index=False)

class Bank():
	def __init__(self):
		self.file_name = "SBIAccountHolder.csv"
		self.final_file = "FinalSBIAccountHolder.csv"
		table = pd.DataFrame({
		"Name": ["Ram", "Sam", "Prabhu", "Nagasai", "Bhanu"],
		"AccountNumber": [9893893891, 9893893898, 9893893871, 9019859516, 9110667707],
		"AccountType": ["SB", "CA", "SB", "SB", "CA"],
		"AadharNo": [959389389173, 959389389179, 959389389159, 123456789012, 324516897642],
		"Balance": [8989839, 7690990, 989330, 80000, 90000]
		})
		table.to_csv(self.file_name, index=False)

	def appendRecord(self):
		table = pd.read_csv(self.file_name)
		print("\n-----Welcome to SBI Account Creation-----\n")
		name = input("Please enter your name: ")
		accountNumber = int(input("Enter 10 digits account number provided to you: "))
		accountType = input("Enter your account type[SB/CA]: ")
		adhaarNo = int(input("Enter your 12 digits adhaar number: "))
		balance = int(input("Please Enter initial amount to start account: "))
		while(balance<=1000):
			print("Please enter amount greater than thousand.")
			balance = int(input("Please Enter initial amount to start account: "))
		account = [name, accountNumber, accountType, adhaarNo, balance]
		table.loc[len(table.index)] = account
		table.to_csv(self.file_name, index=False)
		print("\n-----Your account created successfully-----\n")

	def deleteRecord(self):
		table = pd.read_csv(self.file_name, index_col=["AccountNumber"])
		print("\n-----Welcome to SBI Account Deletion-----\n")
		accountNumber = int(input("Please enter your 10 digit account number: "))
		try:
			table.drop([accountNumber], inplace=True, axis=0)
			table.to_csv(self.file_name)
			print("\n-----Your account deleted successfully-----\n")
		except:
			print("Account number does not exist.")

	def credit(self):
		table = pd.read_csv(self.file_name, index_col=["AccountNumber"])
		print("\n-----Welcome to SBI Account Credit-----\n")
		accountNumber = int(input("Please enter your 10 digit account number: "))
		try:
			print(f'----Hello {table.loc[accountNumber, "Name"]}-----')
			amount = int(input("Please enter the amount to add: "))
			table.loc[accountNumber, "Balance"] += amount
			table.to_csv(self.file_name)
			print("\n-----Amount credited to your account successfully-----\n")
		except:
			print("Account number does not exist")

	def debit(self):
		table = pd.read_csv(self.file_name, index_col=["AccountNumber"])
		print("\n-----Welcome to SBI Account Debit-----\n")
		accountNumber = int(input("Please enter your 10 digit account number: "))
		try:
			print(f'----Hello {table.loc[accountNumber, "Name"]}-----')
			balance = table.loc[accountNumber, "Balance"]
			amount = int(input("Please enter the amount to draw: "))
			accountType = table.loc[accountNumber, "AccountType"]
			if(accountType=="SB" and balance-amount<0):
				print(f"Funds are not enough to draw {amount} from your saving account.")
				return
			table.loc[accountNumber, "Balance"] -= amount
			table.to_csv(self.file_name)
			print("\n-----Amount debited from your account successfully-----\n")
		except:
			print("Account number does not exist")

	def details(self):
		table = pd.read_csv(self.file_name, index_col=["AccountNumber"])
		print("\n-----Welcome to SBI Account Details-----\n")
		accountNumber = int(input("Please enter your 10 digit account number: "))
		try:
			name = table.loc[accountNumber, "Name"]
			balance = table.loc[accountNumber, "Balance"]
			accountType = table.loc[accountNumber, "AccountType"]
			adhaarNo = table.loc[accountNumber, "AadharNo"]
			print(f"Name: {name}\nAccountNumber: {accountNumber}\nAccountType: {accountType}\nAdhaarNo: {adhaarNo}\nBalance: {balance}")
		except:
			print("Account number does not exist")

	def mergeAadharDB(self, aadhar):
		table1 = pd.read_csv(self.file_name, index_col="AadharNo")
		table2 = pd.read_csv(aadhar.file_name, index_col="AadharNo")
		table2 = table2.drop(["Name"], axis=1)
		table3 = pd.concat([table1, table2], axis=1).reindex(table1.index)
		table3.to_csv(self.final_file)

if __name__ == "__main__":
	bank = Bank()
	aadhar = Aadhar()
	choice = 1
	while(choice!=6):
		print("1. Append record(row) of a Account Holder")
		print("2. Delete record(row) given Account Number")
		print("3. Credit to the Account Given Account Number")
		print("4. Debit from the Account Given Account Number")
		print("5. Print Account details given Account Number")
		print("6. Exit")
		choice = int(input("Enter your choice: "))
		if(choice == 1):
			bank.appendRecord()
		elif(choice == 2):
			bank.deleteRecord()
		elif(choice == 3):
			bank.credit()
		elif(choice == 4):
			bank.debit()
		elif(choice == 5):
			bank.details()
		elif(choice == 6):
			print("\n-----Bank Editing is ended by the user-----\n")
			continue
		else:
			print("Please enter a valid choice")
	bank.mergeAadharDB(aadhar)
	print(f"\n-----Bank details merged with aadhar DB and saved to file {bank.final_file}-----\n")