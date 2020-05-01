#include "grafyLepsze.h"

void wypiszMacSas()
{
    cout << "Wypisywanie macierzy sasiectwa:" << endl;
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        	wypEl(macSas[i][j]);
        cout << endl;
    }
}

void wypiszLisNast()
{
    cout << "Wypisywanie listy nastepnikow:" << endl;
    for(int i=0; i<v; i++)
    {
        cout << i+1;
        listaElem * e = lisNast[i];
        while(e)
        {
            cout << "->" << e->dane+1;
            e = e->next;
        }
        cout << endl;
    }
}

void wypiszMacGrafu()
{
    cout << "Wypisywanie macierzy grafu:" << endl;
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v+3; j++)
        	wypEl(macGrafu[i][j]);
        cout << endl;
    }
}
