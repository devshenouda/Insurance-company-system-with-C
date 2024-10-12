#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SHENOUDA_ROMANY 0 
#define OMAR_MOHAMED 0
#define MOHAMED_MAHMOUD 0
#define MOHAMED_ABDELAZEEM 0
/*
   =============================================
   ============THIS CODE WRITTEN BY=============
   ===============AAST MAFIA TEAM===============
   =============================================
*/


// functions 

void AdminMenue() ; 
void AgentMenue() ;
void customerMenue() ;
void loginAdmin() ;
void loginAgent() ;
void loginCustomer() ;
void loginMenu() ;



// structure

struct user
{
    char name[100] ;
    char phonenum[100] ;
    char num_of_polices[100] ;
    char Email[50] ;
    char pass [50] ;
    char policenum[100] ;
    char National_id[100] ;

};
struct policies
{
    char Type_of_policy [100] ;
    char price[1000] ;
    char policenum[10000] ;
    char startdate[100] ;
    char enddate[100] ;


};
struct user usr ;
struct user agent ;
struct policies police ;



// var

    char cuname[100] ;
    char NID[100];
    char filename[500];
    char filename2[500] ;


// Program
int main()
{

    loginMenu();
    return 0;
}

// Functions
void loginMenu()
{
    int choice;
    printf("\n\t\tInsurance Company\t\t");
    printf("\n[1] Log in\n");
    printf("[2] Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

        int choice1;
        printf("Choose your position:\n");
        printf("[1] Admin\n");
        printf("[2] Agent\n");
        printf("[3] Customer\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            loginAdmin();
            break;
        case 2:
            loginAgent();
            break;
        case 3:
            loginCustomer();
            break;
        }
        break;
    case 2:
        exit(EXIT_SUCCESS);
    default:
        printf("Invalid choice! Please choose a valid option.\n");
        loginMenu() ;
        break;
    }
}





// login as a admin


