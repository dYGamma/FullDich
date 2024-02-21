from datetime import datetime
import requests
from threading import Thread

   
def task():
    headers = {
    'accept': 'application/json',
    }

    response = requests.get('https://nvuti.blue/', headers=headers)
    print(datetime.now())


if __name__ == "__main__":
 
    headers = {
            'accept': 'application/json',
        }
    while 1:
      
        thread =Thread(target=task)
        thread.start()
        response = requests.get('https://nvuti.blue/', headers=headers)
        print(datetime.now())