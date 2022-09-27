import pandas as pd

class RailwayTickets():
		def __init__(self):
			self.file_name = "railway_db.csv"
			df = pd.DataFrame({
					"PassengerName": ["Ravindar", "Nagasai", "Vinay", "Praneeth", "Harsha"],
					"BookingDate": ["26-09-2022", "24-09-2022", "25-09-2022", "26-09-2022", "25-09-2022"],
					"CoachNo": ["S3", "S4", "B2", "A1", "B3"],
					"SeatNo": [12, 3, 23, 1, 15],
					"Source": ["Warangal", "Tirupati", "Vijayawada", "Tirupati", "Hyderabad"],
					"Destination": ["Tambaram", "Tambaram", "Chrompet", "Chennai", "Chennai"],
					"TicketPrice": [1000, 500, 1900, 4500, 1750]
			})
			df.to_csv(self.file_name, index=False)

		def findByDestination(self):
			print("\n-----Finding By Destination-----\n")
			destination = input("Enter the destination(string): ")
			df = pd.read_csv(self.file_name, index_col="Destination")
			try:
				details = df.loc[destination]
				print(details)
			except:
				print("There are no passengers with entered destination")

		def appendRecord(self):
			print("\n-----Appending Record----\n")
			df = pd.read_csv(self.file_name)
			try:
				passenger_name = input("Enter the passenger name(string): ")
				booking_date = input("Enter the booking date(string): ")
				coach_no = input("Enter the coach number(string): ")
				seat_no = input("Enter the seat number(integer): ")
				source = input("Enter the source(string): ")
				destination = input("Enter the destination(string): ")
				ticket_price = input("Enter the ticket price(integer): ") 
				passenger = [passenger_name, booking_date, coach_no, seat_no, source, destination, ticket_price]
				df.loc[len(df.index)] = passenger
				df.to_csv(self.file_name, index=False)
			except:
				print("Error occurred while appending data")
			
		def totalTicketPrice(self):
			df = pd.read_csv(self.file_name)
			total_ticket_price = 0
			try:
				for _, row in df.iterrows():
					total_ticket_price += row["TicketPrice"]
				print(f"\n-----Total ticket price is : {total_ticket_price}-----\n")
			except:
				print("Error occurred while finding the total ticket price")

if __name__ == "__main__":
	rt = RailwayTickets()
	choice = 1
	print("\n-----Railway Ticket Database-----\n")
	while(choice!=4):
		print("1. Printing details given destination")
		print("2. Append Record")
		print("3. Find the total ticket price")
		print("4. Exit")
		choice = int(input("Enter your choice: "))
		if(choice == 1):
			rt.findByDestination()
		elif(choice == 2):
			rt.appendRecord()
		elif(choice == 3):
			rt.totalTicketPrice()
		elif(choice == 4):
			print("Program exited by the user")
			exit(0)
		else:
			print("Please enter a valid choice")
