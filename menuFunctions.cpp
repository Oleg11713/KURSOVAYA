#include "MenuFunctions.h"
#include "Checks.h"
#include "CursOOP.h"
#include "AllFuncMenu.h"

int openAdminMenu(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots, Room*& rooms, int& nRooms) {
    while (true) {
        int choose = showAdminMenu();
        if (choose == 0) {
            int check = openMenuAdministration(admins, users, nAdmin, nUsers, roots);
            if (check == 4) return 4;
        }else
            if (choose == 1) {
               int check = openMenuRedHotels(rooms, nRooms, users, nUsers);
               if (check == 4) return 4;
            }else
                if (choose == 2) {
                    int check = openProcMenu(rooms, nRooms, users, nUsers);
                    if (check == 4) return 4;
                }else
                    if (choose == 3) {
                        return 3;
                    }
                    else
                        if (choose == 4) {
                            return 4;
                        }
    }
}

int openUserMenu(Admin*& admins, User*& users, int& nAdmin, int& nUsers, Room*& rooms, int& nRooms, int choose) {
    while (true) {
        if (users[choose].getFilling() == 0) {
            int choose1 = chooseExitOfFill();
            if (choose1 == 1) return 3;
            else {
                redUser(admins, users, nUsers, nAdmin, choose, 1);
                users[choose].checkFilling();
            }
        }
        else {
            while (true) {
                int choose1 = chooseUserMenu();
                if (choose1 == 0) {
                    changeSizeRooms(rooms, nRooms);
                    rooms[nRooms - 1].setDate();
                    string s = chooseTypeRoom();
                    rooms[nRooms - 1].changeType(s);
                    system("cls");
                    cout << "Введите этаж: ";
                    s = writeRoomAndFloor(1, '9');
                    rooms[nRooms - 1].changeFloor(s);
                    int num = 0;
                    for (int i = 0; i < nRooms - 1; i++) {
                        if (s == rooms[i].getFloor()) {
                            num = max(num, stoi(rooms[i].getNumber()));
                        }
                    }
                    string s1;
                    if (num == 0) s1 = s + "00";
                    else {
                        num++;
                        s1 = to_string(num);
                    }
                    rooms[nRooms - 1].changeNumber(s1);
                    system("cls");
                    cout << "Введите кол-во мест в комнате: ";
                    s = writeRoomAndFloor(1, '5');
                    rooms[nRooms - 1].changeVolume(s);
                    system("cls");
                    cout << "Введите кол-во комнат: ";
                    s = writeRoomAndFloor(1, '2');
                    rooms[nRooms - 1].changeNumberOfRooms(s);
                    system("cls");
                    s = chooseTypeFood();
                    rooms[nRooms - 1].changeTypeOfFood(s);
                    rooms[nRooms - 1].changeRoot(users[choose].getRoot());
                    rooms[nRooms - 1].setPrice();
                    int choice = choicYesOrNot(stoi(rooms[nRooms - 1].getCoast()));
                    if (choice == 1) {
                        nRooms--;
                    }
                }
                else
                    if (choose1 == 1) {
                        for (int i = 0; i < nRooms; i++)
                            if (users[choose].getRoot() == rooms[i].getRoot()) {
                                showOneRoom(rooms, i);
                            }
                        system("pause");
                        system("cls");
                    }
                    else
                        if (choose1 == 2) {
                            cout << "Введите номер бронирования который вы хотите отменить: №";
                            string num = writeRoom(3);
                            system("cls");
                            int check = 0;
                            for (int i = 0; i < nRooms; i++)
                                if (users[choose].getRoot() == rooms[i].getRoot() && rooms[i].getNumber() == num) {
                                    int choice = choicYesOrNot(-123);
                                    if (choice == 0) {
                                        for (int j = i; j < nRooms - 1; j++)
                                            rooms[j] = rooms[j + 1];
                                        nRooms--;
                                        check = 1;
                                        break;
                                    }
                                    check = 3;
                                    break;
                                }
                            if (check == 0) cout << "Вы ввели неверный номер" << endl;
                            else
                                if (check == 1) cout << "Бронирование отменено" << endl;
                            system("pause");
                            system("cls");
                        }
                        else
                            if (choose1 == 3) {
                                users[choose].showIfromation();
                                system("pause");
                                system("cls");
                            }
                            else
                                if (choose1 == 4) {
                                    redUser(admins, users, nUsers, nAdmin, choose, 1);
                                }
                                else
                                    if (choose1 == 5) return 3;
                                    else
                                        if (choose1 == 6) return 4;
            }
        }
    }
    return 0;
}

