from openai import OpenAI
from dotenv import load_dotenv
import os
import concurrent.futures

load_dotenv()

api_key = os.getenv("API_KEY")
base_url = os.getenv("BASE_URL")

client = OpenAI(
    api_key = api_key,
    base_url = base_url
)

with open('model.txt', 'r') as f:
    model_list = f.read().splitlines()
    
def ask(question, model):
    chat_completion = client.chat.completions.create(
        messages=[
            {
                "role": "user",
                "content": question,
            }
        ],
        model=model,
    )
    code = chat_completion.choices[0].message.content
    cpp_code = code.split('```cpp\n')[1].split('```')[0]
    return cpp_code


def get_code(problem):
    path = 'code/' + problem.replace(' ', '_')
    os.makedirs(path)
    
    def save_code(model):
        cpp_code = ask(problem, model)
        with open(path + '/' + model + '.cpp', 'w') as f:
            f.write(cpp_code)

    with concurrent.futures.ThreadPoolExecutor() as executor:
        executor.map(save_code, model_list)

problem = '生成判断数组的数是否唯一,请给出cpp代码'
get_code(problem)