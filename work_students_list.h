//
// Created by roman on 3/12/24.
//

#ifndef PRACTIC13_WORK_STUDENTS_LIST_H
#define PRACTIC13_WORK_STUDENTS_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define list_init init_list()
#define malloc_struct(name_struct) malloc(sizeof (struct name_struct))

void* init_list();

struct Student{
    char last_name[20];
    char first_name[20];
    int sex;
    int age;
    char group[14];
    int math_score;
    int physics_score;
    int chemistry_score;

};

struct Node{
    struct Student* student;
    struct Node* next;
};

struct List{
    int value;
    int size;
    struct Node* head;
    struct Node* end;
    void* (*get_student)(void*);
    void (*add_to_the_begin)(void*);
    void (*save)(void*);
    void (*load)(void*);
};

struct Get_students{
    struct List* list;
    int n;
};

struct Data_students{
    struct List* list;
    int n;
    char last_name[20];
    char first_name[20];
    int age;
    int sex;
    char group[14];
    int math_score;
    int physics_score;
    int chemistry_score;
};

struct Moving_and_output{
    struct List* list;
    FILE *file;
    int n;
    int a;
    int b;
};

#endif //PRACTIC13_WORK_STUDENTS_LIST_H
