#include<stdio.h>
#include<string.h>
#include<windows.h>//FOR COLOR
#include<stdlib.h>

struct Customer{  //INFORMATION STRUCTURE;
    char name[20];
    char email[25];
    char phone[12];
    char checkindate[10];
    int roomnumber;
    char nationality[15];
    int stayingperiod;
    char status[10];
    } *s;
FILE *f;

//FUNCTIONS
int login();
int menuDriven();
void add();
void deleterecord();
void viewrecord(int n);
void search(int n);
void sort(int n);
void view(int n);
void searchByName();
void searchByCheckin_Date();
void searchByRoom_no();
void searchByNationality();
void sortByName(int n);
void sortByRoom_Num(int n);
void sortBystayingPeriod(int n);
void foodbilling();
void roominfo();
void Bill();

struct username{
    char username[20];
    char password[20];};

struct username pass_array[4]={
    {"minhazul","minhazul115"},
    {"wasiq","wasiq115"},
    {"farea","farea115"},
    {"rayeed","rayeed115"},};

//Color
void setcolor(int ForgC){
WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
    wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
    SetConsoleTextAttribute(hStdOut,wColor);}}
//
int main(){
int n;
n=22;
s=(struct Customer*)malloc(n*sizeof(struct Customer));
while (1){      //LOGIN FUNCTION CALL
    int isLogin = login();
        if (isLogin != -1){
            printf("\nLogin Successful.\n");break;}
        else printf("\nLogin Usuccessful.\nPlease Enter a Valid username and password.\n\n");
        system("cls");}

system("cls"); //FOR CLEARING SCREEN
while (1){
    int userChoice = menuDriven();

        if (userChoice == 1)
        view(n);
        else if (userChoice == 2)
        search(n);
        else if (userChoice == 3){ //PUT IF ELSE WHEN COMMENT IS REMOVED
            add(&n);
            n++;
        }

        else if (userChoice == 4)
        sort(n);
        else if (userChoice == 5)
        Bill();
         else if (userChoice == 6)
        foodbilling();
         else if (userChoice == 7)
        roominfo();
        else if (userChoice == 8){
        printf("\nSuccesfully Logged Out.\n");break;}}}
//WASIQ
int login(){
    setcolor(3);
    printf("\t\t *********Mr. Robot HOTEL*********");
    printf("\n\n");
    printf("\n  **************************  LOGIN FORM  **************************  ");

//for user input
char name[20];
char pass[20];
printf(" \n                       ENTER USERNAME:-");
    scanf("%s", &name);
printf(" \n                       ENTER PASSWORD:-");
    scanf("%s", &pass);

for(int i=0; i<=4; i++){
//comparing user input with fixed password
    if((strcmp(name,pass_array[i].username)==0)&&(strcmp(pass,pass_array[i].password)==0)) return i;}
//if the compare is equal it will send back as -1 to main
    return -1;}

//WASIQ
int menuDriven(){
int n;
while (1){
    setcolor(15);
        printf(" \n Enter 1 -> View Records  ");
        printf("\n---------------------------");
        printf(" \n Enter 2 -> Search Records");
        printf("\n---------------------------");
        printf(" \n Enter 3 -> Add Records   ");
        printf("\n---------------------------");
        printf(" \n Enter 4 -> Sort Record   ");
        printf("\n---------------------------");
        printf(" \n Enter 5 -> Billing       ");
        printf("\n---------------------------");
        printf(" \n Enter 6 -> Food Billing  ");
        printf("\n---------------------------");
        printf(" \n Enter 7 -> Room Details  ");
        printf("\n---------------------------");
        printf(" \n Enter 8 -> Exit          ");
        printf("\n---------------------------");
        printf("\n");
printf("Enter: ");
scanf("%d", &n);
if (n >= 1 && n <= 10) return n;
else printf("Enter a Valid Number.\n\n");}}

