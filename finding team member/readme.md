# problem
2N contestants want to form N teams of 2 people each. Every contestant has a **distinct** strength value, and wants to team up with the highest available strenght contestant. 

A and B will form a team is each of them is the best possible teammate for the other one.

input:

1. number of teams to be formed
2. i lines containing the strength of each possible team (i, j).
	- every line is an i in [2...N]
	- every line element is a j in [1...i-1]

es.
2  teams

6   ---> (2,1)  
1 2   ---> (3,1) (3,2) 
3 4 5 ---> (4,1) (4,2) (4,3)

output:
a line of 2N numbers where i represent the number of teammate chosed by contestant i.

## solution
- need to check for memeber availability

1. team member boolean array to check for availability
2. insert input team combinations in ordered set, saving combined strenght and team members.
3. iterate through set and greedily extract strongest groups until N teams are extracted.