#ifndef GRAFY_H
#define GRAFY_H

    #include <iostream> //konsola
    #include <fstream> //pliki
    #include <stdlib.h> //random
    #include <time.h>   //random
    #include <queue> //kolejka
    #include <chrono> //czas

    using namespace std;

    //struktury
    struct listaElem
    {
        listaElem * next;
        short dane;
    };
    //zmienne globalne (main) - grafy
    extern int v, e;
    extern short ** macSas;
    extern listaElem ** lisNast;
    extern short ** macGrafu;

    //funkcje konsola
    int toInt(string s);
    string toString(int i);
    int zKonsoli(int minv, int maxv, string komunikat, string blad);
    int zKonsoli(string komunikat, string blad);
    void wypEl(int element);

    //funkcje wypisywania grafow
    void wypiszMacSas();
    void wypiszLisNast();
    void wypiszMacGrafu();

    //funckcje tworzenia grafow
    void utworzLosowo(int wierzcholki, int procenty);
    void utworzZKonsoli();
    void utworzZPliku();

    //funkcje sortowania DFS
    void sortujDFS_msasiedztwa();
    void sortujDFS_lnastepnikow();
    void sortujDFS_mgrafu();

    //funkcje sortowania DEL
    void sortujDEL_msasiedztwa();
    void sortujDEL_lnastepnikow();
    void sortujDEL_mgrafu();

#endif
