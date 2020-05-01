#include "grafyLepsze.h"

void utworzMacSas(int v)
{
    macSas = new short * [v];
    for(int i=0; i<v; i++)
        macSas[i] = new short[v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            macSas[i][j] = 0;
    }
}

int dodajDoMacSas(int x, int y)
{
    macSas[x][y] = 1;
    macSas[y][x] = -1;
    return 0;
}

void utworzLisNast(int v)
{
    lisNast = new listaElem * [v];
    for(int i=0; i<v; i++)
    {
        lisNast[i] = NULL;
    }
}

void dodajDoLisNast(int x, int y)
{
    if(lisNast[x] && lisNast[x]->dane < y)
    {
        listaElem * rodz = lisNast[x];
        while(rodz->next && rodz->next->dane < y)
            rodz = rodz->next;
        listaElem * nowy = new listaElem;
        nowy->next = rodz->next;
        nowy->dane = y;
        rodz->next = nowy;
    }
    else
    {
        listaElem * nowy = new listaElem;
        nowy->next = lisNast[x];
        nowy->dane = y;
        lisNast[x] = nowy;
    }
}

void utworzMacGrafu(int v)
{
    macGrafu = new short * [v];
    for(int i=0; i<v; i++)
        macGrafu[i] = new short[v+3];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v+3; j++)
            macGrafu[i][j] = 0;
    }
}

void wypelnijMacGrafu()
{
    for(int j=0; j<v; j++)
    {
        short ostWych = -1;
        short ostWcho = -1;
        short ostNieInc = -1;
        for(int i=v-1; i>=0; i--)
        {
            if (macSas[j][i] == 1)
            {
                ostWych = i;
                break;
            }
        }
        for(int i=v-1; i>=0; i--)
        {
            if (macSas[j][i] == -1)
            {
                ostWcho = i;
                break;
            }
        }
        for(int i=v-1; i>=0; i--)
        {
            if (macSas[j][i] == 0)
            {
                ostNieInc = i;
                break;
            }
        }
        for(int i=0; i<v; i++)
        {
            if (macSas[j][i] == 1)
                macGrafu[j][i] = ostWych+1;
            else if (macSas[j][i] == -1)
                macGrafu[j][i] = ostWcho+v+1;
            else if (macSas[j][i] == 0)
                macGrafu[j][i] = -ostNieInc-1;
        }
        for(int i=0; i<v; i++)
        {
            if (macSas[j][i] == 1)
            {
                macGrafu[j][v] = i+1;
                break;
            }
        }
        for(int i=0; i<v; i++)
        {
            if (macSas[j][i] == -1)
            {
                macGrafu[j][v+1] = i+1;
                break;
            }
        }
        for(int i=0; i<v; i++)
        {
            if (macSas[j][i] == 0)
            {
                macGrafu[j][v+2] = i+1;
                break;
            }
        }
    }
}

int * stworzLosoweWierzcholki(int v)
{
    int * losoweWierzcholki = new int[v];
    bool wylosowaneWiercholki[v];
    for(int i=0; i<v ;i++)
        wylosowaneWiercholki[i] = false;

    for(int i=0; i<v; i++)
    {
        do
            losoweWierzcholki[i] = rand() % v;
        while(wylosowaneWiercholki[losoweWierzcholki[i]]);
        wylosowaneWiercholki[losoweWierzcholki[i]] = true;
    }
    delete wylosowaneWiercholki;
    return losoweWierzcholki;
}

