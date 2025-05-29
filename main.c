#include <stdio.h>
#include <string.h>
#include "logic.h"

int main() {
    read_file();
    char choose_of_user[6];
    while(loop) {
        printf("\nWhat do you want to do? (add, show, delete or exit)");
        scanf("%s", choose_of_user);
        check(choose_of_user);
    }
    return 0;
}
