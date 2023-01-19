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
const char CHOICE_MESSAGE[200] = "Qu'est-ce que vous voulez faire ? \n 1 - Enregistrer des etudiants \n 2 - Rechercher un etudiant \n 3 - Affichage de Bulletin  \n 4 - Startistique de la classe \n 0 - Pour Quitter \n -> ";
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

StudentType fillStudentAttributes(StudentType);

int writeResultInFile();

void searchStudent();

void printStudents();

void showStat();

int sortArray();

void symbole(int nb, char symbol[5]);

float getStat(int type);