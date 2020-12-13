#pragma once
#include "CursOOP.h"

int openUserMenu(Admin*&, User*&, int&, int&, Room*&, int&, int);
int openAdminMenu(Admin*&, User*&, int&, int&, int&, Room*&, int&);
int openMenuAdministration(Admin*&, User*&, int&, int&, int&);
void addOneUser(Admin*&, User*&, int&, int&, int&);
void changeMenuUsers(Admin*&, User*&, int&, int&, int&);
void showUsers(Admin*&, User*&, int&, int&);
void openMenuRedAdmin(Admin*&, User*&, int&, int&, int&);
void openMenuRedUsers(Admin*&, User*&, int&, int&);
void openMenuRedRooms(Room*&, int&, User*&, int&);
int openMenuRedHotels(Room*&, int&, User*&, int&);
void showAllRooms(Room*&, int&, User*&, int&);
void addOneRooms(Room*&, int&, User*&, int&);
int openProcMenu(Room*&, int&, User*&, int&);
void showOneRoom(Room*&, int);
void openMenuSort(Room*&, int&, User*&, int&);
void redUser(Admin*&, User*&, int&, int&, int, int);
