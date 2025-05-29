#ifndef LOGIC_H
#define LOGIC_H

extern char note_list[20][100];
extern FILE *notes;
extern char loop;

void add_note(int line, char note[100]);
void show_notes();
void delete_note(int line);
void read_file();
void write_file();
void check(char choose[6]);
void exit_program();

#endif