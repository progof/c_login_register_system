#include <stdio.h>

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
        login();
        main();

    case 2:
        registration();
        main();

    case 3:
        return 0;

    default:
        printf("\n\nError: No such option!!!\n\n");
        main();
    }
}

void login()
{
    char nickname[30], password[30];

    printf("Login\n");
    FILE *file_ptr = fopen("users.txt", "w+");

    if(file_ptr != NULL)
    {
        printf("Enter nickname");
        scanf("%s", &nickname);

        printf("Enter password");
        scanf("%s", &password);

        fprintf(file_ptr, "%s | %s", nickname, password);
    }else
    {
        fprintf(stderr, "\n\nFailed to create file 'users.txt' or open file 'users.txt'\n\n");
    }

    fclose(file_ptr);
}

void registration()
{
    printf("Register\n");
}