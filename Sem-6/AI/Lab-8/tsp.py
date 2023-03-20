# In the TSP,  given a set of cities and the distance between each pair of cities, a salesman needs to choose the shortest path to visit every city exactly once and return to the city from where he started. Here, the nodes represent cities, and the values in each edge denote the distance between one city to another. Here the shortest path means the sum of the distance between each city travelled by the salesman, and it should be less than any other path. Implement Simulated Annealing (SA) algorithm to solve the above problem. 

# Implement your algorithm based on following points

# Randomly take 15 cities as 2D random points (x,y) on a grid (0<x<10, 0<y<10)
# Distance between two cities is the Euclidean distance between two corresponding points on the grid
# Randomly take one point as the starting city
# Plot the points and show the initial path taken
# Write the SA optimization algorithm. Do not use predefined libraries to perform SA 
# Take the starting temperature as 1e+10 and the temperature schedule as a GP progression of cooling factor 0.97
# Experiment for different starting temperatures and cooling factors
# Plot the iteration vs cost graph during the optimization
# Plot the final solution and corresponding cost
# What will happen if you take the temperature schedule as AP series
# Link: https://towardsdatascience.com/optimization-techniques-simulated-annealing-d6a4785a1de7