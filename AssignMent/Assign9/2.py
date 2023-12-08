'''
Q2.Create a Time class and initialize it with hours and minutes.
1.Make a method addTime which should take two time object and add
them. E.g.- (2 hour and 50 min)+(1 hr and 20 min) is (4 hr and 10 min)
2. Make a method displayTime which should print the time.
3. Make a method DisplayMinute which should display the total minutes
in the Time. E.g.- (1 hr 2 min) should display 62 minute.
'''
class Time :
    hours=0
    minutes=0

    def __init__(self,hours,minutes) :
        self.hours=hours
        self.minutes=minutes
def add(a,b):
    hrs=a.hours+b.hours+int((a.minutes+b.minutes)/60)
    minute= (a.minutes+b.minutes)%60
    print ("hours = ",hrs)
    print ("Minute = ",minute)
def display(a,b):
    print ("Hours = ",a,"Minutes = ",b)
def displaym(a,b):
    mint= a*60+b
    print("Minutes = " ,mint)
time1 = Time(2,30)
time2 = Time(2,50)
time3 = add(time1,time2)
time4= display(5,30)
time5 = displaym(5,30)
