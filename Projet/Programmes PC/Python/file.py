#!/usr/bin/python
import json

# Open a file
file = "/Applications/MAMP/htdocs/KonnectedObject/app/webroot/files/datas.json"




def read( value ):
	json_values = jsonConvert( datas=value)
	fd = open(file, 'r')
	from pprint import pprint

	with fd as data_file:
	   data = json.load(data_file)

	for key, value in data.items():
		for key_new, value_new in json_values.items():
		   if key_new == key:
		      writeFile( key=key, old_datas=data, new_datas=json_values );
	return;


def writeFile( key, new_datas, old_datas ):
   old_datas[key] = new_datas[key]
   fo = open(file, 'w')
   json.dump(old_datas,fo, indent=4)
   fo.close()
   return;


def jsonConvert( datas ):
   json_val = json.dumps({datas[0]: datas[1:]})

   data_json = json.loads(json_val)
   return data_json;

my_dict = "l47.50"

read(value=my_dict)
