#include "Checks.h"

void createFiles() {
    ifstream check;
    ofstream of;
    check.open("admins.txt");
    if (!check.is_open()) {
        of.open("admins.txt");
        of << "0" << endl;
        of.close();
    }
    check.close();
    check.open("users.txt");
    if (!check.is_open()) {
        of.open("users.txt");
        of << "0" << endl;
        of.close();
    }
    check.close();
    check.open("rooms.txt");
    if (!check.is_open()) {
        of.open("rooms.txt");
        of << "0" << endl;
        of.close();
    }
    check.close();
}

void fillSize(int& nAdmin, int& nUsers, int& nRooms) {
    ifstream check;
    check.open("admins.txt");
    check.seekg(-3, ios::end);
    check >> nAdmin;
    check.close();
    check.open("users.txt");
    check.seekg(-3, ios::end);
    check >> nUsers;
    check.close();
    check.open("rooms.txt");
    check.seekg(-3, ios::end);
    check >> nRooms;
    check.close();
}

int fillClasses(Admin*& admins, User*& users, Room*& rooms, int& nAdmin, int& nUsers, int& nRooms, int& roots) {
    ifstream fin;
    fin.open("admins.txt");
    Admin admin;
    if (fin.peek() != EOF) {
        for (int i = 0; i < nAdmin; i++) {
            fin >> admin;
            admins[i] = admin;
        }
    }
    fin.close();
    fin.open("users.txt");
    User user;
    if (fin.peek() != EOF) {
        for (int i = 0; i < nUsers; i++) {
            fin >> user;
            users[i] = user;
            roots = max(roots, users[i].getRoot());
        }
    }
    fin.close();
    fin.open("rooms.txt");
    Room room;
    if (fin.peek() != EOF) {
        for (int i = 0; i < nRooms; i++) {
            fin >> room;
            rooms[i] = room;
        }
    }
    fin.close();
    return roots;
}

void fillFiles(Admin*& admins, User*& users, Room*& rooms, int& nAdmin, int& nUsers, int& nRooms) {
    ofstream fout;
    fout.open("admins.txt");
    for (int i = 0; i < nAdmin; i++) {
        fout << admins[i];
    }
    fout << nAdmin << endl;
    fout.close();
    fout.open("users.txt");
    for (int i = 0; i < nUsers; i++) {
        fout << users[i];
    }
    fout << nUsers << endl;
    fout.close();
    fout.open("rooms.txt");
    for (int i = 0; i < nRooms; i++) {
        fout << rooms[i];
    }
    fout << nRooms << endl;
    fout.close();
}

void setColor(int text, int background) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

string writeNames() {
    string word;
    int Knopka;
    char symbol;
    while (true) {
        Knopka = _getch();
        if (Knopka == 8) {
            if (word.length() != 0) {
                cout << '\b' << " " << '\b';
                word.erase(word.length() - 1);
            }
        }
        else
            if (Knopka == 13 && word.length() != 0) break;
            else {
                symbol = (char)Knopka;
                if ((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я')) {
                    word = word + symbol;
                    cout << symbol;
                }
            }
    }
    cout << endl;
    return word;
}

string writePhoneNumber() {
    string str;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }else
            if (key == 8) {
                if (str.length() != 0) {
                    cout << '\b' << " " << '\b';
                    str.erase(str.length() - 1);
                    if (str.length() == 1) cout << '\b' << " " << '\b';
                }
            }else
            if (key == 13 && str.length() == 9) break;
            else
                if (key >= '0' && key <= '9' && str.length() < 9) {
                    str = str + (char)key;
                    cout << (char)key;
                    if (str.length() == 2) cout << ")";
                }
    }
    return str;
}

string writeCard() {
    string str;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }
        else
            if (key == 8) {
                if (str.length() != 0) {
                    cout << '\b' << " " << '\b';
                    str.erase(str.length() - 1);
                }
            }
            else
                if (key == 13 && str.length() == 16) break;
                else
                    if (key >= '0' && key <= '9' && str.length() < 16) {
                        str = str + (char)key;
                        cout << (char)key;
                    }
    }
    return str;
}

int getGender() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Мужской" << endl; setColor(15, 0); }
        else cout << " Мужской" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Женский" << endl; setColor(15, 0); }
        else cout << " Женский" << endl;

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) { system("cls"); return choose_menu; }
        system("cls");
    }
}

void changeSizeUsers(User*& users, int& nUsers) {
    nUsers++;
    User* ptr = new User[nUsers];
    for (int i = 0; i < nUsers - 1; i++)
        ptr[i] = users[i];
    users = ptr;
    ptr = NULL;
    delete[]ptr;
}

void changeSizeAdmins(Admin*& admins, int& nAdmin) {
    nAdmin++;
    Admin* ptr = new Admin[nAdmin];
    for (int i = 0; i < nAdmin - 1; i++)
        ptr[i] = admins[i];
    admins = ptr;
    ptr = NULL;
    delete[]ptr;
}

void changeSizeRooms(Room*& rooms, int& nRooms) {
    nRooms++;
    Room* ptr = new Room[nRooms];
    for (int i = 0; i < nRooms - 1; i++)
        ptr[i] = rooms[i];
    rooms = ptr;
    ptr = NULL;
    delete[]ptr;
}

string writePassword() {
    string str;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }
        else
            if (key == 8) {
                if (str.length() != 0) {
                    cout << '\b' << " " << '\b';
                    str.erase(str.length() - 1);
                }
            }
            else
                if (key == 13 && str.length() != 0) break;
                else
                    if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')) {
                        str = str + (char)key;
                        cout << "*";
                    }
    }
    return str;
}

string writeRoomAndFloor(int a, char c) {
    string str;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }
        else
            if (key == 8) {
                if (str.length() != 0) {
                    cout << '\b' << " " << '\b';
                    str.erase(str.length() - 1);
                }
            }
            else
                if (key == 13 && str.length() <= a && str.length() != 0) break;
                else
                    if (key >= '1' && key <= c && str.length() < a) {
                        str = str + (char)key;
                        cout << (char)key;
                    }
    }
    return str;
}

string writeRoom(int a) {
    string str;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }
        else
            if (key == 8) {
                if (str.length() != 0) {
                    cout << '\b' << " " << '\b';
                    str.erase(str.length() - 1);
                }
            }
            else
                if (key == 13 && str.length() <= a && str.length() != 0) break;
                else
                    if (key >= '0' && key <= '9' && str.length() < a) {
                        str = str + (char)key;
                        cout << (char)key;
                    }
    }
    return str;
}