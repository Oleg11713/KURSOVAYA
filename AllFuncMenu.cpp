#include "AllFuncMenu.h"

int chooseMainMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 3) % 3;
        if (choose_menu == 0) { setColor(4, 0); cout << " -> ����� � �������" << endl; setColor(15, 0); }
        else cout << " ����� � �������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ������� ����� �������" << endl; setColor(15, 0); }
        else cout << " ������� ����� �������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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

int showAdminMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "������������ �������������!" << endl;
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ������ � �������� ��������" << endl; setColor(15, 0); }
        else cout << " ������ � �������� ��������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> �������������� ������ ������� �����" << endl; setColor(15, 0); }
        else cout << " �������������� ������ ������� �����" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> �������� � ����� ������ �����" << endl; setColor(15, 0); }
        else { cout << " �������� � ����� ������ �����" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ������� ����" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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

int showMenuAdministration() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 6) % 6;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �������� ������� �������" << endl; setColor(15, 0); }
        else cout << " �������� ������� �������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> �������������� ������� �������" << endl; setColor(15, 0); }
        else cout << " �������������� ������� �������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ���������� ������� ������" << endl; setColor(15, 0); }
        else { cout << " ���������� ������� ������" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ��������� ����������" << endl; setColor(15, 0); }
        else { cout << " ��������� ����������" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> ����� � ���� ��������������" << endl; setColor(15, 0); }
        else { cout << " ����� � ���� ��������������" << endl; }

        if (choose_menu == 5) { setColor(4, 0); cout << " -> ����� �� ��������� � ��������� ����������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ��������� � ��������� ����������" << endl; }

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

int chooseAdminsOrUsers() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ������������� ���������������" << endl; setColor(15, 0); }
        else cout << " ������������� ���������������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ������������� �������������" << endl; setColor(15, 0); }
        else cout << " ������������� �������������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����� � ���� ��������������" << endl; setColor(15, 0); }
        else { cout << " ����� � ���� ��������������" << endl; }

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

int chooseAdmin(Admin*& admins, int& nAdmin) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + (nAdmin + 1)) % (nAdmin + 1);

        for (int i = 0; i < nAdmin; i++)
            if (i == choose_menu) { setColor(4, 0); cout << " -> " << i + 1 << " - " << admins[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << admins[i].getLogin() << endl; }

        if (choose_menu == nAdmin) { setColor(4, 0); cout << " -> ����� � ������ ��������������" << endl; setColor(15, 0); }
        else cout << " ����� � ������ ��������������" << endl;

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

int chooseWhatRedAdmin(Admin*& admins, int choose) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �����: " << admins[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " �����: " << admins[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ������: " << admins[choose].getPass() << endl; setColor(15, 0); }
        else cout << " ������: " << admins[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> �����: �������������" << endl; setColor(15, 0); }
        else { cout << " �����: �������������" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ����� � ���� ������ ��������������" << endl; setColor(15, 0); }
        else { cout << " ����� � ���� ������ ��������������" << endl; }

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

int chooseRoot() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �������������" << endl; setColor(15, 0); }
        else cout << " �������������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ������������" << endl; setColor(15, 0); }
        else cout << " ������������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����� �� ���� ������ ����" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���� ������ ����" << endl; }

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

int chooseYesOrNot() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        cout << "�� ������� ��� ������ ������� �����?" << endl;
        cout << "����� ������������ �������� �� ���� ������� ������." << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ��" << endl; setColor(15, 0); }
        else cout << " ��" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ���" << endl; setColor(15, 0); }
        else cout << " ���" << endl;

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

int chooseUser(User*& users, int& nUsers) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ������������" << endl;
        choose_menu = (choose_menu + (nUsers + 1)) % (nUsers + 1);

        for (int i = 0; i < nUsers; i++)
            if (i == choose_menu) { setColor(4, 0); cout << " -> " << i + 1 << " - " << users[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << users[i].getLogin() << endl; }

        if (choose_menu == nUsers) { setColor(4, 0); cout << " -> ����� � ������ ������������" << endl; setColor(15, 0); }
        else cout << " ����� � ������ ������������" << endl;

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

int chooseWhatRedUser(User*& users, int choose, int a) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 10) % 10;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �����: " << users[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " �����: " << users[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ������: " << users[choose].getPass() << endl; setColor(15, 0); }
        else cout << " ������: " << users[choose].getPass() << endl;

        if (a == 0) {
            if (choose_menu == 2) { setColor(4, 0); cout << " -> �����: ������������" << endl; setColor(15, 0); }
            else { cout << " �����: ������������" << endl; }
        }

        if (choose_menu == 3) {
            setColor(4, 0);
            if (users[choose].getName().length() != 0) cout << " -> ���: " << users[choose].getName() << endl;
            else cout << " -> ���: ��� ������" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getName().length() != 0) cout << " ���: " << users[choose].getName() << endl;
            else cout << " ���: ��� ������" << endl;
        }

        if (choose_menu == 4) {
            setColor(4, 0);
            if (users[choose].getS_Name().length() != 0) cout << " -> �������: " << users[choose].getS_Name() << endl;
            else cout << " -> �������: ��� ������" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getS_Name().length() != 0) cout << " �������: " << users[choose].getS_Name() << endl;
            else cout << " �������: ��� ������" << endl;
        }

        if (choose_menu == 5) {
            setColor(4, 0);
            if (users[choose].getT_Name().length() != 0)  cout << " -> ��������: " << users[choose].getT_Name() << endl;
            else cout << " -> ��������: ��� ������" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getT_Name().length() != 0)  cout << " ��������: " << users[choose].getT_Name() << endl;
            else cout << " ��������: ��� ������" << endl;
        }

        if (choose_menu == 6) {
            setColor(4, 0);
            if (users[choose].getPhoneNumber().length() != 0) cout << " -> ����� ��������: +375" << users[choose].getPhoneNumber() << endl;
            else cout << " -> ����� ��������: ��� ������" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getPhoneNumber().length() != 0) cout << " ����� ��������: +375" << users[choose].getPhoneNumber() << endl;
            else cout << " ����� ��������: ��� ������" << endl;
        }

        if (choose_menu == 7) {
            setColor(4, 0);
            if (users[choose].getCard().length() != 0) cout << " -> �����: " << users[choose].getCard() << endl;
            else cout << " -> �����: ��� ������" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getCard().length() != 0) cout << " �����: " << users[choose].getCard() << endl;
            else cout << " �����: ��� ������" << endl;
        }

        if (choose_menu == 8) {
            setColor(4, 0);
            if (users[choose].getGander() == 1) cout << " -> ���: �������" << endl;
            else
                if (users[choose].getGander() == 2) cout << " -> ���: �������" << endl;
                else cout << " -> ���: ��� ������" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getGander() == 1) cout << " ���: �������" << endl;
            else
                if (users[choose].getGander() == 2) cout << " ���: �������" << endl;
                else cout << " ���: ��� ������" << endl;
        }

        if (choose_menu == 9) { setColor(4, 0); cout << " -> ����� �����" << endl; setColor(15, 0); }
        else { cout << " ����� �����" << endl; }

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) {
                choose_menu--;
                if (a == 1 && choose_menu == 2) choose_menu--;
            }
            if (keyboard_button == 80) {
                choose_menu++;
                if (a == 1 && choose_menu == 2) choose_menu++;
            }
        }
        if (keyboard_button == 13) { system("cls"); return choose_menu; }
        system("cls");
    }
}

