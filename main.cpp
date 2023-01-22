#include "stdio.h"
#define SIZE 3
void printingAllData();
void login();
int charCounting(char toCount[50]);
void myStrCmp(char userInputChar[50]);
void mailCheck(char toCheck[50]);
int eFound=-1;
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
    int found = -1;
    printf("This is Login Form.\n");
    printf("Enter you Email:");
    scanf(" %[^\n]s",lEmail);

    eFound = -1;
    myStrCmp(lEmail);
    if(eFound!=1){
        printf("Welcome Sir: %s ",info[eFound].name);
    } else{
        printf("invalid email.\n");
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
