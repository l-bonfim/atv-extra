# Atividade extra PIF

> Este programa em C implementa um sistema simples de gerenciamento de clientes bancários utilizando arquivos binários. As informações de cada cliente (nome, número da conta e saldo) são armazenadas em uma estrutura (`struct Client`) e gravadas no arquivo `data.dat`.
>
> O programa inicia verificando se o arquivo de dados existe. Caso não exista, ele é criado pela função `createFile()`. A partir disso, um menu interativo permite ao usuário realizar operações de cadastro, consulta, atualização, remoção e listagem de clientes.
>
> A função `clientCreate()` realiza o cadastro de novos clientes, permitindo que o registro seja armazenado em uma posição específica do arquivo através do uso de `fseek()`. Antes da gravação, o programa verifica se a posição escolhida está livre.
>
> A consulta de clientes é feita pela função `getClientByAcc()`, que percorre o arquivo sequencialmente utilizando `fread()` até encontrar o número de conta informado pelo usuário.
>
> A atualização de saldo é realizada pela função `attBalanceByAcc()`. Após localizar o cliente desejado, o saldo é alterado na estrutura em memória e, em seguida, o ponteiro do arquivo é reposicionado para o início do registro utilizando `fseek(data, -sizeof(Client), SEEK_CUR)`. Dessa forma, o registro é sobrescrito com `fwrite()`, garantindo que a alteração seja salva permanentemente no arquivo.
>
> A exclusão de clientes é implementada na função `removeClientByAcc()`. Como arquivos binários não permitem remover registros diretamente do meio do arquivo, o programa cria um arquivo temporário (`temp.dat`) e copia para ele apenas os registros que devem permanecer. Após a cópia, o arquivo original é removido e o temporário é renomeado para `data.dat`.
>
> As funções `clientList()` e `clientRewind()` permitem exibir todos os clientes cadastrados. A segunda demonstra o uso da função `rewind()`, que reposiciona o ponteiro de leitura no início do arquivo antes de percorrer seus registros novamente.
>
> O programa utiliza conceitos importantes de manipulação de arquivos em C, incluindo abertura de arquivos (`fopen()`), leitura (`fread()`), gravação (`fwrite()`), posicionamento (`fseek()`), reinicialização do ponteiro (`rewind()`), remoção (`remove()`) e renomeação (`rename()`), servindo como um exemplo prático de persistência de dados em arquivos binários e atualização direta de registros.

Atividade CESAR School.
