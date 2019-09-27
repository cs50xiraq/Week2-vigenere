#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char keyword)
{
    //This function for shifting the the given character based on whether it is alphapatical or not .
    int key ;
    if (isupper(keyword))
    {
        //When the letter is capital, will subtract it from 'A' to make it as a base.
        key = keyword - 'A';
    }
    else if (islower(keyword))
    {
        //When the letter is small, will subtract it from 'a' to make it as a base.
        key = keyword - 'a';
    }
    else
    {
        //If the given character is not alphapatical .
        key = keyword;
    }
    return key;
}
bool isAlpha(string arg)
{
    //This function to check if the "keyword" is written all with alphapatical letters or not.
    bool isALPHA = true;
    int length = strlen(arg);
    for (int i = 0; i < length; i++)
    {
        if (!(isalpha(arg[i])))
        {
            isALPHA = false;
        }
    }
    return isALPHA;
}

void encipher(string plainText, string key)
{
    // This function is to encipher the plain text that is given by the user.
    //It accepts two arguments:
    //- plainText = a string that is given by the user to be encrypted.
    //- key = a string that is given by the user to help encrypting the plainText.
    //It will not return any value so it is void
    int length = strlen(plainText);
    
    char cipherText[length];
    
    int keyL = strlen(key);
    
    int numnum = 0;
    
    char keyArray[length];
    int iteration = 0;
    bool space = false;
    for (int i = 0 ; i < length ; i++)
    {
        //This function helps organizing the keyword to make it iterate ciclically.
        //If there is a space or "not alphapatical" character, then it will give it
        //a value of 'A' and skips iterating 
        iteration = i;
        if (!(isalpha(plainText[i])))
        {
            keyArray[i] = 'A';
            space = true;
        }
        else
        {
            if (space)
            {
                keyArray[i] = key[++iteration % keyL];
            }
            else
            {
                keyArray[i] = key[(i % keyL)];
            }
        }
    }
    
    for (int i = 0; i < length; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                numnum = (shift(plainText[i]) + shift(keyArray[i])) % 26 + 'a';
                cipherText[i] = (char)numnum;   
            }
            else if (isupper(plainText[i]))
            {
                numnum = (shift(plainText[i]) + shift(keyArray[i])) % 26 + 'A';
                cipherText[i] = (char)numnum;
            }
      
        }
        else
        {
        
            cipherText[i] = plainText[i];
            printf("cipherSpace : %c\n", cipherText[i]);
        }
    }
    printf("ciphertext: ");
    for (int i = 0 ; i < length ; i++)
    {
        printf("%c", cipherText[i]);
        	
    }
    printf("\n");
    
}

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool isALPHA = isAlpha(argv[1]);
        if (!(isALPHA))
        {
            
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string key = argv[1];
            string plainText = get_string("plaintext:  ");
            encipher(plainText, key);
           
        }
    }
    else
    {
        //if argument count does not equal to 2 then :
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
