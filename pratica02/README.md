Para o desenvolvimento desse programa foi utilizado o WSL versão 2.3.24.0, g++ versão 13.2.0. 

Considere que o arquivo Makefile foi criado baseado nos comandos de ambiente linux, caso seja executado em terminais de ambiente windows poderão haver falhas de compilação.

Para a execução do programa extraia os arquivos do .zip e, em um terminal de ambiente linux (preferencialmente ubuntu), execute o comando 'make run'.

Todos os arquivos de output derivados dos arquivos de entrada .CSV estarão no diretorio '/files/fileout/', com o nome 'Saida_(valor equivalente ao arquivo de input).bin' e 'Saida_(valor equivalente ao arquivo de input).txt'. Decidimos adicionar o arquivo tipo txt para melhor visualização dos resultados durante a execução do programa. Esses arquivos não são usados no código de nenhuma forma. Além desses arquivos, existe tambem um arquivo chamado "outBinario.txt" que comporta o vetor de registros advindo da leitura do binario gerado pela função adicionaRegistrosFixo.