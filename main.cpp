#include "stdio.h"
#include "stdlib.h"
#define SIZE 3
void printingAllData();
void login();
int charCounting(char toCount[50]);
void myStrCmp(char userInputChar[50]);
void mailCheck(char toCheck[50]);
void passChecking(char pass[50],int userIndex);
void recordingAllDataToFile();
void userActionSector();
int eFound=-1;
int pFound = -1;
char gmail[11]="@gmail.com";

struct Worker{
    int age;
    char name[30];
    char email[50];
    char password[50];
};

struct Worker info[SIZE];

int main (){
    for(int i=0 ; i<SIZE ;i++){

        printf("Enter your name:");
        scanf(" %[^\n]s",&info[i].name);

        printf("Enter your age:");
        scanf("%d",&info[i].age);

        printf("Enter your email:");
        scanf(" %[^\n]s",&info[i].email);
        mailCheck(info[i].email);


        printf("Enter your password:");
        scanf(" %[^\n]s",&info[i].password);
        printf("===========================\n");



    }
    printingAllData();
    login();
    return 0;
};
void printingAllData(){
    for(int gcc=0; gcc<SIZE; gcc++){
        printf("name:%s - age:%d - email:%s - password:%s\n",info[gcc].name,info[gcc].age,info[gcc].email,info[gcc].password);
    }
};
void login(){
    char lEmail[50]; //user Input
    char passWord[50];
    int found = -1;
    printf("This is Login Form.\n");
    printf("Enter you Email:");
    scanf(" %[^\n]s",lEmail);

    eFound = -1;
    myStrCmp(lEmail);

    printf("Enter Your Password:");
    scanf(" %[^\n]",&passWord);

    pFound = -1;
    passChecking(passWord,eFound);
    if(eFound!=1 && pFound == 1){
        userActionSector();
    } else{
        printf("invalid email or password.\n");
        login();
    }

};
void myStrCmp(char userInputChar[50]){
    int sameCount= 0;
    int second = charCounting(userInputChar);
    for (int i=0 ; i<SIZE;i++){
        int first = charCounting(info[i].email);
        if(first==second){
            for(int gcc=0;gcc<first;gcc++){
                if(info[i].email[gcc]!= userInputChar[gcc]){
                    break;
                }else{
                    sameCount++;
                }
            }
        }
        if(second==sameCount){
            eFound=i;
            break;
        }
    };

}

void passChecking(char pass[50],int userIndex){
    int passCount=charCounting(pass);
    int infoPassCount = charCounting(info[userIndex].password);
    int sameCount = 0;
    if(passCount==infoPassCount){
        for(int ncc=0; ncc<passCount;ncc++){
            if(pass[ncc] == info[userIndex].password[ncc]){
                sameCount++;
            } else{
                break;
            }
        }
        if(sameCount == passCount){
            pFound = 1;
        }
    }



};

int charCounting(char toCount[50]){
    int charCount = 0;
    for(int gcc=0;gcc<50;gcc++){
        if(toCount[gcc]=='\0'){
            break;
        } else{
            charCount++;
        }
    }
    return charCount;
};

void mailCheck(char toCheck[50]){
    int decimallGmail = 0;
    int mail = 0;
    int gSize = sizeof (gmail);
    for(int a=0;a<gSize;a++){
        mail += gmail[a];
    }
    for(int gcc=0 ; gcc<50; gcc++){
        if(toCheck[gcc]=='@'){
            gSize--;
            for(int i=0;i<gSize;i++){
//                printf("%d\n",toCheck[gcc]);
                decimallGmail += toCheck[gcc];
                toCheck[gcc++];
            };

            if(toCheck[gcc]=='\0'){
                break;
            }
        }
    };
//    printf("%d",decimallGmail);
    if(decimallGmail==mail){
        printf("Mail is valid\n");
    } else{
        printf("invalid Email\n");
    }
};

void recordingAllDataToFile(){
    FILE *fptr = fopen ("dipDb.txt", 'w');

    if(fptr == NULL){
        printf("Error at recordingAllDataToFile fun();\n");
    } else{
        for(int gcc=0;gcc<3;gcc++){
            fprintf(fptr,"%d %s %s %s %c",info[gcc].age,info[gcc].name,info[gcc].email,info[gcc].password,'\n');
        }
        printf("Recording all data to dipDB.txt is complete!\n");
    }

}

void userActionSector(){
    int userAction=0;
    printf("Welcome Sir: %s \n",info[eFound].name);
    printf("Press 1 to User Action Sector:\n");
    printf("Press 2 to Home:\n");
    printf("Press 3 to Exit:\n");
    scanf("%d",&userAction);

    if(userAction == 1){
        printf("this is user action sector:\n");
    } else if(userAction==2){
        login();
    }else if(userAction==3) {
        recordingAllDataToFile();
    } else{
        printf("Invalid Option");
    }



}
