#include <errno.h>
#include "work_students_list.h"

void* get_student(void*);
void add_to_the_begin(void*);
void save (void*);
void load(void*);

void* init_list(){

    struct List* list = malloc(sizeof(struct List));

    if (errno == 12){
        perror("");
        exit(errno);
    }

    list->get_student = get_student;
    list->add_to_the_begin = add_to_the_begin;
    list->save = save;
    list->load = load;

    return list;

}

void add_to_the_begin(void* temp_data_students){

    struct Node* temp_node = malloc(sizeof(struct Node));
    temp_node->student = malloc(sizeof (struct Student));

    if (errno == 12){
        perror("");
        exit(errno);
    }

    struct Data_students* data_students = temp_data_students;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    if(data_students->list->size == 0){
        data_students->list->end = temp_node;
        data_students->list->head = temp_node;
    }else{
        temp_node->next = data_students->list->head;
        data_students->list->head = temp_node;
    }

    strcpy(data_students->list->head->student->last_name, data_students->last_name);
    strcpy(data_students->list->head->student->first_name, data_students->first_name);
    strcpy(data_students->list->head->student->group, data_students->group);
    data_students->list->head->student->age = data_students->age;
    data_students->list->head->student->sex = data_students->sex;
    data_students->list->head->student->math_score = data_students->math_score;
    data_students->list->head->student->physics_score = data_students->physics_score;
    data_students->list->head->student->chemistry_score = data_students->chemistry_score;

    data_students->list->size += 1;
}

void save(void* temp_data_student){

    FILE *file = fopen("students.txt", "wb");

    struct Moving_and_output* first_node = temp_data_student;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    struct Node* temp = first_node->list->head;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    for(int i = 1; i <= first_node->list->size; i++){
        fwrite(temp->student->last_name,sizeof(char)*20,1,file);
        fwrite(temp->student->first_name,sizeof(char)*20,1,file);
        fwrite(temp->student->group,sizeof(char)*14,1,file);
        fwrite(&temp->student->age,sizeof(int),1,file);
        fwrite(&temp->student->sex,sizeof(int),1,file);
        fwrite(&temp->student->math_score,sizeof(int),1,file);
        fwrite(&temp->student->physics_score,sizeof(int),1,file);
        fwrite(&temp->student->chemistry_score,sizeof(int),1,file);
        temp = temp->next;
    }

    fclose(file);

}

void load(void* Moving_and_output){

    FILE *file = fopen("students.txt", "rb");

    struct Moving_and_output* students = Moving_and_output;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    if (file != NULL) {
        while (!feof(file)){

            struct Node* temp = malloc(sizeof(struct Node));
            temp->student = malloc(sizeof (struct Student));

            if(students->list->size == 0){
                students->list->end = temp;
                students->list->head = temp;
            }else{
                temp->next = students->list->head;
                students->list->head = temp;
            }

            fread(temp->student->last_name,sizeof(char)*20,1,file);
            fread(temp->student->first_name,sizeof(char)*20,1,file);
            fread(temp->student->group,sizeof(char)*14,1,file);
            fread(&temp->student->age,sizeof(int),1,file);
            fread(&temp->student->sex,sizeof(int),1,file);
            fread(&temp->student->math_score,sizeof(int),1,file);
            fread(&temp->student->physics_score,sizeof(int),1,file);
            fread(&temp->student->chemistry_score,sizeof(int),1,file);

            students->list->size += 1;
        }
        fclose(file);
    }else {
        perror("");
        exit(errno);
    }
}

void* get_student(void* students){

    struct Get_students* student = students;

    struct Node* temp_students;

    temp_students = student->list->head;

    for(int i=1;i<student->n;i++)
        temp_students = temp_students->next;

    return temp_students;

}
