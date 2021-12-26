#include <stdio.h>
#include "passlib.c"

#define TESTCASES "password.txt"

int main() {
    char pass[100];
    FILE *fp;

    fp = fopen("password.txt", "r");
    if (!fp)
    {
        printf("Canot open file %s \n", TESTCASES);
        return -1;
    }
    
    while (fgets(pass, 100, fp))
    {
        pass[strlen(pass) -1] = '\0';
        int strength = check_password(pass);
        if (strength < 4)
        {
            printf("Worst password... Dont use that");
        }
        else if (strength < 5)
        {
            printf("Week password... Dont use this password.");
        }
        else if (strength < 6)
        {
            printf("Average password...");
        }
        
        
        
    }
    
}