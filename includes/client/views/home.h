#ifndef VIEW_MENU_H
#define VIEW_MENU_H

#include "models/UserModel.h"

extern User *selectedUser;
extern User *user;

void changeScreenLogin();

void changeScreenRegister();

void loggedHome();

void unloggedHome();

void renderHome();

User *getSelectedUser();

void renderMoneySender();

#endif