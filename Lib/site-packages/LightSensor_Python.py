from simple_salesforce import Salesforce
import requests
import serial
import http.client
import json
import time
sf = Salesforce(username='rayhane.hamoumi@hotmail.com.dev.dev', password='Rayhane1991', security_token='h1zEbJGD2VhOpHyS9mzh2WS0r')
print('Okey SF:', sf);
params = {
    "grant_type": "password",
    "client_id": "3MVG9lsAlIP.W_V9RYYD0g.bm1QCDPMHWUK16UvO5uJKqsQcCDMJ5aoZ1C.xaQYH7eccMXdHJQDQ7LdwPrqyX", # Consumer Key
    "client_secret": "BCE717EF3AF9D5BADD7FC3A445FC4177ADA6566FD636E8DAC8882D3E0BCCB9EF", # Consumer Secret
    "username": "rayhane.hamoumi@hotmail.com.dev.dev", # The email you use to login
    "password": "Rayhane1991h1zEbJGD2VhOpHyS9mzh2WS0r" # Concat your password and your security token
}
r = requests.post("https://login.salesforce.com/services/oauth2/token", params=params)
access_token = r.json().get("access_token")
instance_url = r.json().get("instance_url")
print("Access Token:", access_token)
print("Instance URL", instance_url)

conn = http.client.HTTPSConnection("brave-hawk-ri8lbf-dev-ed.lightning.force.com/") 

port ='COM7'
baud = 9600

Arduino = serial.Serial(port, baud); # open the serial port

if Arduino.isOpen():
    print(Arduino.name + ' is open…')
        
    while True:
            print('Receiving From Arduino.....')
            outputInBytes = Arduino.readline()
            outputInString = bytes.decode(outputInBytes)       
            print('outputInString  ='+ outputInString)
            
            data = [{"Id__c": "1", 'LightOn__c': outputInString}]
            sf.bulk.LightSensor__e.insert(data)
            print("Platform Event Sent")
            print(outputInString)
            time.sleep(5)   


            