//FAREA
void view(int n){
int i=0;
system("cls");
printf("<== Customer Info ==>");
printf("\n\n");
printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
printf("---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");
f=fopen("robot.txt","r");
s=(struct Customer*)malloc(n*sizeof(struct Customer));
if(f==NULL){
    printf("Can't open file!");
    exit(1);}

while(!feof(f)){
fscanf(f,"%s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
i++;
}

for(i=0;i<n;i++){
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",s[i].name,s[i].email,s[i].phone,s[i].checkindate,s[i].roomnumber,s[i].nationality,s[i].stayingperiod,s[i].status);
}
fclose(f);
}

//FAREA
void search(int n){
int c;
system("cls");
printf("<==Search==>\n");
printf("1.Search by name\n");
printf("2.Search by check-in date\n");
printf("3.Search by room no\n");
printf("4.Search by nationality\n\n");

printf("Enter the choice:");
scanf("%d",&c);

switch(c){
    case 1:
    searchByName();
    break;
    case 2:
    searchByCheckin_Date();
    break;
    case 3:
    searchByRoom_no();
    break;
    case 4:
    searchByNationality();
    break;
    default:
    printf("Invalid Choice!");
    }
    }

//function to search by customer's name
void searchByName(){
int i=0,flag=0;
char name[30];
FILE *f;
printf("Enter the name:");
scanf("%s",name);
printf(" %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
printf(" ---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");
f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);
}
else{
while(!feof(f)){
fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);

if(strcmp(s[i].name,name)==0){
    flag=1;
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",s[i].name,s[i].email,s[i].phone,s[i].checkindate,s[i].roomnumber,s[i].nationality,s[i].stayingperiod,s[i].status);
    i++;
    break;
}
}
}
fclose(f);
if(flag==1)
    printf("\nRecord found successfully");
else if(flag==0)
    printf("Record not found");
}

//function to search by check-in date
void searchByCheckin_Date(){
int i=0,flag=0;
char date[20];
FILE *f;
printf("Enter the date:");
scanf("%s",date);
printf(" %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
printf(" ---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");
f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);}

while(!feof(f)){
fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
if(strcmp(s[i].checkindate,date)==0){
    flag=1;
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",s[i].name,s[i].email,s[i].phone,s[i].checkindate,s[i].roomnumber,s[i].nationality,s[i].stayingperiod,s[i].status);
    i++;}}

fclose(f);
if(flag==1)
    printf("\nRecord found successfully");
else if(flag==0)
    printf("Record not found");
    }

//function to search by room number
void searchByRoom_no(){
int i=0,flag=0;
int room;
FILE *f;
printf("Enter the room no:");
scanf("%d",&room);
printf(" %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
printf(" ---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");

f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);}

while(!feof(f)){
fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
if(s[i].roomnumber==room){
    flag=1;
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",s[i].name,s[i].email,s[i].phone,s[i].checkindate,s[i].roomnumber,s[i].nationality,s[i].stayingperiod,s[i].status);
    i++; break;}}

fclose(f);
if(flag==1)
    printf("\nRecord found successfully");
else if(flag==0)
    printf("Record not found");}

//function to search by nationality
void searchByNationality(){
int i=0,flag=0;
char nationality[20];
FILE *f;
printf("Enter the nationality:");
scanf("%s",nationality);
printf(" %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
printf(" ---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");
f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);}

while(!feof(f)){
fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
if(strcmp(s[i].nationality,nationality)==0){
    flag=1;
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",s[i].name,s[i].email,s[i].phone,s[i].checkindate,s[i].roomnumber,s[i].nationality,s[i].stayingperiod,s[i].status);
    i++;}}

fclose(f);
if(flag==1)
    printf("\nRecord found successfully");
else if(flag==0)
    printf("Record not found");}

//WASIQ
void add(int *n)
{

    char test;
    FILE *f;

    system("cls");
    f=fopen("robot.txt","a");
    if(f==NULL)
    {
        printf("Can't open file!");
        exit(1);
    }

    system("cls");
    printf("\n Enter Customer Details:");
    printf("\n**************************");
    printf("\n");
    printf("Enter Name:\n");
    scanf("%s",s[*n+1].name);
    fprintf(f,"%s\t\t",s[*n+1].name);

    printf("Enter Email:\n");
    scanf(" %s",s[*n+1].email);
    fprintf(f,"%s\t\t",s[*n+1].email);

    printf("Enter Phone Number:\n");
    scanf("%s",s[*n+1].phone);
    fprintf(f,"%s\t\t",s[*n+1].phone);

    printf("Enter Check in date(dd-mm-yyyy):\n");
    scanf("%s",s[*n+1].checkindate);
    fprintf(f,"%s\t",s[*n+1].checkindate);

    printf("Enter Room number:\n");
    scanf("%d",&s[*n+1].roomnumber);
    fprintf(f,"%d\t",s[*n+1].roomnumber);

    printf("Enter Nationality:\n");
    scanf("%s",s[*n+1].nationality);
    fprintf(f,"%s\t\t",s[*n+1].nationality);

    printf("Enter Period(\'x\'days):\n");
    scanf("%d",&s[*n+1].stayingperiod);
    fprintf(f,"%d\t\t",s[*n+1].stayingperiod);

    printf("Enter Status\n");
    scanf("%s",s[*n+1].status);
    fprintf(f,"%s",s[*n+1].status);

    printf("\n\n1 Record successfully added!!");
    printf("\n Press enter key to exit,  any other key to add another customer detail:");
    test=getche();
    if(test==13) ;
    system("cls");

    fclose(f);
}




