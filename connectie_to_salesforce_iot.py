import requests
import serial
import http.client
import json
params = {
    "grant_type": "password",
    "client_id": "3MVG9lsAlIP.W_V9qH7Qv_1pZRQ87bx6wDM3mtz5OEaKyvVXaYdC.VCz1h9m3xqfM3RvYtT4WXt5TbsEaq8mN", 
    "client_secret": "D109E2FD937B0A1F21BADA5BE2BEC577C00C016B1CDB026EAF2A8E7F6A3996C9", 
    "username": "rayhane.hamoumi@hotmail.com.devv", 
    "password": "Rayhane1991DBJLpY7AIgcp1F62gPLBMueY" 
}
r = requests.post("https://login.salesforce.com/services/oauth2/token", params=params)
access_token = r.json().get("access_token")
instance_url = r.json().get("instance_url")
print("Access Token:", access_token)
print("Instance URL", instance_url)

conn = http.client.HTTPSConnection("empathetic-raccoon-fp7a5b-dev-ed.lightning.force.com/") 

port ='COM7'
baud = 9600
 
ser = serial.Serial(port, baud, timeout=1);





