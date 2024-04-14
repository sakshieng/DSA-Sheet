'''1
print("Enter the Count of Row = ",end=" ")
row=int(input())
#  Triangel pattren  # 
k = row - 1
for i in range(0, row):
   
    for j in range(0,k) :
        print(end=" ")
    k=k-1
    for j in range(0, i+1):
        print("* ", end="")
    print("\r")    
'''
'''2
print("Enter the Count of Row = ",end=" ")
row=int(input())
k = 2 * row - 2
for i in range(row, -1, -1):
    for j in range(k, 0, -1):
        print(end=" ")
    k = k + 1
    for j in range(0, i + 1):
        print("* ", end="")
    print("")
'''
'''3
print("Enter the Count of Row = ",end=" ")
row=int(input()) # diamond shape
n=0
for i in range (1,row+1) :
    for j in range (1,(row-i)+1) :
        print(end=" ")
    while n!=(2*i-1):
        print("*", end="")
        n=n+1
    n=0
    print()
k=1
n=1
for i in range(1,row):
    for j in range (1,k+1):
        print(end=" ")
    k=k+1
    while n<= (2*(row-i)-1):
        print("*",end = "")
        n=n+1
    n=1
    print()   
'''
'''4
print("Enter the Count of Row = ",end=" ")
row=int(input())
for i in range (row,0,-1) :
    for j in range (i,0,-1):
        print("*",end=" ")
    for j in range (2*(row-i)):
        print(" ",end=" ")
    for j in range (i,0,-1):
        print("*",end=" ")
    print()
for i in range (1,row) :
    for j in range (i+1):
        print("*",end=" ")
    for j in range (2*(row-i-1)):
        print(" ",end=" ")
    for j in range (i+1):
        print("*",end=" ")
    print()
'''
'''5
print("Enter the Count of Row = ",end=" ")
row=int(input())
for i in range (0,row):
    for j in range (0,i+1):
        print("* ",end="")
    print("\r")
'''
'''6
print("Enter the Count of Row = ",end=" ")
row=int(input())
for i in range(row, 0, -1):
    for j in range(0, i):
        print("* ", end=" ")
    
    print("\r")
'''
'''7
print("Enter the Count of Row = ",end=" ")
row=int(input())
k = 2 * row - 2
for i in range(0, row):
   
    for j in range(0, k):
       
        print(end=" ")
    k = k - 2
    for j in range(0, i + 1):
        
        print("* ", end="")
    print("")
'''
w=10
for(i in range(1,8))
