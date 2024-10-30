#include <stdio.h>
#include <string.h>

typedef struct{
    char cpf[32];
    char nome[32];
    char email[32];
    char celular[16];
} t_proprietario;

typedef struct {
    char placa[16];
    char marca[32];
    char modelo[32];
    char cpf[32];
} t_veiculo;

typedef struct{
    int tam;
    t_proprietario vet[50];
} t_tabela_props;

typedef struct{
    int tam;
    t_veiculo vet[50];
} t_tabela_veics;

t_tabela_veics ler_tab_veiculos(char filename[]){
    FILE *arq = fopen(filename,"rt");
    t_tabela_veics aux;
    char linha[64];
    char *token;

    fgets(linha,60,arq);

    while(!feof(arq)){
        fgets(linha,60,arq);
        linha[strlen(linha)-1] = '\0';

        token = strtok(linha, ",");
        strcpy(aux.vet[aux.tam].placa,token);

        token = strtok(NULL, ",");
        strcpy(aux.vet[aux.tam].marca,token);

        token = strtok(NULL, ",");
        strcpy(aux.vet[aux.tam].modelo,token);

        token = strtok(NULL, ",");
        strcpy(aux.vet[aux.tam].cpf,token);

        aux.tam++;
    } // fim while..

    puts(@@@)
    
    fclose(arq);

    return aux;
}

t_tabela_props ler_tab_proprietarios(char filename[]){
    FILE *arq = fopen(filename,"rt");
    t_tabela_veics aux;

    fclose(arq);

    return aux;
}

int main(){
    t_tabela_veics tabV = ler_tab_veiculos("bdveiculos.txt");
    t_tabela_props tabP = ler_tab_proprietarios("bdproprietarios.txt");

    for(int i= 0; i <= tabV.tam; i++)
    printf("%s, %s, %s, %s\n", tabV.vet[i].placa, tabV.vet[i].marca, tabV.vet[i].modelo, tabV.vet[i].cpf);
	for(in j=0; j < tabV.tam; j++){
		if(strcmp(tabP.vet[i].cpf, tabV.vet[j].cpf)==0)
			printf("placa: %s; model: %s; marca: %s\n", tabV.vet[i].placa,tabV.vet[i].modelo, tabV.vet[i].marca);
	}
    return 0;
}
