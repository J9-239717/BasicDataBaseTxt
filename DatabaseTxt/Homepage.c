#include<stdio.h>
#include "Login.h"
#include "Signup.h"

int main() {
    int Login_completed = 0;
    int op;
    while (1) {
        if (Login_completed) {
            // Homepage logic
            for(int i = 0; i < 100; i++)
                printf("BIG IS GAY\n");
            // Logout
            Login_completed = 0;
        } else {
            printf("Welcome to my program\n"
                   "Enter 1 to Login\n"
                   "Enter 2 to Signup\n"
                   "Enter 3 to End Program\n");
            printf("Please Enter: ");
            scanf("%d", &op);
            getchar();
            switch (op) {
                case 1:
                    if (_Login()) {
                        Login_completed = 1;
                    }
                    break;
                case 2:
                    if (_Signup()) {
                        printf("Signup Completed\n");
                    } else {
                        printf("Please Signup Again\n");
                    }
                    break;
                case 3:
                    printf("Exiting program.\n");
                    return 0;
                default:
                    printf("Please Enter a valid option.\n");
                    break;
            }
        }
    }
}
