#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"DataBase.h"

#define show(a, b, c) printf("Name{%s},ID{%s},PASSWORD{%s}\n", (a) , (b) , (c))

void _insert(DataUser data){
    FILE* src = fopen("dataBase.txt", "a");
    fprintf(src, "%s %s %s\n", data.name, data.ID, data.password);
    fclose(src);
}

void _show_all(void){
    FILE* src = fopen("dataBase.txt", "r");
    
    char bufname[256], bufid[256], bufpas[256];
    
    while (fscanf(src, "%255s %255s %255s", bufname, bufid, bufpas) != EOF) {
        show(bufname, bufid, bufpas);
    }

    fclose(src);
}

int _find(find_mode_flag f,const char key[]){
    char bufname[256], bufid[256], bufpas[256];
    int found = 0;
    FILE* fp = fopen("dataBase.txt", "r");
    
     while (fscanf(fp, "%255s %255s %255s", bufname, bufid, bufpas) != EOF) {
        if ((f == BY_ID && strcmp(bufid, key) == 0) ||
            (f == BY_USER && strcmp(bufname, key) == 0)) {
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

int _delete(find_mode_flag f,const char key[]){
    char buffname[256],buffid[256],buffpass[256];
    int found = 0;
    FILE *fo,*fp;
    fo = fopen("dataBase.txt", "r");
    fp = fopen("temp.txt", "w");

    while (fscanf(fo,"%255s %255s %255s", buffname,buffid,buffpass) != EOF){
        if((f == BY_ID && strcmp(key,buffid) == 0) || 
           (f == BY_USER && strcmp(key,buffname) == 0)){
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

int _check(DataUser src){
    FILE* fp = fopen("dataBase.txt", "r");
    char buffID[256],buffPas[256];
    char buffName[256];
    while (fscanf(fp,"%255s %255s %255s", buffName, buffID, buffPas) != EOF){
        if(strcmp(src.ID,buffID) == 0 && strcmp(src.password,buffPas) == 0){
            return 1;
        }
    }
    return 0;
}

void _listen(DataUser src){
    DataUser data;
    strcpy(data.name,src.name);
    strcpy(data.ID,src.ID);
    strcpy(data.password,src.password);
    _insert(data);
}