int openMenuAdministration(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
    while (true) {
        int choose = showMenuAdministration();
        if (choose == 0) {
            showUsers(admins, users, nAdmin, nUsers);
        }else
            if (choose == 1) {
                changeMenuUsers(admins, users, nAdmin, nUsers, roots);
            }else
                if (choose == 2) {
                    addOneUser(admins, users, nAdmin, nUsers, roots);
                }else
                    if (choose == 3) {
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
                    }else
                        if (choose == 4) {
                            return 0;
                        }else
                            if (choose == 5) {
                                return 4;
                            }
    }
}

void changeMenuUsers(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
    while (true) {
        int choose = chooseAdminsOrUsers();
        if (choose == 0) {
            openMenuRedAdmin(admins, users, nAdmin, nUsers, roots);
        }else
            if (choose == 1) {
                openMenuRedUsers(admins, users, nAdmin, nUsers);
            }
            else
                if (choose == 2) break;
    }
}

void showUsers(Admin*& admins, User*& users, int& nAdmin, int& nUsers) {
    if (nAdmin != 0) {
        cout << "       Админиcтраторы: " << endl;
        for (int i = 0; i < nAdmin; i++) {
            admins[i].showIfromation();
            cout << endl;
        }
    }
    if (nUsers != 0) {
        cout << "       Пользователи: " << endl;
        for (int i = 0; i < nUsers; i++) {
            users[i].showIfromation();
            cout << endl;
        }
    }
    system("pause");
    system("cls");
}

void openMenuRedAdmin(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
    while (true) {
        int choose = chooseAdmin(admins, nAdmin);
        if (choose == nAdmin) break;
        else {
            while (true) {
                int choose1 = chooseWhatRedAdmin(admins, choose);
                if (choose1 == 3) break;
                else
                    if (choose1 == 0) {
                        writeLogin(admins, users, nAdmin, nUsers, choose, 1);
                    }else
                        if (choose1 == 1) {
                            admins[choose].writePass();
                        }else
                            if (choose1 == 2) {
                                int choose2 = chooseRoot();
                                if (choose2 == 1) {
                                    int prov = chooseYesOrNot();
                                    if (prov == 0) {
                                        User user(admins[choose].getLogin(), admins[choose].getPass());
                                        changeSizeUsers(users, nUsers);
                                        users[nUsers - 1] = user;
                                        users[nUsers - 1].changeRoot(roots);
                                        users++;
                                        for (int i = choose; i < nAdmin - 1; i++) {
                                            admins[i] = admins[i + 1];
                                        }
                                        nAdmin--;
                                        break;
                                    }
                                }
                            }
            }
        }
    }
}

void openMenuRedUsers(Admin*& admins, User*& users, int& nAdmin, int& nUsers) {
    while (true) {
        int choose = chooseUser(users, nUsers);
        if (choose == nUsers) break;
        else {
            redUser(admins, users, nUsers, nAdmin, choose, 0);
        }
    }
}

void addOneUser(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int& roots) {
    while (true) {
        int choose = chooseWhoAdd();
        if (choose == 2) break;
        Admin admin;
        User user;
        if (choose == 0) {
            changeSizeAdmins(admins, nAdmin);
            admins[nAdmin - 1] = admin;
            writeLogin(admins, users, nAdmin, nUsers, nAdmin - 1, 1);
            admins[nAdmin - 1].writePass();
        }else
            if (choose == 1) {
                changeSizeUsers(users, nUsers);
                users[nUsers - 1] = user;
                writeLogin(admins, users, nAdmin, nUsers, nUsers - 1, 0);
                users[nUsers - 1].writePass();
                users[nUsers - 1].changeRoot(roots);
                roots++;
            }
    }
}

