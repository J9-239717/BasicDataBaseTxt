#ifndef DATABASE_LOGIC
#define DATABASE_LOGIC
#include"UserData.h"
#include"DataBase.c"
int _insert(DataUser data);
int _find();
int _delete();
void _show_all();
void _show_by_id();
void _listen(DataUser src);
#endif