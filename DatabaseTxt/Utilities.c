#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utilities.h"

int get_input(char* prompt, char* buffer, size_t BUFFER_SIZE) {
    printf("%s", prompt);
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        if (buffer[0] == '\n') return 0;
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        return 1;
    }
    return 0;
}

DataUser show_detail_and_get_data() {
    DataUser data = {0};

    if (!get_input("Please Enter Name: ", data.name, 255)) {
        fprintf(stderr, "ERROR INPUT");
        exit(EXIT_FAILURE);
    }
    if (!get_input("Please Enter ID: ", data.ID, 255)) {
        fprintf(stderr, "ERROR INPUT");
        exit(EXIT_FAILURE);
    }
    if (!get_input("Please Enter Password: ", data.password, 255)) {
        fprintf(stderr, "ERROR INPUT");
        exit(EXIT_FAILURE);
    }
    return data;
}
