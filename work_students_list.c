#include <errno.h>
#include "work_students_list.h"

void* get_student(void*);
void add_to_the_begin(void*);
void add_to_the_end(void*);
void insert(void*);
void swap(void*);
void pop(void*);
void print_list(void*);
void save (void*);
void load(void*);

void swap(void* temp_students){
    struct Moving_and_output* students = temp_students;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    if(students->a >= students->b) return;
    struct Student* first;
    struct Student* second;
    struct Student* temp_first;
    struct Student* temp_second;

    struct Get_students* arguments_get_student_one = malloc(sizeof(struct Get_students));
    arguments_get_student_one->list = students->list;
    arguments_get_student_one->n = students->a;

    struct Get_students* arguments_get_student_two = malloc(sizeof(struct Get_students));
    arguments_get_student_two->list = students->list;
    arguments_get_student_two->n = students->b;

    first = get_student(arguments_get_student_one);
    second = get_student(arguments_get_student_two);

    arguments_get_student_one->n = arguments_get_student_one->n - 1;
    arguments_get_student_two->n = arguments_get_student_two->n - 1;

    if(students->a != 1) temp_first = get_student(arguments_get_student_one);
    temp_second = get_student(arguments_get_student_two);

    if(students->a != 1) temp_first->next = second;
    temp_second->next = first;

    temp_first = first->next;

    first->next = second->next;
    second->next = temp_first;

    if(students->a == 1) students->list->head = second;
    if(students->b == students->list->size) students->list->end = first;

}

void pop(void* temp_students){

    struct Moving_and_output* students = temp_students;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    struct Student* temp;
    struct Student* temp_next;

    struct Get_students* arguments_get_student = malloc(sizeof(struct Get_students));

    if (errno == 12){
        perror("");
        exit(errno);
    }

    arguments_get_student->list = students->list;
    arguments_get_student->n = students->n;

    temp = get_student((void*)arguments_get_student);

    arguments_get_student->n = arguments_get_student->n - 1;
    ((struct Student*)get_student((void*)arguments_get_student))->next = temp->next;

    if(students->n == 1){
        students->list->head = temp->next;
    }else if(students->n == students->list->size) students->list->end = get_student((void*)arguments_get_student);

    free(temp);

    students->list->size -= 1;

}


void insert(void* temp_data_students){

    FILE *file = fopen("students.txt", "a+");

    struct Student* temp = malloc(sizeof(struct Student));

    if (errno == 12){
        perror("");
        exit(errno);
    }

    struct Data_students* data_students = temp_data_students;
    struct Student* temp_first;

    struct Get_students* arguments_get_student = malloc(sizeof(struct Get_students));

    if (errno == 12){
        perror("");
        exit(errno);
    }

    arguments_get_student->list = data_students->list;
    arguments_get_student->n = data_students->n;

    if(data_students->n == 1 || (data_students->n+1) == data_students->list->size)return;

    temp->next = data_students->list->get_student(arguments_get_student);

    arguments_get_student->n = arguments_get_student->n - 1;

    temp_first = data_students->list->get_student(arguments_get_student);
    temp_first->next = temp;

    strcpy(temp->first_name, data_students->first_name);
    temp->age = data_students->age;

    if (data_students->save_file == 1){
        fprintf(file,"%s %s %s %i %i %i %i %i\n",
                data_students->list->head->last_name, data_students->list->head->first_name,
                data_students->list->head->group, data_students->list->head->age,
                data_students->list->head->sex, data_students->list->head->math_score,
                data_students->list->head->physics_score, data_students->list->head->chemistry_score);
    }

    fclose(file);

    data_students->list->size += 1;

}

void* init_list(){

    struct List* list = malloc(sizeof(struct List));

    if (errno == 12){
        perror("");
        exit(errno);
    }

    list->get_student = get_student;
    list->add_to_the_begin = add_to_the_begin;
    list->add_to_the_end = add_to_the_end;
    list->insert = insert;
    list->swap = swap;
    list->pop = pop;
    list->save = save;
    list->load = load;

    return list;

}

