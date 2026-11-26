#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 100;

bool nuskaityti(string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int& n) {
    ifstream failas("uzsakymas.txt");
    if (!failas) {
        cout << "Klaida: nepavyko atidaryti failo uzsakymas.txt" << endl;
        return false;
    }
    failas >> n;
    if (failas.fail() || n < 1 || n > MAX) {
        cout << "Klaida: blogas irasu skaicius (turi buti nuo 1 iki 100)." << endl;
        return false;
    }
    for (int i = 0; i < n; i++) {
        char kabliataskis;
        failas >> ws;
        getline(failas, kategorijos[i], ';');
        getline(failas, pavadinimai[i], ';');
        failas >> kainos[i] >> kabliataskis >> kiekiai[i];
        if (failas.fail() || kabliataskis != ';') {
            cout << "Klaida: nepavyko nuskaityti " << i + 1 << " iraso." << endl;
            return false;
        }
        if (kategorijos[i] != "Dviraciai" && kategorijos[i] != "Dalys" && kategorijos[i] != "Aksesuarai") {
            cout << "Klaida: " << i + 1 << " iraso kategorija netinkama." << endl;
            return false;
        }
        if (kainos[i] <= 0) {
            cout << "Klaida: " << i + 1 << " iraso kaina turi buti teigiama." << endl;
            return false;
        }
        if (kiekiai[i] <= 0) {
            cout << "Klaida: " << i + 1 << " iraso kiekis turi buti teigiamas." << endl;
            return false;
        }
    }
    return true;
}

double eilutesSuma(double kaina, int kiekis) {
    return kaina * kiekis;
}

double nuolaida(double suma, int kiekis) {
    if (kiekis >= 10) {
        return suma * 0.10;
    }
    return 0;
}

double kategorijosSuma(string kategorija, string kategorijos[], double kainos[], int kiekiai[], int n) {
    double bendra = 0;
    for (int i = 0; i < n; i++) {
        if (kategorijos[i] == kategorija) {
            double suma = eilutesSuma(kainos[i], kiekiai[i]);
            bendra = bendra + suma - nuolaida(suma, kiekiai[i]);
        }
    }
    return bendra;
}

int spausdintiPrekes(ostream& out, string kategorija, string kategorijos[], string pavadinimai[],
                     double kainos[], int kiekiai[], int n) {
    int kiek = 0;
    out << left << setw(12) << "Kategorija" << setw(50) << "Pavadinimas" << right << setw(10) << "Kaina"
        << setw(7) << "Kiekis" << setw(14) << "Suma" << setw(12) << "Nuolaida" << setw(14) << "Moketina" << endl;
    for (int i = 0; i < n; i++) {
        if (kategorija == "" || kategorijos[i] == kategorija) {
            double suma = eilutesSuma(kainos[i], kiekiai[i]);
            double nuol = nuolaida(suma, kiekiai[i]);
            out << left << setw(12) << kategorijos[i] << setw(50) << pavadinimai[i] << right << setw(10) << kainos[i]
                << setw(7) << kiekiai[i] << setw(14) << suma << setw(12) << nuol << setw(14) << suma - nuol << endl;
            kiek++;
        }
    }
    return kiek;
}

void spausdintiSumas(ostream& out, double kainos[], int kiekiai[], int n) {
    double pries = 0;
    double nuolaidos = 0;
    for (int i = 0; i < n; i++) {
        double suma = eilutesSuma(kainos[i], kiekiai[i]);
        pries = pries + suma;
        nuolaidos = nuolaidos + nuolaida(suma, kiekiai[i]);
    }
    out << "Suma pries nuolaidas: " << pries << " EUR" << endl;
    out << "Bendra nuolaida:      " << nuolaidos << " EUR" << endl;
    out << "Moketina suma:        " << pries - nuolaidos << " EUR" << endl;
}

void spausdintiKategorijas(ostream& out, string kategorijos[], double kainos[], int kiekiai[], int n) {
    out << "Dviraciai:  " << kategorijosSuma("Dviraciai", kategorijos, kainos, kiekiai, n) << " EUR" << endl;
    out << "Dalys:      " << kategorijosSuma("Dalys", kategorijos, kainos, kiekiai, n) << " EUR" << endl;
    out << "Aksesuarai: " << kategorijosSuma("Aksesuarai", kategorijos, kainos, kiekiai, n) << " EUR" << endl;
}

