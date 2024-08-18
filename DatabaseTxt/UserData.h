#ifndef USERDATA_H
#define USERDATA_H
typedef struct{
    char name[256];
    char ID[256];
    char password[256];
}DataUser;
typedef enum{
    BY_ID = (1 << 0),
    BY_USER = (1 << 1)
}find_mode_flag;
#endif