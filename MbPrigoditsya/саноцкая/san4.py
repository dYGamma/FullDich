from selenium import webdriver
import time

chrome_driver_path = '/Users/Dmitry/Desktop/Chrome'
driver = webdriver.Chrome()

driver.get('https://market.dota2.net/?search=Dark%20Artistry%20Cape&sd=desc')
while True:
    time.sleep(20)
    driver.refresh()
driver.quit()