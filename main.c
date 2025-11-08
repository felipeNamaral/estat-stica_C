#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100000
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
        for(j=i; j > 0; j--)
        {
            if(v[j-1].chave < v[j].chave)
            {
                troca(&v[j-1],&v[j]);
            }
        }
    }
    end_time=clock();

    printf("Tempo decorrido de insertionSort: %.3f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);
}


int particaoEsquerda(str *v, int LI, int LS)
{

    int     pivo,e=LI, d=LS;
    str aux;
    pivo = v[e].chave;
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
int particaoUltimo(str *v, int LI, int LS)
{

    int pivo,e=LI, d=LS;
    str aux;
    pivo = v[d].chave;
    while(e < d)
    {
        while((v[e].chave>pivo)&& (e<LS))
        {
            e++;
        }
        while((v[d].chave<=pivo)&&(d>LI))
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
    aux = v[LS];
    v[LS] = v[e];
    v[e] = aux;
    return e;
}
int particaoMeio(str *v, int LI, int LS)
{

    int pivo,e=LI, d=LS;
    str aux;
    pivo = v[(LS+LI) / 2].chave;
    while(e < d)
    {
        while((v[e].chave>pivo)&& (e<LS))
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
            e++;
            d--;
        }
    }
    return d;
}



void quicksortEsquerda(str *v, int LI, int LS)
{

    if(LI<LS)
    {
        int p;
        p = particaoEsquerda(v,LI,LS);
        quicksortEsquerda(v,LI,p-1);
        quicksortEsquerda(v,p+1,LS);
    }

}

void quicksortMeio(str *v, int LI, int LS)
{

    if(LI<LS)
    {
        int p;
        p = particaoMeio(v,LI,LS);
        quicksortMeio(v,LI,p-1);
        quicksortMeio(v,p+1,LS);
    }

}

void quicksortUltimo(str *v, int LI, int LS)
{

    if(LI<LS)
    {
        int p;
        p = particaoUltimo(v,LI,LS);
        quicksortUltimo(v,LI,p-1);
        quicksortUltimo(v,p+1,LS);
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

    //pivo como primeiro elemento
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarVetorAleatorio(A);


        clock_t start_time,end_time;
        start_time=clock();
        quicksortEsquerda(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort aletorio pivo como primeiro elemento: %.3f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

    }

    printf("----------------------\n");
    //pivo como ultimo elemento
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarVetorAleatorio(A);
        clock_t start_time,end_time;
        start_time=clock();
        quicksortUltimo(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort aletorio pivo ultimo elemento: %.3f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

    }

    printf("----------------------\n");
    //pivo como elemento medio
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarVetorAleatorio(A);
        clock_t start_time,end_time;
        start_time=clock();
        quicksortMeio(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort aletorio pivo elemento meio: %.3f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

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


        //pivo como primeiro elemento
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarOrdenado(A);
        clock_t start_time,end_time;
        start_time=clock();
        quicksortEsquerda(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort ordenado pivo primeiro elemento: %.3f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

    }
    printf("----------------------\n");
    //pivo como ultimo elemento
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarOrdenado(A);
        clock_t start_time,end_time;
        start_time=clock();
        quicksortUltimo(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort ordenado pivo ultimo elemento: %.3f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

    }
    printf("----------------------\n");
    //pivo como elemento medio
    for(int i=0; i<20; i++)
    {
        srand(i);
        gerarOrdenado(A);
        clock_t start_time,end_time;
        start_time=clock();
        quicksortMeio(A,0,n-1);
        end_time=clock();
        printf("Tempo decorrido de Quickshort ordenado pivo elemento meio: %.3f segundos\n",((float)(end_time-start_time))/CLOCKS_PER_SEC);

    }




    return 0;
}
