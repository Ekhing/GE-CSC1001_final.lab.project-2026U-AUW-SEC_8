#include <stdio.h>
#include <string.h>

#define SIZE 5

char name[SIZE][20];
int magic[SIZE];
char house[SIZE][20];

void addStudents()
{
    int i,choice,choice2;
    for(i=0;i<SIZE;i++)
    {
        int score=0;
        printf("\nStudent %d Name: ",i+1);
        scanf("%s",name[i]);

        printf("\nA.What would you do if your friend is in danger?\n");
        printf("1.Save them\n");
        printf("2.Think of a clever plan\n");
        printf("3.Ask for help\n");
        printf("4.Walk away\n");
        printf("Choice: ");
        scanf("%d",&choice);
        if(choice==1)
            score+=45;
        else if(choice==2)
            score+=35;
        else if(choice==3)
            score+=40;
        else
            score+=50;
        printf("\nA.What is your greatest personality trait?\n");
        printf("1.Bravery\n");
        printf("2.Intelligence\n");
        printf("3.Loyalty\n");
        printf("4.Ambition\n");
        printf("2nd Choice: ");
        scanf("%d",&choice);
        if(choice==1)
            score+=20;
        else if(choice==2)
            score+=15;
        else if(choice==3)
            score+=25;
        else
            score+=35;
        magic[i]=score;

        if(magic[i]>=80)
            strcpy(house[i],"Gryffindor");
        else if(magic[i]>=60)
            strcpy(house[i],"Ravenclaw");
        else if(magic[i]>=40)
            strcpy(house[i],"Hufflepuff");
        else
            strcpy(house[i],"Slytherin");
    }
}

void display()
{
    int i;
    printf("\nName Score House\n");
    for(i=0;i<SIZE;i++)
        printf("%s | %d | %s\n",name[i],magic[i],house[i]);
}

void search()
{
    char s[20];
    int i,found=0;

    printf("Enter Student Name: ");
    scanf("%s",s);

    for(i=0;i<SIZE;i++)
    {
        if(strcmp(s,name[i])==0)
        {
            printf("%s | Score: %d | House: %s\n",name[i],magic[i],house[i]);
            found=1;
        }
    }

    if(found==0)
        printf("Student Not Found!\n");
}

void topWizard()
{
    int i,max=0;
    for(i=1;i<SIZE;i++)
        if(magic[i]>magic[max])
            max=i;

    printf("\nTop Wizard: %s\n",name[max]);
    printf("Magic Score: %d\n",magic[max]);
}

int main()
{
    int select=0;

    while(select!=5)
    {
        printf("\n HOGWARTS SORTING SYSTEM \n");
        printf("1. Add Students\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Top Wizard\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d",&select);

        if(select==1)
            addStudents();
        else if(select==2)
            display();
        else if(select==3)
            search();
        else if(select==4)
            topWizard();
        else if(select==5)
            printf("Have fun at Hogwarts!\n");
        else
            printf("Invalid Choice!\n");
    }

    return 0;
}

