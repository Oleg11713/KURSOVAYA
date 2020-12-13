#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <functional>
using namespace std;

string writeWords();
string encryptPass(string);
string deencryptPass(string);

class Admin;
class User;


class Administration {
protected:
	string login;
	string password;
public:
	Administration() {};
	Administration(string log, string pass) {
		login = log;
		password = pass;
	}
	virtual string getPass() = 0;
	virtual string getLogin() = 0;
	virtual void changePass(string) = 0;
	virtual void changeLogin(string) = 0;
	virtual void showIfromation() = 0;
};

class UserFunc :public Administration {
public:
	UserFunc() {};
	UserFunc(string log, string pass) :Administration(log, pass) {
	}
	virtual void changeName(string) = 0;
	virtual void changeS_Name(string) = 0;
	virtual void changeT_Name(string) = 0;
	virtual void changeGander(int) = 0;
	virtual void changePhoneNumber(string) = 0;
	virtual void changeCard(string) = 0;
	virtual void changeFilling(int) = 0;
	virtual void changeRoot(int) = 0;
	virtual string getName() = 0;
	virtual string getS_Name() = 0;
	virtual string getT_Name() = 0;
	virtual int getGander() = 0;
	virtual string getPhoneNumber() = 0;
	virtual string getCard() = 0;
	virtual int getFilling() = 0;
	virtual void writePass() = 0;
	virtual int getRoot() = 0;
};

class AdminFunc :public Administration {
public:
	AdminFunc() {};
	AdminFunc(string log, string pass) :Administration(log, pass) {
	}
	virtual void writePass() = 0;
};

class User :public UserFunc {
private:
	string name;
	string s_name;
	string t_name;
	int gender;
	string phone_number;
	string card;
	int filling;
	int root;
public:
	User() {
		name = "";
		s_name = "";
		t_name = "";
		gender = 0;
		phone_number = "";
		card = "";
		filling = 0;
		root = 0;
	};
	User(const User& user) {
		login = user.login;
		password = user.password;
		name = user.name;
		s_name = user.s_name;
		t_name = user.t_name;
		gender = user.gender;
		phone_number = user.phone_number;
		card = user.card;
		filling = user.filling;
		root = user.root;
	}
	User(string log, string pass) :UserFunc(log, pass) {
		name = "";
		s_name = "";
		t_name = "";
		gender = 0;
		phone_number = "";
		card = "";
		filling = 0;
		root = 0;
	}
	string getLogin() {
		return login;
	}
	string getPass() {
		return password;
	}
	void changeLogin(string log) {
		login = log;
	}
	void changePass(string pass) {
		password = pass;
	}
	string getName() {
		return name;
	}
	string getS_Name() {
		return s_name;
	}
	string getT_Name() {
		return t_name;
	}
	int getGander() {
		return gender;
	}
	string getCard() {
		return card;
	}
	string getPhoneNumber() {
		return phone_number;
	}
	int getFilling() {
		return filling;
	}
	int getRoot() {
		return root;
	}
	void changeName(string ptr) {
		name = ptr;
	}
	void changeS_Name(string ptr) {
		s_name = ptr;
	}
	void changeT_Name(string ptr) {
		t_name = ptr;
	}
	void changeGander(int ptr) {
		gender = ptr;
	}
	void changeCard(string ptr) {
		card = ptr;
	}
	void changePhoneNumber(string ptr) {
		phone_number = ptr;
	}
	void changeFilling(int ptr) {
		filling = ptr;
	}
	void changeRoot(int ptr) {
		root = ptr;
	}
	void showIfromation() {
		cout << " Логин: " << login << endl;
		cout << " Пароль: " << password << endl;
		cout << " Имя: ";
		if (name.length() != 0) cout << name << endl;
		else cout << " Нет данных" << endl;
		cout << " Фамилия: ";
		if (s_name.length() != 0) cout << s_name << endl;
		else cout << " Нет данных" << endl;
		cout << " Отчество: ";
		if (t_name.length() != 0) cout << t_name << endl;
		else cout << " Нет данных" << endl;
		cout << " Пол: ";
		if (gender == 1) cout << " Мужской" << endl;
		else
			if (gender == 2) cout << " Женский" << endl;
			else cout << " Нет данных" << endl;
		cout << " Номер телефона: ";
		if (phone_number.length() != 0) cout << "+375(" << phone_number[0] << phone_number[1] << ")" << phone_number[2] << phone_number[3] <<
			phone_number[4] << phone_number[5] << phone_number[6] << phone_number[7] << phone_number[8] << endl;
		else cout << " Нет данных" << endl;
		cout << " Банковская карта: ";
		if (card.length() != 0) cout << "**** **** **** " << card[12] << card[13] << card[14] << card[15] << endl;
		else cout << " Нет данных" << endl;
	}
	friend void writeLogin(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int choose, int chois);
	void writePass() {
		string pass;
		cout << "Введите Пароль: ";
		pass = writeWords();
		system("cls");
		password = pass;
	}
	void checkFilling() {
		if (name.length() != 0 && s_name.length() != 0 && t_name.length() != 0 && phone_number.length() != 0 && card.length() != 0 && gender != 0)
			filling = 1;
	}
};

