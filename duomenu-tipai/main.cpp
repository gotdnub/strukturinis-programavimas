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
    // const int studentGradesNum = 5;
    // int grade;
    // int sum = 0;
    // int highestGrade = 0;
    //
    // for (int i = 1; i<= studentGradesNum; i++) {
    //     cout << "Iveskite "<<i<<" studento pazymi."<<endl;
    //     cin >> grade;
    //     sum += grade;
    //
    //     highestGrade = (grade > highestGrade) ? grade : highestGrade;
    // }
    //
    // double averageGrade = static_cast<double>(sum) / studentGradesNum;
    // cout <<fixed << setprecision(2) <<"Pazymiu vidurkis " << averageGrade << endl;
    // cout << "Didziausias pazymys "<< highestGrade << endl;

    //Uzduotys 1, 2, 3, 4

    // int grade1;
    // int grade2;
    // int grade3;
    // int grade4;
    // int grade5;
    // int suma = 0;
    //
    // cout << "Iveskite pirma pazymi" <<endl;
    // cin >> grade1;
    // cout << "Iveskite antra pazymi" <<endl;
    // cin >> grade2;
    // cout << "Iveskite trecia pazymi" <<endl;
    // cin >> grade3;
    // cout << "Iveskite ketvirta pazymi" <<endl;
    // cin >> grade4;
    // cout << "Iveskite penkta pazymi" <<endl;
    // cin >> grade5;
    //
    // double vidurkis = static_cast<double>(grade1 + grade2 + grade3 + grade4 + grade5) / 5;
    // cout << "Vidurkis yra " << vidurkis << endl;
    // if (vidurkis > 5) {
    //     cout << "Vidurkis teigiamas. " << endl;
    // } else {
    //     cout << "Vidurkis yra neigiamas. " << endl;
    // }
    //
    // int egzaminoGrade;
    // cout << "Iveskite egzamino ivertinima. " << endl;
    // cin >> egzaminoGrade;

    //Per if else (3 uzd)

    // if (egzaminoGrade == 10) {
    //     cout << "Egzaminas islaikytas puikiai!" << endl;
    // } else if (egzaminoGrade >= 9) {
    //     cout << "Egzaminas islaikytas labai gerai!" << endl;
    // } else if (egzaminoGrade >= 7) {
    //     cout << "Egzaminas islaikytas gerai!" << endl;
    // } else if (egzaminoGrade >= 5) {
    //     cout << "Egzaminas islaikytas patenkinamai" << endl;
    // } else if (egzaminoGrade < 5) {
    //     cout << "Egzaminas neislaikytas" << endl;
    // }

    //Per switch (4uzd)

    // switch (egzaminoGrade) {
    //     case 10:
    //         cout << "Egzaminas islaikytas puikiai!" << endl;
    //         break;
    //     case 9:
    //         cout << "Egzaminas islaikytas labai gerai!" << endl;
    //         break;
    //     case 8:
    //     case 7:
    //         cout << "Egzaminas islaikytas gerai!" << endl;
    //         break;
    //     case 6:
    //     case 5:
    //         cout << "Egzaminas islaikytas patenkinamai" << endl;
    //         break;
    //     default:
    //         cout << "Egzaminas neislaikytas" << endl;
    //
    // }



    // 5 uzduotis

    

    return 0;
}