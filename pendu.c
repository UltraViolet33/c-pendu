#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//prototypes
char readChar();
int gagne(int lettreTrouvee[]);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);

int main(int argc, char *argv[])
{
    char lettre = 0;
    char secretWord[] = "MARRON";
    int letterFound[6]=  {0};
    int count = 10;
    int i = 0;

    printf("Bienvenue dans le pendu !!\n\n");
    //Main loop of the game
    while(count > 0 && !gagne(letterFound))
    {
        printf("\n\n Il vous reste %d coups à jouer", count);
        printf("\n Quel est le mot secret ? ");

        for(i = 0; i < 6; i++)
        {
            if(letterFound[i])
                printf("%c", secretWord[i]);
            else
                printf("*");
        }

        printf("\n Proposez une lettre : ");
        lettre = readChar();

        if(!rechercheLettre(lettre, secretWord, letterFound))
        {
            count--;
        }
    }

    if(gagne(letterFound))
        printf("\n\n Gagne ! Le mot secret était bien : %s", secretWord);
    else
        printf("\n\n Perdu ! le mot secret était %s", secretWord);
    return 0;
}

//function to read an input character
char readChar()
{
    char character = 0;
    character = getchar();
    character = toupper(character);
    while(getchar() != '\n');
    return character;
}

int gagne(int lettreTrouvee[])
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < 6 ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }
    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    int i = 0;
    int bonneLettre = 0;
 
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) 
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1; 
        }
    }
    return bonneLettre;
}
