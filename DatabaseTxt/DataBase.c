#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"DataBase.h"

int _insert(DataUser data){
    FILE* src = fopen("dataBase.txt", "a");
    fprintf(src, "%s %s %s\n", data.name, data.ID, data.password);
    fclose(src);
}

void _listen(DataUser src){
    DataUser data;
    strcpy(data.name,src.name);
    strcpy(data.ID,src.ID);
    strcpy(data.password,src.password);
    _insert(data);
}