int openMenuRedHotels(Room*& rooms, int& nRooms, User*& users, int& nUsers) {
    while (true) {
        int choose = chooseRedHotelsMenu();
        if (choose == 4) return 4;
        if (choose == 3) break;
        if (choose == 0) {
            openMenuRedRooms(rooms, nRooms, users, nUsers);
        }else
            if (choose == 1) {
                addOneRooms(rooms, nRooms, users, nUsers);
            }else
                if (choose == 2) {
                    showAllRooms(rooms, nRooms, users, nUsers);
                }
    }
    return 0;
}

void openMenuRedRooms(Room*& rooms, int& nRooms, User*& users, int& nUsers) {
    while (true) {
        int choose = chooseWhatRed(rooms, nRooms, users, nUsers);
        if (choose == nRooms) break;
        while (true) {
            int choose1 = chooseRedRooms(rooms, choose);
            if (choose1 == 1) {
                string s = chooseTypeRoom();
                rooms[choose].changeType(s);
            }else
                    if (choose1 == 2) {
                        cout << "Введите этаж: ";
                        string s = writeRoomAndFloor(2, '9');
                        rooms[choose].changeFloor(s);
                        system("cls");
                        int num = 0;
                        for (int i = 0; i < nRooms; i++) {
                            if (s == rooms[i].getFloor() && i != choose) {
                                num = max(num, stoi(rooms[i].getNumber()));
                            }
                        }
                        string s1;
                        if (num == 0) s1 = s1 + "00";
                        else s1 = to_string(num++);
                        rooms[choose].changeNumber(s1);
                    }else
                        if (choose1 == 3) {
                            cout << "Введите кол-во мест в номере: ";
                            string s = writeRoomAndFloor(1, '5');
                            rooms[choose].changeVolume(s);
                            system("cls");
                        }else
                            if (choose1 == 4) {
                                cout << "Введите кол-во комнат в номере: ";
                                string s = writeRoomAndFloor(1, '2');
                                rooms[choose].changeNumberOfRooms(s);
                                system("cls");
                            }else
                                if (choose1 == 5) {
                                    string s = chooseTypeFood();
                                    rooms[choose].changeTypeOfFood(s);
                                }
                                else
                                    if (choose1 == 0) {
                                        rooms[choose].setDate();
                                    }
                                    else break;
        }
        rooms[choose].setPrice();
    }
}

void showAllRooms(Room*& rooms, int& nRooms, User*& users, int& nUsers) {
    for (int i = 0; i < nRooms; i++) {
        int ij = 0;
        for (int j = 0; j < nUsers; j++)
            if (users[j].getRoot() == rooms[i].getRoot()) { ij = j; break; }
        cout << "   Комната №" << rooms[i].getNumber() << endl;
        cout << " Заказал: " << users[ij].getName() << " " << users[ij].getS_Name() << endl;
        cout << " Даты: " << rooms[i].getDateArrival() << " - " << rooms[i].getDateLeaving() << endl;
        cout << " Тип комнаты: " << rooms[i].getType() << endl;
        cout << " Этаж: " << rooms[i].getFloor() << endl;
        cout << " Вместимость человек: " << rooms[i].getVolume() << endl;
        cout << " Кол-во комнат в номере: " << rooms[i].getNumberOfRooms() << endl;
        cout << " Тип питания: " << rooms[i].getTypeOfFood() << endl;
        cout << " Цена: " << rooms[i].getCoast() << endl;
        cout << endl;
        cout << endl;
    }
    if (nRooms == 0) cout << "Номера в отеле еще никто не бронировал." << endl;
    system("pause");
    system("cls");
}

