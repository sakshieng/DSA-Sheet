print("Enter amount for withdrawl = ")
amt=int(input())
N_hun=amt/100
N_fif=(amt%100)/50
N_ten=(((amt%100)%50)/10)
amt_rem=(((amt % 100) % 50) % 10)
print("NO.100 notes = ",int(N_hun))
print("NO.50 notes = ",int(N_fif))
print("NO.10 notes = ",int(N_ten))
print("Amount Remaining = ",amt_rem)