void spausdintiAtaskaita(ostream& out, string kategorijos[], string pavadinimai[], double kainos[],
                         int kiekiai[], int n) {
    out << "UZSAKYMO ATASKAITA" << endl << endl;
    spausdintiPrekes(out, "", kategorijos, pavadinimai, kainos, kiekiai, n);
    out << endl << "VISO UZSAKYMO SUMOS" << endl;
    spausdintiSumas(out, kainos, kiekiai, n);
    out << endl << "SUMOS PAGAL KATEGORIJAS" << endl;
    spausdintiKategorijas(out, kategorijos, kainos, kiekiai, n);
}

bool issaugoti(string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int n) {
    ofstream failas("ataskaita.txt");
    if (!failas) {
        cout << "Klaida: nepavyko atidaryti failo ataskaita.txt" << endl;
        return false;
    }
    failas << fixed << setprecision(2);
    spausdintiAtaskaita(failas, kategorijos, pavadinimai, kainos, kiekiai, n);
    if (failas.fail()) {
        cout << "Klaida: nepavyko irasyti i faila." << endl;
        return false;
    }
    return true;
}

int ivestiSkaiciu(int min, int max) {
    int x;
    while (true) {
        if (cin >> x && x >= min && x <= max) {
            return x;
        }
        if (cin.eof()) {
            return max;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Netinkama reiksme. Iveskite skaiciu nuo " << min << " iki " << max << ": ";
    }
}

int main() {
    string kategorijos[MAX];
    string pavadinimai[MAX];
    double kainos[MAX];
    int kiekiai[MAX];
    int n;

    if (!nuskaityti(kategorijos, pavadinimai, kainos, kiekiai, n)) {
        return 1;
    }
    cout << fixed << setprecision(2);

    int pasirinkimas;
    do {
        cout << endl << "===== MENIU =====" << endl;
        cout << "1. Perziureti visas uzsakymo prekes" << endl;
        cout << "2. Perziureti pasirinktos kategorijos prekes" << endl;
        cout << "3. Perziureti viso uzsakymo sumas" << endl;
        cout << "4. Perziureti sumas pagal kategorijas" << endl;
        cout << "5. Parodyti visa uzsakymo ataskaita" << endl;
        cout << "6. Issaugoti visa ataskaita i faila" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Pasirinkimas: ";
        pasirinkimas = ivestiSkaiciu(1, 7);
        cout << endl;

        if (pasirinkimas == 1) {
            spausdintiPrekes(cout, "", kategorijos, pavadinimai, kainos, kiekiai, n);
        } else if (pasirinkimas == 2) {
            cout << "1 - Dviraciai, 2 - Dalys, 3 - Aksesuarai" << endl;
            cout << "Pasirinkite kategorija: ";
            int k = ivestiSkaiciu(1, 3);
            string kategorija;
            if (k == 1) kategorija = "Dviraciai";
            else if (k == 2) kategorija = "Dalys";
            else kategorija = "Aksesuarai";

            int kiek = spausdintiPrekes(cout, kategorija, kategorijos, pavadinimai, kainos, kiekiai, n);
            if (kiek == 0) {
                cout << "Sios kategorijos prekiu uzsakyme nera." << endl;
            }
            cout << "Kategorijos moketina suma: "
                 << kategorijosSuma(kategorija, kategorijos, kainos, kiekiai, n) << " EUR" << endl;
        } else if (pasirinkimas == 3) {
            spausdintiSumas(cout, kainos, kiekiai, n);
        } else if (pasirinkimas == 4) {
            spausdintiKategorijas(cout, kategorijos, kainos, kiekiai, n);
        } else if (pasirinkimas == 5) {
            spausdintiAtaskaita(cout, kategorijos, pavadinimai, kainos, kiekiai, n);
        } else if (pasirinkimas == 6) {
            if (issaugoti(kategorijos, pavadinimai, kainos, kiekiai, n)) {
                cout << "Ataskaita issaugota faile ataskaita.txt" << endl;
            }
        }
    } while (pasirinkimas != 7);

    return 0;
}