int chooseWhoAdd() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �������� ��������������" << endl; setColor(15, 0); }
        else cout << " �������� ��������������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> �������� ������������" << endl; setColor(15, 0); }
        else cout << " �������� ������������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����� � ���� ��������������" << endl; setColor(15, 0); }
        else { cout << " ����� � ���� ��������������" << endl; }

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

int chooseRedHotelsMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �������������� ������������ �������������" << endl; setColor(15, 0); }
        else cout << " �������������� ������������ �������������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ���������� ������������ ��� ������������" << endl; setColor(15, 0); }
        else cout << " ���������� ������������ ��� ������������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> �������� ���� ������������" << endl; setColor(15, 0); }
        else { cout << " �������� ���� ������������" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ������� ����" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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

int chooseWhatRed(Room*& rooms, int& nRooms, User*& users, int& nUsers) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + (nRooms + 1)) % (nRooms + 1);

        for (int i = 0; i < nRooms; i++)
            if (i == choose_menu) { 
                int ij = 0;
                setColor(4, 0); 
                for (int j = 0; j < nUsers; j++)
                    if (users[j].getRoot() == rooms[i].getRoot()) { ij = j; break; }
                cout << " -> " << i + 1 << " - " << users[ij].getLogin() << ". ������� �" << rooms[i].getNumber() << endl; 
                setColor(15, 0); 
            }
            else { 
                int ij = 0;
                for (int j = 0; j < nUsers; j++)
                    if (users[j].getRoot() == rooms[i].getRoot()) { ij = j; break; }
                cout << " " << i + 1 << " - " << users[ij].getLogin() << ". ������� �" << rooms[i].getNumber() << endl;
            }

        if (choose_menu == nRooms) { setColor(4, 0); cout << " -> ����� � ������ ������������" << endl; setColor(15, 0); }
        else cout << " ����� � ������ ������������" << endl;

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

