#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct account
{
    char username[15];
    char password[15];
};


void login (void);
void registration(void);

int main()
{   
    short option;
    printf("\nChoose one of the numbers to interact with the program\n\n 1. Login to system\n 2. Register to system\n 3. Exit\n\n Please select option: ");
    scanf("%hd", &option);

    switch (option)
    {
    case 1:
        system("CLS");
        login();
        break;

    case 2:
        system("CLS");
        registration();
        break;

    case 3:
        return 0;

    default:
        printf("\n\nError: No such option!!!\n\n");
        break;
    }
}

void login()
{
    char username[15], password[15];

    printf("\n\nLogin\n\n");
    FILE *file_ptr = fopen("users.txt", "r");

    if(file_ptr != NULL)
    {
        struct account login;

        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        while(fread(&login,sizeof(login),1,file_ptr))
        {
        if(strcmp(username,login.username)==0 && strcmp(password,login.password)==0)

            {   
                printf("\nSuccessful Login\n");
            }
        else 
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
            }
        }

       
    }else
    {
        fprintf(stderr, "\n\nFailed to create file 'users.txt' or open file 'users.txt'\n\n");
    }

    fclose(file_ptr);
}

void registration()
{
    struct account login;
    printf("\n\nRegistration\n\n");
    FILE *file_ptr = fopen("users.txt", "r+a");

    if(file_ptr != NULL)
    {
        printf("Enter nickname: ");
        scanf("%s", login.username);

        printf("Enter password: ");
        scanf("%s", login.password);

        fprintf(file_ptr, "%s %s\n", login.username, login.password);
    }else
    {
        fprintf(stderr, "\n\nFailed to create file 'users.txt' or open file 'users.txt'\n\n");
    }

    fclose(file_ptr);
}
