#include <stdio.h>
#include <string.h>
#include "logic.h"

char note_list[20][100] = {"empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty",
"empty", "empty"};
FILE *notes;
char loop = 1;
char read_line = 1;

void add_note(int line, char note[100]) {
    strcpy(note_list[line - 1], note);
    write_file();
}

void show_notes() {
    for(int i = 0; i < 20; i++) {
        printf("%d. %s\n", i + 1, note_list[i]);
    }
}

void delete_note(int line) {
    add_note(line, "empty");
}

void read_file() {
    read_line = 1;
    notes = fopen("notes.txt", "r");
    while(read_line <= 20 && fgets(note_list[read_line - 1], sizeof(note_list[0]), notes) != NULL) {
    note_list[read_line - 1][strcspn(note_list[read_line - 1], "\n")] = '\0';
    read_line++;
    }
    fclose(notes);
}

void write_file() {
    notes = fopen("notes.txt", "w");
    for(int i = 0; i < 20; i++) {
        fprintf(notes, "%s\n", note_list[i]);
    }
    fclose(notes);
}

void check(char choose[6]) {
    if(strcmp(choose, "add") == 0) {
        int line;
        char note[100];
        printf("\nEnter the line of note: ");
        scanf("%d", &line);
        printf("\nEnter your note in the line %d: ", line);
        getchar();
        fgets(note, sizeof(note), stdin);
        note[strcspn(note, "\n")] = 0;
        if(line <= 20 && line >= 1 && strlen(note) >= 1 && strlen(note) <= 100) {
            add_note(line, note);
        } else {
            printf("\nThe line can't bigger than 20 or smaller than 1 and note length can't smaller than 1 or bigger than 100\n");
        }
    } else if(strcmp(choose, "show") == 0) {
        show_notes();
    } else if(strcmp(choose, "delete") == 0) {
        int line;
        printf("Enter the line of note: ");
        scanf("%d", &line);
        if(line >= 1 && line <= 20) {
            delete_note(line);
            write_file();
        } else {
            printf("\nLine can't smaller than 1 or bigger than 20\n");
        }
    } else if(strcmp(choose, "exit") == 0) {
        exit_program();
    } else {
        printf("\nThe choose can be: add, show, delete or exit\n");
    }
}

void exit_program() {
    write_file();
    if(notes != NULL) {
    fclose(notes);
    }
    loop = 0;
}
