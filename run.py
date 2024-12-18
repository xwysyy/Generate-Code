from ask import *
from init import parent_path

with open(parent_path + '/data.txt', 'r', encoding='utf-8') as f:
    data = f.read()

get_code(data)