#include "grafyLepsze.h"

void sortujDEL_msasiedztwa()
{
    cout << "Sortowanie grafu - Usuwanie zerowego stopnia - Macierz sasiedztwa" << endl;
    cout << "Posortowane : ";
    //kopia macierzy
    short ** T = new short * [v];
    for(int i=0; i<v; i++)
        T[i] = new short[v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            T[i][j] = macSas[i][j];
    }
    //usuniete
    bool usuniete[v];
    for(int i=0; i<v; i++)
        usuniete[i] = false;

    //sortowanie
    int i=0;
    while(i<v)
    {
        if(usuniete[i])
        {
            i++;
            continue;
        }
        int j = 0;
        while(j<v)
        {
            if(T[i][j] < 0)
            {
                i++;
                break;
            }
            j++;
        }
        if(j==v)
        {
            usuniete[i] = true;
            cout << "\t" << i+1;
            for(int k=0; k<v; k++)
                    T[k][i] = 0;
            i = 0;
        }
    }
    cout << endl;
}

void sortujDEL_lnastepnikow() //dziala na odwrot
{
    cout << "Sortowanie grafu - Usuwanie zerowego stopnia - Lista nastepnikow" << endl;
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
    //tablica wyjsciowa
    int out[v];
    int index = v-1;
    //tablica usunietych
    bool usuniete[v];
    for(int i=0; i<v; i++)
        usuniete[i] = false;
    //sortowanie
    int i = 0;
    while(i<v) //wsyszukiwanie pustych nastepnikow
    {
        if(!usuniete[i] && T[i] == NULL)
        {
            out[index--] = i+1;
            usuniete[i] = true;
            for(int j=0; j<v; j++) //usuwanie lukow miedzy wierz. "i" i wierz. "j"
            {
                if(T[j])
                {
                    listaElem * usuwany;
                    if(T[j]->dane == i) //usuwanie pierwszego
                    {
                        usuwany = T[j];
                        T[j] = T[j]->next;
                        delete usuwany;
                    }
                    else    //usuwanie kolejnych
                    {
                        listaElem * e = T[j];
                        while(e->next && e->next->dane <= i)
                        {
                            if(e->next->dane == i)
                            {
                                usuwany = e->next;
                                e->next = usuwany->next;
                                delete usuwany;
                                break;
                            }
                            e = e->next;
                        }
                    }
                }
            }
            i=0;
        }
        else
            i++;
    }
    for(int i=0; i<v; i++)
        cout << "\t" << out[i];
    cout << endl;
}

void sortujDEL_mgrafu()
{
    bool temp[v];
	for (int i = 0;i<v;i++)
		temp[i]=true;
    cout << "Sortowanie grafu - Usuwanie zerowego stopnia - Macierz grafu" << endl;
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
    //sortowanie
	for (int l=0;l<v;l++)
    {
		for (int i = 0; i<v;i++)
		{
			if(temp[i] && T[i][v+1]==0)
			{
				temp[i] = false;
				cout << i+1 << " ";
				for (int j=0;j<v;j++)
				{
					if(temp[j])
					{
						T[j][v+1]=0;
						for(int k=0; k<v ;k++)
						{
							if (T[j][k] > v && temp[k])
							{
								T[j][v+1]=k;
								break;
							}
						}
					}
				}
				break;
			}
		}
    }
    cout << endl;
}
