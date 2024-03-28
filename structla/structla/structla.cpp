#include <iostream>
#include <windows.h>
#include <string>
using namespace std;




void menu() {
    cout << "0.Cixish" << endl;
    cout << "1.Telefonlar" << endl;
    cout << "2.Ishciler" << endl;
    cout << "3.Axtarish" << endl;
}



void stockPhone(const string* phone, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << phone[i] << endl;
    }
}


void phone_det(const string* phone, const string* color, const int* memory, const int* price, int index) {
    cout << "Telefon: " << phone[index] << endl;
    cout << "Reng: " << color[index] << endl;
    cout << "Daxili yaddas: " << memory[index] << " GB" << endl;
    cout << "Qiymet: " << price[index] << " AZN" << endl;

}


void worker_det(const string* workerN, const string* workerS, const int* age, const int* salary, int index) {
    cout << "Ad: " << workerN[index] << endl;
    cout << "Soyad: " << workerS[index] << endl;
    cout << "Yash: " << age[index] << endl;
    cout << "Maash: " << salary[index] << " AZN" << endl;

}

void worker_all(const string* workerN, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << workerN[i] << endl;
    }
}



int main() {

    string* phone = new string[10]{ "iPhone 14","Samsung Galaxy S23","Xiaomi Redmi 12","Honor 90" };
    string* workerN = new string[10]{ "Ali","Samir","Vasif","Asif" };
    string* workerS = new string[10]{ "Memmedov","Eskerov","Azizov","Azizli" };
    string* color = new string[10]{ "Ag","Qara","Ag","Qara" };

    int* price = new int[10] { 1720, 2700, 380, 1200 };
    int* memory = new int[10] { 128, 256, 128, 512 };
    int* salary = new int[10] { 500, 650, 850, 1100 };
    int* age = new int[10] { 24, 27, 28, 30 };
    int index_phone = 4;
    int index_worker = 4;


    int choice = -1;
    while (choice != 0) {
        menu();
        cout << endl << "Secim edin: ";
        cin >> choice;

        if (choice == 1) {
            while (true) {
                Sleep(800);
                system("cls");
                cout << "0. Esas menu" << endl;
                stockPhone(phone, index_phone);
                cout << index_phone + 1 << ". Telefon elave et" << endl;
                cout << "Telefon haqqinda melumat almaq ucun muvafiq sira nomresini daxil edin: ";

                int phonechoice;
                cin >> phonechoice;
                Sleep(800);
                system("cls");

                if (phonechoice > 0 && phonechoice <= index_phone) {
                    phone_det(phone, color, memory, price, phonechoice - 1);
                    cout << "0. Esas menu" << endl;
                    cout << "1. Telefonu sil" << endl;

                    int option;
                    cout << "Secim edin: ";
                    cin >> option;
                    if (option == 1) {
                        for (int i = phonechoice - 1; i < index_phone - 1; i++) {
                            phone[i] = phone[i + 1];
                            color[i] = color[i + 1];
                            memory[i] = memory[i + 1];
                            price[i] = price[i + 1];
                        }
                        index_phone--;
                        cout << "Telefon silindi" << endl;
                        Sleep(500);
                        system("cls");

                        // break; // silme
                    }
                    else if (option == 0) {
                        Sleep(500);
                        system("cls");

                        break;
                    }
                }
                else if (phonechoice == 0) {
                    break;
                }
                else if (phonechoice == index_phone + 1) {
                    Sleep(200);
                    system("cls");
                    string newPh;
                    string newColor;
                    int newPrice;
                    int newMemory;
                    cout << "Yeni telefonun adini daxil edin: ";
                    cin.ignore();
                    getline(cin, newPh);
                    cout << "Rengini daxil edin: ";
                    getline(cin, newColor);
                    cout << "Daxili yaddasini daxil edin: ";
                    cin >> newMemory;
                    cout << "Qiymetini daxil edin: ";
                    cin >> newPrice;

                    phone[index_phone] = newPh;
                    color[index_phone] = newColor;
                    memory[index_phone] = newMemory;
                    price[index_phone] = newPrice;
                    index_phone++;
                    cout << "Telefon elave olundu" << endl;
                    Sleep(500);
                    system("cls");
                    break;
                }
            }
        }

        else if (choice == 2) {
            while (true) {
                Sleep(500);
                system("cls");
                cout << "0. Esas menu" << endl;
                worker_all(workerN, index_worker);
                cout << index_worker + 1 << ". " << "Ishci elave et" << endl;

                cout << "Ishci haqqinda melumat almaq ucun muvafiq sira nomresini daxil edin: ";
                int workerchoice;
                cin >> workerchoice;
                Sleep(500);
                system("cls");

                if (workerchoice > 0 && workerchoice <= index_worker) {
                    worker_det(workerN, workerS, age, salary, workerchoice - 1);
                    cout << "0. Esas menu" << endl;
                    cout << "1. Ishcini sil" << endl;

                    int option2;
                    cout << "Secim edin: ";
                    cin >> option2;
                    if (option2 == 1) {
                        for (int i = workerchoice - 1; i < index_worker - 1; i++) {
                            workerN[i] = workerN[i + 1];
                            workerS[i] = workerS[i + 1];
                            age[i] = age[i + 1];
                            salary[i] = salary[i + 1];
                        }
                        index_worker--;
                        cout << "Ishci silindi" << endl;
                        Sleep(500);
                        system("cls");
                        break;
                    }
                    else if (option2 == 0) {
                        Sleep(500);
                        system("cls");
                        break;
                    }
                }
                else if (workerchoice == 0) {
                    break;
                }
                else if (workerchoice == index_worker + 1) {
                    Sleep(500);
                    system("cls");

                    string newNm;
                    string newSr;
                    int newSalary;
                    int newAge;
                    cout << "Ishchinin adini daxil edin: ";
                    cin.ignore();
                    getline(cin, newNm);
                    cout << "Soyadini daxil edin: ";
                    getline(cin, newSr);
                    cout << "Yashini daxil edin: ";
                    cin >> newAge;
                    cout << "Maashini daxil edin: ";
                    cin >> newSalary;

                    workerN[index_worker] = newNm;
                    workerS[index_worker] = newSr;
                    age[index_worker] = newAge;
                    salary[index_worker] = newSalary;
                    index_worker++;
                    cout << "Ishci elave olundu" << endl;
                    Sleep(1500);
                    system("cls");
                    break;
                }
            }
        }

        else if (choice == 3) {
            int inchoice;
            Sleep(500);
            system("cls");
            cout << "Axtarish etmek istediyiniz bolmeni secin:" << endl;
            cout << "1.Telefonlar" << endl;
            cout << "2.Ishciler" << endl;

            cin >> inchoice;

            if (inchoice == 1) {
                Sleep(500);
                system("cls");

                cout << "Axtarmaq istediyiniz telefon adini daxil edin: ";
                string phonename;
                cin.ignore();
                getline(cin, phonename);

                bool found = false;
                for (size_t i = 0; i < index_phone; i++) {
                    if (phone[i] == phonename) {
                        found = true;
                        cout << "Reng: " << color[i] << endl;
                        cout << "Daxili yaddas: " << memory[i] << " GB" << endl;
                        cout << "Qiymet: " << price[i] << " AZN" << endl;
                        break;
                    }
                }

                if (!found) cout << "Axtaris uzre melumat tapilmadi" << endl;

                cout << "0. Esas menu" << endl;
                int option3;
                cin >> option3;
                if (option3 == 0) {
                    Sleep(500);
                    system("cls");
                }
            }

            else if (inchoice == 2) {
                Sleep(500);
                system("cls");

                string workername;
                cout << "Axtarmaq istediyiniz ishci adini daxil edin: ";
                cin.ignore();
                getline(cin, workername);
                bool found2 = false;
                for (size_t i = 0; i < index_worker; i++) {
                    if (workerN[i] == workername) {
                        found2 = true;
                        cout << "Soyad: " << workerS[i] << endl;
                        cout << "Yash: " << age[i] << endl;
                        cout << "Maash: " << salary[i] << " AZN" << endl;
                        break;
                    }
                }
                if (!found2) cout << "Axtaris uzre melumat tapilmadi" << endl;

                cout << "0. Esas menu" << endl;
                int option4;
                cin >> option4;
                if (option4 == 0) {
                    Sleep(500);
                    system("cls");
                }
            }
        }

        else if (choice != 0) {
            cout << "Duzgun secim edin" << endl;
            Sleep(500);
            system("cls");
        }
    }

    return 0;
}






