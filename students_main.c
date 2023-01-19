/**
 * Students Manager Program (HomeWork)
 * Author : Elfried Fortunatus KIDJE (https://github.com/v1p3r75)
 * Licence : MIT
 * Date : 2023-02-21
 * Source & Documentation : https://github.com/v1p3r75/students_manager
*/

#include <stdio.h>
#include <stdlib.h>

#include "./cores/students_functions.h"

int main()

{
    int choice;

    system("cls");
    showBanner();

     do {

        printf("%s", CHOICE_MESSAGE);
        scanf("%d", &choice);

        switch (choice)
        {

            case 1: saveStudents(); break;

            case 2: searchStudent(); break;

            case 3: printStudents(); break;

            case 4: showStat(); break;
            
            default: break;
        }

    }while (choice != 0);
    
    return 0;
}