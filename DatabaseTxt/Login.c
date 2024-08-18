#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Login.h"
#include"DataBase.h"


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

