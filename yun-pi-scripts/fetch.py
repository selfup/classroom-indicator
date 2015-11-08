import requests, json, time, sys

sys.path.insert(0, '/usr/lib/python2.7/bridge/')

from bridgeclient import BridgeClient as bridgeclient

endpoint_url = "http://intelyzine.com/api/v1/classroom_bs"

r = requests.get(endpoint_url)
count  = 0

value = bridgeclient()

while (count < 100):
  print r.status_code

  teach = r.json()[0]['teacher']
  cohort = r.json()[0]['cohort']

  print teacher
  print cohort
  value.put(teacher)
  time.sleep(10)
