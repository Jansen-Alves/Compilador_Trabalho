#include <stdio.h>
#include <stdlib.h>

struct tabelaSimbolos{
	string nome;
	string tipo;
	string classe;
	string endereco;
	string val;
};
struct atributos
{
	string label;
	string traducao;
	string tipo;
	string classe;
	string val;
};

typedef struct No {
    atributos dado;
    struct No* proximo;
} No;


No* criarNo(atributos dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado->label = dado->label;
    novoNo->dado->traducao = dado->traducao;
    novoNo->dado->tipo = dado->tipo;
    novoNo->dado->classe = dado->classe;
    novoNo->dado->val = dado->val;
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionar(No** inicioNo, atributos dado) {
    No* novoNo = criarNo(dado);
    if (*inicioNo == NULL) {
        *inicioNo = novoNo;
        return;
    }
    No* ultimoNo = *inicioNo;
    while (ultimoNo->proximo != NULL) {
        ultimoNo = ultimoNo->proximo;
    }
    ultimoNo->proximo = novoNo;
}

void imprimirLista(No* inicioNo) {
    No* atual = inicioNo;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
}

void freeLista(No* inicioNo)
{
   No* tmp;

   while (inicioNo != NULL)
    {
       tmp = inicioNo;
       inicioNo = inicioNo->proximo;
       free(tmp);
    }

}

No* buscaLista(Node* inicioNo, string chave) {
    No* atual = inicioNo;
    while (atual != NULL) {
        if (atual->dado == chave) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL; //NULL se a chave não for encontrada
}