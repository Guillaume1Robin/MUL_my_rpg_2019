import json
from sys import argv

with open(argv[1], 'r') as f:
    maprpg = json.load(f)

try:
    f = open("map", "x")
except:
    f = open("map", "w")

for layer in maprpg['layers']:
    if layer['name'] == 'collision':
        f.write(str(layer['width']) + ' ' + str(layer['height']) + '\n')
        for elem in layer['data']:
            f.write(str(elem) + ' ')