class Admin :public AdminFunc {
public:
	Admin() {};
	Admin(const Admin& admin) {
		login = admin.login;
		password = admin.password;
	}
	Admin(string log, string pass) :AdminFunc(log, pass) {
	}
	string getPass() {
		return password;
	}
	string getLogin() {
		return login;
	}
	void changePass(string pass) {
		password = pass;
	}
	void changeLogin(string log) {
		login = log;
	}
	void showIfromation() {
		cout << " Логин: " << login << endl;
		cout << " Пароль: " << password << endl;
	}
	friend void writeLogin(Admin*& admins, User*& users, int& nAdmin, int& nUsers, int choose, int chois);
	void writePass() {
		string pass;
		cout << "Введите Пароль: ";
		pass = writeWords();
		system("cls");
		password = pass;
	}
};

class Hotel {
protected:
	string type;
	string number_of_rooms;
	string volume;
	string type_of_food;
	string number;
	string floor;
	string coast;
public:
	Hotel() {};
	virtual string getType() = 0;
	virtual string getNumberOfRooms() = 0;
	virtual string getVolume() = 0;
	virtual string getTypeOfFood() = 0;
	virtual string getNumber() = 0;
	virtual string getFloor() = 0;
	virtual string getCoast() = 0;
	virtual void changeType(string) = 0;
	virtual void changeNumberOfRooms(string) = 0;
	virtual void changeVolume(string) = 0;
	virtual void changeTypeOfFood(string) = 0;
	virtual void changeNumber(string) = 0;
	virtual void changeFloor(string) = 0;
	virtual void changeCoast(string) = 0;
};

class RoomFunc:public Hotel {
public:
	RoomFunc() {};
	string getType() {
		return type;
	}
	string getNumberOfRooms() {
		return number_of_rooms;
	}
	string getVolume() {
		return volume;
	}
	string getTypeOfFood() {
		return type_of_food;
	}
	string getNumber() {
		return number;
	}
	string getFloor() {
		return floor;
	}
	string getCoast() {
		return coast;
	}
	void changeCoast(string ptr) {
		coast = ptr;
	}
	void changeType(string ptr) {
		type = ptr;
	}
	void changeNumberOfRooms(string ptr) {
		number_of_rooms = ptr;
	}
	void changeVolume(string ptr) {
		volume = ptr;
	}
	void changeTypeOfFood(string ptr) {
		type_of_food = ptr;
	}
	void changeNumber(string ptr) {
		number = ptr;
	}
	void changeFloor(string ptr) {
		floor = ptr;
	}
};

