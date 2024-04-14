import requests
from bs4 import BeautifulSoup
import csv

url = 'https://www.goodreads.com/genres/biography'
response = requests.get(url)

if response.status_code == 200:
    soup = BeautifulSoup(response.content, 'html.parser')

    title = soup.find('h1', class_='bigBoxBody').text
    author = soup.find('span', class_='author-name').text
    isbn = soup.find('span', class_='isbn').text
    genre = soup.find('span', class_='genre').text
    description = soup.find('div', class_='book-description').text
    reviews = [review.text for review in soup.find_all('div', class_='book-review')]
    with open('data.csv', 'w', newline='') as csv_file:
        writer = csv.writer(csv_file)

        writer.writerow(['Title', 'Author', 'ISBN', 'Genre', 'Description', 'Review'])


    print('Data saved to data.csv.')

else:
    print('Failed to retrieve the web page.')