void addOneRooms(Room*& rooms, int& nRooms, User*& users, int& nUsers) {
    while (true) {
        int choose = chooseUser(users, nUsers);
        if (choose == nUsers) break;
        changeSizeRooms(rooms, nRooms);
        rooms[nRooms - 1].setDate();
        string s = chooseTypeRoom();
        rooms[nRooms - 1].changeType(s);
        system("cls");
        cout << "Введите этаж: ";
        s = writeRoomAndFloor(1, '9');
        rooms[nRooms - 1].changeFloor(s);
        int num = 0;
        for (int i = 0; i < nRooms - 1; i++) {
            if (s == rooms[i].getFloor()) {
                num = max(num, stoi(rooms[i].getNumber()));
            }
        }
        string s1;
        if (num == 0) s1 = s + "00";
        else {
            num++;
            s1 = to_string(num);
        }
        rooms[nRooms - 1].changeNumber(s1);
        system("cls");
        cout << "Введите кол-во мест в комнате: ";
        s = writeRoomAndFloor(1, '5');
        rooms[nRooms - 1].changeVolume(s);
        system("cls");
        cout << "Введите кол-во комнат: ";
        s = writeRoomAndFloor(1, '2');
        rooms[nRooms - 1].changeNumberOfRooms(s);
        system("cls");
        s = chooseTypeFood();
        rooms[nRooms - 1].changeTypeOfFood(s);
        rooms[nRooms - 1].changeRoot(users[choose].getRoot());
        rooms[nRooms - 1].setPrice();
        int choice = choicYesOrNot(stoi(rooms[nRooms - 1].getCoast()));
        if (choice == 1) {
            nRooms--;
        }
    }
}

int openProcMenu(Room*& rooms, int& nRooms, User*& users, int& nUsers) {
    while (true) {
        int choose = chooseProcMenu();
        if (choose == 3) break;
        if (choose == 4) return 4;
        if (choose == 0) {
            showAllRooms(rooms, nRooms, users, nUsers);
        }else
            if (choose == 1) {
                cout << "Введите логин пользователя: ";
                string log = writeWords();
                cout << endl;
                int check = 0;
                for(int i = 0; i < nUsers; i++)
                    if (users[i].getLogin() == log) {
                        check = 1;
                        for (int j = 0; j < nRooms; j++)
                            if (users[i].getRoot() == rooms[j].getRoot()) {
                                showOneRoom(rooms, j);
                                check = 2;
                            }
                        break;
                    }
                if (check == 0) cout << "Такого пользователя не существует." << endl;
                else
                    if (check == 1) cout << "Данный пользователь еще не забронировал номер." << endl;
                system("pause");
                system("cls");
            }else
                if (choose == 2) {
                    openMenuSort(rooms, nRooms, users, nUsers);
                }
    }
    return 0;
}

void showOneRoom(Room*& rooms, int choose) {
    cout << "   Комната №" << rooms[choose].getNumber() << endl;
    cout << " Тип комнаты: " << rooms[choose].getType() << endl;
    cout << " Этаж: " << rooms[choose].getFloor() << endl;
    cout << " Вместимость человек: " << rooms[choose].getVolume() << endl;
    cout << " Кол-во комнат в номере: " << rooms[choose].getNumberOfRooms() << endl;
    cout << " Тип питания: " << rooms[choose].getTypeOfFood() << endl;
    cout << " Цена: " << rooms[choose].getCoast() << endl;
    cout << endl;
    cout << endl;
}

