#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
   // int number;
   // cout <<"iveskite teigiama skaiciu"<<endl;
   // cin >>number;
   // while (number <= 0) {
   //     cout << "Klaida, skaicius nera teigiamas"<< endl;
   //     cout <<"iveskite teigiama skaiciu"<< endl;
   //     cin >>number;
   // }
   // cout <<"Ivestas sakicius yra: " <<number<< endl;



    // double savings = 100.0;
    // const double target = 500.0;
    // const double monthlyDeposit = 75.0;
    // int month = 0;
    //
    // while (savings < target) {
    //     month++;
    //     savings += monthlyDeposit;
    //     cout << month << " menuo "
    //         <<fixed << setprecision(2)
    //         <<savings <<" EUR"<<endl;
    // }
    //
    // cout <<"Tikslas yra pasiektas per "<<month<<" menesius"<<endl;



    // string password;
    //
    // do {
    //     cout <<"Sukurkite slaptazodi bent 8 simboliu ilgumo"<<endl;
    //     cin >> password;
    //
    //     if (password.length() < 8) {
    //         cout << "Slaptazodis turi buti maziausiai 8 simboliu. "<<endl;
    //     }
    // } while (password.length() < 8);
    //
    // cout << "Slaptazodis yra priimtas"<<endl;



    // int balance = 100;
    // int choice;
    //
    // do {
    //     cout<<"\n--- SASKAITOS MENIU ---\n";
    //     cout<<"1. Perziureti balansa \n";
    //     cout<<"2. Papildyti balansa \n";
    //     cout<<"3. Atlikti mokejima \n";
    //     cout<<"0. Baigti programa \n";
    //     cout<<"Iveskite pasirinkima \n";
    //     cin >> choice;
    //
    //     switch (choice) {
    //         case 1:
    //             cout << "Balansas: "<<balance<<" Eur\n";
    //             break;
    //         case 2: {
    //             int amount;
    //             cout <<"Papildymo suma: ";
    //             cin >> amount;
    //
    //             if (amount > 0) {
    //                 balance += amount;
    //                 cout <<"Balansas papildytas. \n";
    //             } else {
    //                 cout <<"Neteisinga suma. Ivedama suma turi buti teigiama. \n";
    //             }
    //         break;
    //         }
    //         case 3: {
    //             int amount;
    //             cout << "Mokejimo suma";
    //             cin >> amount;
    //
    //             if (amount <= 0 ) {
    //                 cout <<"Neteisinga suma. \n";
    //             } else if (amount > balance) {
    //                 cout <<"Nepakankamas likutis balanse. /n";
    //             } else {
    //                 balance -= amount;
    //                 cout <<"Mokejimas atlikta \n";
    //             }
    //             break;
    //         }
    //         case 0:
    //             cout <<"Programa baigta. \n";
    //             break;
    //         default:
    //             cout << "Tokio pasirinkimo nera";
    //     }
    // } while (choice != 0);



    // Studento pazymiu statistika
    const int studentGradesNum = 5;
    int grade;
    int sum = 0;
    int highestGrade = 0;

    for (int i = 1; i<= studentGradesNum; i++) {
        cout << "Iveskite "<<i<<" studento pazymi."<<endl;
        cin >> grade;
        sum += grade;

        highestGrade = (grade > highestGrade) ? grade : highestGrade;
    }

    double averageGrade = static_cast<double>(sum) / studentGradesNum;
    cout <<fixed << setprecision(2) <<"Pazymiu vidurkis" << averageGrade << endl;
    cout << "Didziausias pazymys "<< highestGrade << endl;


    return 0;
}