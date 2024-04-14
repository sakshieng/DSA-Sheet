import requests
from bs4 import BeautifulSoup
import csv

# Define the URL of the real estate website you want to scrape
url = "https://www.example.com/real-estate"

# Send an HTTP GET request to the website and parse the HTML
response = requests.get(url)
soup = BeautifulSoup(response.text, "html.parser")

# Find and extract property listings
property_listings = soup.find_all("div", class_="property-listing")

# Create or open a CSV file for writing
with open("property_data.csv", "w", newline="") as csvfile:
    fieldnames = ["Price", "Location", "Property Type", "Rental Yield"]
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    # Write the header row
    writer.writeheader()

    # Loop through property listings and extract data
    for listing in property_listings:
        # Extract property details such as price, location, and type
        price = listing.find("span", class_="price").text
        location = listing.find("div", class_="location").text
        property_type = listing.find("div", class_="property-type").text

        # Extract monthly rental income (you may need to navigate to a different page for this)
        rental_url = listing.find("a")["href"]
        rental_response = requests.get(rental_url)
        rental_soup = BeautifulSoup(rental_response.text, "html.parser")
        monthly_rent = rental_soup.find("span", class_="monthly-rent").text

        # Calculate rental yield
        monthly_rent = float(monthly_rent.strip("₹").replace(",", ""))
        price = float(price.strip("₹").replace(",", ""))
        rental_yield = (monthly_rent * 12) / price

        # Write the data to the CSV file
        writer.writerow({"Price": price, "Location": location, "Property Type": property_type, "Rental Yield": rental_yield})

# Data has been saved to "property_data.csv" file
