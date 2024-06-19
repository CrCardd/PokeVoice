import requests
import random

url = "https://pokeapi.co/api/v2/pokemon/"

data = requests.get(url).json()

num = random.randint(0, 20)

pokemon = data['results'][num]

print(pokemon)
