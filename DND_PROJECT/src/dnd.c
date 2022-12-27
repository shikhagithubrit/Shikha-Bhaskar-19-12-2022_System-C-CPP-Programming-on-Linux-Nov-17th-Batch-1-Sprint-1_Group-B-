#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "dnd.h"


/*****************  Registraion Function **************/
void registration(){
        customer s;
        FILE *fp;
        fp = fopen("mydata.txt","a+");
        printf("\n*********** Registration**********\n");
        printf("\n Enter PhoneNo : ");  
        scanf("%ld",&s.phno);
        printf("Enter Name : ");
        scanf("%s",s.name);
        strcpy(s.status, "Disable");
        strcpy(s.type, "None");
        strcpy(s.selection, "None");
        fwrite(&s,sizeof(customer),1,fp);
        fclose(fp);
        printf("Your Registration is Completed\n");
        printf("\n ***********************\n");
}

/***********************************/



/***************  Display Function ***************/
void display(){
     customer s1;
        FILE *fp;
        int j;
        fp = fopen("mydata.txt","r");
        printf("\n*********** Registered Data of User ********\n");
        printf("\n Phone_No || Name|| Status || Type || Selection \n");
        while(fread(&s1,sizeof(customer),1,fp))  // read data from the file
        {
            printf("\n%ld||%s||%s||%s||%s", s1.phno,s1.name,s1.status,s1.type,s1.selection);
        }
            printf("\n\n **************************\n\n");
        fclose(fp);
}


/***********************************/



/**************** Change DND Function ********/

void changeDndService() {
    void activateDND();
    int search(long uphno);
    int check;
    long uphno;
    printf("\n\n ****** Update DND Service ****************\n\n");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    check = search(uphno);
    if (check == 2 ){
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
            printf("\n *********************\n");
            printf("\n DND deactivated\n");
            printf("\n Now you can change the type of dnd from next menu\n");
            printf("\n **********************\n");
            activateDND();
        }
        else{
            printf("\n Data Not Found.....\n");
        }
    }
    else{
        printf("\n No DND service is activated on your number\n");
    }
     printf("\n***************************\n");

}


/***********************************/





/************** Dial Function ****************/


void dial(){
    int gs,found;
    long uphno; //take input
    printf("**********  Dial  Number ***********");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    printf("Select Call Type\n");
    printf("\n Press 1.Promotion Call\n Press 2. Feedback call\n Press 3. Company call\n Press 4. Normal\n Press 5. Exit\n");
    printf("\n Enter your choice:");
    scanf("%d", &gs);
    customer s1;
    FILE *fp;
    fp = fopen("mydata.txt","r");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno)
            {
                found = 1;
                if(strcmp(s1.status,"Enable") == 0)
                {
                    if(strcmp(s1.type, "Selective") == 0) // check condition for selective 
                    {
                        switch(gs) {
                        case 1:
                            if(strcmp(s1.selection,"Promotional_Call") == 0) {
                                found = 6;
                                break;
                            }else {
                                found = 7;
                                break;
                            }
                        case 2:
                            if(strcmp(s1.selection,"Feedback_Call")==0) {
                                found = 6;
                                break;
                            }else {
                                found = 7;
                                break;
                            }
                        case 3:
                            if(strcmp(s1.selection,"Company_Call")==0) {
                                found = 6;
                                break;
                            }else {
                                found = 7;
                                break;
                            }
                        case 4:
                                found = 7;
                        }
                    }
                    else{
                        found = 3; // check condition for global
                    }
                }else
                {
                   found =2; // status is disable
                }
            }
        }
        if(!found){
        printf("\n Not Found.....\n");
        }
        fclose(fp);
    // decision logic

    if (found == 3 || found == 6){
        printf("\n *************************\n");
        printf("\nUser has opted for DND service, You won't be able to connect on this number\n");
        printf("\n ***************************\n");
    }
    else{
        printf("\n Call is Connecting........................\n");
        sleep(0.25);
          printf("\n ....\n");
	  sleep(2);
	printf("\n...........");
	sleep(2);
	printf("\n.................\n");
	sleep(2);
	printf("\n********* Call is connected**********\n");
         
    }
   
}


/*********************************/



/************* Activate DND Function***********/

void activateDND(){
    void global();
    void selective();
    int dnd;
    printf("**************************");
    printf("\n Select your DND choice from the two options:");
    printf("\n Press 1. Global Service\n Press 2. Selective Service\n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&dnd);
    switch(dnd)
    {
        case 1:
            global();
            break;

        case 2:
            selective();
            break;

        default:
            printf("Error! choice is not correct");
    }
     printf("**************************");
}