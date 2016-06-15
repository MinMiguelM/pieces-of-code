#!/usr/bin/python3
import json
import requests
import sys

load = 0
inf_users = []
user = ''
password = ''
host = ''
domain="http://"+user+":"+password+"@"+host+":8181/"

def loadFile():
    if len(sys.argv) == 2:
        try:
            f = open(sys.argv[1],"r")
        except FileNotFoundError as err:
            print("ERROR: File not found")
            return
        for line in f:
            data = line.strip().split("\t")
            id = data[0].split()[0]
            balance = data[1].split()[1]
            quota = data[2].split()[1]
            contributions = data[3].split()[1]
            valueCredits = data[4].split()[1]
            inf_users.append([id,balance,quota,contributions,valueCredits])
        global load
        load = 1
        f.close()

def amountCredits(id):
    r = requests.get(domain + "requests/getByIdMemberState/%i" % id)
    amount = r.text
    return amount

def updateUser(userInfo):
    id = int(userInfo[0])
    r = requests.get(domain + "members/getByIdMember/%i" % (id))
    body = json.loads(r.text)
    body['balance'] = userInfo[1]
    body['quota'] = userInfo[2]
    body['contributions'] = userInfo[3]
    body['amountCredits'] = amountCredits(id)
    body['valueCredits'] = userInfo[4]
    requests.post(domain + "members/update",data=json.dumps(body),headers={"content-type": "application/json"})

loadFile()
if load == 1:
    for i in inf_users:
        updateUser(i)
