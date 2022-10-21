import pandas as pd
import matplotlib.pyplot as plt
from colorama import Fore, Style


class DataVisualizer():
	def __init__(self):
		self.file_name = "diabetes1.csv"
		self.df = pd.read_csv(self.file_name)
	
	def describeData(self):
		print("-----Data description[Count, Mean, SD, Min, 25%, 50%, 75%, Max]-----")
		print(self.df.describe())
		print("-----Median-----")
		print(self.df.median())
		print("-----Mode-----")
		print(self.df.mode())
	
	def correlationCoefficients(self):
		others_df_excluding_outcome = self.df[[column for column in self.df.columns if column != "Outcome"]]
		print("-----Correlation Coefficient Matrix of Age with all other attributes excluding Outcome-----")
		print(others_df_excluding_outcome.corr()["Age"])
		print("-----Correlation Coefficient Matrix of BMI with all other attributes excluding Outcome-----")
		print(others_df_excluding_outcome.corr()["BMI"])

	def scatterPlotAge(self):
		age_df = self.df[["Age"]]
		other_columns = [column for column in self.df.columns if column != 'Outcome' and column != 'Age']
		other_dfs = [self.df[column] for column in other_columns]
		for index, df in enumerate(other_dfs):
			x_title = "Age"
			y_title = other_columns[index]
			plt.scatter(age_df, df)
			plt.title(f"Scatter Plot Between {x_title} and {y_title}")
			plt.xlabel(x_title)
			plt.ylabel(y_title)
			plt.show()

	def scatterPlotBMI(self):
		age_df = self.df[["BMI"]]
		other_columns = [column for column in self.df.columns if column != 'Outcome' and column != 'BMI']
		other_dfs = [self.df[column] for column in other_columns]
		for index, df in enumerate(other_dfs):
			x_title = "BMI"
			y_title = other_columns[index]
			plt.scatter(age_df, df)
			plt.title(f"Scatter Plot Between {x_title} and {y_title}")
			plt.xlabel(x_title)
			plt.ylabel(y_title)
			plt.show()

	def histPregnanciesSkinThickness(self):
		self.df[["Pregnancies"]].hist()
		self.df[["SkinThickness"]].hist()
		plt.show()

	def histPregnanciesGroupby(self):
		self.df[["Pregnancies", "Outcome"]].groupby("Outcome").hist()
		plt.show()
	
	def boxplot(self):
		plt.figure(figsize=(15, 5))
		self.df[[column for column in self.df.columns]].boxplot()
		plt.show()


if __name__ == "__main__":
	data_visualizer = DataVisualizer()
	choice = 1
	while(1):
		print("\n" + Fore.BLUE + "1. Describe data [Mean, median, mode, min, max and standard deviation of each column]")
		print("2. Correlation Coefficients of Age with all other attributes except Outcome")
		print("3. Scatter plot of Age with other attributes except Outcome")
		print("4. Scatter plot of BMI with other attributes except Outcome")
		print("5. Histogram of Pregnancies and thickness")
		print("6. Histogram of Pregnancies grouped by outcome")
		print("7. Boxplot of all the attributes except Outcome")
		print("8. Exit\n")
		choice = int(input(Style.BRIGHT + Fore.GREEN + "Enter your choice: "))
		print(Style.RESET_ALL + "\n")
		if choice == 1:
			data_visualizer.describeData()
		elif choice == 2:
			data_visualizer.correlationCoefficients()
		elif choice == 3:
			data_visualizer.scatterPlotAge()
		elif choice == 4:
			data_visualizer.scatterPlotBMI()
		elif choice == 5:
			data_visualizer.histPregnanciesSkinThickness()
		elif choice == 6:
			data_visualizer.histPregnanciesGroupby()
		elif choice == 7:
			data_visualizer.boxplot()
		elif choice == 8:
			print("Program exited")
			exit(0)
		else:
			print('Please enter a valid choice')
