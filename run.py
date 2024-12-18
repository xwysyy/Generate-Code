from ask import *

with open('data.txt', 'r', encoding='utf-8') as f:
    data = f.read()

get_code(data)