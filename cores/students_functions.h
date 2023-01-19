/**
 * Students Manager Program
 * Author : Elfried Fortunatus KIDJE (https://github.com/v1p3r75)
 * Licence : MIT
 * Date : 2023-02-21
 * Source : https://github.com/v1p3r75/students_manager
*/
#include <stdio.h>
#include <string.h>
#include "students_declaration.h"
#include "students_helpers.h"

char * getSubject(int subject) {

    return subjects[subject];

}

void saveStudents() {

    printf(" Entrer le nombre total d'etudiants : ");
    scanf("%d", &nb_total_students);

    for (int student = 0; student < nb_total_students; student++){

        StudentType studentData;

        printf(" Entrer le nom et prenoms de l'etudiant n*%d : ", student + 1);
        scanf("%s %s", &studentData.lastname, &studentData.firstname);

        for (int subject = 0; subject < NB_SUBJECTS; subject++){

            for (int note = 0; note < NB_SUBJECT_NOTE; note++){

                printf("\n Entrer la note %d pour la matiere %s: ", note + 1, getSubject(subject));
                scanf("%f", &studentData.subject[subject][note]);
            }
        }
        
        studentData = fillStudentAttributes(studentData);

        allStudents[student] = studentData;

        
    }

    printf("\n \e[0;32mLa Moyenne la plus faible de classe est : %.2f et la plus forte est : %.2f\e[0m\n\n", getStat(1), getStat(2));
    
    writeResultInFile();


    
}

StudentType fillStudentAttributes(StudentType data) {

    float total = 0, moyTotal = 0;

    for (int i = 0; i < NB_SUBJECTS; i++) {
        float sum = 0, moySubject = 0;

        for (int j = 0; j < NB_SUBJECT_NOTE; j++) {
            sum += data.subject[i][j];
        }
        moySubject = sum / NB_SUBJECT_NOTE;
        data.moyenneBySubject[i] = moySubject;
        total += moySubject;
    }
    moyTotal = total / NB_SUBJECTS;

    data.moyTotal = moyTotal;
    
    data = setMention(data);

    return data; 
}


StudentType setMention(StudentType student) {

    float moyenne = student.moyTotal;

    if(moyenne < 3) strcpy(student.mention, "Nul");
    else if (moyenne >= 3 && moyenne <= 6) strcpy(student.mention,  "Mediocre");
    else if (moyenne > 6 && moyenne < 10) strcpy(student.mention, "Insufisant");
    else if (moyenne >= 10 && moyenne < 12) strcpy(student.mention, "Passable");
    else if (moyenne >= 12  && moyenne < 14) strcpy(student.mention, "Assez Bien");
    else if (moyenne >= 14  && moyenne < 16) strcpy(student.mention, "Bien");
    else if (moyenne >= 16  && moyenne < 18) strcpy(student.mention, "Tres Bien");
    else if (moyenne >= 18  && moyenne <= 20) strcpy(student.mention, "Excellent");

    return student;

}


void searchStudent() {
    char searchName[30]; int result = 0;

    printf(" Entrer seulement le nom de l'etudiant : ");
    scanf("%s", &searchName);


    for (int z = 0; z < nb_total_students; z++)
    {
        if(strcmp(allStudents[z].lastname, searchName) == 0) {
            
            printf("\e[0;32m");
            symbole(30, "o");
            printf("\n Nom : %s \n Prenom : %s\n Matieres : ", allStudents[z].lastname, allStudents[z].firstname);
            for(int matiere = 0; matiere < NB_SUBJECTS; matiere++) {
                printf("\n\t+ %s : ", getSubject(matiere));
                for(int note = 0; note < NB_SUBJECT_NOTE; note ++) {
                    printf("%.2f ", allStudents[z].subject[matiere][note]);
                }
                printf("\tMoy : %.2f", allStudents[z].moyenneBySubject[matiere]);
                
            }
            symbole(15, "--");
            printf("\n\nMoyenne Generale : %.2f \t Rang : %d \n\n", allStudents[z].moyTotal, 1);
            symbole(30, "o");
            printf("\e[0m");

            result = 1;
            break;
        }

    }

    result ? 0 : colorText("\nCe nom n'existe pas dans la base de donnees !\n\n", 2);


}


