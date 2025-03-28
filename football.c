//football.c
#include <stdio.h>

void print_combos(int score) {
    for (int td_2pt = 0; td_2pt <= score / 8; td_2pt++) {
        for (int td_fg = 0; td_fg <= score / 7; td_fg++) {
            for (int td = 0; td <= score / 6; td++) {
                for (int fg = 0; fg <= score/3; fg++) {
                    for (int safety = 0; safety <= score/2; safety++) {
                        int remaining_score = score - (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2);
                        if (remaining_score == 0) {
                            printf("%d TD + 2pt,%d TD + FG,%d TD,%d 3pt FG,%d Safety\n", td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score = 0;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        print_combos(score);
    }

    return 0;
}