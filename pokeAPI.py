import requests
import random

num = random.randint(0, 150)

url = "https://pokeapi.co/api/v2/pokemon/" + str(num)

data = requests.get(url).json()

name = data['name']

hp = random.randint(25, 90)

with open('pokemon.txt', 'w') as file:
    file.write(name + ', ' + str(hp))

with open('moves.txt', 'w') as file:
    for move in range(4):

        num = random.randint(0, 800)

        url = "https://pokeapi.co/api/v2/move/" + str(num)

        data = requests.get(url).json()

        move = data['name']

        file.write(move + ' ,' + str(random.randint(5, 40)) + ', ' + str(random.randint(5, 20)) + '\n')