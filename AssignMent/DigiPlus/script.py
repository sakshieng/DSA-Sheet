import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

# Load your historical odds data (replace 'data.csv' with your data file)
data = pd.read_csv('DigiPlus\data.csv')

# Data preprocessing and feature engineering
# You'll need to clean and prepare your data, create relevant features, and select the target variable.

# Example features and target variable
# Assuming your data.csv has columns like this
# Date,Type,Odds,Outcome,Team1,Team2,Venue,Weather,Team1_Win_Loss,Team2_Win_Loss

# Update the features you want to use
X = data[['Odds', 'Team1_Win_Loss', 'Team2_Win_Loss']]
y = data['Outcome']

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a Linear Regression model
model = LinearRegression()

# Train the model
model.fit(X_train, y_train)

# Make predictions on the test set
predictions = model.predict(X_test)

# Evaluate the model's performance (you can use different metrics)
from sklearn.metrics import mean_absolute_error

mae = mean_absolute_error(y_test, predictions)
print(f'Mean Absolute Error: {mae}')

# Visualize the results (you can create more sophisticated visualizations)
plt.scatter(y_test, predictions)
plt.xlabel('Actual Values')
plt.ylabel('Predicted Values')
plt.show()
