/**
 * Students Manager Program (HomeWork)
 * Author : Elfried Fortunatus KIDJE (https://github.com/v1p3r75)
 * Licence : MIT
 * Date : 2023-02-21
 * Source & Documentation : https://github.com/v1p3r75/students_manager
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_STUDENTS 100
#define NB_SUBJECTS 5
#define NB_SUBJECT_NOTE 2
char CHOICE_MESSAGE[200] = "Qu'est-ce que vous voulez faire ? \n 1 - Enregistrer des etudiants \n 2 - Rechercher un etudiant \n 3 - Affichage de Bulletin  \n 4 - Startistique de la classe \n 0 - Pour Quitter \n -> ";
char subjects[NB_SUBJECTS][15] = {"Matrice ", "Database", "Dev Web ", "Francais","LangageC"};
int nb_total_students;

typedef struct
{
    char lastname[30];
    char firstname[30];
    float subject[NB_SUBJECTS][NB_SUBJECT_NOTE];
    float moyenneBySubject[NB_SUBJECTS];
    float moyTotal;
    char mention[20];

} StudentType;

StudentType allStudents[TOTAL_STUDENTS];

StudentType setMention(StudentType student);

char * getSubject(int subject);

void saveStudents();

void symbole(int nb, char symbol[5]);

StudentType fillStudentAttributes(StudentType);

int writeResultInFile();

void searchStudent();

void printStudents();

void showStat();

int sortArray();

float getStat(int type);

void colorText(char text[200], int color);

int main()

{
    int choice;

    system("clear");

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
    char mention[20];

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
        printf("Erreur rencontree lors de l'enregistrement de l'etudiant dans le fichier");
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
    symbole(15, "--"), 3;
    printf("\n Nombre Total d etudiants : %d \n Plus forte moyenne : %.2f\n Plus faible moyenne : %.2f\n", nb_total_students, getStat(2), getStat(1));
    symbole(15, "--");
    printf("\e[0m");

}

void symbole (int nb, char symbol[5]) {
    printf("\n");
    for (int st = 0; st < nb; st++) {
        printf(symbol);
    }
    printf("\n");
}

void colorText(char text[200], int color) {
    char colorCode[12][5] = {"0;30", "1;30", "0;31", "1;31", "0;32", "1;34", "0;35", "1;35", "1;36", "0;37", "1;37"};
    char bgCode[8][2] = {"40", "41", "42", "43", "44", "45", "46", "47"};

    printf("\e[%sm%s\e[0m", colorCode[color], text);
		
		// return !bg ? "\e[".$colorCode[$color]."m". $text ."\e[0m" : "\e[".$colorCode[$color].";". $bgCode[$bg] . "m" . $text ."\e[0m";
}