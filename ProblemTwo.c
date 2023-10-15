
#include <stdio.h>

void getComboes() {
    int options[100000][5];
    // touchdown + 1 = 7
    // fieldgoal     = 3
    // safety        = 2
    // touchdown + 2 = 8
    // touchdown + 0 = 6

    int score;
    while (1) {
        printf("Enter the score: ");
        scanf("%d", &score);
        
        if (score < 2) {
            printf("Invalid input. The score cannot be less than 2.\n");
            break;
        } 
        else {
            int count = 0;
            // touchdown+1, fieldgoal, safety, touch+2, touchdown+0
            for(int a = 0; a < score; a++){
                for(int b = 0; b < score; b++) {
                    for(int c = 0; c < score; c++){
                        for(int d = 0; d < score; d++){
                            for(int e = 0; e < score; e++){
                                if((7*a + 3*b  + 2*c + 8*d + 6*e ) == score){
                                    options[count][0] = a;
                                    options[count][1] = b;
                                    options[count][2] = c;
                                    options[count][3] = d;
                                    options[count][4] = e;
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
            // Print the valid combinations with scoring play names
            printf("All possible combinations that the score could be:\n");
            for (int i = 0; i < count; i++) {
                printf("%d 7pt Touchdown + %d Field Goal + %d Safety + %d 8pt Touchdown + %d 6pt Touchdown\n",
                       options[i][0], options[i][1], options[i][2],
                       options[i][3], options[i][4]);
            }
        }
    }
}

int main(){
    getComboes();
    return 1;
}