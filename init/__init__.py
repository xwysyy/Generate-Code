import os

current_file_path = os.path.abspath(os.path.dirname(__file__))
parent_path = os.path.abspath(os.path.dirname(current_file_path))

model_path = current_file_path + '/models.yaml'