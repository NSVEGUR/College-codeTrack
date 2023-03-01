MAX_WEIGHT = 400

items = [
		{"name": "item1", "cost": 1000, "weight": 10},
		{"name": "item2", "cost": 2000, "weight": 100},
		{"name": "item3", "cost": 4000, "weight": 300},
		{"name": "item4", "cost": 5000, "weight": 1},
		{"name": "item5", "cost": 5000, "weight": 200},
]

def greedy(items):
	items = sorted(items, key = lambda x: x["cost"] / x["weight"], reverse = True)
	knapsack = {
		"items": [],
		"cost": 0,
		"weight": 0,
	}
	for item in items:
		if knapsack["weight"] + item["weight"] > MAX_WEIGHT:
			break
		knapsack["items"].append(item["name"])
		knapsack["cost"] += item["cost"]
		knapsack["weight"] += item["weight"]
	return knapsack


if __name__ == "__main__":
	print(greedy(items))