void add_to_the_begin(void* temp_data_students){

    struct Student* temp = malloc(sizeof(struct Student));

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
        data_students->list->end = temp;
        data_students->list->head = temp;
    }else{
        temp->next = data_students->list->head;
        data_students->list->head = temp;
    }

    strcpy(data_students->list->head->last_name, data_students->last_name);
    strcpy(data_students->list->head->first_name, data_students->first_name);
    strcpy(data_students->list->head->group, data_students->group);
    data_students->list->head->age = data_students->age;
    data_students->list->head->sex = data_students->sex;
    data_students->list->head->math_score = data_students->math_score;
    data_students->list->head->physics_score = data_students->physics_score;
    data_students->list->head->chemistry_score = data_students->chemistry_score;

    data_students->list->size += 1;
}

void add_to_the_end(void* temp_data_students){

    struct Student* temp = malloc(sizeof(struct Student));

    if (errno == 12){
        perror("");
        exit(errno);
    }

    struct Data_students* data_students = temp_data_students;

    if(data_students->list->size == 0){
        data_students->list->end = temp;
        data_students->list->head = temp;
    }else{
        data_students->list->end->next = temp;
        data_students->list->end = temp;
    }

    strcpy(data_students->list->end->last_name, data_students->last_name);
    strcpy(data_students->list->end->first_name, data_students->first_name);
    strcpy(data_students->list->end->group, data_students->group);
    data_students->list->end->age = data_students->age;
    data_students->list->end->sex = data_students->sex;
    data_students->list->end->math_score = data_students->math_score;
    data_students->list->end->physics_score = data_students->physics_score;
    data_students->list->end->chemistry_score = data_students->chemistry_score;

    data_students->list->size += 1;

}

void print_list(void* temp_students){

    struct Moving_and_output* students = temp_students;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    struct Student* temp = students->list->head;

    for(int i = 1; i <= students->list->size; i++){
        fwrite(temp->last_name,sizeof(char)*20,1,students->file);
        fwrite(temp->first_name,sizeof(char)*20,1,students->file);
        fwrite(temp->group,sizeof(char)*14,1,students->file);
        fwrite(&temp->age,sizeof(int),1,students->file);
        fwrite(&temp->sex,sizeof(int),1,students->file);
        fwrite(&temp->math_score,sizeof(int),1,students->file);
        fwrite(&temp->physics_score,sizeof(int),1,students->file);
        fwrite(&temp->chemistry_score,sizeof(int),1,students->file);
        temp = temp->next;
    }
}

void save(void* temp_data_student){

    FILE *file = fopen("students.txt", "wb");

    struct Moving_and_output* students = temp_data_student;

    if (errno == 12){
        perror("");
        exit(errno);
    }

    students->file = file;

    if (file) {
        print_list(students);
    }
    else {
        perror("");
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

    if (file) {
        while (!feof(file)){

            struct Student* temp = malloc(sizeof(struct Student));

            if(students->list->size == 0){
                students->list->end = temp;
                students->list->head = temp;
            }else{
                temp->next = students->list->head;
                students->list->head = temp;
            }

            fread(temp->last_name,sizeof(char)*20,1,file);
            fread(temp->first_name,sizeof(char)*20,1,file);
            fread(temp->group,sizeof(char)*14,1,file);
            fread(&temp->age,sizeof(int),1,file);
            fread(&temp->sex,sizeof(int),1,file);
            fread(&temp->math_score,sizeof(int),1,file);
            fread(&temp->physics_score,sizeof(int),1,file);
            fread(&temp->chemistry_score,sizeof(int),1,file);

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

    struct Student* temp_students;

    temp_students = student->list->head;

    for(int i=1;i<student->n;i++)
        temp_students = temp_students->next;

    return temp_students;

}