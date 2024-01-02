#include<stdio.h>
#include<time.h>
#include<conio.h>
char name[100];
int age,phone;
char  pass[100];
char name1[100];
char passo[100];
float accban=500;
float newa;
float storemoney;
struct user{
     char namf[100000];
     char naml[100000];
     char gmail[100000];
     int n,national;
     char b;

};
void reg()
{

    FILE*file;
    file=fopen( "new.txt","a");
    if(file==NULL)
    {
        printf("The file isnot created");
    }
    else
    {
        struct user u;
        printf("Fill up your information \n");
        printf("Enter your first name=");
        scanf("%s",&u.namf);
        printf("Enter your last name=");
        scanf("%s",&u.naml);
        printf("Enter your phone number(+880)=");
        scanf("%d",&u.n);
        printf("Enter your Email=");
        scanf("%s",&u.gmail);
        printf("Enter your data of birth DD/MM/Year=");
        scanf("%s",&u.b);
        printf("Enter your National ID number/Student ID card=");
        scanf("%d",&u.national);
        printf("Enter your user name= ");
        scanf("%s",&name);
        printf("Enter a password=");
        scanf("%s",&pass);
        fprintf(file,"%s  %s\n",name,pass);
        printf("Registration successfull...");
    }
    fclose(file);
}
void login()
{
    FILE *file;
    file=fopen("new.txt","r");
    if(file==NULL)
    {
        printf("File isnot there");
    }
    else
    {
        char storename[100];
        char storepass[100];
        printf("Enter name=");
        scanf("%s",&name1);
        printf("Enter the password=");
        scanf("%s",&passo);
        while( fscanf(file,"%s %s ",storename,storepass) !=EOF);
        if(strcmp(storename,name1) ==0 && strcmp(storepass,passo)==0)
        {
            printf("Login successfull\n");
            mainu();
        }
        else
        {
            printf("Try again");
            Beep(510,600);
        }
    }
    fclose(file);
}
void mainu()
{
    int c;
    printf("1.Add money.\n");
    printf("2.Withdraw money.\n");
    printf("3.Balance of my account.\n");
    printf("4.Account setting.\n");
    printf("5.Other information.\n");
    printf("6.Exit.\n");

    printf("Enter your choice=");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        add();
        break;
    case 2:
        withdraw();
        break;
    case 3:
        accountb();
        break;
    case 4:
        accounts();
        break;
    case 5:
        information();
        break;
    case 6:
        exit(0);
        break;

    default:
        printf("Try again thanks.");

    }
}
void add()
{
    float newmoney;
    FILE*file;
    file=fopen("add.txt","a");
    if(file==NULL)
    {
        printf("The file isnot created");
    }
    else
    {
        time_t tm;
        time(&tm);
        printf("Enter the password again=");
        scanf("%s",&pass);
        printf("\nEnter your deposit amount=");
        scanf("%f",&newmoney);

        newa=accban+newmoney;
        printf("Account balance is = %f",newa);



        fprintf(file,"%s  %f %s\n",pass,newa,ctime(&tm));
    }
    fclose(file);
}
void withdraw()
{
    float newmoney;
    FILE*file;
    file=fopen("with.txt","a");
    if(file==NULL)
    {
        printf("The file isnot created");
    }
    else
    {
        time_t tm;
        time(&tm);
        float withacc;
        printf("\nEnter withdraw amount=");
        scanf("%f",&withacc);
        if(withacc<500000000)
        {
            printf("Withdraw successfull");
            fprintf(file,"%f  %s\n",withacc,ctime(&tm));
        }
        else
        {
            printf("Please add money to your account.");
        }
    }
    fclose(file);
}
void accountb()
{
    FILE*file;
    file=fopen("add.txt","r");
    if(file==NULL)
    {
        printf("File is not created");
    }
    else
    {
        char ch;
        printf("\nFile is open.\n");
        while(!feof(file))
        {
            ch=fgetc(file);
            printf("%c",ch);
        }
        fclose(file);
    }
}
void information()
{
    printf("\nThis is Sonar Bank Limited.\n");
    printf("Thanks for joining us .\n");
    printf("Sorry sir currently we have no other branch.\n");
    printf("****************************************************************************Sonar Bank Limited.\n");
    printf("***********************************************************************************Dhaka , 1201.");
}
void accounts()
{
    int ch;
    printf("          1.Change password.\n");
    printf("          2.Add picture.\n");
    printf("          3.Update account information.\n");
    printf("Enter the choice=");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        printf("Try again.");

    }

}
int main()
{

    system("color 9F");
    printf("\n                                                Sonar Bank Limited                                           \n\n");
    printf("1.Reg\n2.login");
    int choice;
    printf("\nEnter your choice=");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        reg();
        break;
    case 2:
        login();
        break;
    default:
        printf("Somethink wrong");
    }
    getch();
}

