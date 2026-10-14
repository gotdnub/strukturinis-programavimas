#include <iomanip>
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << fixed << setprecision(2);
    const double GBP_Bendras  = 0.8729;
    const double GBP_Pirkti   = 0.8600;
    const double GBP_Parduoti = 0.9220;

    const double USD_Bendras  = 1.1793;
    const double USD_Pirkti   = 1.1460;
    const double USD_Parduoti = 1.2340;

    const double INR_Bendras  = 104.6918;
    const double INR_Pirkti   = 101.3862;
    const double INR_Parduoti = 107.8546;
    int choice;

    do {
        cout<<"\n --- VALIUTOS KEITYKLOS MENIU ---" << endl;
        cout<<"1. Valiutos kurso palyginimas" << endl;
        cout<<"2. Valiutos pirkimas" << endl;
        cout<<"3. Valiutos pardavimas" << endl;
        cout<<"0. Išeiti" << endl;
        cout<<"Iveskite pasirinkima " << endl;
        cin >> choice;

        switch (choice) {
            case 1: { // palyginimas
                int choice2;
                do {
                    cout << "\n --- PASIRINKITE VALIUTĄ ---" << endl;
                    cout<< "1. GBP" << endl;
                    cout<< "2. USD" << endl;
                    cout<< "3. INR" << endl;
                    cout <<"0. Atgal" << endl;
                    cin >> choice2;

                    switch (choice2) {
                        case 1:
                            cout << "--- GBP ---" << endl;
                            cout << "Bendras:   1 EUR = "<< GBP_Bendras <<" GBP" << endl;
                            cout << "           1 GBP = " << 1 / GBP_Bendras << " EUR" << endl;
                            cout << "Pirkti:    1 EUR = "<< GBP_Pirkti <<" GBP" << endl;
                            cout << "Parduoti:  1 EUR = "<< GBP_Parduoti <<" GBP" << endl;
                            break;

                        case 2:
                            cout << "--- USD ---" << endl;
                            cout << "Bendras:   1 EUR = "<< USD_Bendras <<" USD" << endl;
                            cout << "           1 USD = " << 1 / USD_Bendras << " EUR" << endl;
                            cout << "Pirkti:    1 EUR = "<< USD_Pirkti <<" USD" << endl;
                            cout << "Parduoti:  1 EUR = "<< USD_Parduoti <<" USD" << endl;
                            break;

                        case 3:
                            cout << "--- INR ---" << endl;
                            cout << "Bendras:   1 EUR = "<< INR_Bendras <<" INR" << endl;
                            cout << "           1 INR = " << 1 / INR_Bendras << " EUR" << endl;
                            cout << "Pirkti:    1 EUR = "<< INR_Pirkti <<" INR" << endl;
                            cout << "Parduoti:  1 EUR = "<< INR_Parduoti <<" INR" << endl;
                            break;

                        case 0:
                            cout << "Grįžtama..." << endl;
                            break;

                        default:
                            cout << "Tokio pasirinkimo nera" << endl;
                            break;
                    }

                }while (choice2 != 0);
                break;
            }
            case 2: { // pirkimas
                int choice2;
                    cout << "\n --- PASIRINKITE VALIUTĄ ---" << endl;
                    cout<< "1. GBP" << endl;
                    cout<< "2. USD" << endl;
                    cout<< "3. INR" << endl;
                    cout <<"0. Atgal" << endl;
                    cin >> choice2;

                if (choice2 < 0 || choice2 > 3 ) {
                    cout << "Tokio pasirinkimo nera" << endl;
                    break;
                }

                if (choice2 == 0) {
                    cout << "Grįžtama..." << endl;
                    break;
                }

                double suma;
                cout << "Įveskite sumą EUR: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Klaida: suma turi būti teigiama." << endl;
                    break;
                }


                switch (choice2) {
                    case 1:
                        cout << "Pradinė suma: " << suma << " EUR" << endl;
                        cout << "Valiuta: GBP" << endl;
                        cout << "Gausite: " << suma * GBP_Pirkti << " GBP" << endl;
                        break;

                    case 2:
                        cout << "Pradinė suma: " << suma << " EUR" << endl;
                        cout << "Valiuta: USD" << endl;
                        cout << "Gausite: " << suma * USD_Pirkti << " USD" << endl;
                        break;

                    case 3:
                        cout << "Pradinė suma: " << suma << " EUR" << endl;
                        cout << "Valiuta: INR" << endl;
                        cout << "Gausite: " << suma * INR_Pirkti << " INR" << endl;
                        break;

                }
                break;
            }

            case 3: { // pardavimas
                int choice2;
                cout << "\n --- PASIRINKITE VALIUTĄ ---" << endl;
                cout<< "1. GBP" << endl;
                cout<< "2. USD" << endl;
                cout<< "3. INR" << endl;
                cout <<"0. Atgal" << endl;
                cin >> choice2;

                if (choice2 < 0 || choice2 > 3 ) {
                    cout << "Tokio pasirinkimo nera" << endl;
                    break;
                }

                if (choice2 == 0) {
                    cout << "Grįžtama..." << endl;
                    break;
                }

                double suma;
                cout <<"Įveskite valiutos parduodamą sumą: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Klaida: suma turi būti teigiama." << endl;
                    break;
                }

                switch (choice2) {
                    case 1:
                        cout << "Pradinė suma: " << suma << " GBP" << endl;
                        cout << "Valiuta: GBP" << endl;
                        cout << "Gausite: " << suma / GBP_Parduoti << " EUR" << endl;
                        break;

                    case 2:
                        cout << "Pradinė suma: " << suma << " USD" << endl;
                        cout << "Valiuta: USD" << endl;
                        cout << "Gausite: " << suma / USD_Parduoti << " EUR" << endl;
                        break;

                    case 3:
                        cout << "Pradinė suma: " << suma << " INR" << endl;
                        cout << "Valiuta: INR" << endl;
                        cout << "Gausite: " << suma / INR_Parduoti << " EUR" << endl;
                        break;

                }
                break;

            }
            case 0:
                cout << "Baigiama..." << endl;
                break;

            default:
                cout << "Tokio pasirinkimo nera" << endl;
                break;
        }

    } while (choice != 0);


    return 0;
}