#NAME: V NAGASAI
#ROLL: CS20B1016
#TOWER OF HONOI PROBLEM WITH 3 DISKS AND 3 TOWERS BOTH RECURSIVE AND ITERATIVE SOLUTIONS

class Pole:
	def __init__(self, title):
		self.disks = list()
		self.title = title

def legal_movement(pole_X:Pole, pole_Y:Pole):
	len_X = len(pole_X.disks)
	len_Y = len(pole_Y.disks)
	disk, from_pole, to_pole = None, None, None
	if len_X != 0 or len_Y != 0:
		if len_X == 0:
			disk = pole_Y.disks.pop()
			pole_X.disks.append(disk)
			from_pole = pole_Y.title
			to_pole = pole_X.title
		elif len_Y == 0:
			disk = pole_X.disks.pop()
			pole_Y.disks.append(disk)
			from_pole = pole_X.title
			to_pole = pole_Y.title
		elif pole_X.disks[len_X - 1] > pole_Y.disks[len_Y - 1]:
			disk = pole_Y.disks.pop()
			pole_X.disks.append(disk)
			from_pole = pole_Y.title
			to_pole = pole_X.title
		else:
			disk = pole_X.disks.pop()
			pole_Y.disks.append(disk)
			from_pole = pole_X.title
			to_pole = pole_Y.title
	return (disk, from_pole, to_pole)


def recursive(disks, from_tower, to_tower, using_tower):
		if disks == 0:
				return
		recursive(disks - 1, from_tower, using_tower, to_tower)
		print(f"Disk - {disks}, {from_tower} -> {to_tower}")
		recursive(disks - 1, using_tower, to_tower, from_tower)

def iterative(disks, from_tower, to_tower, using_tower):
		from_pole = Pole(from_tower)
		from_pole.disks = [i for i in range(disks, 0, -1)]
		to_pole, using_pole = Pole(to_tower), Pole(using_tower)
		n = int(pow(2, disks))
		for i in range(1, n):
				if i%3 == 1:
						d, f, t = legal_movement(from_pole, to_pole)
						print(f"Disk - {d}, {f} -> {t}")
				elif i%3 == 2:
						d, f, t = legal_movement(from_pole, using_pole)
						print(f"Disk - {d}, {f} -> {t}")
				elif i%3 == 0:
						d, f, t = legal_movement(using_pole, to_pole)
						print(f"Disk - {d}, {f} -> {t}")

disks = 3
towers = ["a", "b", "c"]
from_tower = input(f"Enter from tower{towers}: ")
to_tower = input(f"Enter to tower{[tower for tower in towers if tower != from_tower]}: ")
using_tower = [x for x in towers if x != from_tower and x != to_tower][0]
print("----------Using Recursion----------")
recursive(disks, from_tower, to_tower, using_tower)
print("----------Using Iteration----------")
iterative(disks, from_tower, to_tower, using_tower)