#NAME: V NAGASAI
#ROLL: CS20B1016
#TWO JUG PROBLEM USING ARITHMETIC PROCEDURE VIA DIOPHANTINE EQUATION AND EXTENDED EUCLIDEAN ALGORITHM

def gcd(a, b):
	if a == 0:
		return b
	return gcd(b%a, a)

def pour_water(from_jug_capacity, to_jug_capacity, target_water):
	from_jug = from_jug_capacity
	to_jug = 0
	steps = 1
	while from_jug != target_water and to_jug != target_water:
		water = min(from_jug, to_jug_capacity-to_jug)
		to_jug += water
		from_jug -= water
		steps += 1
		if from_jug == target_water or to_jug == target_water:
			break
		if from_jug == 0:
			from_jug = from_jug_capacity
			steps += 1
		if to_jug == to_jug_capacity:
			to_jug = 0
			steps += 1
	return steps

def min_steps(jug_a, jug_b, target_water):
	if jug_a < jug_b:
		jug_a, jug_b = jug_b, jug_a
	if (target_water%gcd(jug_a, jug_b) != 0):
		return -1
	return min(pour_water(jug_a, jug_b, target_water), pour_water(jug_b, jug_a, target_water))


a = int(input("Enter Jug A capacity: "))
b = int(input("Enter Jug B capacity: "))
target = int(input("Enter target water capacity: "))

print("Minimum number of steps required: ", min_steps(a, b, target))