void openMenuSort(Room*& rooms, int& nRooms, User*& users, int& nUsers) {
    while (true) {
        int choose = chooseSort();
        if (choose == 0) {
            int choose1 = chooseHowSort();
            if (choose1 == 0) {
                for (int i = 0; i < nRooms; i++)
                    for(int j = 0; j < nRooms - 1; j++)
                        if (stoi(rooms[j].getNumber()) > stoi(rooms[j + 1].getNumber())) {
                            Room a;
                            a = rooms[j];
                            rooms[j] = rooms[j + 1];
                            rooms[j + 1] = a;
                        }
            }
            else 
                if (choose1 == 1){
                    for (int i = 0; i < nRooms; i++)
                        for (int j = 0; j < nRooms - 1; j++)
                            if (stoi(rooms[j].getNumber()) < stoi(rooms[j + 1].getNumber())) {
                                Room a;
                                a = rooms[j];
                                rooms[j] = rooms[j + 1];
                                rooms[j + 1] = a;
                            }
                }
        }else
            if (choose == 1) {
                int choose1 = chooseHowSort();
                if (choose1 == 0) {
                    for (int i = 0; i < nRooms; i++)
                        for (int j = 0; j < nRooms - 1; j++)
                            if (stoi(rooms[j].getCoast()) > stoi(rooms[j + 1].getCoast())) {
                                Room a;
                                a = rooms[j];
                                rooms[j] = rooms[j + 1];
                                rooms[j + 1] = a;
                            }
                }
                else
                    if (choose1 == 1) {
                        for (int i = 0; i < nRooms; i++)
                            for (int j = 0; j < nRooms - 1; j++)
                                if (stoi(rooms[j].getCoast()) < stoi(rooms[j + 1].getCoast())) {
                                    Room a;
                                    a = rooms[j];
                                    rooms[j] = rooms[j + 1];
                                    rooms[j + 1] = a;
                                }
                    }
            }
            else
                if (choose == 2) {
                    int choose1 = chooseHowSort();
                    if (choose1 == 0) {
                        for (int i = 0; i < nRooms; i++)
                            for (int j = 0; j < nRooms - 1; j++)
                                if (stoi(rooms[j].getVolume()) > stoi(rooms[j + 1].getVolume())) {
                                    Room a;
                                    a = rooms[j];
                                    rooms[j] = rooms[j + 1];
                                    rooms[j + 1] = a;
                                }
                    }
                    else
                        if (choose1 == 1) {
                            for (int i = 0; i < nRooms; i++)
                                for (int j = 0; j < nRooms - 1; j++)
                                    if (stoi(rooms[j].getVolume()) < stoi(rooms[j + 1].getVolume())) {
                                        Room a;
                                        a = rooms[j];
                                        rooms[j] = rooms[j + 1];
                                        rooms[j + 1] = a;
                                    }
                        }
                }
                else break;
    }
}

void redUser(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int choose, int a) {
    while (true) {
        int choose1 = chooseWhatRedUser(users, choose, a);
        if (choose1 == 9) break;
        if (choose1 == 0) {
            writeLogin(admins, users, nAdmin, nUsers, choose, 0);
        }
        else
            if (choose1 == 1) {
                users[choose].writePass();
            }
            else
                if (choose1 == 2) {
                    int choose2 = chooseRoot();
                    if (choose2 == 0) {
                        int prov = chooseYesOrNot();
                        if (prov == 0) {
                            Admin admin(users[choose].getLogin(), users[choose].getPass());
                            changeSizeAdmins(admins, nAdmin);
                            admins[nAdmin - 1] = admin;
                            for (int i = choose; i < nUsers - 1; i++) {
                                users[i] = users[i + 1];
                            }
                            nUsers--;
                            break;
                        }
                    }
                }
                else
                    if (choose1 == 3) {
                        string name;
                        cout << "Введите Имя: ";
                        name = writeNames();
                        system("cls");
                        users[choose].changeName(name);
                    }
                    else
                        if (choose1 == 4) {
                            string name;
                            cout << "Введите Фамилию: ";
                            name = writeNames();
                            system("cls");
                            users[choose].changeS_Name(name);
                        }
                        else
                            if (choose1 == 5) {
                                string name;
                                cout << "Введите Отчество: ";
                                name = writeNames();
                                system("cls");
                                users[choose].changeT_Name(name);
                            }
                            else
                                if (choose1 == 6) {
                                    string Phone;
                                    cout << "Введите телефон: +375(";
                                    Phone = writePhoneNumber();
                                    system("cls");
                                    users[choose].changePhoneNumber(Phone);
                                }
                                else
                                    if (choose1 == 7) {
                                        string Card;
                                        cout << "Введите номер карты: ";
                                        Card = writeCard();
                                        system("cls");
                                        users[choose].changeCard(Card);
                                    }
                                    else
                                        if (choose1 == 8) {
                                            int gender = getGender() + 1;
                                            users[choose].changeGander(gender);
                                        }
    }
}
