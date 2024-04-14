'''
 Q7.Write a program using class to read 3 values of a, b and c and calculate
value of X as
X= a/b – c
'''
class X:
    def Expression(a:int ,b:int ,c:int):
        print('Value of X is :',a/b-c)

print('Enter 3 integer:')
a=int(input())
b=int(input())
c=int(input())
X.Expression(a,b,c)

