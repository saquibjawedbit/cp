from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
import time

# Replace this with the URL of your Google Form
google_form_url = "https://docs.google.com/forms/d/e/1FAIpQLSeDIMQ61LzB_xd2rcaAAWR9rP7Wj708v5EgP8aIus1wsb6FYQ/viewform"

# Replace these with your form's questions and their corresponding element names
data_to_fill = {
    "Name": "Table Kumar",
    "Email": "tablekumar@gmail.com",
    "Roll No": "6969",  # You may need to change this if it's a dropdown or radio buttons
}

# Path to the image to be uploaded
image_path = "image.jpg"

# Initialize WebDriver
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))

try:
    # Open the Google Form
    driver.get(google_form_url)

    # Wait until the form is loaded (using the Name field as an example)
    WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CSS_SELECTOR, "input[name='entry.1234567890']")))

    # Fill out the form fields
    for question, answer in data_to_fill.items():
        # Find input elements by their name attributes (use the correct input element name)
        input_element = driver.find_element(By.CSS_SELECTOR, f"input[name='entry.1234567890']")  # Replace 'entry.1234567890' with the form's actual field name
        input_element.send_keys(answer)
    
    # Upload image (if there is an image upload field)
    upload_button = driver.find_element(By.CSS_SELECTOR, "input[type='file']")  # Find file input element
    upload_button.send_keys(image_path)

    # Optionally, handle any checkboxes or radio buttons
    checkbox = driver.find_element(By.CSS_SELECTOR, "div[role='checkbox']")  # Adjust according to form structure
    checkbox.click()

    # Submit the form
    submit_button = driver.find_element(By.CSS_SELECTOR, "div[role='button'][aria-label='Submit']")  # Replace with actual submit button locator
    submit_button.click()

    # Wait for submission to complete
    time.sleep(5)  # Adjust depending on your needs
finally:
    driver.quit()

