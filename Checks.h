#pragma once
#include "CursOOP.h"

void setColor(int, int);
string writeNames();
string writePhoneNumber();
string writeCard();
int getGender();
void changeSizeUsers(User*&, int&);
void changeSizeAdmins(Admin*&, int&);
string writePassword();
void createFiles();
void fillSize(int&, int&, int&);
int fillClasses(Admin*&, User*&, Room*&, int&, int&, int&, int&);
void fillFiles(Admin*&, User*&, Room*&, int&, int&, int&);
string writeRoomAndFloor(int, char);
void changeSizeRooms(Room*&, int&);
string writeRoom(int);