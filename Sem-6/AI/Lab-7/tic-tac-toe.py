import sys

class TicTacToe:
		def __init__(self):
				self.config = [['-', '-', '-'], ['-', '-', '-'], ['-', '-', '-']]
				self.turn = 'X'
		
		def print_config(self):
			print()
			print("+---+---+---+")
			print(f"| {self.config[0][0]} | {self.config[0][1]} | {self.config[0][2]} |")
			print("+---+---+---+")
			print(f"| {self.config[1][0]} | {self.config[1][1]} | {self.config[1][2]} |")
			print("+---+---+---+")
			print(f"| {self.config[2][0]} | {self.config[2][1]} | {self.config[2][2]} |")
			print("+---+---+---+")
			print()
		
		def is_valid_movement(self, x, y):
			if x < 0 or x > 2 or y < 0 or y > 2:
				return False
			elif self.config[x][y] != '-':
				return False
			return True
		
		def is_final_state(self):
			#Vertical
			for i in range(3):
				if self.config[0][i] != '-' and self.config[0][i] == self.config[1][i] and self.config[0][i] == self.config[2][i]:
					return self.config[0][i]
			#Horizontal
			for i in range(3):
				if self.config[i][0] != '-' and self.config[i][0] == self.config[i][1] and self.config[i][0] == self.config[i][2]:
					return self.config[i][0]
			#Diagonal
			if self.config[0][0] != '-' and self.config[0][0] == self.config[1][1] and self.config[0][0] == self.config[2][2]:
					return self.config[0][0]
			if self.config[0][2] != '-' and self.config[0][2] == self.config[1][1] and self.config[0][2] == self.config[2][0]:
					return self.config[0][2]
			#Still moves left
			for i in range(3):
				for j in range(3):
					if self.config[i][j] == '-':
						return None
			#Tie
			return '-'

		def maximize(self):
			alpha = - sys.maxsize - 1
			x, y = None, None
			res = self.is_final_state()
			if(res == 'X'):
				return (-1, 0, 0)
			elif (res == 'O'):
				return (1, 0, 0)
			elif (res == '-'):
				return (0, 0, 0)
			
			for i in range(3):
				for j in range(3):
					if self.config[i][j] == '-':
						self.config[i][j] = 'O'
						(beta, _, _) = self.minimize()
						if beta > alpha:
							alpha = beta
							x, y = i, j
						self.config[i][j] = '-'
			return (alpha, x, y)
		
		def minimize(self):
			beta = sys.maxsize
			x, y = None, None
			res = self.is_final_state()
			if(res == 'X'):
				return (-1, 0, 0)
			elif (res == 'O'):
				return (1, 0, 0)
			elif (res == '-'):
				return (0, 0, 0)
			
			for i in range(3):
				for j in range(3):
					if self.config[i][j] == '-':
						self.config[i][j] = 'X'
						(alpha, _, _) = self.maximize()
						if alpha < beta:
							beta = alpha
							x, y = i, j
						self.config[i][j] = '-'
			return (alpha, x, y)

		def play(self):
			while True:
				self.print_config()
				res = self.is_final_state()
				if res != None:
					if(res == 'X'):
						print("You Win 🥳")
					elif (res == 'O'):
						print("You Lose 😛")
					elif (res == '-'):
						print("Match Tied 🎀!")
					return
				if self.turn == 'X':
					print("Your turn..👻")
					while True:
						print("Please Enter your choices...")
						x = int(input("X index of array: "))
						y = int(input("Y index of array: "))
						if self.is_valid_movement(x, y):
							self.config[x][y] = 'X'
							self.turn = 'O'
							break
						else:
							print("Invalid movement 💥")
				else:
					print("My move goes here ..😉")
					_, x, y = self.maximize()
					self.config[x][y] = 'O'
					self.turn = 'X'
		

if __name__ == "__main__":
	game = TicTacToe()
	game.play()