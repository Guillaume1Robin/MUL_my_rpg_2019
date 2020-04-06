import json
from sys import argv

with open(argv[1], 'r') as f:
    maprpg = json.load(f)

try:
    f = open("map", "x")
except:
    f = open("map", "w")

f.write(str(maprpg['layers'][1]['width']) + ' ' + str(maprpg['layers'][1]['height']) + '\n')
for layer in maprpg['layers']:
    if layer['name'] == 'collision':
        for elem in maprpg['layers'][1]['data']:
            f.write(str(elem) + ' ')