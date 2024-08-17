#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DataBase.h"

int main(){
    DataUser data;
    char buffer[256];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1] = '\0';
    sscanf(buffer,"%s %s %s", data.name,data.ID,data.password);
    printf("++%s %s %s++", data.name,data.ID,data.password);
    _listen(data);
}