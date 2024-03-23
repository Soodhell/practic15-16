/*

Русская версия:
(Дата создания:28.01.2024)
Этот код был написан с целью обучения работы со структурами.
Все вопросы или предложения писать на почту pleshakovroma13@gmail.com .
Код был запущен на ОС ArchLinux.
gcc version 13.2.1.
gcc <названия файла в котором сохранили код> -o <название файла(любое) которй получится в ходе компиляции>
(gcc main.c -o main команда в моем случае)

*/

/*

English version:
(Date of creation: 01/28/2024)
This code was written for the purpose of teaching how to work with structures.
Please write all questions or suggestions to pleshakovroma13@gmail.com.
The code was run on ArchLinux OS.
gcc version 13.2.1.
gcc <name of the file in which the code exists> -o <name of the file (any) that will be executed during compilation>
(gcc main.c -o main in my case)

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
 #include "work_students_list.h"

int main(){

    struct List* list = list_init;

    char first_name[5][20] = {
            "Роман",
            "Игорь",
            "Владимир",
            "Лиза",
            "Лена"
    };

    char last_name[5][20] = {
            "Плешаков",
            "Егоров",
            "Дмитриев",
            "Берушева",
            "Леновна"
    };

    char group[3][14] = {
            "ИСП-206",
            "ИСП-207",
            "ИСП-208"
    };

    struct Data_students* data_students = malloc_struct(Data_students);
    if (errno == 12){
        perror("");
        exit(errno);
    }
//
//    data_students->list = list;
//    strcpy(data_students->last_name, last_name[0]);
//    strcpy(data_students->first_name, first_name[0]);
//    data_students->age = 18;
//    data_students->sex = 1;
//    strcpy(data_students->group, group[0]);
//    data_students->math_score = 5;
//    data_students->physics_score = 5;
//    data_students->chemistry_score = 5;
//    data_students->save_file = 0;
//
//    list->add_to_the_begin(data_students);
//
//    strcpy(data_students->last_name, last_name[1]);
//    strcpy(data_students->first_name, first_name[1]);
//    data_students->age = 19;
//    data_students->sex = 1;
//    strcpy(data_students->group, group[1]);
//    data_students->math_score = 5;
//    data_students->physics_score = 2;
//    data_students->chemistry_score = 5;
//    data_students->save_file = 0;
//
//    list->add_to_the_begin(data_students);
//
//    strcpy(data_students->last_name, last_name[2]);
//    strcpy(data_students->first_name, first_name[2]);
//    data_students->age = 17;
//    data_students->sex = 1;
//    strcpy(data_students->group, group[2]);
//    data_students->math_score = 5;
//    data_students->physics_score = 5;
//    data_students->chemistry_score = 3;
//    data_students->save_file = 0;
//
//    list->add_to_the_begin(data_students);
//
//    strcpy(data_students->last_name, last_name[3]);
//    strcpy(data_students->first_name, first_name[3]);
//    data_students->age = 18;
//    data_students->sex = 0;
//    strcpy(data_students->group, group[0]);
//    data_students->math_score = 5;
//    data_students->physics_score = 4;
//    data_students->chemistry_score = 5;
//    data_students->save_file = 0;
//
//    list->add_to_the_begin(data_students);
//
//    strcpy(data_students->last_name, last_name[4]);
//    strcpy(data_students->first_name, first_name[4]);
//    data_students->age = 18;
//    data_students->sex = 0;
//    strcpy(data_students->group, group[1]);
//    data_students->math_score = 2;
//    data_students->physics_score = 3;
//    data_students->chemistry_score = 5;
//    data_students->save_file = 1;
//
//    list->add_to_the_begin(data_students);

    struct Moving_and_output* print_students = malloc_struct(Moving_and_output);

    if (errno == 12){
        perror("");
        exit(errno);
    }

    print_students->list = list;
//    list->save(print_students);
    list->load(print_students);

    struct Student* temp = list->head;

    printf("==============ЖЕНЩИНЫ ОТЛИЧНИЦЫ ПО ХИМИИ==============\n");

    for(int i = 1; i <= list->size; i++){
        //if(temp->sex == 0 && temp->chemistry_score == 5){
            printf("Your age is %d, your first_name is %s\n", temp->age, temp->first_name);
            printf("Your sex is %d, your last_name is %s\n", temp->sex, temp->last_name);
            printf("Your group is %s\n", temp->group);
            printf("Math: %d, physics: %d, chemistry: %d\n", temp->math_score, temp->physics_score, temp->chemistry_score);
            printf("=========================================");
            printf("\n");
        //}
        temp = temp->next;
    }
    return 0;
}

