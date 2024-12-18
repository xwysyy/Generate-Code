import os
import yaml
import concurrent.futures
from openai import OpenAI
from dotenv import load_dotenv
from init import model_path

load_dotenv()
with open(model_path, 'r', encoding='utf-8') as file:
    models_config = yaml.load(file, Loader=yaml.FullLoader)
models_list = [model for model in list(models_config.keys()) if models_config[model]['enabled']]
print(f'Enabled models: {models_list}')

def ask(question, model, api_key, base_url):
    api_key = os.getenv(api_key)
    if api_key is None:
        raise ValueError('API Key not found')
    client = OpenAI(api_key = api_key, base_url = base_url)
    chat_completion = client.chat.completions.create(
        messages = [
            {"role": "system", "content": "You are a C++ programmer, please just give me the code to solve the problem."},
            {"role": "user","content": question}
        ],
        model = model,
    )
    code = chat_completion.choices[0].message.content
    code = '/*\n\n' + code + '\n\n*/'
    code = code.replace('```cpp', '*/\n')
    code = code.replace('```', '\n/*')
    return code

def get_code(problem):
    path = 'code/' + '2'
    if not os.path.exists(path):
        os.makedirs(path)
    def save_code(model):
        enaled = models_config[model]['enabled']
        if not enaled:
            return
        api_key = models_config[model]['api_key']
        if api_key is None:
            raise ValueError('API Key not found')
        base_url = models_config[model]['base_url']
        cpp_code = ask(problem, model, api_key, base_url)
        with open(path + '/' + model + '.cpp', 'w', encoding='utf-8') as f:
            for chunk in [cpp_code[i:i+1024] for i in range(0, len(cpp_code), 1024)]:
                f.write(chunk)

    with concurrent.futures.ThreadPoolExecutor() as executor:
        executor.map(save_code, models_list)
