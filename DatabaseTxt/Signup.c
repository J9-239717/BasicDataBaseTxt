#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Signup.h"
#include"DataBase.h"

int _Signup(){
    DataUser user = show_detail_and_get_data();
    _listen(user);
    return 1;
}