void loginAdmin()
{
    char email[100];
    char password[100];
    char x[100] = "E";
    char y[100] = "E";

    printf("Enter your email: ");
    scanf("%s", email);

    if (strcmp(email, x) != 0) {
        printf("This email is invalid\n");
        loginAdmin() ;
    }

        int attempts = 5;
        while (attempts > 0) {
            printf("Enter your password: ");
            scanf("%s", password);

            if (strcmp(password, y) != 0) {
                printf("This password is invalid\n");
                attempts--;
            } else {
                AdminMenue() ;
                break;
            }
        }

        if (attempts == 0) {
            printf("Exceeded the maximum number of attempts\n");
        }
    }


    // admin menue  :::::

    void AdminMenue()
    {
        FILE *fp ;
        int cho ;
        printf("\n\t\t\t===============  WELLCOME ADMIN  =================\n");
        printf("\n[1] Add New Customer") ;
        printf("\n[2] Remove Customer") ;
        printf("\n[3] View customer") ;
        printf("\n[4] Add Agents") ;
        printf("\n[5] Remove Agents") ;
        printf("\n[6] View Agents") ;
        printf("\n[7] Add Policy") ;
        printf("\n[8] Review Policy") ;
        printf("\n[9] Remove Policy") ;
        printf("\n[10] Logout") ;
        printf("\nEnter Your Choice\n") ;
        scanf("%d" , &cho) ;
        switch (cho)
        {
            //case 1

            case 1:
                printf("\nEnter client's Name: ");
                scanf("%s", usr.name);

                printf("\nEnter client's phone number: ");
                scanf("%s", usr.phonenum);

                printf("\nEnter Client's Email: ");
                scanf("%s", usr.Email);

                printf("\nEnter Client's Password: ");
                scanf("%s", usr.pass);

                printf("\nEnter Clint's National ID: ");
                scanf("%s", usr.National_id);

                strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers\\");
                strcat(filename, usr.National_id);
                strcat(filename, ".csv");

                strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers.dat\\") ;
                strcat(filename2, usr.National_id);
                strcat(filename2, ".dat");
                

                //file name (excel) 
                fp = fopen(filename, "w");
                if (fp != NULL) {
                    fprintf(fp, "First Name,Email,National ID,Password,Phone\n");
                    fprintf(fp, "%s,%s,%s,%s,%s\n" , usr.name , usr.Email , usr.National_id , usr.pass , usr.phonenum);

                    fclose(fp);
                    
                    // open the new file (dat) to read
                    fp = fopen(filename2, "w");
                    if (fp != NULL) {
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);
                    }
                    printf("\n\nThe account added successfully.");
                    AdminMenue() ;
                }
                else
                    {
                    printf("\n\nThere is an error. Please try again.");
                    AdminMenue() ;
                }


                break;



                //case 2



            case 2 :
            printf("\nEnter client's National ID to remove: ");
            char NID[100];
            scanf("%s", NID);

            strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers\\");
            strcat(filename, NID);
            strcat(filename, ".csv");

            // file with (dat)
            strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers.dat\\") ;
            strcat(filename2, NID);
            strcat(filename2, ".dat");

            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("\n\nFile does not exist.");
                AdminMenue() ;
                break;
            }
            fclose(fp);
            fp = fopen(filename2 , "r") ;
            fclose(fp) ;
            if (remove(filename) == 0 && remove(filename2)== 0) {
                printf("\n\nThe account removed successfully.");
                AdminMenue() ;
            }
            else {
                printf("\n\nError removing the account. Please try again.");
                AdminMenue() ;
            }
            break;



            //case 3



           case 3:
           // char NID[100];
            printf("\nEnter client's National ID to review: ");
            scanf("%s", NID);
            

            //file with excel
            strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers\\");
            strcat(filename, NID);
            strcat(filename, ".csv");
            

            //file with dat
            strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers.dat\\") ;
            strcat(filename2, NID);
            strcat(filename2, ".dat");

            fp = fopen(filename2, "r");
            if (fp == NULL) {
                printf("\n\nFile does not exist.");
                AdminMenue() ;
                break;
            }

            struct user usr; // Define the user structure
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);

            printf("\nClient's Name: %s", usr.name);
            printf("\nClient's Phone Number: %s", usr.phonenum);
            printf("\nClient's Email: %s", usr.Email);
            printf("\nClient's National ID: %s", usr.National_id);
            printf("\nClient's Password : %s" , usr.pass) ;
            AdminMenue() ;
            break;


          // case 4


           case 4 :
                printf("\nEnter Agent's Name: ");
                scanf("%s", agent.name);

                printf("\nEnter Agent's phone number: ");
                scanf("%s", agent.phonenum);

                printf("\nEnter Agent's Email: ");
                scanf("%s", agent.Email);

                printf("\nEnter Agent's Password: ");
                scanf("%s", agent.pass);

                printf("\nEnter Agent's ID: ");
                scanf("%s", agent.National_id);

                // with excel file
                strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Agents\\");
                strcat(filename, agent.National_id);
                strcat(filename, ".csv");


                //with dat file 
                strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Agents.dat\\") ;
                strcat(filename2, agent.National_id);
                strcat(filename2, ".dat");



                fp = fopen(filename, "w");

                if (fp != NULL) {
                    
                    fprintf(fp, "First Name,Email,National ID,Password,Phone\n");
                    fprintf(fp, "%s,%s,%s,%s,%s\n" , agent.name , agent.Email , agent.National_id , agent.pass , agent.phonenum);
                    fclose(fp);
                    
                    // open the new file (dat) to read
                    fp = fopen(filename2, "w");
                    if (fp != NULL) {
                    fwrite(&agent, sizeof(struct user), 1, fp);
                    fclose(fp);
                    }
                    printf("\n\nThe account added successfully.");
                    AdminMenue() ;
                }
                else
                {
                    printf("\n\nThere is an error. Please try again.");
                    AdminMenue();
                }
                break;



               //case 5


           case 5 :

                printf("\nEnter Agent's ID to remove: ");
                //char NID[100];                           
                scanf("%s", NID);

                //file with excel
                strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Agents\\");
                strcat(filename, NID);
                strcat(filename, ".csv");

                
                // file with dat 
                strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Agents.dat\\") ;
                strcat(filename2, NID);
                strcat(filename2, ".dat");



                fp = fopen(filename, "r");
                if (fp == NULL) {
                printf("\n\nFile does not exist.");
                AdminMenue() ;
                break;
                }
                fclose(fp);
                fp = fopen(filename2 , "r") ;
                fclose(fp) ;
                if (remove(filename) == 0 && remove(filename2)== 0) {
                printf("\n\nThe account removed successfully.");
                AdminMenue() ;
                }
                else {
                printf("\n\nError removing the account. Please try again.");
                AdminMenue() ;
                }
                break;



            // case 6
            case 6 :
            printf("\nEnter agent National ID to review: ");
            scanf("%s", NID);
            

            //file with excel
            strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Agents\\");
            strcat(filename, NID);
            strcat(filename, ".csv");
            

            //file with dat
            strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Agents.dat\\") ;
            strcat(filename2, NID);
            strcat(filename2, ".dat");

            fp = fopen(filename2, "r");
            if (fp == NULL) {
                printf("\n\nFile does not exist.");
                AdminMenue() ;
                break;
            }
            struct user agent; // Define the user structure
            fread(&agent, sizeof(struct user), 1, fp);
            fclose(fp);

            printf("\nClient's Name: %s", agent.name);
            printf("\nClient's Phone Number: %s", agent.phonenum);
            printf("\nClient's Email: %s", agent.Email);
            printf("\nClient's National ID: %s", agent.National_id);
            printf("\nClient's Password : %s" , agent.pass) ;
            AdminMenue() ;
            break;


           case 7 :

                printf("\n\t\t\t===============  Policy Details  =================\n");

                printf("\nEnter Policy Number: ");
                scanf("%s", police.policenum);

                printf("\nEnter Client's National ID: ");
                scanf("%s", usr.National_id);

                printf("\nEnter The Price of Policy: ");
                scanf("%s", police.price);

                printf("\nEnter The Type of Policy: ");
                scanf("%s", police.Type_of_policy);

                printf("\nEnter The Start Date: ");
                scanf("%s", police.startdate);

                printf("\nEnter The End Date: ");
                scanf("%s", police.enddate);


                // start for pathes   ========> 

                // path with excel 
                strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices\\");
                strcat(filename, usr.National_id);
                strcat(filename, " ");
                strcat(filename, police.policenum);
                strcat(filename, ".csv");


                // path for dat
                strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices.dat\\");
                strcat(filename2, usr.National_id);
                strcat(filename2, " ");
                strcat(filename2, police.policenum);
                strcat(filename2, ".dat");

                // end of pathes ======> 

                //start creation ======>>|>

                 fp = fopen(filename, "w");
                if (fp != NULL) {
                    fprintf(fp, "Police NO: , National ID , Police price , Type , Start Date , End Date\n");
                    fprintf(fp, "%s,%s,%s,%s,%s,%s\n" , police.policenum , usr.National_id , police.price , police.Type_of_policy , police.startdate , police.enddate);
                    fclose(fp);
                    // open the new file (dat) to read
                    fp = fopen(filename2, "w");
                    if (fp != NULL) {
                    fwrite(&police, sizeof(struct policies), 1, fp);
                    fclose(fp);
                    }
                    printf("\n\nThe account added successfully.");
                    AdminMenue() ;
                }
                else
                    {
                    printf("\n\nThere is an error. Please try again.");
                    AdminMenue() ;
                }
                break;



                //case 8
           case 8 :
             printf("\nEnter client's National ID: ");
            scanf("%s", usr.National_id);
            printf("\nEnter client's police no : ") ;
            scanf("%s" , police.policenum) ;
                strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices.dat\\"); 
                strcat(filename2, usr.National_id);
                strcat(filename2, " ");
                strcat(filename2, police.policenum);
                strcat(filename2, ".dat");
            fp = fopen(filename2, "r");
            if (fp == NULL) {
                printf("\n\nFile does not exist.");
                AdminMenue() ;
                break;
            }
            struct policies police; // Define the user structure
            fread(&police, sizeof(struct policies), 1, fp);
            fclose(fp);

            printf("\nClient's Police Number: %s", police.policenum);
            printf("\nClient's police price: %s", police.price);
            printf("\nClient's police type: %s", police.Type_of_policy);
            printf("\nClient's start date: %s", police.startdate);
            printf("\nClient's end date : %s" , police.enddate) ;
            AdminMenue() ;
            break;


        //case 9
           case 9 :
           
            printf("\n\nEnter client's National ID : ") ;
            scanf("%s" , usr.National_id) ;
            printf("\nEnter number of the policy : ") ;
            scanf("%s" , police.policenum) ;
            
                
                // file with csv
                strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices\\");
                strcat(filename, usr.National_id);
                strcat(filename, " ");
                strcat(filename, police.policenum);
                strcat(filename, ".csv");

                //file with dat 
                strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices.dat\\");
                strcat(filename2, usr.National_id);
                strcat(filename2, " ");
                strcat(filename2, police.policenum);
                strcat(filename2, ".dat");


                


                 fp = fopen(filename, "r");
                if (fp == NULL) {
                printf("\n\nFile does not exist.");
                AdminMenue() ;
                break;
                }
                fclose(fp);
                
                fp = fopen(filename2 , "r") ;
                fclose(fp) ;
                if (remove(filename) == 0 && remove(filename2)== 0) {
                printf("\n\nPolicy removed successfully.");
                AdminMenue() ;
                }
                else {
                printf("\n\nError removing the Policy. Please try again.");
                AdminMenue() ;
                }

            case 10 :
             loginMenu() ;
            
            default:
                printf("Invalid choice! Please choose a valid option.\n");
                loginMenu() ;
                break;
        

            
        }
    }






    // login as customer


