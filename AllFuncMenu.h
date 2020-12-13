#pragma once
#include "CursOOP.h"
#include "Checks.h"

int chooseMainMenu();
int showAdminMenu();
int showMenuAdministration();
int chooseAdminsOrUsers();
int chooseAdmin(Admin*&, int&);
int chooseWhatRedAdmin(Admin*&, int);
int chooseRoot();
int chooseYesOrNot();
int chooseUser(User*&, int&);
int chooseWhatRedUser(User*&, int, int);
int chooseWhoAdd();
int chooseRedHotelsMenu();
int chooseWhatRed(Room*&, int&, User*&, int&);
int chooseRedRooms(Room*&, int);
int chooseProcMenu();
string chooseTypeRoom();
string chooseTypeFood();
int chooseSort();
int chooseHowSort();
int choicYesOrNot(int);
int chooseExitOfFill();
int chooseUserMenu();