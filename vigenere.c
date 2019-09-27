#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    string key, plt, c = "";
    int j = 0;
    if (argc == 2)// check the arguments
    {
        key = argv[1];
        
        for (int k = 0; k < strlen(key); k++)// check the is alpha only
        {
            if (!(isalpha(key[k])))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        plt = get_string("plaintext: ");// Enter the plaintext
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plt); i++) 
        {
            if (plt[i] >= 'a' && plt[i] <= 'z')// check the plain is lower?
            {
                printf("%c", (((plt[i] + shift(key[j])) - 'a') % 26) + 'a');
                j++;
            }
            else if (plt[i] >= 'A' && plt[i] <= 'Z')// check the plain is upper?
            {
                printf("%c", (((plt[i] + shift(key[j])) - 'A') % 26) + 'A');
                j++;
            }
            else 
            {
                printf("%c", plt[i]);
            }
           
            if (j >= strlen(key))
            {
                j = 0;
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");//when the argc has not Valid keyword
        return 1;
    }
}
int shift(char c)// Function to shift key
{
    
    if (c >= 'a' && c <= 'z')
    {
        return (c - 'a');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return (c - 'A');
    }
    return 0;
}
