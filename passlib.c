#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check_password(char *password) {
    int score = 0;
    int count = 0;
    int slen = strlen(password);

    //cheak length for score 1
    if (strlen(password) >= 8)
    {
        score = score +2;
    } else {
        return score;
    }

    // Check for one uppercase element and add score 1
    for (int i = 0; i < slen; i++)
    {
        if (isupper(password[i])) 
        {
            score = score +1;
        } 
    }

    // Check for one uppercase element and add score 1
    for (int i = 0; i < slen; i++)
    {
        if (isupper(password[i])) 
        {
            count = count + 1;
        }
        if (count >= 3)
        {
            score = score + 1;
            count = 0;
            break;
        }
    }

    //Check for one symbol add score 1
    for (int i = 0; i < slen; i++)
    {
        if (ispunct(password[i]))
        {
            score = score + 2;
            break;
        }
    }
    
    //Check if it has 3 numeric characters and add score 1 
    for (int i = 0; i < slen; i++)
    {
        if (isdigit(password[i]))
        {
            count = count + 1;
            if (count >= 3)
            {
                score =+ score;
                count = 0; //we can reuse this variable later
                break;
            }
        }
    }

    //TODO: check if its sequential.
    int lastpos = -1, flag = 0;
    for (int i = 0; i < slen; i++)
    {
        printf("checking if '%c' is a digit... \n", password[i]);
        if (isdigit(password[i]))
        {
            printf("yes, '%c' is a digit... \n", password[i]);
            
            if (lastpos == -1)
            {
                lastpos = i;
            } 
            else {
                int temp = i - lastpos;
                if (temp == 1)
                {
                    int check = password[i] - password[lastpos];
                    printf("checking %d [%c] vs %d [%c]", password[i],password[lastpos], password[i], password[lastpos]);
                    if (abs(check) == 1)
                    { 
                        flag = flag + 1;
                        lastpos = i;
                        continue;
                    }
                } else {
                    flag = 0;
                }
            }
        } else 
            {
                lastpos = -1;
        }
    }
    if (flag < 2)
    {
        score = score + 2;
    }
    return score;
}