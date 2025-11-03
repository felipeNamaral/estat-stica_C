#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 500000
typedef struct estrutura
{
    float valor;
    int chave;
} str;



void troca(str *a,str *b)
{
    str aux = *a;
    *a = *b;
    *b = aux;
}


void InsertionSort (str v[])
{


    int i,j;

    clock_t start_time,end_time;
    start_time=clock();
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
    end_time=clock();

    printf("Tempo decorrido de insertionSort: %.2f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);
}


int particao(str *v, int LI, int LS)
{

    int pivo, e=LI, d=LS;
    str aux;
    pivo=v[(LI + LS) / 2].chave;
    while(e < d)
    {
        while((v[e].chave>=pivo)&& (e<LS))
        {
            e++;
        }
        while((v[d].chave<pivo)&&(d>LI))
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

void quicksort(str *v, int LI, int LS)
{

    if(LI<LS)
    {
        int p;
        p = particao(v,LI,LS);
        quicksort(v,LI,p-1);
        quicksort(v,p+1,LS);
    }



}



void gerarOrdenado(str A[])
{

    int c;
    c = 100000 + rand() % (300000 - 100000 + 1);
    for(int i=0; i<n; i++)
    {
        A[i].chave = c;
        A[i].valor = 100001.0f + ((float)rand() / RAND_MAX) * 899999.0f;
        c += 100; //
    }

}
void gerarVetorAleatorio(str A[])
{

    for(int i=0; i<n; i++)
    {
        A[i].valor = 100001.0f + ((float)rand() / RAND_MAX) * 899999.0f;
        A[i].chave = rand()%900000+100000;

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




    //aleatorio

    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarVetorAleatorio(A);
        InsertionSort(A);
    }
        printf("----------------------\n");
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarVetorAleatorio(A);


        clock_t start_time,end_time;
        start_time=clock();
        quicksort(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort: %.2f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

    }




    printf("----------------------\n");


    //ordenado
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarOrdenado(A);
        InsertionSort(A);
    }
        printf("----------------------\n");

    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarOrdenado(A);
        clock_t start_time,end_time;
        start_time=clock();
        quicksort(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort: %.2f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

    }




    return 0;
}
