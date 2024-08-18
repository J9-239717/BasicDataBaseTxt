#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"DataBase.h"

#define show(a, b, c) printf("Name{%s},ID{%s},PASSWORD{%s}\n", (a) ? (a) : "NULL", (b) ? (b) : "NULL", (c) ? (c) : "NULL")

int _insert(DataUser data){
    FILE* src = fopen("dataBase.txt", "a");
    fprintf(src, "%s %s %s\n", data.name, data.ID, data.password);
    fclose(src);
}

void _show_all(){
    FILE* src = fopen("dataBase.txt", "r");
    
    char bufname[256], bufid[256], bufpas[256];
    
    while (fscanf(src, "%255s %255s %255s", bufname, bufid, bufpas) != EOF) {
        show(bufname, bufid, bufpas);
    }

    fclose(src);
}

int _find(find_mode_flag f){
    char buffer[256];
    char bufname[256], bufid[256], bufpas[256];
    int found = 0;
    FILE* fp = fopen("dataBase.txt", "r");
    
    switch (f)
    {
    case BY_ID:
        printf("Plase Enter id to find: ");scanf("%255s", buffer);
        break;
    case BY_USER:
        printf("Plase Enter User to find: ");scanf("%255s", buffer);
        break;
    default:
        printf("eror\n");
        break;
    }

     while (fscanf(fp, "%255s %255s %255s", bufname, bufid, bufpas) != EOF) {
        if ((f == BY_ID && strcmp(bufid, buffer) == 0) ||
            (f == BY_USER && strcmp(bufname, buffer) == 0)) {
            show(bufname, bufid, bufpas);
            found = 1;
        }
    }

    if (!found) {
        printf("No match found.\n");
    }

    fclose(fp);
    return found;
}

int _delete(find_mode_flag f){
    char buffname[256],buffid[256],buffpass[256];
    char buffer[256];
    int found = 0;
    FILE *fo,*fp;
    fo = fopen("dataBase.txt", "r");
    fp = fopen("temp.txt", "w");

    switch (f)
    {
    case BY_ID:
        printf("Plase Enter id to delete: ");scanf("%255s", buffer);
        break;
    case BY_USER:
        printf("Plase Enter User to delete: ");scanf("%255s", buffer);
        break;
    default:
        printf("eror\n");
        break;
    }

    while (fscanf(fo,"%255s %255s %255s", buffname,buffid,buffpass) != EOF){
        if((f == BY_ID && strcmp(buffer,buffid) == 0) || 
           (f == BY_USER && strcmp(buffer,buffname) == 0)){
            found = 1;
            continue;
        }else{
            fprintf(fp,"%s %s %s\n",buffname,buffid,buffpass);
        }
    }
    fclose(fo);
    fclose(fp);
    if(!found){
        remove("temp.txt");
        printf("Not found\n");
        
        return 0;
    }else{
        remove("dataBase.txt");
        rename("temp.txt","dataBase.txt");
        printf("Delete Completed\n");
    }
    
    return 1;
}

void _listen(DataUser src){
    DataUser data;
    strcpy(data.name,src.name);
    strcpy(data.ID,src.ID);
    strcpy(data.password,src.password);
    _insert(data);
}