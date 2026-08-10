#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 50

void playGame(int *score);
void displayPlayers(char names[][30], int scores[], int count);
void searchPlayer(char names[][30], int scores[], int count, char search[]);

int main()
{
    char players[MAX_PLAYERS][30];
    int scores[MAX_PLAYERS];
    int count = 0;
    int choice;
    char search[30];

    while(1)
    {
        printf("\n1. Play Game\n2. Display Players\n3. Search Player\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter player name: ");
                scanf("%s", players[count]);

                playGame(&scores[count]);
                count++;
                break;

            case 2:
                displayPlayers(players, scores, count);
                break;

            case 3:
                printf("Enter player name: ");
                scanf("%s", search);
                searchPlayer(players, scores, count, search);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

void playGame(int *score)
{
    int number = 50;
    int guess;
    int attempts = 5;

    *score = 50;

    while(attempts > 0)
    {
        printf("Enter guess: ");
        scanf("%d",&guess);

        if(guess == number)
        {
            printf("Correct!\n");
            return;
        }

        else if(guess < number)
            printf("Too Low\n");
        else
            printf("Too High\n");

        attempts--;
        *score -= 10;
    }

    *score = 0;
    printf("Game Over\n");
}
#include <stdio.h>

void displayPlayers(char names[][30], int scores[], int count)
{
    int i;

    printf("\nPlayer List\n");

    for(i=0; i<count; i++)
    {
        printf("%s  %d\n", names[i], scores[i]);
    }
}
#include <stdio.h>
#include <string.h>

void searchPlayer(char names[][30], int scores[], int count, char search[])
{
    int i;

    for(i=0; i<count; i++)
    {
        if(strcmp(names[i], search)==0)
        {
            printf("Player Found\n");
            printf("Name: %s\n", names[i]);
            printf("Score: %d\n", scores[i]);
            return;
        }
    }

    printf("Player Not Found\n");
}