//FAREA
void sort(int n){
int ch;
system("cls");
printf("<==Sort==>\n");
printf("1.Sort by name\n");
printf("2.Sort by room number\n");
printf("3.Sort by staying period\n\n");

printf("Enter the choice:");
scanf("%d",&ch);

switch(ch){
    case 1:
    sortByName(n);
    printf("\nRecord sorted successfully");
    break;

    case 2:
    sortByRoom_Num(n);
    printf("\nRecord sorted successfully");
    break;

    case 3:
    sortBystayingPeriod(n);
    printf("\nRecord sorted successfully");
    break;

    default:
    printf("\nInvalid Choice!!");
    }
    }

//function to sort by name of the customers
void sortByName(int n){
int i=0,j,min;
struct Customer c[n],temp;
system("cls");
    printf("<== Customer Info ==>");
    printf("\n");
    printf(" %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
    printf(" ---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");

f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);
    }

while(!feof(f)){

fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
c[i]=s[i];
i=i+1;
}

for(i=0;i<n;i++){
    min=i;
        for(j=i+1;j<n;j++){
            if(strcmp(c[j].name,c[min].name)==-1)
            min=j;
            }
    temp=c[i];
    c[i]=c[min];
    c[min]=temp;
    }

for(i=0;i<n;i++){
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",c[i].name,c[i].email,c[i].phone,c[i].checkindate,c[i].roomnumber,c[i].nationality,c[i].stayingperiod,c[i].status);
}
fclose(f);
}

//function to sort by room number
void sortByRoom_Num(int n){
int i=0,j,min;
struct Customer c[n],temp;
system("cls");
    printf("<== Customer Info ==>");
    printf("\n");
    printf(" %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
    printf(" ---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");

f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);}

while(!feof(f)){
fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
c[i]=s[i];
i++;}

for(i=0;i<n;i++){
    min=i;
        for(j=i+1;j<n;j++){
            if(c[j].roomnumber<c[min].roomnumber) min=j;}
    temp=c[i];
    c[i]=c[min];
    c[min]=temp;}

for(i=0;i<n;i++){
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",c[i].name,c[i].email,c[i].phone,c[i].checkindate,c[i].roomnumber,c[i].nationality,c[i].stayingperiod,c[i].status);
} fclose(f);}

//function to sort by staying period
void sortBystayingPeriod(int n){
int i=0,j,min;
struct Customer c[n],temp;
system("cls");
    printf("<== Customer Info ==>");
    printf("\n");
    printf(" %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n","Name","Email Id","PhoneNO","Check In","RoomNO","Nationality","Staying ","Status");
    printf(" ---------\t----------\t\t----------\t----------\t\t----------\t----------\t\t----------\t----------\n");

f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);}

while(!feof(f)){
fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
c[i]=s[i];
i++;}

for(i=0;i<n;i++){
    min=i;
        for(j=i+1;j<n;j++){
            if(c[j].stayingperiod<c[min].stayingperiod) min=j;}
    temp=c[i];
    c[i]=c[min];
    c[min]=temp;}

for(i=0;i<n;i++){
    printf("%s\t\t%s\t\t%s\t%s\t\t %d\t\t%s\t\t\t %d \t\t%s\n",c[i].name,c[i].email,c[i].phone,c[i].checkindate,c[i].roomnumber,c[i].nationality,c[i].stayingperiod,c[i].status);
} fclose(f);}

