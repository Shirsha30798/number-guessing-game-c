#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

#define MIN_LIMIT 1
#define MAX_LIMIT 100

typedef char String[16];

int main() {

    int userGuess = 0;
    int randomNumber = 0;
    int attemptCount = 0;
    String str = {0};
    char *endptr = NULL;

    srand(time(NULL));

    randomNumber = rand() % (MAX_LIMIT - MIN_LIMIT + 1) + MIN_LIMIT;

    printf("\n*************** GUESS THE SECRET NUMBER ***************\n");


    while (1) {


        if(attemptCount == 0) {
            printf("\nEnter a number b/w (%d-%d) you think is the secret number or enter 'Q' to quit : ", MIN_LIMIT, MAX_LIMIT);
        } else {

            printf("\nAttempt to guess again btw (%d-%d) or enter 'Q' to Quit and be called a loser : ", MIN_LIMIT, MAX_LIMIT);
        
        }

        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        if (toupper(str[0]) == 'Q' && strlen(str) == 1) {

            printf("\nQutting the game....\n");

            break;

        }

        userGuess = strtol(str, &endptr, 10);

        if (str == endptr || (*endptr != '\0')) {
                
            printf("\nPlease enter a valid input\n");
                
            continue;
        
        }

        if (userGuess > randomNumber) {

            printf("\nToo high..\n");

        } else if (userGuess < randomNumber) {

            printf("\nToo low..\n");

        } else if(userGuess == randomNumber) {

            printf("\nCorrect!!\nAttempts : %d\n\n", attemptCount);

            break;

        }

        attemptCount ++;

    }

    return 0;

}
