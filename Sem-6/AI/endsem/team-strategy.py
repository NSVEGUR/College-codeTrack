# ROLL: CS20B1016
# Name: V Nagasai

# Design a team-based strategy game where there are two teams, Team A and Team B, each consisting of multiple players. 
# Each player can move up, down, left, or right on a 2D grid. The goal of the game is for one team to eliminate all the 
# members of the other team. The elimination can happen in two ways: either one team eliminates all the members of the
# other team by landing on the same cell as their opponent or one team traps the other team against the edge of the grid 
# so that they have nowhere to move. The players move alternatively, and Team A always starts.

# Write a program that implements the game and allows two players to play against each other 
# (one user and one computer player). The game ends when either Team A eliminates all members of Team B or Team B
# eliminates all members of Team A.



import random

class Game:
		def __init__(self, num_players, grid_size):
				self.num_players = num_players
				self.grid_size = grid_size
				self.current_player = "A"
				self.game_over = False
				self.__initialise__()
				
		#initializing random positions for players at start
		def __initialise__(self):
				self.team_a = [(random.randint(0, self.grid_size - 1), random.randint(0, self.grid_size - 1)) for _ in range(self.num_players)]
				self.team_b = [(random.randint(0, self.grid_size - 1), random.randint(0, self.grid_size - 1)) for _ in range(self.num_players)]

				for i in self.team_a:
						if i in self.team_b:
								self.team_b = [(random.randint(0, self.grid_size - 1), random.randint(0, self.grid_size - 1)) for _ in range(self.num_players)]

				for i in self.team_a:
						if self.team_a.count(i)>=2:
								self.team_a = [(random.randint(0, self.grid_size - 1), random.randint(0, self.grid_size - 1)) for _ in range(self.num_players)]

				for i in self.team_b:
						if i in self.team_a:
								self.team_a = [(random.randint(0, self.grid_size - 1), random.randint(0, self.grid_size - 1)) for _ in range(self.num_players)]

				for i in self.team_b:
						if self.team_b.count(i)>=2:
								self.team_b = [(random.randint(0, self.grid_size - 1), random.randint(0, self.grid_size - 1)) for _ in range(self.num_players)]

		#To check whether the move is valid or not
		def is_valid_move(self, pos, move, grid_size):
				x, y = pos
				dx, dy = move
				new_pos = (x + dx, y + dy)
				return 0 <= new_pos[0] < grid_size and 0 <= new_pos[1] < grid_size

		#To check the winning status of current player
		def has_won(self, game_state, team):
				for pos, player in game_state.items():
						if player['team'] != team:
								continue
						for dx, dy in [(0,1), (0,-1), (1,0), (-1,0)]:
								if self.is_valid_move(pos, (dx, dy), self.grid_size):
										new_pos = (pos[0]+dx, pos[1]+dy)
										if new_pos in game_state and game_state[new_pos]['team'] != team:
												return False
				return True

		#Move of user (Human)
		def user_move(self, game_state):
				while True:
						pos_str = input('Select a player to move (x,y): ')
						pos = tuple(map(int, pos_str.split(',')))
						if pos not in game_state or game_state[pos]['team'] != 'A':
								print('Invalid position')
								continue
						move_str = input('Select a move (u/d/l/r): ')
						if move_str == 'u':
								move = (-1,0)
						elif move_str == 'd':
								move = (1,0)
						elif move_str == 'l':
								move = (0,-1)
						elif move_str == 'r':
								move = (0,1)
						else:
								print('Invalid move')
								continue
						if self.is_valid_move(pos, move, self.grid_size):
								new_pos = (pos[0]+move[0], pos[1]+move[1])
								if new_pos in game_state:
										print('Player eliminated!')
										del game_state[new_pos]
								game_state[new_pos] = game_state[pos]
								del game_state[pos]
								break
						else:
								print('Invalid move')

		#Move of computer (AI)
		def computer_move(self, game_state):
				for pos, player in game_state.items():
						if player['team'] == 'B':
								for dx, dy in [(0,1), (0,-1), (1,0), (-1,0)]:
										if self.is_valid_move(pos, (dx, dy), self.grid_size):
												new_pos = (pos[0]+dx, pos[1]+dy)
												if new_pos not in game_state:
														game_state[new_pos] = player
														del game_state[pos]
														return
												elif game_state[new_pos]['team'] == 'A':
														print('Computer eliminated your player!')
														del game_state[new_pos]
														del game_state[pos]
														return


		#function to display the current state
		def display_state(self):
			state = [['-' for _ in range(self.grid_size)] for _ in range(self.grid_size)]
			for position in self.team_a:
				x, y = position
				state[x][y] = 'A'
			for position in self.team_b:
					x, y = position
					state[x][y] = 'B'
			for i in range(self.grid_size):
				for j in range(self.grid_size):
					print(state[i][j], end=" ")
				print("")
			print("\n")

		#Start the game and run in loop till the game is over
		def play(self):
			print("\nInput example: 1,up  [for player 1 and direction up(`separated by comma`)]\n")
			print("Players numbers available: Input given at start, 1 to x.")
			print("Directions available: up, down, right, left\n")

			print("\nA -> indicates HUMAN(you)")
			print("B -> indicates AI(computer)\n")
			while not self.game_over:
					# display current state of game
					self.display_state()

					# get move from player
					if self.current_player == "A":
							print("Player A's turn")
							player = self.team_a
							opponent = self.team_b
					else:
							print("Player B's turn")
							player = self.team_b
							opponent = self.team_a

					# check if player has won
					if len(opponent) == 0:
							print(f"Player {self.current_player} has won!")
							game_over = True
							continue

					# make move for player
					if self.current_player == "A":
							move = input("Enter move (player, direction): ")
							player_idx, direction = move.split(",")
							player_idx = int(player_idx) - 1
							direction = direction.strip().lower()

							# check if move is valid
							pos = player[player_idx]
							if direction == "up":
									move = (-1, 0)
							elif direction == "down":
									move = (1, 0)
							elif direction == "left":
									move = (0, -1)
							elif direction == "right":
									move = (0, 1)
							else:
									print("Invalid direction. Please try again.")
									continue

							if not self.is_valid_move(pos, move, self.grid_size):
									print("Invalid move. Please try again.")
									continue

							# update position of player
							new_pos = (pos[0] + move[0], pos[1] + move[1])
							player[player_idx] = new_pos

					else:
							# computer player logic
							# choose a random player to move
							player_idx = random.randint(0, len(player) - 1)
							pos = player[player_idx]
							
							# choose a random direction to move in
							possible_moves = [(0, -1), (0, 1), (-1, 0), (1, 0)]
							valid_moves = [move for move in possible_moves if self.is_valid_move(pos, move, self.grid_size)]
							move = random.choice(valid_moves)
							
							# update position of player
							new_pos = (pos[0] + move[0], pos[1] + move[1])
							player[player_idx] = new_pos


					# check if player has won
					for i, pos in enumerate(opponent):
							if pos in player:
									print(f"Player {self.current_player} has eliminated player {i+1} of the opposite team.")
									opponent.remove(pos)

					# switch to next player
					if self.current_player == "A":
							self.current_player = "B"
					else:
							self.current_player = "A"

					# check if game is over
					if len(self.team_a) == 0 or len(self.team_b) == 0:
							print("Game over.")
							game_over = True


if __name__ == '__main__':
	num_players = int(input("Enter the number of players on each team: "))
	grid_size = int(input("Enter the size of the grid: "))
	game = Game(num_players, grid_size)
	game.play()