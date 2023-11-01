#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "safeinput.h"
#include "studentregister.h"

// Struct, declaring a Student.
typedef struct {
        int BirthYear;
        char FirstName [50];
        char LastName [50];
        char City [50];
    } Student;

// Getting input from the user.
void InputStudent (Student *p) {
printf("\t\nNew Student\n");
printf("First name: ");
scanf(" %s", p->FirstName);
printf("Last name: ");
scanf(" %s", p->LastName);
printf("City: ");
scanf(" %s", p->City);
printf("Birthyear: ");
scanf("%d", &p->BirthYear);
}

// Const makes the function Read-Only. Will not modify any data.
void PrintStudent (const Student *p) {
printf("Name: %s %s\n", p->FirstName, p->LastName);
printf("City: %s \nBirthyear: %d\n", p->City, p->BirthYear);
}

void StudentRegister(){
    
    int numStudents;
    printf("How many students would you like to add?\n");
    printf("Enter: ");
    scanf(" %d", &numStudents);
    Student studentList[numStudents];
    
    printf("\t\n--- INPUT ---\n");
    for (int i = 0; i < numStudents; i++){
        InputStudent(&studentList[i]);
    }

    // Getting the oldest student in the list.
    Student *oldestStudent = &studentList[0];
    for (int i = 0; i < numStudents; i++){
        if(studentList[i].BirthYear < oldestStudent->BirthYear){
            oldestStudent = &studentList[i];
        }
    }

    // Printing out every single student in the list.
    printf("\n\t--- PRINTOUT --- \n");
    for (int i = 0; i < numStudents; i++){
    printf("\t\nStudent nr %d: \n", i+1);
    PrintStudent(&studentList[i]);
    }
    
    // Printing out the oldest student.
    printf("\nThe oldest student right now: \n");
    PrintStudent(oldestStudent);
}