class Room :public RoomFunc {
private:
	int root;
	int days;
	string dateArrival;
	string dateLeaving;
public:	
	Room() {
		root = 0;
		days = 0;
	};
	string getDateArrival(){
		return dateArrival;
	}
	string getDateLeaving(){
		return dateLeaving;
	}
	int getRoot() {
		return root;
	}
	int getDays() {
		return days;
	}
	void changeDays(int ptr) {
		days = ptr;
	}
	void changeDateArrival(string ptr) {
		dateArrival = ptr;
	}
	void changeDateLeaving(string ptr) {
		dateLeaving = ptr;
	}
	void changeRoot(int ptr) {
		root = ptr;
	}
	void setPrice() {
		int price = 0;
		if (type == "Стандарт") price += 50;
		else
			if (type == "VIP") price += 70;
			else
				if (type == "Люкс") price += 90;
				else
					if (type == "Президентский") price += 110;
		price += stoi(volume) * 5;
		price += stoi(number_of_rooms) * 5;
		if (type_of_food == "Завтраки") price += 5;
		else
			if (type_of_food == "Все включено") price += 15;
			else
				if (type_of_food == "Ультра все включено") price += 30;
		price = price * days;
		coast = to_string(price);
	}
	void setDate() {
		cout << "Укажите год в котором вы хотите заехать: 202";
		string s;
		int year = writeYear("0");
		system("cls");
		int month = chooseMonth(0);
		int day = checkDay(month, year, 0, "Введите день заселения: ");
		system("cls");
		s = to_string(day) + "." + to_string(month + 1) + ".202" + to_string(year);
		dateArrival = s;
		system("cls");
		cout << "Укажите год в котором вы хотите выселяться: 202";
		int year1 = writeYear(to_string(year));
		int month1;
		int day1;
		system("cls");
		if (year1 == year) month1 = chooseMonth(month);
		else month1 = chooseMonth(0);
		system("cls");
		if (month == month1 && year == year1) {
			day1 = checkDay(month1, year1, day, "Введите день выселения: ");
		}
		else day1 = checkDay(month1, year1, 0, "Введите день выселения: ");
		system("cls");
		string s1 = to_string(day1) + "." + to_string(month1 + 1) + ".202" + to_string(year1);
		dateLeaving = s1;
		days = rdn(year1, month1, day1) - rdn(year, month, day);
	}
	int writeYear(string year) {
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
					if (key == 13 && str.length() <= 1 && str.length() != 0) break;
					else
						if (key >= year[0] && key <= '9' && str.length() < 1) {
							str = str + (char)key;
							cout << (char)key;
						}
		}
		return stoi(str);
	}
	int chooseMonth(int month) {
		int choose_menu = 0, keyboard_button = 0;
		while (true) {
			cout << "Стрелочками ВВЕРХ и ВНИЗ выберите месяц" << endl;
			choose_menu = (choose_menu + 12) % 12;
			if (choose_menu < month) choose_menu = month;
			if (0 >= month) {
				if (choose_menu == 0) { setColor(4, 0); cout << " -> Январь" << endl; setColor(15, 0); }
				else cout << " Январь" << endl;
			}
			if (1 >= month) {
				if (choose_menu == 1) { setColor(4, 0); cout << " -> Февраль" << endl; setColor(15, 0); }
				else cout << " Февраль" << endl;
			}
			if (2 >= month) {
				if (choose_menu == 2) { setColor(4, 0); cout << " -> Март" << endl; setColor(15, 0); }
				else cout << " Март" << endl;
			}
			if (3 >= month) {
				if (choose_menu == 3) { setColor(4, 0); cout << " -> Апрель" << endl; setColor(15, 0); }
				else cout << " Апрель" << endl;
			}
			if (4 >= month) {
				if (choose_menu == 4) { setColor(4, 0); cout << " -> Май" << endl; setColor(15, 0); }
				else cout << " Май" << endl;
			}
			if (5 >= month) {
				if (choose_menu == 5) { setColor(4, 0); cout << " -> Июнь" << endl; setColor(15, 0); }
				else cout << " Июнь" << endl;
			}
			if (6 >= month) {
				if (choose_menu == 6) { setColor(4, 0); cout << " -> Июль" << endl; setColor(15, 0); }
				else cout << " Июль" << endl;
			}
			if (7 >= month) {
				if (choose_menu == 7) { setColor(4, 0); cout << " -> Август" << endl; setColor(15, 0); }
				else cout << " Август" << endl;
			}
			if (8 >= month) {
				if (choose_menu == 8) { setColor(4, 0); cout << " -> Сентябрь" << endl; setColor(15, 0); }
				else cout << " Сентябрь" << endl;
			}
			if (9 >= month) {
				if (choose_menu == 9) { setColor(4, 0); cout << " -> Октябрь" << endl; setColor(15, 0); }
				else cout << " Октябрь" << endl;
			}
			if (10 >= month) {
				if (choose_menu == 10) { setColor(4, 0); cout << " -> Ноябрь" << endl; setColor(15, 0); }
				else cout << " Ноябрь" << endl;
			}
			if (11 >= month) {
				if (choose_menu == 11) { setColor(4, 0); cout << " -> Декабрь" << endl; setColor(15, 0); }
				else cout << " Декабрь" << endl;
			}
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
	int checkDay(int month, int year, int days, string s) {
		while (true) {
			cout << s;
			int day = writeNumbers();
			if (day > days) {
				if ((month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) && day <= 31) {
					return day;
				}
				else
					if (month == 1) {
						if ((year % 4 == 0) && (year % 100 == 0)) {
							if (day <= 29) return day;
						}
						else
							if (day <= 28) return day;
					}
					else
						if (day <= 30) return day;
			}
			system("cls");
		}
	}
	int writeNumbers() {
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
					if (key == 13 && str.length() <= 2 && str.length() != 0) break;
					else
						if (key >= '0' && key <= '9' && str.length() < 2) {
							if (str.length() == 0 && key == '0') continue;
								str = str + (char)key;
								cout << (char)key;
						}
		}
		return stoi(str);
	}
	int rdn(int y, int m, int d) {
		if (m < 3)
			y--, m += 12;
		return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
	}
	void setColor(int text, int background) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}
};

ostream& operator<<(ostream&, Admin&);
istream& operator>>(istream&, Admin&);
ostream& operator<<(ostream&, User&);
istream& operator>>(istream&, User&);
ostream& operator<<(ostream&, Room&);
istream& operator>>(istream&, Room&);
