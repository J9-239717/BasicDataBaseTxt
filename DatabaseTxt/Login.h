#ifndef LOGIN_H
#define LOGIN_H

#include "UserData.h"

int get_input(char* prompt,char* buffer,size_t BUFFER_SIZE);
DataUser show_detail_and_get_data();
int _Login();

#endif