void loginCustomer() {
    FILE *fp;
    char pword[100];
    struct user usr;
    printf("Enter Your Name : ") ;
    scanf("%s" , &cuname) ;
    printf("Enter your National ID: ");
    scanf("%s", NID);
    printf("Enter your password: ");
    scanf("%s", pword);

    strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers.dat\\");
    strcat(filename2, NID);
    strcat(filename2, ".dat");

    fp = fopen(filename2, "r");
    if (fp == NULL) {
        printf("File not found or cannot be opened.\n");
        return;
    }

    fread(&usr, sizeof(struct user), 1, fp);
    fclose(fp);

    if (!strcmp(pword, usr.pass)) {
        printf("Password matched.\n");
        customerMenue() ;
    } else {
        printf("Invalid Password.\n");
        loginCustomer() ;
    }
}



// customerMenue function  ;

 void customerMenue()
 {
     FILE *fp ;
     struct user usr ;
     printf("\n\n\n\t\t=====================  Hello, %s =============================" , cuname) ;
     printf("\n\n[1] Read your policy ") ;
     printf("\n[2] profile ") ;
     printf("\n[3] settings ") ;
     printf("\n[4] Exit ") ;
     printf("\nEnter your choice :") ;
     fp = fopen(filename2, "r");
     fread(&usr, sizeof(struct user), 1, fp);
     fclose(fp);
     int choice ;
     scanf("%d" , &choice) ;
     switch(choice)
     {
     case 1 :
            printf("\nEnter Your National ID: ");
            scanf("%s", NID);
            printf("\nEnter your police no : ");
            scanf("%s", police.policenum);

            // File with dat
            strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices.dat\\");
            strcat(filename2, NID);
            strcat(filename2, " ");
            strcat(filename2, police.policenum);
            strcat(filename2, ".dat");

            // Open DAT file
            fp = fopen(filename2, "r");
            if (fp == NULL) {
                printf("\n\nFile does not exist.");
                customerMenue();
                break;
            }
            fread(&police, sizeof(struct policies), 1, fp);
            fclose(fp);

            printf("\nPolice Number: %s", police.policenum);
            printf("\nPolice price: %s", police.price);
            printf("\nPolice type: %s", police.Type_of_policy);
            printf("\nStart date: %s", police.startdate);
            printf("\nEnd date : %s", police.enddate);
            customerMenue();
            break;

     case 2 :
        
        


        // File with dat
            strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers.dat\\");
            strcat(filename2, NID);
            strcat(filename2, ".dat");
        
        
         // Open DAT file
            fp = fopen(filename2, "r");
            if (fp == NULL) {
                printf("\n\nFile does not exist.");
                customerMenue();
                break;
            }
            fread(&police, sizeof(struct policies), 1, fp);
            fclose(fp);


        printf("\n\nYour Email : %s" , usr.Email) ;
        printf("\nYour password : %s" , usr.pass) ;
        printf("\nYour National ID : %s" , usr.National_id) ;
        printf("\nYour Phone number : %s" , usr.phonenum) ;
        customerMenue();
        break ;

     case 3 :
        printf("\n\n[1] Change Email");
            printf("\n[2] Change Password");
            printf("\n[3] Change Phone number");
            printf("\nEnter Your choice : ");
            int cho;

            scanf("%d", &cho);

            switch (cho) {
                case 1:
                    printf("Enter new Email: ");
                    scanf("%s", usr.Email);
                    break;

                case 2:
                    printf("Enter new Password: ");
                    scanf("%s", usr.pass);
                    break;

                case 3:
                    printf("Enter new Phone number: ");
                    scanf("%s", usr.phonenum);
                    break;

                default:
                    printf("Invalid choice!\n");
                    customerMenue();
            }

            // Update user data in CSV file
            strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers\\");
            strcat(filename, usr.National_id);
            strcat(filename, ".csv");
            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }
            fprintf(fp, "First Name,Email,National ID,Password,Phone\n");
            fprintf(fp, "%s,%s,%s,%s", usr.National_id, usr.Email, usr.pass, usr.phonenum);
            fclose(fp);

            // Update user data in DAT file
            strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\customers.dat\\");
            strcat(filename2, usr.National_id);
            strcat(filename2, ".dat");
            fp = fopen(filename2, "w");
            if (fp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }
            fwrite(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            customerMenue();

            break;

        case 4 :
        loginMenu() ;

     default:
         printf("Invalid choice!\n");
         customerMenue();

        }


     }









