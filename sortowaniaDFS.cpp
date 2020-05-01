#include "grafyLepsze.h"

void sortujDFS_msasiedztwa()
{
    cout << "Sortowanie grafu - DFS - Macierz sasiedztwa" << endl;
    cout << "Posortowane : ";
    //kopia macierzy
    short ** T;
    T = new short * [v];
    for(int i=0; i<v; i++)
        T[i] = new short[v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            T[i][j] = macSas[i][j];
    }
    //informacja o usunietych wierzcholkach
    bool usuniete[v];
    for(int i=0; i<v; i++)
        usuniete[i] = false;
    //stos
    int stos[1000];
    int stosIndex = 0;
    //tablica wyjsciowa
    int out[v];
    int outIndex = v;
    //sortowanie
    int wierzcholek;
    do
    {
        //znajdowanie nowego startowego wierzolka z in=0
        wierzcholek = -1;
        for(int i=0; i<v; i++)
        {
            if(usuniete[i])
                continue;
            int j;
            for(j=0; j<v; j++)
            {
                if(T[i][j]<0)
                    break;
            }
            if(j==v)
            {
                wierzcholek = i;
                break;
            }
        }
        //jak nie znaleziono to konczenie
        if(wierzcholek == -1)
            break;
        stos[stosIndex++] = wierzcholek;
        while(stosIndex > 0)
        {
            wierzcholek = stos[--stosIndex];
            //przechodzenie w glab, oddkladajac na stos, do momonetu znalezienia wierzcholka out=0
            int i;
            for(i=0; i<v; i++)
            {
                if(T[wierzcholek][i]==1)
                {
                    stos[stosIndex++] = wierzcholek;
                    wierzcholek = i;
                    i = -1;
                }
            }
            //usuwanie wierzolka o out=0
            if(i==v)
            {
                out[--outIndex] = wierzcholek;
                usuniete[wierzcholek] = true;
                for(int j=0; j<v; j++)
                    T[j][wierzcholek] = 0;
            }
        }
    }while(true);
    for(int i=0; i<v; i++)
        cout << "\t" << out[i]+1;
    cout << endl;
}

void sortujDFS_lnastepnikow()
{
    cout << "Sortowanie grafu - DFS - Lista Nastepnikow" << endl;
    cout << "Posortowane : ";
    //kopia listy
    listaElem ** T;
    T = new listaElem * [v];
    for(int i=0; i<v; i++)
    {
        if(lisNast[i])
        {
            listaElem * stary = lisNast[i];
            listaElem * nowy = new listaElem;
            T[i] = nowy;
            nowy->dane = stary->dane;
            while(stary->next)
            {
                nowy->next = new listaElem;
                nowy->next->dane = stary->next->dane;
                nowy = nowy->next;
                stary = stary->next;
            }
            nowy->next = NULL;
        }
        else
            T[i] = NULL;

    }
    //informacja o usunietych wierzcholkach
    bool usuniete[v];
    for(int i=0; i<v; i++)
        usuniete[i] = false;
    //stos
    int stos[1000];
    int stosIndex = 0;
    //tablica wyjsciowa
    int out[v];
    int outIndex = v;
    //sortowanie
    int wierzcholek;
    do
    {
        //znajdowanie nowego startowego wierzolka z in=0
        wierzcholek = -1;
        for(int i=0; i<v; i++)
        {
            if(usuniete[i])
                continue;
            int j;
            for(j=0; j<v; j++)
            {
                if(i!=j && !usuniete[j])
                {
                    listaElem * elem = T[j];
                    while(elem)
                    {
                        if(elem->dane == i)
                            break;
                        elem = elem->next;
                    }
                    if(elem) //je�eli znalaz�o to kolejne i
                    {
                        break;
                    }
                }
            }
            if(j==v)
            {
                wierzcholek = i;
                break;
            }
        }
        //jak nie znaleziono to konczenie
        if(wierzcholek == -1)
            break;
        stos[stosIndex++] = wierzcholek;
        while(stosIndex > 0)
        {
            wierzcholek = stos[--stosIndex];
            //przechodzenie w glab, oddkladajac na stos, do momonetu znalezienia wierzcholka out=0
            listaElem * elem = T[wierzcholek];
            while(elem)
            {
                elem = T[wierzcholek];
                while(elem)
                {
                    if(!usuniete[elem->dane])
                    {
                        stos[stosIndex++] = wierzcholek;
                        wierzcholek = elem->dane;
                        break;
                    }
                    elem = elem->next;
                }
            }

            //usuwanie wierzolka o out=0
            out[--outIndex] = wierzcholek;
            usuniete[wierzcholek] = true;
        }
    }while(true);
    for(int i=0; i<v; i++)
        cout << "\t" << out[i]+1;
    cout << endl;
}

void sortujDFS_mgrafu()
{
    cout << "Sortowanie grafu - DFS - Macierz grafu" << endl;
    cout << "Posortowane : ";
    //kopia macierzy
    short ** T;
	T = new short * [v];
    for(int i=0; i<v; i++)
        T[i] = new short[v+3];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v+3; j++)
            T[i][j] = macGrafu[i][j];
    }
    //informacja o usunietych wierzcholkach
    bool usuniete[v];
    for(int i=0; i<v; i++)
        usuniete[i] = false;
    //stos
    int stos[1000];
    int stosIndex = 0;
    //tablica wyjsciowa
    int out[v];
    int outIndex = v;
    //sortowanie
    int wierzcholek;
    do
    {
        //znajdowanie nowego startowego wierzolka z in=0
        wierzcholek = -1;
        for(int i=0; i<v; i++)
        {
            if(!usuniete[i] && T[i][v+1] == 0)
                wierzcholek = i;
        }
        //jak nie znaleziono to konczenie
        if(wierzcholek == -1)
            break;
        stos[stosIndex++] = wierzcholek;
        while(stosIndex > 0)
        {
            wierzcholek = stos[--stosIndex];
            //przechodzenie w glab, oddkladajac na stos, do momonetu znalezienia wierzcholka out=0
            while(T[wierzcholek][v] != 0)
            {
                stos[stosIndex++] = wierzcholek;
                wierzcholek = T[wierzcholek][v]-1;
            }
            //usuwanie wierzolka o out=0
            out[--outIndex] = wierzcholek;
            usuniete[wierzcholek] = true;
            //aktualizacja kolumny
            for(int i=0;i<v;i++)
            {
                if(!usuniete[i])
                {
                    T[i][v]=0;
                    for(int k=0; k<v ;k++)
                    {
                        if(T[i][k] > 0 && T[i][k] <= v && !usuniete[k])
                        {
                            T[i][v]=k+1;
                            break;
                        }
                    }
                }
            }
        }
    }while(true);
    for(int i=0; i<v; i++)
        cout << "\t" << out[i]+1;
    cout << endl;
}
