/**
 * Students Manager Program
 * Author : Elfried Fortunatus KIDJE (https://github.com/v1p3r75)
 * Licence : MIT
 * Date : 2023-02-21
 * Source : https://github.com/v1p3r75/students_manager
*/

#define TOTAL_STUDENTS 100
#define NB_SUBJECTS 5
#define NB_SUBJECT_NOTE 2
char CHOICE_MESSAGE[200] = "\n\nQu'est-ce que vous voulez faire ? \n 1 - Enregistrer des etudiants \n 2 - Rechercher un etudiant \n 3 - Affichage de Bulletin  \n 4 - Startistique de la classe \n 0 - Pour Quitter \n -> ";
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
    int range;

} StudentType;

StudentType allStudents[TOTAL_STUDENTS];

StudentType setMention(StudentType student);

char * getSubject(int subject);

void saveStudents();

void symbole(int nb, char symbol[5]);

StudentType fillStudentAttributes(StudentType);

int writeResultInFile();

void searchStudent();

void setRange();

void printStudents();

void showStat();

int sortArray();

float getStat(int type);

void colorText(char text[200], int color);

void showBanner();