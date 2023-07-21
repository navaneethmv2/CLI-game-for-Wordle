#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int i, j, k, pos[5];
int compare(char word[], char s[])
{
    if (strcmp(s, word) == 0)
        return 0;

    else
    {
        for (i = 0; i < 5; i++) //count for s
        {
            pos[i] = -1;
            for (j = 0; j < 5; j++) //count for word
            {
                if (word[j] == s[i])
                {

                    if (i == j)
                    {
                        pos[i] = 1;
                        break;
                    }
                    else
                        pos[i] = 0;
                }
            }
        }
        return 1;
    }
}



char *list[] = {
    "spike",
    "slice",
    "pluto",
    "speed",
    "hound",
    "ghost",
    "trail",
    "lever",
    "quail",
    "volvo",
    "joker",
    "liver",
    "volvo",
    "hairy",
    "amber",
    "delta",
    "place",
    "niece",
    "weary",
    "bully",
    "zebra",
    "young",
    "fight",
    "india",
    "rivet",
    "lotus",
    "raise",
    "skill",
    "prize",
    "found",
    "eagle",
    "ranch",
    "cough",
    "house",
    "shore"
};
int size=35;

int main()
{
    int r, p=1;
    char guess[6];
    char t[6];
    while(p)
    {
        srand(time(0));
        r = (rand() % size);
        strcpy(t,list[r]);                  //choosing random word from list

        for (int c = 0; c < 6; c++)
        {
            printf("\n\nEnter guess %d: ", c + 1);
            fflush(stdin);
            gets(guess);
            int a = compare(t, guess);
            if (!a)
            {
                printf("\nWell done!\nObtained right answer with %d guesses ", c + 1);
                break;
            }
            printf("\t");
            for (int l = 0; l < 5; l++)
            {
                printf(" %c[%d]", guess[l], pos[l]);
            }
            if(c==5)
            {
                printf("\nYou lose! (boo)\n");
                printf("WORD:  ");
                puts(t);
            }
        }
        printf("\nPlay again : (1/0)?");
        scanf("%d", &p);
    }
}