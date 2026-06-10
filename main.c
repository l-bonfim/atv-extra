#include <stdio.h>

int main() {
    int choice = 0;
    while (choice != 7) {
        printf("Escolha uma opção: \n"
               "1. Cadastrar um novo cliente em uma posição específica.\n"
               "2. Consultar um cliente pelo número da conta.\n"
               "3. Atualizar o saldo de um cliente.\n"
               "4. Encerra conta (remover cliente).\n"
               "5. Listar todos os clientes.\n"
               "6. Restaurar a leitura do arquivo do início com `rewind()` para repetir a listagem.\n"
               "7. Encerrar.\n");
    
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            printf("Número inválido.\n");
            break;
        }
    }

    return 0;
}