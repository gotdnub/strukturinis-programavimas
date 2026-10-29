#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

int nuskaityti() {
    string eilute;
    while (true) {
        getline(cin, eilute);
        bool tinka = true;
        if (eilute.empty() || eilute.length() > 9) {
            tinka = false;
        }
        for (int i = 0; i < eilute.length(); i++) {
            if (eilute[i] < '0' || eilute[i] > '9') {
                tinka = false;
            }
        }
        if (tinka) {
            return stoi(eilute);
        }
        cout << "Įveskite sveikąjį skaičių: ";
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string vardai[100];
    int pazymiai[100][10];
    int pazymiuSk[100];
    int mokiniuSk = 0;
    int pasirinkimas;

    do {
        cout << endl;
        cout << "===== MENIU =====" << endl;
        cout << "1. Įvesti mokinį ir jo pažymius" << endl;
        cout << "2. Peržiūrėti visų mokinių pažymius" << endl;
        cout << "3. Peržiūrėti konkretaus mokinio pažymius" << endl;
        cout << "4. Atnaujinti pažymį" << endl;
        cout << "5. Apskaičiuoti mokinio vidurkį" << endl;
        cout << "6. Pašalinti mokinį" << endl;
        cout << "7. Išeiti" << endl;
        cout << "Pasirinkite: ";
        pasirinkimas = nuskaityti();

        if (pasirinkimas == 1) {
            // 1. Įvesti mokinį
            if (mokiniuSk >= 100) {
                cout << "Pasiektas mokinių limitas (100)." << endl;
            }
            else {
                cout << "Įveskite mokinio vardą: ";
                getline(cin, vardai[mokiniuSk]);
                while (vardai[mokiniuSk].empty()) {
                    cout << "Vardas negali būti tuščias. Įveskite iš naujo: ";
                    getline(cin, vardai[mokiniuSk]);
                }

                int kiek;
                cout << "Kiek pažymių įvesite (0-10): ";
                kiek = nuskaityti();
                while (kiek < 0 || kiek > 10) {
                    cout << "Neteisingas kiekis. Įveskite skaičių nuo 0 iki 10: ";
                    kiek = nuskaityti();
                }

                pazymiuSk[mokiniuSk] = 0;
                for (int i = 0; i < kiek; i++) {
                    int p;
                    cout << "Įveskite " << i + 1 << " pažymį: ";
                    p = nuskaityti();
                    while (p < 1 || p > 10) {
                        cout << "Pažymys turi būti nuo 1 iki 10. Įveskite iš naujo: ";
                        p = nuskaityti();
                    }
                    pazymiai[mokiniuSk][i] = p;
                    pazymiuSk[mokiniuSk]++;
                }
                mokiniuSk++;
                cout << "Mokinys pridėtas." << endl;
            }
        }
        else if (pasirinkimas == 2) {
            if (mokiniuSk == 0) {
                cout << "Sąrašas tuščias." << endl;
            }
            else {
                for (int i = 0; i < mokiniuSk; i++) {
                    cout << i + 1 << ". " << vardai[i] << ": ";
                    if (pazymiuSk[i] == 0) {
                        cout << "pažymių nėra";
                    }
                    else {
                        for (int j = 0; j < pazymiuSk[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else if (pasirinkimas == 3) {
            if (mokiniuSk == 0) {
                cout << "Sąrašas tuščias." << endl;
            }
            else {
                int nr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuSk << ", 0 - atgal į meniu): ";
                nr = nuskaityti();
                while (nr != 0 && (nr < 1 || nr > mokiniuSk)) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuSk << ": ";
                    nr = nuskaityti();
                }
                if (nr != 0) {
                    int i = nr - 1;
                    cout << vardai[i] << ": ";
                    if (pazymiuSk[i] == 0) {
                        cout << "pažymių nėra";
                    }
                    else {
                        for (int j = 0; j < pazymiuSk[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else if (pasirinkimas == 4) {
            if (mokiniuSk == 0) {
                cout << "Sąrašas tuščias." << endl;
            }
            else {
                int nr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuSk << ", 0 - atgal į meniu): ";
                nr = nuskaityti();
                while (nr != 0 && (nr < 1 || nr > mokiniuSk)) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuSk << ": ";
                    nr = nuskaityti();
                }
                if (nr != 0) {
                    int i = nr - 1;
                    if (pazymiuSk[i] == 0) {
                        cout << "Šis mokinys pažymių neturi." << endl;
                    }
                    else {
                        int pnr;
                        cout << "Kelintą pažymį keisti (1-" << pazymiuSk[i] << ", 0 - atgal į meniu): ";
                        pnr = nuskaityti();
                        while (pnr != 0 && (pnr < 1 || pnr > pazymiuSk[i])) {
                            cout << "Neteisingas pažymio numeris. Įveskite skaičių nuo 1 iki " << pazymiuSk[i] << ": ";
                            pnr = nuskaityti();
                        }
                        if (pnr != 0) {
                            int naujas;
                            cout << "Įveskite naują pažymį (1-10): ";
                            naujas = nuskaityti();
                            while (naujas < 1 || naujas > 10) {
                                cout << "Pažymys turi būti nuo 1 iki 10. Įveskite iš naujo: ";
                                naujas = nuskaityti();
                            }
                            pazymiai[i][pnr - 1] = naujas;
                            cout << "Pažymys atnaujintas." << endl;
                        }
                    }
                }
            }
        }
        else if (pasirinkimas == 5) {
            if (mokiniuSk == 0) {
                cout << "Sąrašas tuščias." << endl;
            }
            else {
                int nr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuSk << ", 0 - atgal į meniu): ";
                nr = nuskaityti();
                while (nr != 0 && (nr < 1 || nr > mokiniuSk)) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuSk << ": ";
                    nr = nuskaityti();
                }
                if (nr != 0) {
                    int i = nr - 1;
                    if (pazymiuSk[i] == 0) {
                        cout << "Šis mokinys pažymių neturi, vidurkio nėra." << endl;
                    }
                    else {
                        int suma = 0;
                        for (int j = 0; j < pazymiuSk[i]; j++) {
                            suma = suma + pazymiai[i][j];
                        }
                        double vidurkis = (double)suma / pazymiuSk[i];
                        cout << "Vidurkis: " << fixed << setprecision(2) << vidurkis << endl;
                    }
                }
            }
        }
        else if (pasirinkimas == 6) {
            if (mokiniuSk == 0) {
                cout << "Sąrašas tuščias." << endl;
            }
            else {
                int nr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuSk << ", 0 - atgal į meniu): ";
                nr = nuskaityti();
                while (nr != 0 && (nr < 1 || nr > mokiniuSk)) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuSk << ": ";
                    nr = nuskaityti();
                }
                if (nr != 0) {
                    int i = nr - 1;
                    for (int k = i; k < mokiniuSk - 1; k++) {
                        vardai[k] = vardai[k + 1];
                        pazymiuSk[k] = pazymiuSk[k + 1];
                        for (int j = 0; j < pazymiuSk[k]; j++) {
                            pazymiai[k][j] = pazymiai[k + 1][j];
                        }
                    }
                    mokiniuSk--;
                    cout << "Mokinys pašalintas." << endl;
                }
            }
        }
        else if (pasirinkimas == 7) {
            cout << "Programa baigta." << endl;
        }
        else {
            cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 7." << endl;
        }

    } while (pasirinkimas != 7);

    return 0;
}