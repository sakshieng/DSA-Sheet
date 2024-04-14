'''
Q10.Write a program of exception handling which throws an exception using
raise keyword
'''
def divide(x, y):
	try:
		result = x // y
	except ZeroDivisionError:
		print("Sorry ! You are dividing by zero ")
	else:
		print("Yeah ! Your answer is :", result)

divide(3, 2)
divide(3, 0)
