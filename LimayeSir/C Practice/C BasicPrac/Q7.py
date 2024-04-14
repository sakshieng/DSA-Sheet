class X:
    def Expression(a:int ,b:int ,c:int):
        print('Value of X is :',a/b-c)

print('Enter 3 integer:')
a=int(input())
b=int(input())
c=int(input())
X.Expression(a,b,c)