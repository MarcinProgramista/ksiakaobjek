#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
   if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" <<endl;
   else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku. " << endl;

   system("pause");
}

Adresat  AdresatMenedzer:: podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numeTelefonu, email, adres;

    adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    for (int i = 0; i < adresaci.size(); i++)
    {
        cout << "Id:                   " << adresaci[i].pobierzId() <<  endl;
        cout << "Id Uzytkownika:       " << adresaci[i].pobierzIdUzytkownika() <<  endl;
        cout << "Imie:                 " << adresaci[i].pobierzImie() <<  endl;
        cout << "Nazwisko:             " << adresaci[i].pobierzNazwisko() <<  endl;
        cout << "Numer Telefonu        " << adresaci[i].pobierzNumerTelefonu() <<  endl;
        cout << "Emial:                " << adresaci[i].pobierzEmail() <<  endl;
        cout << "Adres:                " << adresaci[i].pobierzAdres() <<  endl;
    }
}
