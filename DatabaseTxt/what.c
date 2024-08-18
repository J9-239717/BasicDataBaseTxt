#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DataBase.h"

int main(){
    DataUser data;
    char buffer[256];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1] = '\0';
    while(sscanf(buffer,"%s %s %s", data.name,data.ID,data.password) != 3){
        printf("Invalid input. Please enter name, ID, and password separated by spaces: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
    }
    _listen(data);
    _show_all();
    _find(BY_ID);
    _delete(BY_ID);
}
