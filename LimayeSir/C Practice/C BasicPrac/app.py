import requests
from bs4 import BeautifulSoup
from getpass import getpass

username = input("Username: ")
password = getpass()

s = requests.Session()
s.get('http://115.247.20.236/moodle/')
r = s.post('http://115.247.20.236/moodle/login/index.php',{"username": username,"password": password})
soup = BeautifulSoup(r.text, 'html.parser')

print("\nScrapped Data: ")
data = soup.find_all("span", {"class": "usertext"})[0].get_text()
print(data)
