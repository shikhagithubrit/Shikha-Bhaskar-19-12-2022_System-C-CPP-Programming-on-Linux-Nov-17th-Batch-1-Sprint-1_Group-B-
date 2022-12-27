#include<stdio.h>
#include<string.h>
#include "dnd.h"


/************ search ****************/

int search(long uphno){
    customer s1;
        FILE *fp;
        int found = 0;
        fp = fopen("mydata.txt","r");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
                if(strcmp(s1.status,"Enable") == 0){
                    printf("%s DND is already activated", s1.type);
                    found = 2;
                }
                else{
                    found = 1;
                }
            //printf("\n%ld--%s--%s",s1.phno,s1.name,s1.status);
            }
        }
        if(!found){
        printf("\n Data Not Found.....\n");}
        fclose(fp);
        return found;

}


/**************** Global Function ***********/

void global() {
    void Active_globaldnd(long uphno);
    int search(long uphno);
    int gs,check;
    long uphno;
    printf("\n************* Global Service ***********\n");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    check = search(uphno);
    if (check == 1){
    printf("\n Press 1. Activate Global DND\n Press 2. Exit\n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&gs);

    switch(gs)
        {
        case 1:
        Active_globaldnd(uphno);
        break;

        case 2:
        printf("Thanks for choosing us, Enter choice from main menu\n\n");
        break;

        default:
        printf("Error! choice is not correct");
        }

    }
    else if( check == 0){
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
    else{
        printf("\nThank you");
    }
// printf("\n*****************************\n");
}

void Active_globaldnd(long uphno)
{
customer s1;
        FILE *fp, *fp1;
        int found = 0;
        fp = fopen("mydata.txt","r");
        fp1 = fopen("temp.txt","w");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){      // check condition input phone number is equal to file phone number
            found = 1;
            strcpy(s1.status, "Enable");
            strcpy(s1.type, "Global");
            }
            fwrite(&s1,sizeof(customer),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        if(found){
            fp = fopen("mydata.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(customer),1,fp1)){    // read a file
                fwrite(&s1,sizeof(customer),1,fp);       // write a file
            }
            fclose(fp);
            fclose(fp1);
            printf("\n**************************\n");
	    printf("\n\n Global DND Service activated\n\n");
        }
        else{
            printf("\n Not Found.....\n");
        }
 	printf("\n*****************************\n");
}


/***********************************/






/**************** Selective Function ************/

void selective() {
void Selective_dnd(long uphno);
int search(long uphno);
int gs,check;
long uphno;
printf("\n*************Selective Service*************\n\n");
printf("\n Enter your PhoneNo : ");
scanf("%ld",&uphno);
check = search(uphno);
if (check == 1){
printf("\n Press 1. Activate Selective DND\n Press 2. Exit\n");
printf("\nEnter Your Choice : ");
scanf("%d",&gs);

switch(gs)
{
    case 1:
    Selective_dnd(uphno);
    break;

    case 2:
    printf("Thanks for choosing us, Enter choice from main menu\n\n");
    break;

    default:
    printf("Error! choice is not correct");
}

}
else if( check == 0){
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
    else{
        printf("\nThank you");
    }
}

void Selective_dnd(long uphno)
{
customer s1;
        FILE *fp, *fp1;
        int found = 0,choice;
        char uselection[20];
        fp = fopen("mydata.txt","r");
        fp1 = fopen("temp.txt","w");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
            found = 1;
             printf("\n****************************\n");
            printf("\n Press 1. Promotion Call\n Press 2. Feedback call\n Press 3. Company call\n");
            printf("\nEnter Your Choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                strcpy(s1.selection, "Promotion_Call");
                break;

                case 2:
                strcpy(s1.selection, "Feedback_Call");
                break;

                case 3:
                strcpy(s1.selection, "Company_Call");
                break;

                //default:
               // printf("Error! choice is not correct");
            }
            strcpy(s1.status, "Enable");
            strcpy(s1.type, "Selective");
            }
            fwrite(&s1,sizeof(customer),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        if(found){
            fp = fopen("mydata.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(customer),1,fp1)){
                fwrite(&s1,sizeof(customer),1,fp);
            }
            fclose(fp);
            fclose(fp1);
            printf("\n******* Selective DND Service successfully activated ********\n");
            printf("\n******************************\n");
        }
        else{
            printf("\n Not Found.....\n");
            }
}

/***********************************/


/*************** Deactive Function ****************/

void deactivateDND(){
    void deactive_dnd(long uphno);
    int search_deactivate(long uphno);
    int gs,check;
    long uphno;
    printf("\n***************************\n");
    printf("\n                                    Deactivate DND Service                    \n");
    printf("\n **************************\n");
    printf("\n Enter your PhoneNo :  ");
    scanf("%ld",&uphno);
    check = search_deactivate(uphno);
    if (check == 1){
        printf("\n Press 1. Deactivate DND\n Press 2. Exit\n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&gs);

        switch(gs)
        {
            case 1:
            deactive_dnd(uphno);
            break;

            case 2:
            printf("Thanks for choosing us, Enter choice from main menu\n\n");
            break;

            default:
            printf("Error! choice is not correct");
        }

    }
    else if ( check == 0){
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
    else{
        printf("\n ####################### Thank you ##################################\n");
    }
  }

void deactive_dnd(long uphno){
    customer s1;
        FILE *fp, *fp1;
        int found = 0;
        fp = fopen("mydata.txt","r");
        fp1 = fopen("temp.txt","w");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
            found = 1;
            strcpy(s1.status, "Disable");
            strcpy(s1.type, "None");
            strcpy(s1.selection, "None");
            }
            fwrite(&s1,sizeof(customer),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        if(found){
            fp = fopen("mydata.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(customer),1,fp1)){
                fwrite(&s1,sizeof(customer),1,fp);
            }
            fclose(fp);
            fclose(fp1);
            printf("\n******************************\n");
            printf("\n                                 DND Service successfully deactivated                \n");
            printf("\n ****************************\n");
        }
        else{
            printf("\n Not Found.....\n");
        }
      //   printf("\n*******************************\n");
}



int search_deactivate(long uphno){
    customer s1;
        FILE *fp;
        int found = 0;
        fp = fopen("mydata.txt","r");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
                if(strcmp(s1.status,"Disable") == 0){
                    printf("\n******* No DND service activated*********");
                    found = 2;
                    break;
                }
                else{
                    found = 1;
                }
            }
        }
        if(!found){
        printf("\n Data Not Found.....\n");}
        fclose(fp);
        return found;

}





/************************************/