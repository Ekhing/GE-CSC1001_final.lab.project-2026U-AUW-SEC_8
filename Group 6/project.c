#include <stdio.h>
#include <string.h>

// Function Prototypes
int calculateScore(int mood, int stress, int sleep, int study);
void suggestions(int mood, int stress, int sleep, int study);

int main()
{
    char name[50];
    int id;
    int mood = 0, stress = 0;
    int sleep, study;
    int score;
    char choice;

      /* ============================= */
    /* FIRST PRESET STUDENT          */
    /* ============================= */

    strcpy(name, "Tuly");
    id = 242190;
    mood = 4;
    stress = 2;
    sleep = 7;
    study = 5;

    printf("\n=====================================\n");
    printf(" Student Mental Wellness Check-in\n");
    printf("=====================================\n");

    score = calculateScore(mood, stress, sleep, study);

    printf("\nStudent Name   : %s\n", name);
    printf("Student ID     : %d\n", id);
    printf("Mood           : %d\n", mood);
    printf("Stress Level   : %d\n", stress);
    printf("Sleep Hours    : %d\n", sleep);
    printf("Study Hours    : %d\n", study);
    printf("Wellness Score : %d\n", score);

    if(score >= 80)
    {
        printf("Status         : Excellent\n");
    }
    else if(score >= 60)
    {
        printf("Status         : Good\n");
    }
    else if(score >= 40)
    {
        printf("Status         : Fair\n");
    }
    else
    {
        printf("Status         : Needs Attention\n");
    }

    suggestions(mood, stress, sleep, study);


    /* ============================= */
    /* SECOND PRESET STUDENT          */
    /* ============================= */

    strcpy(name, "Ekhing");
    id = 242304;
    mood = 2;
    stress = 5;
    sleep = 5;
    study = 9;

    printf("\n=====================================\n");
    printf(" Student Mental Wellness Check-in\n");
    printf("=====================================\n");

    score = calculateScore(mood, stress, sleep, study);

    printf("\nStudent Name   : %s\n", name);
    printf("Student ID     : %d\n", id);
    printf("Mood           : %d\n", mood);
    printf("Stress Level   : %d\n", stress);
    printf("Sleep Hours    : %d\n", sleep);
    printf("Study Hours    : %d\n", study);
    printf("Wellness Score : %d\n", score);

    if(score >= 80)
    {
        printf("Status         : Excellent\n");
    }
    else if(score >= 60)
    {
        printf("Status         : Good\n");
    }
    else if(score >= 40)
    {
        printf("Status         : Fair\n");
    }
    else
    {
        printf("Status         : Needs Attention\n");
    }

    suggestions(mood, stress, sleep, study);


    /* ============================= */
    /* USER INPUT PART                */
    /* ============================= */

    while(1)
    {
        printf("\nWould you like to check another student? (Y/N): ");
        scanf(" %c", &choice);
        getchar();

        if(choice == 'N' || choice == 'n')
        {
            printf("\nThank you for using the Student Mental Wellness Check-in System!\n");
            break;
        }

        if(choice == 'Y' || choice == 'y')
        {
            printf("\n=====================================\n");
            printf(" Student Mental Wellness Check-in\n");
            printf("=====================================\n");

            printf("Enter Student Name: ");
            fgets(name, sizeof(name), stdin);

            if(name[strlen(name) - 1] == '\n')
            {
                name[strlen(name) - 1] = '\0';
            }

            printf("Enter Student ID: ");
            scanf("%d", &id);

            mood = 0;

            while(mood < 1 || mood > 5)
            {
                printf("Enter Mood (1-5): ");
                scanf("%d", &mood);

                if(mood < 1 || mood > 5)
                {
                    printf("Invalid input! Please enter a number between 1 and 5.\n");
                }
            }

            stress = 0;

            while(stress < 1 || stress > 5)
            {
                printf("Enter Stress Level (1-5): ");
                scanf("%d", &stress);

                if(stress < 1 || stress > 5)
                {
                    printf("Invalid input! Please enter a number between 1 and 5.\n");
                }
            }

            printf("Enter Sleep Hours: ");
            scanf("%d", &sleep);

            printf("Enter Study Hours: ");
            scanf("%d", &study);

            score = calculateScore(mood, stress, sleep, study);

            printf("\n========== RESULT ==========\n");
            printf("Student Name   : %s\n", name);
            printf("Student ID     : %d\n", id);
            printf("Mood           : %d\n", mood);
            printf("Stress Level   : %d\n", stress);
            printf("Sleep Hours    : %d\n", sleep);
            printf("Study Hours    : %d\n", study);
            printf("Wellness Score : %d\n", score);

            if(score >= 80)
            {
                printf("Status         : Excellent\n");
            }
            else if(score >= 60)
            {
                printf("Status         : Good\n");
            }
            else if(score >= 40)
            {
                printf("Status         : Fair\n");
            }
            else
            {
                printf("Status         : Needs Attention\n");
            }

            suggestions(mood, stress, sleep, study);
        }
    }

    return 0;
}


int calculateScore(int mood, int stress, int sleep, int study)
{
    int score = 100;

    if(mood <= 2)
    {
        score -= 20;
    }

    if(stress >= 4)
    {
        score -= 20;
    }

    if(sleep < 6)
    {
        score -= 20;
    }

    if(study > 8)
    {
        score -= 10;
    }

    if(score < 0)
    {
        score = 0;
    }

    return score;
}


void suggestions(int mood, int stress, int sleep, int study)
{
    printf("\nSuggestions:\n");

    if(mood <= 2)
    {
        printf("- Try doing something you enjoy.\n");
    }

    if(stress >= 4)
    {
        printf("- Take regular breaks while studying.\n");
    }

    if(sleep < 6)
    {
        printf("- Try to sleep at least 7-8 hours.\n");
    }

    if(study > 8)
    {
        printf("- Avoid studying continuously for long hours.\n");
    }

    if(mood > 2 && stress < 4 && sleep >= 6 && study <= 8)
    {
        printf("- Great! Keep maintaining your healthy routine.\n");
    }
}
