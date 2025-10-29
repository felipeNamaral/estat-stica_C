#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100
typedef struct estrutura
{
    float valor;
    int chave;
} str;


void troca(str *a,str *b)
{
    int aux;
    aux = a->chave;
    a->chave = b->chave;
    b->chave = aux;

}
void InsertionSort (str v[])
{
    int i,j;

    for(i=0; i<n; i++)
    {
        for(j=i; j >= 0; j--)
        {
            if(v[j-1].chave < v[j].chave)
            {
                troca(&v[j-1],&v[j]);
            }
        }
    }
}



void quicksort(int *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p,i;
        p = particao(v,LI,LS);
        quicksort(v,LI,p-1);
        quicksort(v,p+1,LS);
    }
}





int particao(int *v, int LI, int LS)
{
    int aux, pivo, e=LI, d=LS;
    pivo=v[e];
    while(e < d)
    {
        while((v[e]<=pivo)&& (e<LS))
        {
            e++;
        }
        while((v[d]>pivo)&&(d>LI))
        {
            d--;
        }
        if(e<d)
        {
            aux = v[e];
            v[e]=v[d];
            v[d]=aux;
        }
    }
    aux = v[LI];
    v[LI]=v[d];
    v[d]=aux;
    return d;
}











void gerarVetorAleatorio(str A[])
{
    int v;
    int c;


    for(int i=0; i<n;i++)
    {
        v = 100001.0f + ((float)rand() / RAND_MAX) * 899999.0f;
        c = rand()%900000+100000;

        A[i].chave=c;
        A[i].valor=v;

    }

}





int main()
{

    str *A = malloc(n * sizeof(str));
    if (A == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    srand(time(NULL));



    //aleatorio

    for(int i=0; i<20; i++){
    gerarVetorAleatorio(A);
    InsertionSort(A);
        for(int i=0; i<n; i++){
        printf("%d - %f\n",A[i].chave,A[i].valor);
    }
    printf("----------------------\n");
    }





    //ordenado


    return 0;
}
