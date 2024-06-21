import requests
import random

num = random.randint(0, 800)

url = "https://pokeapi.co/api/v2/pokemon/" + str(num)

data = requests.get(url).json()

pokemon = data['sprites']['front_default']

print(pokemon)