//FAREA
void Bill(){
int i=0,flag=0;
float Bill;
char name[20];
FILE *f;
printf("Enter the name:");
scanf("%s",name);

f=fopen("robot.txt","r");
if(f==NULL){
    printf("Can't open file!");
    exit(1);
}

while(!feof(f)){
fscanf(f," %s %s %s %s %d %s %d %s",s[i].name,s[i].email,s[i].phone,s[i].checkindate,&s[i].roomnumber,s[i].nationality,&s[i].stayingperiod,s[i].status);
if(strcmp(s[i].name,name)==0){
    flag=1;
    if(s[i].roomnumber>=100 && s[i].roomnumber<=110 && s[i].roomnumber!=104){
    Bill=s[i].stayingperiod * 4500.00;
    break;
    }
    else if(s[i].roomnumber>=200 && s[i].roomnumber<=210 && s[i].roomnumber!=204){
    Bill=s[i].stayingperiod * 5000.00;
    break;
    }
    else if(s[i].roomnumber>=300 && s[i].roomnumber<=310 &&s[i].roomnumber!=305){
    Bill=s[i].stayingperiod * 6000.00;
    break;
    }
    else if(s[i].roomnumber==204){
    Bill=s[i].stayingperiod * 7000.00;
    break;
    }
    else if(s[i].roomnumber==104|| s[i].roomnumber==305){
    Bill=s[i].stayingperiod * 8500.00;
    break;
    }
    i++;
}
}
if(flag==1)
    printf("\nRecord found successfully\n");
else if(flag==0)
    printf("Record not found");

    printf("\nTotal Bill of %s is=%0.2f\n",s[i].name,Bill);
    fclose(f);
}

//RAYEED
void foodbilling(){

printf("\t\t\t\t\t============Food Prices==================\n");
printf("\t\t\t\t\t_________________________________________\n");
printf("\t\t\t\t\t|Food                        |   Price  |\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|                   Breakfast           |\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|Traditional breakfast       |    BDT150|\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|Continental breakfast       |    BDT200|\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|                   Buffets             |\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|Platter 1                   |    BDT560|\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|Platter 2                   |    BDT450|\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|Platter 3                   |    BDT480|\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|Platter 4                   |    BDT350|\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|Platter 5                   |    BDT520|\n");
printf("\t\t\t\t\t|----------------------------|----------|\n");
printf("\t\t\t\t\t|____________________________|__________|\n\n");

int tb,cb,p1,p2,p3,p4,p5;
int a,b,c,d,e,f,g,total;
printf("Enter your orders:\n");
printf("Traditional: ");
scanf("%d", &tb);
printf("Continental: ");
scanf("%d", &cb);
printf("Platter 1: ");
scanf("%d", &p1);
printf("Platter 2: ");
scanf("%d", &p2);
printf("Platter 3: ");
scanf("%d", &p3);
printf("Platter 4: ");
scanf("%d", &p4);
printf("Platter 5: ");
scanf("%d", &p5);

a=150*tb;
b=200*cb;
c=560*p1;
d=450*p2;
e=480*p3;
f=350*p4;
g=520*p5;

total=a+b+c+d+e+f+g;
return printf("\n\nFood total=%d\n", total);
}


void roominfo(){

printf("\t\t\t========================Prices for Rooms===========================\n");
printf("\t\t\t___________________________________________________________________\n");
printf("\t\t\t|                 Rooms (per night)                    |   Price  |\n");
printf("\t\t\t|------------------------------------------------------|----------|\n");
printf("\t\t\t|Single Bed (without AC) (Rooms 100-110, excluding 104)|   BDT4500|\n");
printf("\t\t\t|------------------------------------------------------|----------|\n");
printf("\t\t\t|Single Bed (with AC) (Rooms 200-210, excluding 204)   |   BDT5000|\n");
printf("\t\t\t|------------------------------------------------------|----------|\n");
printf("\t\t\t|Double Bed (without AC) (Rooms 300-310, excluding 305)|   BDT6000|\n");
printf("\t\t\t|------------------------------------------------------|----------|\n");
printf("\t\t\t|Double Bed (with AC) (Room 204)                       |   BDT7000|\n");
printf("\t\t\t|------------------------------------------------------|----------|\n");
printf("\t\t\t|Ocean view Room (Room 104 and 305)                    |   BDT8500|\n");
printf("\t\t\t|______________________________________________________|__________|\n\n");


}


