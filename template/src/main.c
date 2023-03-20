
#include <stdio.h>
#include <string.h>

typedef struct
{
    int age;
    char name[10];
    char gender;
} person;


typedef struct
{
    char study;
    int size;

}group;

int main()
{
    person darius;
    person* arrow;
    arrow = &darius;
    darius.age = 2;
    strcpy (darius.name, "johny");
    printf("subject age = %d ,%s\n", arrow->age, arrow->name);

    group KH922ie;
    
    return 0;

}