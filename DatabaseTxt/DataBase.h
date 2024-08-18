#ifndef DATABASE_H
#define DATABASE_H

#include"UserData.h"

int _check(DataUser src);
int _insert(DataUser data);
int _find(find_mode_flag f,const char key[]);
int _delete(find_mode_flag f,const char key[]);
void _show_all();
void _listen(DataUser src);

#endif