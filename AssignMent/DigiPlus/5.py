import gspread
from oauth2client.service_account import ServiceAccountCredentials

# Set up the Google Sheets API credentials
scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]
creds = ServiceAccountCredentials.from_json_keyfile_name("api.json", scope)
client = gspread.authorize(creds)

# Open the Google Sheet by its title
sheet = client.open("Your Google Sheet Title").sheet1

# Data to be saved (replace with your scraped data)
data = [
    ["Project 1 Title", "Project 1 Description", "$100"],
    ["Project 2 Title", "Project 2 Description", "$200"],
]

# Write the data to the Google Sheet
for row in data:
    sheet.append_table(row)

print("Data has been saved to Google Sheets.")
