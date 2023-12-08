'''
1.Write a program of exception handling which throws an exception using 
raise keyword (there should be multiple raise statements based on certain 
condition)
'''
try:
	k = 5//0 
	print(k)
except ZeroDivisionError:
	print("Can't divide by zero")
else :
    print('When no exception')
finally:
	
	print('This is always executed')
