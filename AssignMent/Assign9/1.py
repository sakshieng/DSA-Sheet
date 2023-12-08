'''
Create a Temperature class. Make two methods :
1. ConvertFahrenheit - It will take Celsius and will print it into Fahrenheit.
2. ConvertCelsius - It will take Fahrenheit and will convert it into Celsius.
'''
class Temprature:
    temp=0
    def __init__(self,temp) :
        self.temp=temp
    def convertfaranitr(self) :
        result= float((9*self.temp)/5+32)
        return result
    def convertcelcius (self) :
        result = float((self.temp-32)*5/9)
        return result
temp= Temprature(float(input()))
result = temp.convertcelcius()
print (result)
temp= Temprature(float(input()))
result =temp.convertfaranitr()
print(result)
