#include "grafyLepsze.h"

//grafy w pamieci
int v, e;
short ** macSas;
listaElem ** lisNast;
short ** macGrafu;
auto start = chrono::steady_clock::now();
auto end = chrono::steady_clock::now();

int main()
{
    srand(time(NULL));
    cout << "Witaj w prawie najlepszym programie do sortowania grafow. (v 0.3.0)" << endl;
    int opcjaI;
    bool zamykanie = false;
    while(!zamykanie)
    {
        cout << endl;
        cout << "Co chcesz zrobic?" << endl;
        cout << "1 - Utworz graf z liczb losowych" << endl;
        cout << "2 - Utworz graf z danych wpisanych w konsoli" << endl;
        cout << "3 - Utworz graf z pliku" << endl;
        cout << "4 - Wyswietl graf - Macierz sasiedztwa" << endl;
        cout << "5 - Wyswietl graf - Lista nastepnikow" << endl;
        cout << "6 - Wyswietl graf - Macierz grafu" << endl;
        cout << "7 - Sortuj topologicznie graf - DFS - Macierz sasiedztwa" << endl;
        cout << "8 - Sortuj topologicznie graf - DFS - Lista nastepnikow" << endl;
        cout << "9 - Sortuj topologicznie graf - DFS - Macierz grafu (nie dziala)" << endl;
        cout << "10 - Sortuj topologicznie graf - Usuwanie zerowego stopnia - Macierz sasiedztwa" << endl;
        cout << "11 - Sortuj topologicznie graf - Usuwanie zerowego stopnia - Lista nastepnikow" << endl;
        cout << "12 - Sortuj topologicznie graf - Usuwanie zerowego stopnia - Macierz grafu (nie dziala)" << endl;
        cout << "13 - Zamknij program" << endl;
        cout << endl;
        opcjaI = zKonsoli(0, 13, "","Bledne polecenie.");

        switch(opcjaI)
        {
        case 1:
            utworzLosowo(2000, 50);
            break;
        case 2:
            utworzZKonsoli();
            break;
        case 3:
            utworzZPliku();
            break;
        case 4:
            wypiszMacSas();
            break;
        case 5:
            wypiszLisNast();
            break;
        case 6:
            wypiszMacGrafu();
            break;
        case 7:
            sortujDFS_msasiedztwa();
            break;
        case 8:
            sortujDFS_lnastepnikow();
            break;
        case 9:
            sortujDFS_mgrafu();
            break;
        case 10:
            sortujDEL_msasiedztwa();
            break;
        case 11:
            sortujDEL_lnastepnikow();
            break;
        case 12:
            sortujDEL_mgrafu();
            break;
        case 14:
            // TODO usuwanie
            cout << "Konczenie pracy programu" << endl;
            zamykanie = true;
            break;
        }
    }
    return 0;
}
