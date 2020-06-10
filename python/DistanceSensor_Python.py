# import libraries
from simple_salesforce import Salesforce
import requests
import serial
import http.client
import json
import time
sf = Salesforce(username='rayhane.hamoumi@hotmail.com.dev.dev', password='Rayhane1991', security_token='h1zEbJGD2VhOpHyS9mzh2WS0r')# Salesforce inloggegevens
print('Okey SF:', sf);
params = {
    "grant_type": "password",
    "client_id": "3MVG9lsAlIP.W_V9RYYD0g.bm1QCDPMHWUK16UvO5uJKqsQcCDMJ5aoZ1C.xaQYH7eccMXdHJQDQ7LdwPrqyX", # Consumer Key van Api
    "client_secret": "BCE717EF3AF9D5BADD7FC3A445FC4177ADA6566FD636E8DAC8882D3E0BCCB9EF", # Consumer Secret van Api
    "username": "rayhane.hamoumi@hotmail.com.dev.dev", # Inlog email
    "password": "Rayhane1991h1zEbJGD2VhOpHyS9mzh2WS0r" # Concat your password and security token
}
link = requests.post("https://login.salesforce.com/services/oauth2/token", params=params)#Link naar onze Salesforce CRM
access_token = link.json().get("access_token")
instance_url = link.json().get("instance_url")
print("Access Token:", access_token)
print("Instance URL", instance_url)
conn = http.client.HTTPSConnection("brave-hawk-ri8lbf-dev-ed.lightning.force.com/") 

port ='COM7'
baud = 9600

Arduino = serial.Serial(port, baud); # open the serial port

if Arduino.isOpen():
    print(Arduino.name + ' is open…')
        
    while True:
            print('Receiving From Arduino')
            outputInBytes = Arduino.readline()# Output data dat word afgeprint in arduino 
            outputInString = bytes.decode(outputInBytes)
            print('Distance  ='+ outputInString)
            
            data = [{"Id__c": "1", 'Distance__c': outputInString}]# De field die in Salesforce zijn aangemaakt geef ik hier terug met de juiste data en de data dat van arduino komt (Outputstring)
            sf.bulk.DistanceSensor__e.insert(data)# Het doorsturen van data naar Salesforce
            print("Platform Event Sent To Salesforce")
            print(outputInString)
            time.sleep(5)# De loop herhaald zich om de 5sec


            
