import httplib2
import json

def getGeocodeLocation(inputString):
	google_api_key = 'AIzaSyAoVV9-BRguDO1MR9yqzFYboi-fY_Fe83U'
	locationString = inputString.replace(" ","+")
	url = ('https://maps.googleapis.com/maps/api/geocode/json?address=%s&key=%s' % (locationString,google_api_key))
	h = httplib2.Http()
	response, content = h.request(url,'GET')
	result = json.loads(content)
	#print 'response header: ', response
	latitude = result['results'][0]['geometry']['location']['lat']
	longitude = result['results'][0]['geometry']['location']['lng']
	return (latitude,longitude)