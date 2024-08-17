#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DataBase.h"

int main(){
    DataUser data;
    char buffer[256];
    char bufferID[50],bufferPas[50];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1] = '\0';
    sscanf(buffer,"%s %s %s", data.name,bufferID,bufferPas);
    data.ID = strdup(bufferID);
    data.password = strdup(bufferPas);
    _listen(data);
    free(data.ID);data.ID = NULL;
    free(data.password);data.password = NULL;
}