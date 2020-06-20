each of the cell has  a direction east /west this dimension is n*m from 1 u need to go n*m u can change tje directioin in a cell by changing one direction by cost 

p2)u are given a graph with many islands u need to find the minimum number of boxes which u must built a bridge from to connect all the islands
There is always an X which when connected to n islands individualy gives the optimal answer

for every cell find out the shortest path for each of the components

do  a multisource bfs 0/1 from componenets of 1 to all others cell
dis[a][i][j] means distance of a cell[i,j]  from 'a'component (1,2,3)


there exist an X and find the shortest path to each of the connected point  
if  it is an empty cell then subtract 2 from it

Revise Dail's algorithm()

online queuries mean  that ur solution can process each query before reading that come after it.offline means that ur solution reads all the queris then process them together