int chooseRedRooms(Room*& rooms, int choose) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ����: " << rooms[choose].getDateArrival() << " - " << rooms[choose].getDateLeaving() << endl; setColor(15, 0); }
        else cout << " ����: " << rooms[choose].getDateArrival() << " - " << rooms[choose].getDateLeaving() << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ��� �������: " << rooms[choose].getType() << endl; setColor(15, 0); }
        else cout << " ��� �������: " << rooms[choose].getType() << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����: " << rooms[choose].getFloor() << endl; setColor(15, 0); }
        else cout << " ����: " << rooms[choose].getFloor() << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ���������������: " << rooms[choose].getVolume() << endl; setColor(15, 0); }
        else cout << " ���������������: " << rooms[choose].getVolume() << endl;

        if (choose_menu == 4) { setColor(4, 0); cout << " -> ���-�� ������: " << rooms[choose].getNumberOfRooms() << endl; setColor(15, 0); }
        else cout << " ���-�� ������: " << rooms[choose].getNumberOfRooms() << endl;

        if (choose_menu == 5) { setColor(4, 0); cout << " -> ��� �������: " << rooms[choose].getTypeOfFood() << endl; setColor(15, 0); }
        else cout << " ��� �������: " << rooms[choose].getTypeOfFood() << endl;

        if (choose_menu == 6) { setColor(4, 0); cout << " -> ����� � ���� ������ �������" << endl; setColor(15, 0); }
        else { cout << " ����� � ���� ������ �������" << endl; }

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

string chooseTypeRoom() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ����������� " << endl; setColor(15, 0); }
        else cout << " ����������� " << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ���� " << endl; setColor(15, 0); }
        else cout << " ���� " << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> VIP" << endl; setColor(15, 0); }
        else cout << " VIP " << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ������������� " << endl; setColor(15, 0); }
        else cout << " ������������� " << endl;

        if (choose_menu == 4) { setColor(4, 0); cout << " -> ����� � ���� ��������������" << endl; setColor(15, 0); }
        else { cout << " ����� � ���� ��������������" << endl; }

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) { 
            system("cls"); 
            if (choose_menu == 0) return "�����������";
            else
                if (choose_menu == 1) return "����";
                else
                    if (choose_menu == 2) return "VIP";
                    else
                        if (choose_menu == 3) return "�������������";
                        else return "0";

        }
        system("cls");
    }
}

string chooseTypeFood() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �������� " << endl; setColor(15, 0); }
        else cout << " �������� " << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ��� �������� " << endl; setColor(15, 0); }
        else cout << " ��� �������� " << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ������ ��� �������� " << endl; setColor(15, 0); }
        else cout << " ������ ��� �������� " << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ����� � ���� ��������������" << endl; setColor(15, 0); }
        else { cout << " ����� � ���� ��������������" << endl; }

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) {
            system("cls");
            if (choose_menu == 0) return "��������";
            else
                if (choose_menu == 1) return "��� ��������";
                else
                    if (choose_menu == 2) return "������ ��� ��������";
                    else return "0";

        }
        system("cls");
    }
}

int chooseProcMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> �������� ���� ������������" << endl; setColor(15, 0); }
        else cout << " �������� ���� ������������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ����� ���� ������������ ������������" << endl; setColor(15, 0); }
        else cout << " ����� ���� ������������ ������������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����������� ������������" << endl; setColor(15, 0); }
        else { cout << " ����������� ������������" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ������� ����" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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

int chooseSort() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ����������� �� ������" << endl; setColor(15, 0); }
        else cout << " ����������� �� ������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ����������� �� ����" << endl; setColor(15, 0); }
        else cout << " ����������� �� ����" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����������� �� ���������������" << endl; setColor(15, 0); }
        else cout << " ����������� �� ���������������" << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> ����� � ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ����" << endl; }

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

int chooseHowSort() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ����������� �� �����������" << endl; setColor(15, 0); }
        else cout << " ����������� �� �����������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ����������� �� ��������" << endl; setColor(15, 0); }
        else cout << " ����������� �� ��������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> ����� � ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ����" << endl; }

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

int choicYesOrNot(int a) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        if (a != -123) {
            cout << "�������� ���� �� ���� ���������� �������: " << a << endl;
            cout << "�� ��������?" << endl;
        }
        else
            cout << "�� ������� ��� ������ �������� ������������?" << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ��" << endl; setColor(15, 0); }
        else cout << " ��" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ���" << endl; setColor(15, 0); }
        else cout << " ���" << endl;

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

int chooseExitOfFill() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ������������." << endl;
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        cout << "�� �� ����� ��� ���������� � ����. ��� ��� �� �� ������� ������������� �����." << endl;
        cout << "��������� ���������� ����������." << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ��������� �������" << endl; setColor(15, 0); }
        else cout << " ��������� �������" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else cout << " ����� � ������� ����" << endl;

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

int chooseUserMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "������������ ������������!" << endl;
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> ������������� �����" << endl; setColor(15, 0); }
        else cout << " ������������� �����" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> �������� ��������������� �������" << endl; setColor(15, 0); }
        else cout << " �������� ��������������� �������" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> �������� ������������" << endl; setColor(15, 0); }
        else { cout << " �������� ������������" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> �������� ���������� ��������" << endl; setColor(15, 0); }
        else { cout << " �������� ���������� ��������" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> �������������� ������ ��������" << endl; setColor(15, 0); }
        else { cout << " �������������� ������ ��������" << endl; }

        if (choose_menu == 5) { setColor(4, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ������� ����" << endl; }

        if (choose_menu == 6) { setColor(4, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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
