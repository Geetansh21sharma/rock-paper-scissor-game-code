#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generaterandomnumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char char1, char char2)
{
    
    if (char1 == char2)
    {
        return -1;
    }

    else if ((char1 == 'r') && (char2 == 's')) 
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's')) // comp aur player dono ke jeetne ki condition likhi h .
    {
        return 0;
    }
    else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }
    else if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}
int main()
{

    int playerscore = 0, compscore = 0, temp;
    char playerchar, compchar;
    char dict[] = {'r', 'p', 's'};
    printf("welcome to the rock,paper,scissors.\n");
    for (int i = 0; i < 3; i++)
    {
    
        printf("player 1'st turn : \n");
        printf("choose 1 for Rock, 2 for Paper and 3 for Scissors.\n ");
        scanf("%d", &temp);
        getchar();
        playerchar = dict[temp - 1];
        printf("you choose : %c\n", playerchar);

        
        printf("computer's turn : \n");
        printf("choose 1 for Rock, 2 for Paper and 3 for Scissors.\n ");
        temp = generaterandomnumber(3) + 1;
        compchar = dict[temp - 1];
        printf("CPU choose : %c\n\n", compchar);

        
        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
            printf("CPU got it, you loses this time!\n\n");
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf("its a draw!\n\n");
        }
        else
        {
            playerscore += 1;
            printf("you got it, CPU losses!\n\n");
        }
        printf("you : %d\nCPU : %d\n", playerscore, compscore);
    }
    if (playerscore > compscore)
    {
        printf("congrats! you won the game\n");
    }
    else if (compscore > playerscore)
    {
        printf("CPU wins , better luck next time.\n");
    }
    else
    {
        printf(" WoHoo it's a draw");
    }

    return 0;
}