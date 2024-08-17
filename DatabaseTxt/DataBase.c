#include<stdio.h>
#include<string.h>
#include"DataBase.h"

void _listen(DataUser src){
    DataUser data;
    src.ID = strdup(src.ID);
    src.password = strdup(src.password);
    strcpy(data.name,src.name);
    _insert(data);
}

int _insert(DataUser data){
    FILE* src = fopen("dataBase.txt", "w");
    fprintf(src, "\n%s %s %s", data.name, data.ID, data.password);
    fclose(src);
}