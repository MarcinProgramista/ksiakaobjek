#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
     vector <Adresat> adresaci;


 public:

    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
    }
    int dodajAdresata(int idZalogowanegoUzytownika);
    int pobierzIdOstatniegoAdresata();
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika,int idOstatniegoAdresata);

    void wypiszWszystkichAdresatow();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};
#endif
