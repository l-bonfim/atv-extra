#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int acc_number;
    float balance;
} Client;

void createFile(){
    FILE *data = fopen("data.dat", "rb+");
    if (data == NULL){
        data = fopen("data.dat", "wb+");
    }
    fclose(data);
}

void clientList() {
    FILE *data = fopen("data.dat", "rb+");
    fclose(data);
}

int main() {
    createFile();
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
            clientList();
            break;

        case 6:
            break;

        case 7:
            printf("Encerrado.\n");
            break;

        default:
            printf("Número inválido.\n");
            break;
        }
    }

    return 0;
}