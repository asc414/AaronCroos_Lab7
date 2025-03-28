//football.c
/*
Author: Aaron Croos
KUID: 3047275
Creation Date: 03/27/2025
Name: football
Purpose: Gives all possible combinations for a score in football
Colloborators: None
Other Sources: None
*/
#include <stdio.h>

void print_combos(int score) {
    for (int td_2pt = 0; td_2pt <= score / 8; td_2pt++) { //Increments touchdowns + 2pts by 1 per iteration
        for (int td_fg = 0; td_fg <= score / 7; td_fg++) { //Increments touchdowns + fg by 1 per iteration
            for (int td = 0; td <= score / 6; td++) { //Incrments touchdowns by 1 per iteration
                for (int fg = 0; fg <= score/3; fg++) { //Increments fieldgoals by 1 per iteration
                    for (int safety = 0; safety <= score/2; safety++) { //Increments safety by 1 per iteration
                        int points_left = score - (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2); //Calculates remaining score by multiplying all the scoring plays by how many points their worth and summing those values together
                        if (points_left == 0) { //Checks if there are 0 points left after summing the scores
                            printf("%d TD + 2pt,%d TD + FG,%d TD,%d 3pt FG,%d Safety\n", td_2pt, td_fg, td, fg, safety); //Prints the combination that results in points left of 0
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score; //Declares score integer
    while (1) { //Repeatedly asks user for an NFL score
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) { //terminates program if previous value entered is less than or equal to 1
            break;
        }
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        print_combos(score); //Prints all possible cominbations user provided score
    }

    return 0;
}