// login agent function
void loginAgent()
{
    FILE *fp;
    char pword[100];
    struct user agent;
    printf("Enter your National ID: ");
    scanf("%s", NID);
    printf("Enter your password: ");
    scanf("%s", pword);

    strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Agents.dat\\") ;
    strcat(filename2, NID);
    strcat(filename2, ".dat");
    fp = fopen(filename2, "r");
    if (fp == NULL) {
        printf("File not found or cannot be opened.\n");
        return;
    }

    fread(&agent, sizeof(struct user), 1, fp);
    fclose(fp);

    if (!strcmp(pword, agent.pass)) {
        printf("Password matched.\n");
        AgentMenue() ;
    } else {
        printf("Invalid Password.\n");
        loginAgent() ;
    }

}




// agent menu

void AgentMenue()
{
    struct policies police ;
    struct user agent ;
    struct user usr ;

    FILE *fp;
    printf("\n\t\t\t===============  WELLCOME AGENT  =================\n");
    printf("\n[1] Create Policy") ;
    printf("\n[2] Delete Policy") ;
    printf("\n[3] Exit") ;
    printf("\nEnter Your Choice: ") ;
    int cho ;
    scanf("%d" , &cho) ;
    switch(cho)
    {
    case 1 :
                printf("\n\t\t\t===============  Policy Details  =================\n");

                printf("\nEnter Policy Number: ");
                scanf("%s", police.policenum);

                printf("\nEnter Client's National ID: ");
                scanf("%s", usr.National_id);

                printf("\nEnter The Price of Policy: ");
                scanf("%s", police.price);

                printf("\nEnter The Type of Policy: ");
                scanf("%s", police.Type_of_policy);

                printf("\nEnter The Start Date: ");
                scanf("%s", police.startdate);

                printf("\nEnter The End Date: ");
                scanf("%s", police.enddate);


                // start for pathes   ========> 

                // path with excel 
                strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\polices\\");
                strcat(filename, usr.National_id);
                strcat(filename, " ");
                strcat(filename, police.policenum);
                strcat(filename, ".csv");


                // path for dat
                strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\polices.dat\\");
                strcat(filename2, usr.National_id);
                strcat(filename2, " ");
                strcat(filename2, police.policenum);
                strcat(filename2, ".dat");

                // end of pathes ======> 

                //start creation ======>>|>

                 fp = fopen(filename, "w");
                if (fp != NULL) {
                    fprintf(fp, "Police NO: , National ID , Police price , Type , Start Date , End Date\n");
                    fprintf(fp, "%s,%s,%s,%s,%s,%s\n" , police.policenum , usr.National_id , police.price , police.Type_of_policy , police.startdate , police.enddate);
                    fclose(fp);
                    // open the new file (dat) to read
                    fp = fopen(filename2, "w");
                    if (fp != NULL) {
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);
                    }
                    printf("\n\nThe account added successfully.");
                    AgentMenue() ;
                }
                else
                    {
                    printf("\n\nThere is an error. Please try again.");
                    AgentMenue() ;
                }
                break;

    case 2 :
        printf("\n\nEnter client's National ID : ") ;
        scanf("%s" , usr.National_id) ;
        printf("\nEnter number of the policy : ") ;
        scanf("%s" , police.policenum) ;
            
                
         // file with csv
         strcpy(filename, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices\\");
         strcat(filename, usr.National_id);
         strcat(filename, " ");
         strcat(filename, police.policenum);
         strcat(filename, ".csv");
        //file with dat 
        strcpy(filename2, "C:\\Users\\Eng Shenouda Romany\\Desktop\\PR II\\Polices.dat\\");
        strcat(filename2, usr.National_id);
        strcat(filename2, " ");
        strcat(filename2, police.policenum);
        strcat(filename2, ".dat");

                
        fp = fopen(filename, "r");
        if (fp == NULL) {
        printf("\n\nFile does not exist.");
        AgentMenue() ;
        break;
        }
        fclose(fp);
        fp = fopen(filename2 , "r") ;
        fclose(fp) ;
        if (remove(filename) == 0 && remove(filename2)== 0) {
        printf("\n\nPolicy removed successfully.");
        AgentMenue() ;
        }
        else {
        printf("\n\nError removing the Policy. Please try again.");
        AgentMenue() ;         
        }   
    
    case 3 :
        loginMenu() ;

    }
}    
