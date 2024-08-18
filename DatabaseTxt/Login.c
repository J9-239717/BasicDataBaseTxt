#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Login.h"
#include"DataBase.h"

int get_input(char* prompt,char* buffer,size_t BUFFER_SIZE){
    printf("%s", prompt);
    if(fgets(buffer,BUFFER_SIZE,stdin) != NULL){
        if(buffer[0] == '\n')return 0;
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len -1] == '\n'){
            buffer[len-1] = '\0';
        }
        return 1;
    }
    return 0;
}

DataUser show_detail_and_get_data(){
    DataUser data = {0};
    strcpy(data.name, "");
    if(!get_input("Please Enter ID: ", data.ID, 255)){
        fprintf(stderr, "EROR INPUT");
        exit(EXIT_FAILURE);
    }
    if(!get_input("Please Enter Password: ", data.password, 255)){
        fprintf(stderr, "EROR INPUT");
        exit(EXIT_FAILURE);
    }
    return data;
}

int _Login(){
    DataUser user = show_detail_and_get_data();
    if(_check(user)){
        printf("Login Success\n");
        return 1;
    }else{
        printf("ID or PassWord Incorrect\n"
               "Please Try Again\n");
    }
    return 0;
}

int main(){
    
}
