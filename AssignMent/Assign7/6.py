organisms = int(input("Enter the initial number of organisms:"))
rateOfGrowth = int(input("Enter the rate of growth : "))
numOfhours = int(input("Enter the number of hours to achieve the rate of growth: "))
totalhours = int(input("Enter the total hours of growth: "))
hours=0
while (hours <= totalhours):
    organisms*=rateOfGrowth
    hours += numOfhours
    if (hours==totalhours):
        break
print("The total population:" ,organisms)
