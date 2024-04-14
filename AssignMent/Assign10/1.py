from tkinter import *
from tkinter import messagebox
from tkinter.messagebox import showinfo

master = Tk()
master.geometry('550x550')
master.title("Sakshi's Wizarding World")

La_01 = Label(master, text="College Account", width=20,
              fg='blue', font=("bold", 20))
La_01.place(x=90, y=60)

name_label = Label(master, text="Enter Name : ", width=10, font=("arial", 12))
name_label.place(x=20, y=120)
name_text = Entry(master)
name_text.place(x=200, y=120)

email_label = Label(master, text="Enter Email : ",
                    width=10, font=("arial", 12))
email_label.place(x=19, y=160)
email_text = Entry(master)
email_text.place(x=200, y=160)

no_label = Label(master, text="Mobile No : ", width=13, font=("arial", 12))
no_label.place(x=19, y=200)
no_text = Entry(master)
no_text.place(x=200, y=200)

gender_label = Label(master, text="Select Gender : ",
                     width=15, font=("arial", 12))
gender_label.place(x=5, y=240)

vars = IntVar()
Radiobutton(master, text="Male", fg='brown', padx=5, variable=vars,
            value=1).place(x=180, y=240)
Radiobutton(master, text="Female", fg='crimson', padx=10,
            variable=vars, value=2).place(x=240, y=240)
Radiobutton(master, text="Others", fg='black', padx=15,
            variable=vars, value=3).place(x=310, y=240)

state_label = Label(master, text="States", width=20, font=("bold", 11))
state_label.place(x=70, y=280)
list_of_cntry = ['Maharashtra', 'Himachal',
                 'Madhya Pradesh', 'Arunachal Pradesh', 'Jammu and Kashmir']
cv = StringVar()
drplist = OptionMenu(master, cv, *list_of_cntry)
drplist.config(width=15)
cv.set('Select your State')
drplist.place(x=240, y=280)

hostel_label = Label(master, text="Hostel Requirement ",
                     width=20, font=('bold', 10))
hostel_label.place(x=75, y=330)
vars1 = IntVar()
Checkbutton(master, text="Yes",
            variable=vars1).place(x=230, y=330)

Button(master, text='Create Account', command=lambda: print_details(),
       width=20, bg="steelblue", fg='black').place(x=180, y=380)


def print_details():
    name = name_text.get()
    mobile = no_text.get()
    email = email_text.get()
    gender = vars.get()
    state = cv.get()
    hostel = vars.get()
    print("Name: {}\nMobile Number: {}\nEmail ID: {}\nGender: {}\nState: {}\nHostel Requirement: {}".format(
        name, mobile, email, gender, state, hostel))
    showinfo(title='Registration', message="Successfully done\n Name: {}\nMobile Number: {}\nEmail ID: {}\nGender: {}\nState: {}\nHostel Requirement: {}".format(
        name, mobile, email, gender, state, hostel))


master.mainloop()

print("Whoaaa......Account is created Successfully ! ")