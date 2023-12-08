G_class = input("Enter the class you got = ")

S_failed= int(input("Enter the subject you failed = "))
if G_class=="first" and S_failed>3 :
    print("No Grace Marks")
elif G_class=="first" and S_failed<=3 :
        print("5 Grace Marks Per Subject")
elif G_class=="second" and S_failed>2 :
        print("No Grace Marks")
elif G_class=="second" and S_failed<=2 :
            print("4 Grace Marks Per Subject")
elif G_class=="third" and S_failed>1 :
        print("No Grace Marks")
elif G_class=="third" and S_failed<=1 :
             print("5 Grace Marks Per Subject")