void utworzLosowo(int wierzcholki, int procenty) //szybkie jak błyskawica
{
    cout << "Tworzenie grafu losowo." << endl;
    v = wierzcholki;
    e = v*(v-1)*procenty/200;
    utworzMacSas(v);
    utworzLisNast(v);
    utworzMacGrafu(v);
    cout << "Tworzenie losowej tablicy." << endl;
    int * losoweWierzcholki = stworzLosoweWierzcholki(v);
    cout << "Losowanie lukow." << endl;
    int maxE = v*(v-1)/2; // max numer luku
    bool wylosowaneLuki[maxE];
    for(int i=0; i<maxE ;i++)
        wylosowaneLuki[i] = false;
    int wylos; // wylosowany numer luku
    int s; //suma (prog do kolejnej dlugosci; suma pierwszych n elementow zbioru [v-1, v-2, v-3, ..., 3, 2, 1])
    int dlugosc; //dlugosc luku
    int zaczepienie; //index losowego wierzcholka z ktorego zaczyna sie luk
    int x; //poczatek luku w "poprawnej" numeracji
    int y; //koniec luku w "poprawnej" numeracji

    cout <<"ilosc: " << e << endl;
    for(int i=0; i<e; i++) // i - index luku
    {
        if(e>10 &&!(i%(e/10)))
            cout << (i*100)/e << "%  " << endl;
        do
            wylos = (rand()*rand()) % maxE;
        while(wylosowaneLuki[wylos]);
        wylosowaneLuki[wylos] = true;
        s = v-1;
        dlugosc = 1;
        while(wylos >= s)
            s += v - ++dlugosc;
        zaczepienie = wylos - s + v -dlugosc;
        x = losoweWierzcholki[zaczepienie];
        y = losoweWierzcholki[zaczepienie+dlugosc];
        if(dodajDoMacSas(x, y))
            cout << "Blad :C" << endl;
        dodajDoLisNast(x, y);
    }
    cout << "100%" << endl;
    wypelnijMacGrafu();
}

void utworzZKonsoli()
{
    cout << "Tworzenie grafu z konsoli." << endl;
    v = zKonsoli(0,1000,"podaj ilosc wierzcholkow: ", "Nie poprawna ilosc.");
    e = zKonsoli(0,v*(v-1)*0.5,"podaj ilosc lukow: ", "Nie poprawna ilosc.");
    utworzMacSas(v);
    utworzLisNast(v);
    utworzMacGrafu(v);
    cout << "Wprowadzanie lukow z konsoli." << endl;
    int err; //kod bledu
    int x, y; //poczatek i koniec lukow
    for(int i=0; i<e; i++)
    {
        do
        {
            x = zKonsoli(1, v, "podaj poczatek luku (" + toString(i+1) + "/" + toString(e) + "): ", "Bledne id wierzcholka.");
            y = zKonsoli(1, v, "podaj koniec luku (" + toString(i+1) + "/" + toString(e) + "): ", "Bledne id wierzcholka.");
            x--;
            y--;
            err = dodajDoMacSas(x, y);
            if(err == -1)
                cout << "Luki nie moga byc petlami wlasnymi (nie moga wychodzic i wchodzic do tego samego wierzcholka)." << endl;
            else if(err == -2)
                cout << "Taki luk juz istnieje (nie ma multigrafow)." << endl;
            else if(err == -3)
                cout << "Taki luk spowoduje cykl." << endl;
        }
        while(err<0);
        dodajDoLisNast(x, y);
    }
    wypelnijMacGrafu();
}

void utworzZPliku()
{
    string loc;
    fstream plik;
    cout << "Generowanie grafu z plku." << endl;
    cout << "podaj lokalizacje pliku: ";
    cin >> loc;
    plik.open(loc.c_str(), ios::in);
    if(plik.good())
    {
        plik >> v;
        plik >> e;
        if(e>v*(v-1)*0.5)
        {
            cout << "Zbyt duzo lukow." << endl;
            plik.close();
            return;
        }
        utworzMacSas(v);
        utworzLisNast(v);
        utworzMacGrafu(v);
        int err; //kod bledu
        int x, y; //poczatek i koniec lukow
        while(!plik.eof())
        {
            plik >> x;
            plik >> y;
            x--;
            y--;
            err = dodajDoMacSas(x, y);
            if(err == -1)
                cout << "Plik zawiera wierzolki z petlami wlasnymi." << endl;
            else if(err == -2)
                cout << "Graf zapisany w plku jest multigrafem." << endl;
            else if(err == -3)
                cout << "Graf posiada cykl." << endl;
            if(err < 0)
            {
                plik.close();
                return;
            }
            dodajDoLisNast(x, y);
        }
        wypelnijMacGrafu();
    }
    else
    {
        cout << "Niepoprawna lokalizacja. :C";
    }
    plik.close();
}
