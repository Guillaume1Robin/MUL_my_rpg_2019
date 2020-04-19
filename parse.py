#!/usr/bin/env python3
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
        f.write('\n')

for layer in maprpg['layers']:
    if layer['name'] == 'enemies':
        nb = 0
        for elem in layer['data']:
            if (elem != 0):
                nb += 1
        f.write(str(nb) + '\n')
        for i in range(len(layer['data'])):
            if (layer['data'][i] != 0):
                f.write(str(layer['data'][i]) + ':' + str((i % layer['width']) * 32) + ':' + str(int(i / layer['width']) * 32) + ' ')
        f.write('\n')

found = False
for layer in maprpg['layers']:
    if layer['name'] == 'merchant':
        found = True
        idx = -1
        for i in range(len(layer['data'])):
            if (layer['data'][i] != 0):
                idx = i
        if (idx != -1):
            f.write(str((idx % layer['width']) * 32) + ':' + str(int(idx / layer['width']) * 32) + ' ')
        else:
            f.write('None ')
if (not found):
    f.write('None ')

found = False
for layer in maprpg['layers']:
    if layer['name'] == 'start':
        found = True
        idx = -1
        for i in range(len(layer['data'])):
            if (layer['data'][i] != 0):
                idx = i
        if (idx != -1):
            f.write(str((idx % layer['width']) * 32) + ':' + str(int(idx / layer['width']) * 32) + ' ')
        else:
            f.write('None ')
if (not found):
    f.write('None ')

found = False
for layer in maprpg['layers']:
    if layer['name'] == 'end':
        found = True
        idx = -1
        for i in range(len(layer['data'])):
            if (layer['data'][i] != 0):
                idx = i
        if (idx != -1):
            f.write(str((idx % layer['width']) * 32) + ':' + str(int(idx / layer['width']) * 32))
        else:
            f.write('None')
if (not found):
    f.write('None')