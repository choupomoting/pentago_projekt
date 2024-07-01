#include <iostream>
#include <string>

using namespace std;
const int n = 6; //wiersze i kolumny


string wpiszGracza() // dodanie nazwy graczy
{
    string gracz;
    cin >> gracz;
    return gracz;
}

void wypiszPlansze(char plansza[n][n])
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            cout << plansza[i][j] << " ";
            if (j == 2)
                cout << "|";

        }

        if (i == 2)
        {
            cout << endl;
            cout << "-------------" << endl;
        }

        else
            cout << endl;
    }
}


int sprawdz_w_poziomie(char c, char plansza[n][n]) // funkcja sprawdzajaca wygrana w poziomie
{
    int licznik;
    for (int i = 0; i < n; i++)
    {
        licznik = 0;
        for (int j = 0; j < n; j++)
        {
            if (plansza[i][j] == c)
            {
                licznik++;
            }
            if (licznik == 5)
            {
                return 1;
                break;
            }
        }
    }
    return 0;
}




int sprawdz_w_pionie(char c, char plansza[n][n]) //funkcja sprawdzajaca wygrana w pionie
{
    int licznik;
    for (int i = 0; i < n; i++)
    {
        licznik = 0;
        for (int j = 0; j < n; j++)
        {
            if (plansza[j][i] == c)
            {
                licznik++;
            }
            if (licznik == 5)
            {
                return 1;
                break;
            }
        }
    }
    return 0;
}
int sprawdz_po_skosie(char c, char plansza[n][n]) //funkcja sprawdzajaca wygrana po skosie
{
    int licznik = 0;
    for (int i = 0; i < n; i++)
    {
        if (plansza[i][i] == c || plansza[i][2 - i] == c)
        {
            licznik++;
        }
        if (licznik == 5)
        {
            return 1;
            break;
        }
    }
    return 0;
}
void sprawdzWygrana(char plansza[n][n], int tura)
{
    char zeton;
    if (tura == 1)
        zeton = 'X';
    else
        zeton = 'O';
    int a = 0;
    a += sprawdz_w_poziomie(zeton, plansza);
    a += sprawdz_w_pionie(zeton, plansza);
    a += sprawdz_po_skosie(zeton, plansza);
    if (a > 0)
        cout << "WYGRANA" << endl;
}


void wypiszTure(int tura, string gracz1, string gracz2)
{
    cout << "Tura gracza ";
    if (tura == 1)
        cout << gracz1 << ". Żetony: X" << endl;
    else
        cout << gracz2 << ". Żetony: O" << endl;

}

void wypiszOpcjeGry()
{
    cout << "A - ZROB RUCH" << endl;
    cout << "P - ZASTOPUJ GRE" << endl;
    cout << "U - COFNIJ RUCH" << endl;
    cout << "V - WYJDZ Z PROGRAMU" << endl;
    cout << "PODAJ SWOJ WYBOR: " << endl;
}
void wypisz_menu() {
    cout << "K - ZAGRAJ W KOLKO I KRZYZYK" << endl;
    cout << "L - ZAGRAJ W PENTAGO" << endl;
    cout << "O - WCZYTAJ PLANSZE" << endl;
    cout << "H - OPIS GRY" << endl;
    cout << "M - OPCJE" << endl;
    cout << "J - WYJDZ Z PROGRAMU" << endl;
    cout << "PODAJ SWOJ WYBOR: " << endl;
}
void zrobRuch(char plansza[n][n], int tura)
{
    char zeton;
    char cwiartka;
    int pole;
    if (tura == 1)
        zeton = 'X';
    else
        zeton = 'O';
    cout << "Podaj cwiartke i nr pola" << endl;
    cin >> cwiartka >> pole;
    pole--;
    int x, y;
    if (cwiartka == 'q')
    {
        x = 0;
        y = 0;
    }
    else if (cwiartka == 'w')
    {
        x = 0;
        y = 3;
    }
    else if (cwiartka == 'a')
    {
        x = 3;
        y = 0;
    }
    else if (cwiartka == 's')
    {
        x = 3;
        y = 3;
    }
    int rzad = pole / 3;
    int kolumna = pole % 3;
    if (plansza[x + rzad][y + kolumna] == '_')
        plansza[x + rzad][y + kolumna] = zeton;
    else
    {
        cout << "To miejsce juz jest zajete" << endl;
        zrobRuch(plansza, tura);
    }

}
int main() {
    char opcje_menu;
    char opcje_gry;
    string gracz1, gracz2;
    char plansza[n][n] = {
        
        {'_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_'},

    };
    int tura = 1;
    int x;
    int y;
    cout << "===============WITAJ W GRZE W KOLKO I KRZYZYK I PENTAGO=================" << endl << endl << endl;
    cout << "Podaj nazwe gracza 1" << endl;
    gracz1 = wpiszGracza();
    cout << "Podaj nazwe gracza 2" << endl;
    gracz2 = wpiszGracza();

    cout << gracz1 << endl;
    cout << gracz2 << endl;



    wypisz_menu(); //klohmj
    cin >> opcje_menu;
    do {
        switch (opcje_menu) {
        case 'k':
            do {
                wypiszPlansze(plansza);
                wypiszTure(tura, gracz1, gracz2);
                cin >> opcje_gry;

                switch (opcje_gry) {
                case 'a':
                    zrobRuch(plansza, tura);
                    // obrócić ćwiartkę
                    sprawdzWygrana(plansza, tura);
                    tura *= -1;
                    break;
                case 'p':
                    break;
                case 'u':
                    break;
                case 'v':
                    break;
                    
                default:
                    cout << "Niepoprawna opcja!" << endl << endl;
                    break;
                }
                //sprawdzWygrana(plansza, tura);
                //tura *= -1;
                // czyszczenie ekranu
            } while (opcje_gry != 'j');

            break;
        case 'l':
            break;
        case 'o':
            break;
        case 'h':
            break;
        case 'm':
            break;
        case 'j':
            break;
        default:
            cout << "Niepoprawna opcja!" << endl << endl;
            break;
        }

    } while (opcje_menu != 'j');
    
    return 0;
}
