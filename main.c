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

void clientCreate(){
    FILE *data = fopen("data.dat", "ab+");
    Client client, client_test;
    int id, write_test = 0;
    printf("Nome do cliente: ");
    scanf("%s", client.nome);
    printf("Número da conta: ");
    scanf("%d", &client.acc_number);
    printf("Saldo: ");
    scanf("%f", &client.balance);
    while (write_test != 1) {
        printf("Onde você deseja salvar? ");
        scanf("%d", &id);
        fseek(data, sizeof(client) * id, SEEK_SET);
        size_t read_test = fread(&client_test, sizeof(client_test), 1, data);
        if (read_test == 0){
            fwrite(&client, sizeof(client), 1, data);
            write_test = 1;
        }
    }
    fclose(data);
}

void getClientByAcc() {
    FILE *data = fopen("data.dat", "rb+");
    int account;
    Client client;
    printf("Qual numero de conta você deseja consultar? ");
    scanf("%d", &account);
    while(fread(&client, sizeof(client), 1, data) != 0) {
        if (account == client.acc_number) {
            printf("Conta: %d\tNome: %s\tSaldo: %.2f\n", client.acc_number, client.nome, client.balance);
        }
    }

    fclose(data);
}

void attBalanceByAcc() {
    FILE *data = fopen("data.dat", "rb+");
    int account;
    float newBalance;
    Client client;
    printf("Qual numero de conta você deseja atualizar? ");
    scanf("%d", &account);
    printf("Qual novo saldo da conta? ");
    scanf("%f", &newBalance);
    while(fread(&client, sizeof(client), 1, data) != 0) {
        if (account == client.acc_number) {
            client.balance = newBalance;

            fseek(data, -sizeof(Client), SEEK_CUR);
            fwrite(&client, sizeof(Client), 1, data);

            printf("Conta atualizada!\n");
            printf("Conta: %d\tNome: %s\tSaldo: %.2f\n", client.acc_number, client.nome, client.balance);
        }
    }

    fclose(data);
}

void removeClientByAcc() {
    FILE *data = fopen("data.dat", "rb+");
    FILE *dataTemp = fopen("temp.dat","wb+");
    int account;
    Client client;
    printf("Qual numero de conta você deseja excluir? ");
    scanf("%d", &account);
    while(fread(&client, sizeof(client), 1, data) != 0) {
        if (account != client.acc_number) {
            fwrite(&client, sizeof(client), 1, dataTemp);
        }
    }
    fclose(dataTemp);
    fclose(data);

    remove("data.dat");
    rename("temp.dat", "data.dat");
    
    FILE *dataAtt = fopen("data.dat", "rb+");
    while(fread(&client, sizeof(client), 1, dataAtt) != 0) {
        printf("Conta: %d\tNome: %s\tSaldo: %.2f\n", client.acc_number, client.nome, client.balance);
    }
    fclose(dataAtt);
}

void clientList() {
    FILE *data = fopen("data.dat", "rb+");
    Client client;
    while(fread(&client, sizeof(client), 1, data) != 0) {
        printf("Conta: %d\tNome: %s\tSaldo: %.2f\n", client.acc_number, client.nome, client.balance);
    }
    fclose(data);
}

void clientRewind() {
    FILE *data = fopen("data.dat", "rb+");
    Client client;
    rewind(data);
    while(fread(&client, sizeof(client), 1, data) != 0) {
        printf("Conta: %d\tNome: %s\tSaldo: %.2f\n", client.acc_number, client.nome, client.balance);
    }
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
            clientCreate();
            break;

        case 2:
            getClientByAcc();
            break;

        case 3:
            attBalanceByAcc();
            break;

        case 4:
            removeClientByAcc();
            break;

        case 5:
            clientList();
            break;

        case 6:
            clientRewind();
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