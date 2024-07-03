import requests
import random

num = random.randint(0, 150)    # Gera um número aleatório entre os Pokémons de 1º geração

url = "https://pokeapi.co/api/v2/pokemon/" + str(num)   # Concatena com o link da API com as Infos do Poke

data = requests.get(url).json()

name = data['name']

pokeTypeName = data['types'][0]['type']['name'] # Recebe o Tipo do Pokémon como String

pokeType = 0

match pokeTypeName:           # Respectivo Valor do Tipo para a Matriz de danos  
        case 'normal':
            pokeType = 0
        case 'fighting':
            pokeType = 1
        case 'flying':
            pokeType = 2
        case 'poison':
            pokeType = 3
        case 'ground':
            pokeType = 4
        case 'rock':
            pokeType = 5
        case 'bug':
            pokeType = 6
        case 'ghost':
            pokeType = 7
        case 'steel':
            pokeType = 8
        case 'fire':
            pokeType = 9
        case 'water':
            pokeType = 10
        case 'grass':
            pokeType = 11
        case 'eletric':
            pokeType = 12
        case 'psychic':
            pokeType = 13
        case 'ice':
            pokeType = 14
        case 'dragon':
            pokeType = 15
        case 'dark':
            pokeType = 16
        case 'fairy':
            pokeType = 17
        case _:
            pokeType = 1

hp = random.randint(40, 90)     # Vida do Pokémon gerada aleatóriamente

with open('pokemon.txt', 'w') as file:
    file.write(name + ', ' + str(hp) + ',' + str(pokeType))     # Escreve Tudo em um arquivo de Texto

with open('moves.txt', 'w') as file:
    for move in range(4):

        while 1:
            num = random.randint(0, 800)    # Número aleatório para os ataques

            url = "https://pokeapi.co/api/v2/move/" + str(num)

            data = requests.get(url).json()

            move = data['name']

            if not '--' in move:
                break

        atackTypeName = data['type']['name']    # Tipo do Ataque como String

        atackType = 0

        match atackTypeName:    # Respectivo Valor do Tipo do ataque para a Matriz de danos
            case 'normal':
                atackType = 0
            case 'fighting':
                atackType = 1
            case 'flying':
                atackType = 2
            case 'poison':
                atackType = 3
            case 'ground':
                atackType = 4
            case 'rock':
                atackType = 5
            case 'bug':
                atackType = 6
            case 'ghost':
                atackType = 7
            case 'steel':
                atackType = 8
            case 'fire':
                atackType = 9
            case 'water':
                atackType = 10
            case 'grass':
                atackType = 11
            case 'eletric':
                atackType = 12
            case 'psychic':
                atackType = 13
            case 'ice':
                atackType = 14
            case 'dragon':
                atackType = 15
            case 'dark':
                atackType = 16
            case 'fairy':
                atackType = 17
            case _:
                atackType = 1

        # Nome  -  Dano  -  Cargas  -  Tipo , Salvos em um Arquivo txt 
        file.write(move + ' ,' + str(random.randint(5, 40)) + ', ' + str(random.randint(5, 20)) + ', ' + str(atackType) + '\n')