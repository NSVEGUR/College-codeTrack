#TSP using simulated annealing

import numpy as np
import random
import math
import copy
import matplotlib.pyplot as plt

n=15
cities_coordinates=[]
cities=[]
for i in range(n):
    cities.append(chr(i+65))
    l=[]
    a=random.randint(0,10)
    b=random.randint(0,10)
    l.append(a)
    l.append(b)
    cities_coordinates.append(l)

graph=np.zeros((n,n))

for i in range(n):
    for j in range(n):
        graph[i][j]=math.dist(cities_coordinates[i],cities_coordinates[j])

curr_route=np.random.permutation(cities)
temp=1e+10
r=0.97
optimal_dist=[]
dist=[]
curr_dist=0
for k in range(n):
        if k<n-1:
            curr_dist+=graph[ord(curr_route[k])-65][ord(curr_route[k+1])-65]
        else:
            curr_dist+=graph[ord(curr_route[k])-65][ord(curr_route[0])-65]

ite=0
opt_dst=curr_dist
opt_route=curr_route
while temp>1:
    print("\n==========================================")
    print(f"Current route : {curr_route}\tDistance : {curr_dist}\tTemperature : {temp}")

    i,j=random.sample(range(n), 2)
    route=copy.deepcopy(curr_route)
    route[i],route[j]=route[j],route[i]
    distance=0
    for k in range(n):
        if k<n-1:
            distance+=graph[ord(curr_route[k])-65][ord(curr_route[k+1])-65]
        else:
            distance+=graph[ord(curr_route[k])-65][ord(curr_route[0])-65]

    if distance < opt_dst:
        opt_dst=distance
        opt_route=route

    if curr_dist > distance:
            curr_route=route
            curr_dist=distance
    else:
        prob=np.exp(-(distance-curr_dist)/temp)
        if prob>random.uniform(0,1):
            curr_route=route
            curr_dist=distance

    optimal_dist.append(opt_dst)
    dist.append(distance)
    temp=temp*r
    ite+=1

print("\n==========================================")
print(f"Optimal route : {opt_route}\tDistance : {opt_dst}")

plt.subplot(1,2,1)
plt.plot(range(ite), dist)
plt.plot(range(ite), optimal_dist)
plt.xlabel("Iterations")
plt.ylabel("Cost")

x_cord=[]
y_cord=[]
for i in range(n):
    a,b=cities_coordinates[ord(opt_route[i])-65][0],cities_coordinates[ord(opt_route[i])-65][1]
    x_cord.append(a)
    y_cord.append(b)

plt.subplot(1,2,2)
plt.scatter(x_cord, y_cord, c='blue')
for i in range(n):
    plt.annotate(opt_route[i], (x_cord[i]+0.1, y_cord[i]+0.2))

x_cord.append(x_cord[0])
y_cord.append(y_cord[0])
plt.plot(x_cord, y_cord, color='green')
plt.title(f"optimal distance = {round(opt_dst)}")

plt.show()