int writeResultInFile () {

    FILE *file = fopen("./data/students_informations.txt", "w");

    if(file == NULL) {
        colorText("Erreur rencontree lors de l'enregistrement de l'etudiant dans le fichier \n", 2);
    }

    sortArray();


    for (int student = 0; student < nb_total_students; student++) {

        fprintf(file, "%s %s ", allStudents[student].lastname, allStudents[student].firstname);

        for(int matiere = 0; matiere < NB_SUBJECTS; matiere++) {

            for( int note = 0; note < NB_SUBJECT_NOTE; note++) {
                fprintf(file, "%.2f:", allStudents[student].subject[matiere][note]);
            }
            fprintf(file, "%.2f ", allStudents[student].moyenneBySubject[matiere]);
        }


        fprintf(file, "%.2f %s\n", allStudents[student].moyTotal, allStudents[student].mention);
    } 
    
    fclose(file);
    
    return 0;

}

float getStat(int type) {

    float lowerMoy = allStudents[0].moyTotal, supMoy = allStudents[0].moyTotal;
    
    switch (type) {
        
        case 1:
            for (int std = 0; std < nb_total_students; std++) {
                if(allStudents[std].moyTotal < lowerMoy) {
                    lowerMoy = allStudents[std].moyTotal ;
                }
            }

            return lowerMoy;
            break;

        case 2: 
            for (int std = 0; std < nb_total_students; std++) {
                if(allStudents[std].moyTotal > supMoy) {
                    supMoy = allStudents[std].moyTotal ;
                }
            }

            return supMoy;
            break;

        default: break;
    }

    return 0;

}

void printStudents() {
    
    char searchName[30]; int result = 0;
    printf("Entrer seulement le nom de l'etudiant : ");
    scanf("%s", &searchName);


    for (int z = 0; z < nb_total_students; z++)
    {

        if(strcmp(allStudents[z].lastname, searchName) == 0) {

            printf("\e[0;32m");
            symbole(66, "o");
            printf("o\t\t\t BULLETIN DE NOTES !");
            symbole(66, "o");
            printf("\no Nom : %s \no Prenom : %s\n", allStudents[z].lastname, allStudents[z].firstname);
            printf("o Matricule : 12412923\t\t\t\tAnnee : 22-23\n");
            printf("o Licence : 1\t\t\t\t\tSemestre: 1");
            symbole(33, "--");
            printf("o Matieres : \n");
            for(int matiere = 0; matiere < NB_SUBJECTS; matiere++) {
                printf("\no  %s : ", getSubject(matiere));
                for(int note = 0; note < NB_SUBJECT_NOTE; note ++) {
                    printf("%.2f\t", allStudents[z].subject[matiere][note]);
                }

                printf("\tMoy : %.2f\n", allStudents[z].moyenneBySubject[matiere]);
                
            }
            symbole(33, "--");
            printf("\no Moyenne Generale : %.2f \no Rang : %d \n", allStudents[z].moyTotal, 1);
            printf("o Mention : %s \t\t\t\tDecision : %s\n", allStudents[z].mention, allStudents[z].moyTotal < 10 ? "Redouble" : "Admis(e)");
            symbole(66, "o");
            printf("\e[0m");
            result = 1;
            break;
        }

    }

    result ? 0 : colorText("\nCe nom n'existe pas dans la base de donnees !\n\n", 2);
}


int sortArray() {

    for (int current_student = 0; current_student < nb_total_students; current_student++) {
        
        for (int next_student = current_student + 1; next_student < nb_total_students; next_student++) {
            
            if (strcmp(allStudents[current_student].lastname, allStudents[next_student].lastname) > 0) {

                StudentType tempStudents = allStudents[current_student];
                allStudents[current_student] = allStudents[next_student];
                allStudents[next_student] = tempStudents;
            }
        }
    }

    return 0;
}

void showStat() {

    printf("\e[0;32m");
    symbole(15, "--");
    printf("\n Nombre Total d etudiants : %d \n Plus forte moyenne : %.2f\n Plus faible moyenne : %.2f\n", nb_total_students, getStat(2), getStat(1));
    symbole(15, "--");
    printf("\e[0m");

}