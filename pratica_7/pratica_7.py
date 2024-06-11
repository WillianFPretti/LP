'''

Program: Experimento 7

Author: Willian Pretti

Date: 10/06/2024

Description:  Produza um código em Python que acesse arquivos YAML, convertendo a informação estruturada para ser utilizada na LP.

License: [Type of License]

'''

import yaml

# Função para carregar dados de um arquivo YAML
def carregar_dados_yaml(nome_arquivo):
    try:
        # Abre o arquivo YAML e carrega os dados
        with open(nome_arquivo, 'r') as arquivo:
            dados = yaml.safe_load(arquivo)
        return dados
    except FileNotFoundError:
        print("O arquivo YAML especificado não foi encontrado.")
        return None
    except yaml.YAMLError as e:
        print("Erro ao carregar os dados YAML:", e)
        return None

# Exemplo de utilização
if __name__ == "__main__":
    # Nome do arquivo YAML
    arquivo_yaml = "dados.yaml"

    # Carrega os dados do arquivo YAML
    dados = carregar_dados_yaml(arquivo_yaml)

    # Verifica se os dados foram carregados com sucesso
    if dados is not None:
        # Exibe os dados carregados
        print("Dados do arquivo YAML:")
        print(dados)