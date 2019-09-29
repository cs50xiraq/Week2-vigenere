#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("you must enter mor than one world");//if user enter just one argument
        return 1 ;
    }

    else if (argc == 2)
    {   
        string key = argv[1], plain_text;
        int lenk = strlen(key);
            
        for (int i = 0 ; i < lenk ; i++)//check if the char is alphabet
        {
            if (!isalpha(key[i]))
            {
                printf("you must enter string world");
                return 1;
            }
        }
           
        plain_text = get_string("enter plain_text : ");//inpute plain text by user
        int lenp = strlen(plain_text);//calculate length of plain text
        printf("ciphertext: ");
           
        for (int j = 0, index = 0 ; j < lenp ; j++)//loop for cipher text
        {
            if (isalpha(plain_text[j]))
            {
                if (islower(plain_text[j]))
                {
                    printf("%c", (plain_text[j] - 'a' + toupper(key[index]) - 'A') % 26 + 'a');
                }
                else if (isupper(plain_text[j]))
                {
                    printf("%c", (plain_text[j] - 'A' + toupper(key[index]) - 'A') % 26 + 'A');
                }
                index = (index + 1) % lenk;
                   
            }
            else
            {
                printf("%c", plain_text[j]);
            }
               
        }
           
        printf("\n");
    }
}

