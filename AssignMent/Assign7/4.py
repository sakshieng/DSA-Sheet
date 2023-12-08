x = [[1,25,10],
    [3,2,9],
    [4,6,3]]

y = [[4,6,7],
    [1,5,6],
    [7,6,3]]

result = [[0,0,0],
         [0,0,0],
         [0,0,0]]


for i in range(len(x)):

   for j in range(len(y[0])):
      
       for k in range(len(y)):
           result[i][j] += x[i][k] * y[k][j]

for ans in result:
   print(ans)
