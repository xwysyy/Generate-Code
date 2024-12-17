from openai import OpenAI
from dotenv import load_dotenv
import os
import concurrent.futures
from init import model_path
load_dotenv()

api_key = os.getenv("API_KEY")
base_url = os.getenv("BASE_URL")

client = OpenAI(
    api_key = api_key,
    base_url = base_url
)

with open(model_path, 'r') as f:
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
    code = '/*\n\n' + code + '\n\n*/'
    code = code.replace('```cpp', '*/\n')
    code = code.replace('```', '\n/*')
    return code


def get_code(problem):
    path = 'code/' + problem.replace(' ', '_')
    os.makedirs(path)
    
    def save_code(model):
        cpp_code = ask(problem, model)
        with open(path + '/' + model + '.cpp', 'w', encoding='utf-8') as f:
            for chunk in [cpp_code[i:i+1024] for i in range(0, len(cpp_code), 1024)]:
                f.write(chunk)

    with concurrent.futures.ThreadPoolExecutor() as executor:
        executor.map(save_code, model_list)

def test():
    print(1)