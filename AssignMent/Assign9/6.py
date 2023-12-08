class value:
    num=0
    def __init__(self,num) :
        self.num=num
def max(a,b,c) :
    if(a.num>b.num and a.num>c.num):
        print(a.num)
    elif (b.num>c.num and b.num>a.num):
        print(b.num)
    else :
        print(c.num)
num1= value(int(input()))
num2=value(int(input()))
num3= value(int(input()))
num4=max(num1,num2,num3)
