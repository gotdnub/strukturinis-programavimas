#include <iomanip>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int balance = 100;
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
            case 1: {
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
                            cout << "\n --- GBP ---" << endl;
                            cout << "Bendras:   1 EUR = 0.8729 GBP" << endl;
                            cout << "Pirkti:    1 EUR = 0.8600 GBP" << endl;
                            cout << "Parduoti:  1 EUR = 0.9220 GBP" << endl;
                            break;

                        case 2:
                            cout << "\n --- USD ---" << endl;
                            cout << "Bendras:   1 EUR = 1.1793 USD" << endl;
                            cout << "Pirkti:    1 EUR = 1.1460 USD" << endl;
                            cout << "Parduoti:  1 EUR = 1.2340 USD" << endl;
                            break;

                        case 3:
                            cout << "\n --- INR ---" << endl;
                            cout << "Bendras:   1 EUR = 104.6918 INR" << endl;
                            cout << "Pirkti:    1 EUR = 101.3862 INR" << endl;
                            cout << "Parduoti:  1 EUR = 107.8546 INR" << endl;
                            break;

                        case 0: cout <<"\n Grįžtama" << endl;
                            break;

                        default:
                            cout << "\n Tokio pasirinkimo nera";
                    }

                }while (choice2 != 0);
            }
        }

    } while (choice != 0);


    return 0;
}