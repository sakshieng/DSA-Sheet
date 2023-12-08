# Initialize a list lst=[ 1.5, “Python”, -5, 4, 0.8, -3.2, ‘C++’]
list=[1.5, "Python" ,-5, 4, 0.8, -3.2, 'C++']
list.append(0.8)
print("Aftre Appending 0.8")
print(list)
add= [4,1.5,6,0.8]
list.append(add)
print("Aftre Appending list add ")
print(list)
list1=[1.5, "Python" ,-5, 4, 0.8, -3.2, 'C++']
list1.insert(2,20)
print("Aftre Adding element at second position ")
print(list1)
list1.remove('C++')
print("Aftre removing C++")
print(list1)
list1.pop(5)
print("Aftre removing element at 5th position ")
print(list1)
pos= list1.index(-5)
print("Position of element of -5 ")
print(pos)
ct=list1.count(4)
print("Occurences of element 4 ")
print(ct)
print("List from 2 to 6 position ")
print(list1[2:6])
list1.reverse()
print("print list aftre reversing ")
print(list1)
copy=list1 ## copy the list
print("Aftre copying list list1 wieh copy ")
print(copy)

