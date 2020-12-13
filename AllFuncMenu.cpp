#include "AllFuncMenu.h"

int chooseMainMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 3) % 3;
        if (choose_menu == 0) { setColor(4, 0); cout << " -> Войти в аккаунт" << endl; setColor(15, 0); }
        else cout << " Войти в аккаунт" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Создать новый аккаунт" << endl; setColor(15, 0); }
        else cout << " Создать новый аккаунт" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
        else { cout << " Выйти из программы" << endl; }

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
        cout << "Здравствуйте администратор!" << endl;
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Работа с учетными записями" << endl; setColor(15, 0); }
        else cout << " Работа с учетными записями" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Редактирование данных номеров отеля" << endl; setColor(15, 0); }
        else cout << " Редактирование данных номеров отеля" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Просмотр и поиск данных отеля" << endl; setColor(15, 0); }
        else { cout << " Просмотр и поиск данных отеля" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else { cout << " Выход в главное меню" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
        else { cout << " Выйти из программы" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 6) % 6;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Просмотр учетных записей" << endl; setColor(15, 0); }
        else cout << " Просмотр учетных записей" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Редактирование учетных записей" << endl; setColor(15, 0); }
        else cout << " Редактирование учетных записей" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Добавление учетной записи" << endl; setColor(15, 0); }
        else { cout << " Добавление учетной записи" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Сохранить информацию" << endl; setColor(15, 0); }
        else { cout << " Сохранить информацию" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> Выход в меню администратора" << endl; setColor(15, 0); }
        else { cout << " Выход в меню администратора" << endl; }

        if (choose_menu == 5) { setColor(4, 0); cout << " -> Выйти из программы и сохранить информацию" << endl; setColor(15, 0); }
        else { cout << " Выйти из программы и сохранить информацию" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Редактировать администраторов" << endl; setColor(15, 0); }
        else cout << " Редактировать администраторов" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Редактировать пользователей" << endl; setColor(15, 0); }
        else cout << " Редактировать пользователей" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Выход в меню администратора" << endl; setColor(15, 0); }
        else { cout << " Выход в меню администратора" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + (nAdmin + 1)) % (nAdmin + 1);

        for (int i = 0; i < nAdmin; i++)
            if (i == choose_menu) { setColor(4, 0); cout << " -> " << i + 1 << " - " << admins[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << admins[i].getLogin() << endl; }

        if (choose_menu == nAdmin) { setColor(4, 0); cout << " -> Выйти с выбора администратора" << endl; setColor(15, 0); }
        else cout << " Выйти с выбора администратора" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Логин: " << admins[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " Логин: " << admins[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Пароль: " << admins[choose].getPass() << endl; setColor(15, 0); }
        else cout << " Пароль: " << admins[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Права: Администратор" << endl; setColor(15, 0); }
        else { cout << " Права: Администратор" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Выход в меню выбора администратора" << endl; setColor(15, 0); }
        else { cout << " Выход в меню выбора администратора" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Администратор" << endl; setColor(15, 0); }
        else cout << " Администратор" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Пользователь" << endl; setColor(15, 0); }
        else cout << " Пользователь" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Выход из меню выбора прав" << endl; setColor(15, 0); }
        else { cout << " Выход из меню выбора прав" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        cout << "Вы уверены что хотите сменить права?" << endl;
        cout << "Тогда пользователь исчезнет из меню данного выбора." << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Да" << endl; setColor(15, 0); }
        else cout << " Да" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Нет" << endl; setColor(15, 0); }
        else cout << " Нет" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пользователя" << endl;
        choose_menu = (choose_menu + (nUsers + 1)) % (nUsers + 1);

        for (int i = 0; i < nUsers; i++)
            if (i == choose_menu) { setColor(4, 0); cout << " -> " << i + 1 << " - " << users[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << users[i].getLogin() << endl; }

        if (choose_menu == nUsers) { setColor(4, 0); cout << " -> Выйти с выбора пользователя" << endl; setColor(15, 0); }
        else cout << " Выйти с выбора пользователя" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 10) % 10;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Логин: " << users[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " Логин: " << users[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Пароль: " << users[choose].getPass() << endl; setColor(15, 0); }
        else cout << " Пароль: " << users[choose].getPass() << endl;

        if (a == 0) {
            if (choose_menu == 2) { setColor(4, 0); cout << " -> Права: Пользователь" << endl; setColor(15, 0); }
            else { cout << " Права: Пользователь" << endl; }
        }

        if (choose_menu == 3) {
            setColor(4, 0);
            if (users[choose].getName().length() != 0) cout << " -> Имя: " << users[choose].getName() << endl;
            else cout << " -> Имя: Нет данных" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getName().length() != 0) cout << " Имя: " << users[choose].getName() << endl;
            else cout << " Имя: Нет данных" << endl;
        }

        if (choose_menu == 4) {
            setColor(4, 0);
            if (users[choose].getS_Name().length() != 0) cout << " -> Фамилия: " << users[choose].getS_Name() << endl;
            else cout << " -> Фамилия: Нет данных" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getS_Name().length() != 0) cout << " Фамилия: " << users[choose].getS_Name() << endl;
            else cout << " Фамилия: Нет данных" << endl;
        }

        if (choose_menu == 5) {
            setColor(4, 0);
            if (users[choose].getT_Name().length() != 0)  cout << " -> Отчество: " << users[choose].getT_Name() << endl;
            else cout << " -> Отчество: Нет данных" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getT_Name().length() != 0)  cout << " Отчество: " << users[choose].getT_Name() << endl;
            else cout << " Отчество: Нет данных" << endl;
        }

        if (choose_menu == 6) {
            setColor(4, 0);
            if (users[choose].getPhoneNumber().length() != 0) cout << " -> Номер телефона: +375" << users[choose].getPhoneNumber() << endl;
            else cout << " -> Номер телефона: Нет данных" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getPhoneNumber().length() != 0) cout << " Номер телефона: +375" << users[choose].getPhoneNumber() << endl;
            else cout << " Номер телефона: Нет данных" << endl;
        }

        if (choose_menu == 7) {
            setColor(4, 0);
            if (users[choose].getCard().length() != 0) cout << " -> Карта: " << users[choose].getCard() << endl;
            else cout << " -> Карта: Нет данных" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getCard().length() != 0) cout << " Карта: " << users[choose].getCard() << endl;
            else cout << " Карта: Нет данных" << endl;
        }

        if (choose_menu == 8) {
            setColor(4, 0);
            if (users[choose].getGander() == 1) cout << " -> Пол: Мужской" << endl;
            else
                if (users[choose].getGander() == 2) cout << " -> Пол: Женский" << endl;
                else cout << " -> Пол: Нет данных" << endl;
            setColor(15, 0);
        }
        else {
            if (users[choose].getGander() == 1) cout << " Пол: Мужской" << endl;
            else
                if (users[choose].getGander() == 2) cout << " Пол: Женский" << endl;
                else cout << " Пол: Нет данных" << endl;
        }

        if (choose_menu == 9) { setColor(4, 0); cout << " -> Выход назад" << endl; setColor(15, 0); }
        else { cout << " Выход назад" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Добавить администратора" << endl; setColor(15, 0); }
        else cout << " Добавить администратора" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Добавить пользователя" << endl; setColor(15, 0); }
        else cout << " Добавить пользователя" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Выход в меню администратора" << endl; setColor(15, 0); }
        else { cout << " Выход в меню администратора" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Редактирование бронирований пользователей" << endl; setColor(15, 0); }
        else cout << " Редактирование бронирований пользователей" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Добавление бронирования для пользователя" << endl; setColor(15, 0); }
        else cout << " Добавление бронирования для пользователя" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Просмотр всех бронирований" << endl; setColor(15, 0); }
        else { cout << " Просмотр всех бронирований" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else { cout << " Выход в главное меню" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
        else { cout << " Выйти из программы" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + (nRooms + 1)) % (nRooms + 1);

        for (int i = 0; i < nRooms; i++)
            if (i == choose_menu) { 
                int ij = 0;
                setColor(4, 0); 
                for (int j = 0; j < nUsers; j++)
                    if (users[j].getRoot() == rooms[i].getRoot()) { ij = j; break; }
                cout << " -> " << i + 1 << " - " << users[ij].getLogin() << ". Комната №" << rooms[i].getNumber() << endl; 
                setColor(15, 0); 
            }
            else { 
                int ij = 0;
                for (int j = 0; j < nUsers; j++)
                    if (users[j].getRoot() == rooms[i].getRoot()) { ij = j; break; }
                cout << " " << i + 1 << " - " << users[ij].getLogin() << ". Комната №" << rooms[i].getNumber() << endl;
            }

        if (choose_menu == nRooms) { setColor(4, 0); cout << " -> Выйти с выбора пользователя" << endl; setColor(15, 0); }
        else cout << " Выйти с выбора пользователя" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Даты: " << rooms[choose].getDateArrival() << " - " << rooms[choose].getDateLeaving() << endl; setColor(15, 0); }
        else cout << " Даты: " << rooms[choose].getDateArrival() << " - " << rooms[choose].getDateLeaving() << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Тип комнаты: " << rooms[choose].getType() << endl; setColor(15, 0); }
        else cout << " Тип комнаты: " << rooms[choose].getType() << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Этаж: " << rooms[choose].getFloor() << endl; setColor(15, 0); }
        else cout << " Этаж: " << rooms[choose].getFloor() << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Вместительность: " << rooms[choose].getVolume() << endl; setColor(15, 0); }
        else cout << " Вместительность: " << rooms[choose].getVolume() << endl;

        if (choose_menu == 4) { setColor(4, 0); cout << " -> Кол-во комнат: " << rooms[choose].getNumberOfRooms() << endl; setColor(15, 0); }
        else cout << " Кол-во комнат: " << rooms[choose].getNumberOfRooms() << endl;

        if (choose_menu == 5) { setColor(4, 0); cout << " -> Тип питания: " << rooms[choose].getTypeOfFood() << endl; setColor(15, 0); }
        else cout << " Тип питания: " << rooms[choose].getTypeOfFood() << endl;

        if (choose_menu == 6) { setColor(4, 0); cout << " -> Выход в меню выбора комнаты" << endl; setColor(15, 0); }
        else { cout << " Выход в меню выбора комнаты" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Стандартный " << endl; setColor(15, 0); }
        else cout << " Стандартный " << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Люкс " << endl; setColor(15, 0); }
        else cout << " Люкс " << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> VIP" << endl; setColor(15, 0); }
        else cout << " VIP " << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Президентский " << endl; setColor(15, 0); }
        else cout << " Президентский " << endl;

        if (choose_menu == 4) { setColor(4, 0); cout << " -> Выход в меню редактирования" << endl; setColor(15, 0); }
        else { cout << " Выход в меню редактирования" << endl; }

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) { 
            system("cls"); 
            if (choose_menu == 0) return "Стандартный";
            else
                if (choose_menu == 1) return "Люкс";
                else
                    if (choose_menu == 2) return "VIP";
                    else
                        if (choose_menu == 3) return "Президентский";
                        else return "0";

        }
        system("cls");
    }
}

string chooseTypeFood() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Завтраки " << endl; setColor(15, 0); }
        else cout << " Завтраки " << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Все включено " << endl; setColor(15, 0); }
        else cout << " Все включено " << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Ультра все включено " << endl; setColor(15, 0); }
        else cout << " Ультра все включено " << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Выход в меню редактирования" << endl; setColor(15, 0); }
        else { cout << " Выход в меню редактирования" << endl; }

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) {
            system("cls");
            if (choose_menu == 0) return "Завтраки";
            else
                if (choose_menu == 1) return "Все включено";
                else
                    if (choose_menu == 2) return "Ультра все включено";
                    else return "0";

        }
        system("cls");
    }
}

int chooseProcMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 5) % 5;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Просмотр всех бронирований" << endl; setColor(15, 0); }
        else cout << " Просмотр всех бронирований" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Поиск всех бронирований пользователя" << endl; setColor(15, 0); }
        else cout << " Поиск всех бронирований пользователя" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Сортировать бронирования" << endl; setColor(15, 0); }
        else { cout << " Сортировать бронирования" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else { cout << " Выход в главное меню" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
        else { cout << " Выйти из программы" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Сортировать по номеру" << endl; setColor(15, 0); }
        else cout << " Сортировать по номеру" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Сортировать по цене" << endl; setColor(15, 0); }
        else cout << " Сортировать по цене" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Сортировать по вместительности" << endl; setColor(15, 0); }
        else cout << " Сортировать по вместительности" << endl;

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Выход в меню" << endl; setColor(15, 0); }
        else { cout << " Выход в меню" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Сортировать по возрастанию" << endl; setColor(15, 0); }
        else cout << " Сортировать по возрастанию" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Сортировать по убыванию" << endl; setColor(15, 0); }
        else cout << " Сортировать по убыванию" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Выход в меню" << endl; setColor(15, 0); }
        else { cout << " Выход в меню" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        if (a != -123) {
            cout << "Итоговая цена по ваши параметрам выходит: " << a << endl;
            cout << "Вы согласны?" << endl;
        }
        else
            cout << "Вы уверены что хотите отменить бронирование?" << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Да" << endl; setColor(15, 0); }
        else cout << " Да" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Нет" << endl; setColor(15, 0); }
        else cout << " Нет" << endl;

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
        cout << "Здраствуйте Пользователь." << endl;
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        cout << "Вы не ввели всю информацию о себе. Без нее вы не сможете забронировать номер." << endl;
        cout << "Заполните информацию пожалуйста." << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Заполнить аккаунт" << endl; setColor(15, 0); }
        else cout << " Заполнить аккаунт" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else cout << " Выход в главное меню" << endl;

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
        cout << "Здравствуйте пользователь!" << endl;
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(4, 0); cout << " -> Забронировать номер" << endl; setColor(15, 0); }
        else cout << " Забронировать номер" << endl;

        if (choose_menu == 1) { setColor(4, 0); cout << " -> Просмотр забронированных номеров" << endl; setColor(15, 0); }
        else cout << " Просмотр забронированных номеров" << endl;

        if (choose_menu == 2) { setColor(4, 0); cout << " -> Отменить бронирование" << endl; setColor(15, 0); }
        else { cout << " Отменить бронирование" << endl; }

        if (choose_menu == 3) { setColor(4, 0); cout << " -> Просмотр информации аккаунта" << endl; setColor(15, 0); }
        else { cout << " Просмотр информации аккаунта" << endl; }

        if (choose_menu == 4) { setColor(4, 0); cout << " -> Редактирование данных аккаунта" << endl; setColor(15, 0); }
        else { cout << " Редактирование данных аккаунта" << endl; }

        if (choose_menu == 5) { setColor(4, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else { cout << " Выход в главное меню" << endl; }

        if (choose_menu == 6) { setColor(4, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
        else { cout << " Выйти из программы" << endl; }

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
