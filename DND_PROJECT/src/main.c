//#include<stdio.h>
//#include<string.h>
//#include<unistd.h>
#include "dnd.h"


int main(){
    int service;
    do
    {
        printf("\n <>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-DND Service <>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>\n");
	sleep(2);
        printf("\n\n############################### DND MENU ###############################\n\n");
        printf("\n Press 1. Registration \n Press 2. Activate DND\n Press 3. Dial");
        printf("\n Press 4. Change DND Service");
        printf("\n Press 5. Display Record");
        printf("\n Press 6. Deactivate DND");
        printf("\n Press 7. Exit \n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&service);

        switch(service)
        {
        case 1:
            registration();
            break;

        case 2:
            activateDND();
            break;

        case 3:
            dial();
            break;

        case 4:
            changeDndService();
            break;

        case 5:
            display();
            break;

        case 6:
            deactivateDND();
            break;

        case 7:
            printf("\n\n************Thank You**************\n\n");
            break;

        default:
            printf("Error! choice is not correct");
        }
    }
    while(service != 7);
    return 0;
}