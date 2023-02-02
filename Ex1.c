/*Considere uma lista contendo numeros inteiros. Escreva uma função para ordenar essa fila em ordem crescente de seus valores.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct st_no
{
    int valor;
    struct st_no *prox;
};

typedef struct st_no noh;

int vazia(noh *li)
{
    if (li->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inicia(noh *le)
{
    le->prox = NULL;
}

void limpa(noh *le)
{
    if (!vazia(le))
    {
        noh *proxiNoh, *atual;
        atual = le->prox;
        while (atual != NULL)
        {
            proxiNoh = atual->prox;
            free(atual);
            atual = proxiNoh;
        }
    }
}

void imprime(noh *le)
{
    if (vazia(le))
    {
        printf("Lista vazia!!");
        return;
    }
    noh *aux;
    aux = le->prox;
    while (aux != NULL)
    {
        printf("%d", aux->valor);
        aux = aux->prox;
    }
    printf(" \n \n");
}

void ordena(noh *le)
{
    noh *i, *j, *min, *temp;

    for (i = le; i->prox != NULL; i = i->prox) /*Percorre toda a lista*/
    {
        min = i; /*Menor = atual*/

        for (j = i->prox; j != NULL; j = j->prox) /*perore a partir do segundo no do I*/
        {

            /*J correspoonde ao segundo nó a partir do I*/
            if (j->valor < min->valor)
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = (noh *)malloc(sizeof(noh));
            temp->valor = i->valor;
            i->valor = min->valor;
            min->valor = temp->valor;
            free(temp);
        }
    }
}

void isere_final(noh *le)
{
    noh *novo = (noh *)malloc(sizeof(noh));
    if (!novo)
    {
        printf("Memória insuficiente \n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);
    novo->prox = NULL;

    if (vazia(le))
        le->prox = novo;
    else
    {
        noh *aux = le->prox;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void opcao(noh *le, int op)
{
    switch (op)
    {
    case 0:
        limpa(le);
        break;
    case 1:
        imprime(le);
        break;
    case 2:
        inicia(le);
        break;
    case 3:
        isere_final(le);
        break;
    case 4:
        ordena(le);
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

int menu()
{
    int opt;

    printf("Escolha a função:\n");
    printf("[0] - Limpa\n");
    printf("[1] - Exibe\n");
    printf("[2] - Iniciar lista \n");
    printf("[3] - Insere final\n");
    printf("[4] - Ordena\n");

    printf("Opção: ");
    scanf("%d", &opt);

    return opt;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    noh *le = (noh *)malloc(sizeof(noh));

    if (!le)
    {
        printf("Sem memória disponível: ");
        exit(1);
    }
    inicia(le);
    int opt;

    do
    {
        opt = menu();
        opcao(le, opt);
    } while (opt);

    free(le);
    return 0;
}