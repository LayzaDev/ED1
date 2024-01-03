#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

// Define a estrutura do CAMPO da fila de prioridades (ou seja, define cada elemento da fila)
struct elemento_fila {
    char valor;
    int prioridade;
};

struct fila_prioridade {
    int nro_elementos;
    struct elemento_fila elementos[MAX];
};

/*
 * Cria uma nova fila de prioridades
 */
FilaPrioridade *criar()
{
    FilaPrioridade *fp;
    
    fp = malloc(sizeof(FilaPrioridade));
    fp->nro_elementos = 0;
    
    return fp;
}

/*
 * Destroi a fila de prioridades
 */
void destruir(FilaPrioridade *fp)
{
    if (fp != NULL) free(fp);
}

/*
 * Verifica se a fila de prioridades esta vazia
 */
int vazia(FilaPrioridade *fp)
{
    return fp->nro_elementos == 0;
}

/*
 * Verifica de a fila de prioridades esta cheia
 */
int cheia(FilaPrioridade *fp)
{
    return fp->nro_elementos == MAX;
}

/*
 * Insere um elemento com uma dada prioridade na fila de prioridades
 */
int inserir(FilaPrioridade *fp, char valor, int prioridade)
{

    if (cheia(fp)) return 0;

    int i;
    for (i = fp->nro_elementos - 1; 
		    i >= 0 && fp->elementos[i].prioridade >= prioridade;
		    i--) {
        fp->elementos[i + 1] = fp->elementos[i];
    }

    fp->elementos[i + 1].valor = valor;
    fp->elementos[i + 1].prioridade = prioridade;
    fp->nro_elementos = fp->nro_elementos + 1;

    return 1;
}

/*
 * Retira um elemento respeitando a ordem de prioridades
 */
int retirar(FilaPrioridade *fp, char *valor)
{
    if (vazia(fp)) return 0;

    *valor = fp->elementos[fp->nro_elementos - 1].valor;
    fp->nro_elementos--;

    return 1;
}
