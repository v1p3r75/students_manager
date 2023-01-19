/**
 * Students Manager Program
 * Author : Elfried Fortunatus KIDJE (https://github.com/v1p3r75)
 * Licence : MIT
 * Date : 2023-02-21
 * Source : https://github.com/v1p3r75/students_manager
*/

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

void symbole (int nb, char symbol[5]) {
    printf("\n");
    for (int st = 0; st < nb; st++) {
        printf(symbol);
    }
    printf("\n");
}

// void colorText(char color[10], char bg[10]) {
//     char colorCode[12][10] = {}
// 			'black' = '0;30',
// 			'darkGrey' = '1,30',
// 			'red' = '0;31',
// 			'lightRed' = '1;31',
// 			'green' = '0;32',
// 			'lightBle' = '1;34',
// 			'magenta' = '0;35',
// 			'lightMagenta' = '1;35',
// 			'cyan' = '0;36',
// 			'lightCyan' = '1;36',
// 			'lightGrey' = '0;37',
// 			'white' = '1;37',
// 		];
	
// 		$bgCode = [
// 			'black' = '40',
// 			'red' = '41',
// 			'green' = '42',
// 			'yellow' = '43',
// 			'blue' = '44',
// 			'magenta' = '45',
// 			'cyan' = '46',
// 			'lightCyan' = '47',
// 		];
		
// 		return !$bg ? "\e[".$colorCode[$color]."m". $text ."\e[0m" : "\e[".$colorCode[$color].";". $bgCode[$bg] . "m" . $text ."\e[0m";
// 	}
    
// }