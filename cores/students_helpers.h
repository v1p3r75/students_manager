/**
 * Students Manager Program
 * Author : Elfried Fortunatus KIDJE (https://github.com/v1p3r75)
 * Licence : MIT
 * Date : 2023-02-21
 * Source : https://github.com/v1p3r75/students_manager
*/

#include <stdio.h>

void symbole (int nb, char symbol[5]) {
    printf("\n");
    for (int st = 0; st < nb; st++) {
        printf(symbol);
    }
    printf("\n");
}

void colorText(char text[200], int color) {

    char colorCode[12][5] = {"0;30", "1;30", "0;31", "1;31", "0;32", "1;34", "0;35", "1;35", "1;36", "0;37", "1;37"};
    printf("\e[%sm%s\e[0m", colorCode[color], text);
		
}

void showBanner() {

    printf("\n\e[0;32m");
    printf("\n\t\t╭╮╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╭━━━╮\n");
    printf("\t\t┃┃╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃╭━╮┃\n");
    printf("\t\t┃┃╱╱╭━━┳━╮╭━━┳━━┳━━┳━━╮┃┃╱╰╯\n");
    printf("\t\t┃┃╱╭┫╭╮┃╭╮┫╭╮┃╭╮┃╭╮┃┃━┫┃┃╱╭╮\n");
    printf("\t\t┃╰━╯┃╭╮┃┃┃┃╰╯┃╭╮┃╰╯┃┃━┫┃╰━╯┃\n");
    printf("\t\t╰━━━┻╯╰┻╯╰┻━╮┣╯╰┻━╮┣━━╯╰━━━╯\n");
    printf("\t\t╱╱╱╱╱╱╱╱╱╱╭━╯┃╱╱╭━╯┃\n");
    printf("\t\t╱╱╱╱╱╱╱╱╱╱╰━━╯╱╱╰━━╯By : Fortunatus EK\n");
    // printf("\t\t\t██╗░░░░░░█████╗░███╗░░██╗░██████╗░░█████╗░░██████╗░███████╗  ░█████╗░\n");
    // printf("\t\t\t██║░░░░░██╔══██╗████╗░██║██╔════╝░██╔══██╗██╔════╝░██╔════╝  ██╔══██╗\n");
    // printf("\t\t\t██║░░░░░███████║██╔██╗██║██║░░██╗░███████║██║░░██╗░█████╗░░  ██║░░╚═╝\n");
    // printf("\t\t\t██║░░░░░██╔══██║██║╚████║██║░░╚██╗██╔══██║██║░░╚██╗██╔══╝░░  ██║░░██╗\n");
    // printf("\t\t\t███████╗██║░░██║██║░╚███║╚██████╔╝██║░░██║╚██████╔╝███████╗  ╚█████╔╝\n");
    // printf("\t\t\t╚══════╝╚═╝░░╚═╝╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ░╚════╝░\n\t\t\t\tAuthor : Fortunatus EK\t\tContact : +22996457545\n\n");
    printf("\e[0m\n");
}