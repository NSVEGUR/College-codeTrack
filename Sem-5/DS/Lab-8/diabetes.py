#Name: V Nagasai
#Roll: CS20B1016
import pandas as pd

class Diabetes():
	def __init__(self):
		self.file_name = "diabetes.csv"
		self.df = pd.read_csv(self.file_name)
		#Removing the not required NaN column "Type"
		self.df.drop("Type", inplace=True, axis=1)
	
	def totalProbability(self):
		count = 0
		for _, row in self.df.iterrows():
			if row["Outcome"] == 1:
				count += 1
		return count/len(self.df.index)

	def aboveCertainAge(self, age):
		diabetic = 0
		count = 0
		for _, row in self.df.iterrows():
			if row["Age"] > age:
				count += 1
				if row["Outcome"] == 1:
					diabetic += 1
		return diabetic/count
	
	def betweenCertainAge(self, age1, age2):
		diabetic = 0
		count = 0
		for _, row in self.df.iterrows():
			if row["Age"] > age1 and row["Age"] < age2:
				count += 1
				if row["Outcome"] == 1:
					diabetic += 1
		return diabetic/count

	def belowCertainAge(self, age):
		diabetic = 0
		count = 0
		for _, row in self.df.iterrows():
			if row["Age"] < age:
				count += 1
				if row["Outcome"] == 1:
					diabetic += 1
		return diabetic/count

	def glucoseBPSkinInsulinBMI(self, glucose, BP, skinThickness, Insulin, BMI):
		count = 0
		for _, row in self.df.iterrows():
			if row["Outcome"] == 1:
				if row["Glucose"] > glucose and row["BloodPressure"] > BP and row["SkinThickness"] > skinThickness and row["Insulin"] > Insulin and row["BMI"] > BMI:
					count += 1
		return count/len(self.df.index)




if __name__ == "__main__":
	diabetes = Diabetes()
	choice = 1
	while(choice != 3):
		print("1. Total Probability and Based on certain age groups")
		print("2. Based on certain glucose, bp and other levels")
		print("3. Exit")
		try:
			choice = int(input("Please enter your choice: "))
		except ValueError:
			print("Please Enter a valid choice.")
			continue
		if(choice == 1):
			print(f"Total Probability of getting diabetes given dataset: {diabetes.totalProbability()}")
			print(f"Probability of getting diabetes given age above 50: {diabetes.aboveCertainAge(50)}")
			print(f"Probability of getting diabetes given age between 40 and 50: {diabetes.betweenCertainAge(40, 50)}")
			print(f"Probability of getting diabetes given age between 30 and 40: {diabetes.betweenCertainAge(30, 40)}")
			print(f"Probability of getting diabetes given age below 30: {diabetes.belowCertainAge(30)}")
		elif(choice == 2):
			print(f"Probability of getting diabetes given glucose > 120, BP > 90, skin thickness > 30, insulin > 150, BMI > 25: {diabetes.glucoseBPSkinInsulinBMI(120, 90, 30, 150, 25)}")
		elif(choice == 3):
			print("Program exited by user")
			exit(0)
		else:
			print("Please enter a valid choice.")