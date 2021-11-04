#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<ctype.h>


typedef struct details
{
    char sname[20];
    char rname[20];
    char radd1[100];
    char radd2[100];
    char radd3[100];
    char sadd1[100];
    char sadd2[100];
    char sadd3[100];
    char email[50];
    char city[20];
    char trackid[50];
    char filename[50];
    int type;
    char others[100];
    float weight;
    float distance;
    float net;
    float tax;
    float total;
    int spin;
    int rpin;
    long long sphno;
    long long rphno;
    int billno;
    char datetime[50];
}det;

void inputstring(char[]);
void inputstringn(char[]);
void login();
void euser();
void nuser();
void services();
void track();
void invoice(det*);
void home();
void createfile(det*);
void feeddata(det*);
void retrievedata(char[]);
void generate(det*);
void volumecalculator();
void bannedarticles();
void more();
int passwordvalid(char[]);
void franchiseelogin();
void employeelogin();
void franchisee();
void employee();
void weightprice(det*);
void distanceprice(det*);
void foodprice(det*);
void otherprice(det*);
void payment(det*);
void tandc();

/*input of string without enter character*/
void inputstring(char s[])
{
    int i = 0;
    s[i] = getchar();
    while (s[i++] != '\n')
    {
        s[i] = getchar();
    }
    s[i - 1] = '\0';
}

/*input of string with enter character if in case*/
void inputstringn(char s[])
{
    int i;
    if (getchar() == '\n') {
        i = 0;

        while (s[i++] != '\n')
        {
            s[i] = getchar();
        }
    }
    for (int j = 0;j < i;j++)
    {
        s[j] = s[j + 1];
    }
    s[i - 2] = '\0';
}

//main method
void main()
{
    printf("\n");
    home();
}

//home page
void home()
{
    printf("\n\t\t\tFriendly Couriers\t\t\t\n");
    printf("1.Admin\n2.Services\n3.Track Order\n4.Terms and Conditions\n5.More Tools\n6.Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        services();
        break;
    case 3:
        track();
        break;
    case 4:
        tandc();
        break;
    case 5:
        more();
        break;
    case 6:
        printf("Thank you for exploring Friendly Couriers !!");
        exit(0);
    default:
        printf("Please enter a valid option");
        break;
    }
}

//login page for both existing and new accounts
void login()
{
    int choice;
    int n = 3;
    printf("\n\t\t\tFriendly Couriers\t\t\t\n");
    printf("-----------------------------------------------------------------\n");
    printf("1.Login (Existing User)\n2.New Account (Sign Up)\n3.Home\n");
    scanf("%d", &choice);
    if (choice == 1)
        euser();
    else if (choice == 2)
        nuser();
    else if (choice == 3)
        home();
    else
    {
        printf("Please enter a valid choice !!\n");
        login();
    }
}

//page for existing users
void euser()
{

    printf("\n\t\t\tWelecome to Friendly Couriers\t\t\t\n");
    printf("-----------------------------------------------------------------\n");
    printf("1.Franchisee Login\n2.Employees Login\n3.Back\n");
    int type;
    scanf("%d", &type);
    if (type == 1)
        franchiseelogin();
    else if (type == 2)
        employeelogin();
    else if (type == 3)
        login();
    else
        home();
}
//login link for franchisee or admin
void franchiseelogin()
{
    char uname[50], pass[50];
    char ch;
    printf("Enter username :\n");
    inputstringn(uname);
    printf("\nEnter password :\n");
    int i;
    while (1) {
        if (i < 0) {
            i = 0;
        }
        ch = getch();
        if (ch == 13)//Ascii value of enter
            break;
        if (ch == 8) //Ascii value of backspace
        {
            putch('\b');//\b is for backspace
            putch(' ');
            putch('\b');
            i--;
            continue;
        }
        pass[i++] = ch;
        ch = '*';
        putch(ch);//masking character
    }
    pass[i] = '\0';
    FILE* f;
    f = fopen("flogin.txt", "r");
    char username[50];
    char password[50];
    char data[200];
    char c;
    int j, k;
repeat:k = 0;
    while ((c = fgetc(f)) != '\n')
    {
        if (c == EOF)
            goto jump;
        else
            username[k++] = c;
    }
    username[k] = '\0';
    j = 0;
    while ((c = fgetc(f)) != '\n')
    {
        password[j++] = c;
    }
    password[j] = '\0';
    int temp1 = strcmp(username, uname);
    int temp2 = strcmp(password, pass);
    if (temp1 == 0 && temp2 == 0)
    {
        printf("\n\nPlease Wait , reaching the server ......\n");
        Sleep(2000);
        printf("\nLogged in Successfully !");
        franchisee();
    }
    else
    {
        goto repeat;
    }
jump:printf("\nInvalid Login Credentials !\nRedirecting to login page !\n");
    Sleep(2000);
    login();
}

//login link for employee
void employeelogin()
{
    char uname[50], pass[50];
    char ch;
    printf("Enter username :\n");
    inputstringn(uname);
    printf("\nEnter password :\n");
    int i;
    while (1) {
        if (i < 0) {
            i = 0;
        }
        ch = getch();
        if (ch == 13)//Ascii value of enter
            break;
        if (ch == 8) //Ascii value of backspace
        {
            putch('\b');
            putch(' ');
            putch('\b');
            i--;
            continue;
        }
        pass[i++] = ch;
        ch = '*';
        putch(ch);
    }
    pass[i] = '\0';
    FILE* f;    //use of file structure
    f = fopen("elogin.txt", "r");
    char username[50];
    char password[50];
    char data[200];
    char c;
    int j, k;
repeat:k = 0;       //goto statement label
    while ((c = fgetc(f)) != '\n')
    {
        if (c == EOF)
            goto jump;
        else
            username[k++] = c;
    }
    username[k] = '\0';
    j = 0;
    while ((c = fgetc(f)) != '\n')
    {
        password[j++] = c;
    }
    password[j] = '\0';
    int temp1 = strcmp(username, uname);
    int temp2 = strcmp(password, pass);//comparing username and password
    if (temp1 == 0 && temp2 == 0)
    {
        printf("\n\nPlease Wait , reaching the server ......\n");
        Sleep(2000);
        printf("\nLogged in Successfully !");
        employee();
    }
    else
    {
        goto repeat;
    }
jump:printf("\nInvalid Login Credentials !\nRedirecting to login page !\n");
    Sleep(2000);
    login();
}

//function to check for the validity of the password
int passwordvalid(char password[50])
{
    int len = strlen(password);
    int n = 0, l = 0, u = 0, s = 0;
    for (int i = 0;i < len;i++)
    {
        char c = password[i];
        if (islower(c))
            l++;
        if (isupper(c))
            u++;
        if (isdigit(c))
            n++;
        if (c == '$' || c == '@' || c == '#' || c == '*' || c == '&' || c == '^')
            s++;
    }
    if (n && l && u && s && (len >= 6))
        return 1;
    else
        return 0;
}

//sign up page for new users
void nuser()
{
    int n;
    char ch;
    char username[40];
    char password[30];
    char c;
    int type;
    long long secret;
    printf("\n\t\t\tWelcome to Friendly Couriers\t\t\t\n");
    printf("-----------------------------------------------------------------\n");
    printf("Please sign up the following details :\n");
    printf("Are you a franchisee or employee (F or E) :\n");scanf("%c", &c);
    scanf("%c", &c);
    if (c == 'f' || c == 'F')
    {
        printf("\nIf you are a franchisee, please enter the secret code or 0 to go back :\n");
        scanf("%lld", &secret);
        if (secret == 395142306)  //a special secret code known to admin and higher officials
            type = 1;
        else
        {
            printf("Wrong Secret Code !!\nMoving to Sign Up!!\n");
            Sleep(1500);
            nuser();
        }

    }
    else if (c == 'e' || c == 'E')
    {
        type = 2;
    }

    printf("\nEnter a username :\n");
    scanf("%s", username);
passworderror:printf("\nEnter a password : (min 6 characters - password contains atleast 1 special character (@,#,$,^,&,*),\n1 uppercase, 1 lowercase and 1 number )\n");
    int i;
    while (1) {
        if (i < 0) {
            i = 0;
        }
        ch = getch();
        if (ch == 13)//Ascii value of enter
            break;
        if (ch == 8) //Ascii value of backspace
        {
            putch('\b');
            putch(' ');//removing the character
            putch('\b');
            i--;
            continue;
        }
        password[i++] = ch;
        ch = '*';   //masking the password characters
        putch(ch);
    }
    password[i] = '\0';
    printf("\nPress 1 to proceed else 0 to cancel");
    scanf("%d", &n);
    if (n)
    {
        int check = passwordvalid(password);
        if (check)
        {
            printf("Account activation in progress....\nFeeding details to server...\n");
            Sleep(3500);
            FILE* f;
            if (type == 1)
            {
                f = fopen("flogin.txt", "a");
            }
            else if (type == 2)
            {
                f = fopen("elogin.txt", "a");
            }
            fprintf(f, "%s", username);
            fprintf(f, "%s", "\n");
            fprintf(f, "%s", password);
            fprintf(f, "%s", "\n");
            fclose(f);
            printf("Account created under username - %s\n", username);
        reenter:printf("\nPress 1 to move to login page or 0 to homepage .\n");
            ch = getch();
            if (ch == '1')
            {
                printf("\nTransferring details to login server ....\n");
                Sleep(1500);
                login();
            }
            else if (ch == '0')
            {
                printf("\nProceeding to homepage !\n");
                Sleep(1500);
                home();
            }
            else
            {
                printf("Please enter a valid option !!\n");
                goto reenter;
            }
        }
        else
        {
            printf("\nPlease enter a valid password !!\n");
            goto passworderror;
        }
    }
    else
    {
        printf("Cancelled ! Leading to Home Page .....\n");
        Sleep(1500);
        home();
    }
}

char captcha[7][50] = { "Xuj45k","Gi64Ne","Ps2Kb6","7Ju4sG","Yu1DF9","Afg67j","iL8S34" };//random captcha codes

void services()
{
    det* d = (det*)malloc(sizeof(det));//*d is pointer ;d is address of ptra
    printf("\t\t\tWelecome to Friendly Couriers\t\t\t\n");
    printf("Please enter the following details (Note : Domestic Services only) : \n");
    printf("\nEnter sender name :");
    inputstringn(d->sname);
    printf("\nEnter your address :\n");
    printf("Line 1 :\n");
    inputstring(d->sadd1);
    printf("Line 2 :\n");
    inputstring(d->sadd2);
    printf("Line 3 :\n");
    inputstring(d->sadd3);
    printf("Pincode :\n");
    scanf("%d", &d->spin);
    printf("\nEnter receiver name :");
    inputstringn(d->rname);
    printf("\nEnter receiver address :\n");
    printf("Line 1 :\n");
    inputstring(d->radd1);
    printf("Line 2 :\n");
    inputstring(d->radd2);
    printf("Line 3 :\n");
    inputstring(d->radd3);
    printf("Pincode :\n");
    scanf("%d", &d->rpin);
    printf("\nEnter document type :");
    printf("\n1.Goods\n2.Documents\n3.Food\n4.Others\n");
    scanf("%d", &d->type);
    if (d->type == 1)
        weightprice(d);
    else if (d->type == 2)
        distanceprice(d);
    else if (d->type == 3)
        foodprice(d);
    else if (d->type == 4)
    {
        printf("Please specify the type of cargo you want to ship :\n");
        inputstringn(d->others);
        distanceprice(d);
    }
    printf("\nEnter your ph no :");
    scanf("%lld", &d->sphno);
    printf("\nEnter receiver ph no :");
    scanf("%lld", &d->rphno);
    printf("\nEnter email :");
    inputstringn(d->email);
    printf("\nEnter your city:");
    inputstring(d->city);//current city - first three letters
    char t;
    printf("\nAre you sure you want continue, then press enter else 0 to cancel :");
    scanf("%c", &t);
    if (t == '\n')
    {
        generate(d);
        createfile(d);
        feeddata(d);

    reenter:printf("Please enter the below captcha code to invoice else 0 to cancel : \n");
        int temp = rand();
        while (!(temp >= 1 && temp <= 6))
        {
            temp = rand();
        }
        char recaptcha[50];
        printf("%s\n", captcha[temp]);
        scanf("%s", recaptcha);
        if (strcmp(captcha[temp], recaptcha) == 0)
        {
            printf("\nPassing details to the server.....");
            Sleep(3000);//milliseconds=3 seconds
            invoice(d);
        }
        else
            goto reenter;
    }
    else if (t == '0')
        home();
}


void generate(det* d)
{
    char tid[11];
    srand(time(0));
    int add1 = rand();
    int add2 = rand();
    time_t curtime;
    time(&curtime);
    int bno = rand();
    char* tempdt = ctime(&curtime);
    int i;
    for (i = 0;i < strlen(tempdt);i++)
    {
        d->datetime[i] = *(tempdt + i);
    }
    d->datetime[i - 1] = '\0';
    while (!(bno > 100 && bno < 1000))
    {
        bno = rand();
    }
    d->billno = bno;
    while (!(add1 > 1000 && add1 < 10000))
    {
        add1 = rand();//6687
    }
    while (!(add2 > 1000 && add2 < 10000))
    {
        add2 = rand();//1256
    }
    long int add = (add1 * 10000 + add2);
    for (int i = 0;i < 3;i++)
    {
        char c = d->city[i];
        tid[i] = toupper(c);//city first 3 lettersBAN
    }
    long int temp = add;
    for (int i = 10;i >= 3;i--)
    {
        char c = (temp % 10) + '0';
        tid[i] = c;
        temp /= 10;
    }
    tid[11] = '\0';
    for (int i = 0;i < 11;i++)
    {
        d->trackid[i] = tid[i];
    }
    d->trackid[11] = '\0';
}
void createfile(det* d)
{
    char address[15];
    for (int i = 0;i < 11;i++)
    {
        address[i] = d->trackid[i];//ban12345678
    }
    address[11] = '.';
    address[12] = 't';
    address[13] = 'x';
    address[14] = 't';
    address[15] = '\0';//ban12345678.txt
    for (int i = 0;i < 15;i++)
    {
        d->filename[i] = address[i];
    }
    d->filename[15] = '\0';
}

char type[4][10] = { "Goods","Document","Food","Others" };
void invoice(det* d)
{
    printf("\n\t\t\tFriendly Couriers\t\t\t\n");
    printf("----------------------------------------------------------\n");
    printf("Bill No : %d \t     Date/Time: %s\n", d->billno, d->datetime);
    printf("From : \n%s\n%s\n%s\n%s - %d\nPh - %lld\n", d->sname, d->sadd1, d->sadd2, d->sadd3, d->spin, d->sphno);
    printf("----------------------------------------------------------\n");
    printf("To : \n%s\n%s\n%s\n%s - %d\nPh - %lld\n", d->rname, d->radd1, d->radd2, d->radd3, d->rpin, d->rphno);
    printf("----------------------------------------------------------\n");
    printf("Weight in kgs : %.2f kgs \n\t\tOR\n", d->weight);
    printf("Distance in kms : %.2f kms\n", d->distance);
    printf("----------------------------------------------------------\n");
    printf("Net Amount   : Rs.%.2f\n", d->net);
    printf("GST Amount   : Rs.%.2f\n", d->tax);
    printf("Total Amount : Rs.%.2f\n", d->total);
    printf("----------------------------------------------------------\n");
    printf("Courier Type : %s\n", type[d->type - 1]);
    printf("Your TRACK ID for the courier is : %s\n", d->trackid);
    printf("Invoice details are mailed to your email address - \n%s", d->email);
    printf("\n----------------------------------------------------------\n");
    printf("Press 1 to payment or 0 to cancel !\n");
    int t;
    scanf("%d", &t);
    if (t == 1)
        payment(d);
    else if (t == 0)
        home();
}


void feeddata(det* d)
{
    FILE* f;
    f = fopen(d->filename, "a");
    fprintf(f, "%d\n%s\n%s\n%s\n%s\n%s\n%d\n%lld\n%s\n%s\n%s\n%s\n%d\n%lld\n%s\n%s\n%.2f\n%s\n%.2f\n%.2f\n%.2f\n%.2f\n%s", d->billno, d->datetime, d->sname, d->sadd1, d->sadd2, d->sadd3, d->spin, d->sphno, d->rname, d->radd1, d->radd2, d->radd3, d->rpin, d->rphno, d->email, type[d->type - 1], d->weight, "OR", d->distance, d->net, d->tax, d->total, d->trackid);
    fclose(f);
}

char heading[23][50] = { "Bill No : ","Date/Time : ","Sender's Name : ","Address L1 : ","Address L2 : ","Address L3 : ","Pincode    : ","Mob : ","Receiver's Name : ","Address L1 : ","Address L2 : ","Address L3 : ","Pincode    : ","Mob : ","Email : ","Courier Type : ","Weight :","\t","Distance :","Net Amount   :","Tax Amount   :","Total Amount :","Track ID : " };

void track()
{
    char trackid[8];
    printf("Please enter your courier track id: \n");
    scanf("%s", trackid);
    for (int i = 0;i < 3;i++)
    {
        trackid[i] = toupper(trackid[i]);
    }
    printf("Searching for required data ....\n");
    Sleep(4000);
    retrievedata(trackid);
}

void retrievedata(char trackid[])
{
    FILE* f;
    char filename[15];
    for (int i = 0;i < 11;i++)
    {
        filename[i] = trackid[i];//ban12345678
    }
    filename[11] = '.';
    filename[12] = 't';
    filename[13] = 'x';
    filename[14] = 't';
    filename[15] = '\0';
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Error ! While opening file !");
        printf("Redirecting to home !");
        Sleep(1500);
        home();
    }
    char ch;
    if (f)
    {
        printf("Details for track id : %s\n------------------------------------------------------------\n", trackid);
        for (int i = 0;i < 23;i++)
        {
            printf("%s", heading[i]);
            while ((ch = fgetc(f)) != '\n')
            {
                if (ch != EOF)
                    putchar(ch);
                else
                    break;
            }
            printf("\n");
        }
    }
    printf("\nStatus : Out to Delivery !!");//status confirmation
    fclose(f);
    printf("\n\nPress 1 to home\nPress 0 to exit");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nRedirecting to Homepage.....\n\n");
        Sleep(1500);
        home();
    }
    else if (choice == 0)
    {
        exit(0);
    }
}


void volumecalculator()
{
    float l, b, h, v;
    printf("Volume of Cargo Calculator :\nEnter length, breadth and height:\n");
    scanf("%f%f%f", &l, &b, &h);
    v = l * b * h;
    printf("\nVolume : %f", v);
    printf("\n\nPress 1 to home\nPress 0 to exit");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nRedirecting to Homepage.....\n\n");
        Sleep(1500);
        home();
    }
    else if (choice == 0)
    {
        exit(0);
    }
}

void bannedarticles()
{
    FILE* f;
    f = fopen("bannedarticles.txt", "r");
    char ch;
    if (f)
    {
        while ((ch = fgetc(f)) != EOF)
        {
            putchar(ch);
        }
        printf("\n");
    }
    fclose(f);
    printf("\n\nPress 1 to home\nPress 0 to exit");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nRedirecting to Homepage.....\n\n");
        Sleep(1500);
        home();
    }
    else if (choice == 0)
    {
        exit(0);
    }
}
void more()
{
    printf("\n\t\t\t\t\tFriendly Couriers\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("1.Volume of Carriage\n2.Banned Articles\n3.Back\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        volumecalculator();
        break;
    case 2:
        bannedarticles();
        break;
    case 3:
        home();
        break;
    default:
        exit(0);
    }
}


void weightprice(det* d)
{
    printf("\nEnter the weight of goods: ");
    scanf("%f", &d->weight);
    float w = d->weight;
    float p = 0.0;
    if (w > 0 && w <= 10)
        p = 30.0;
    else if (w > 10 && w <= 50)
        p = 30.0 + (w - 10.0) * 1.5;
    else if (w > 50 && w <= 100)
        p = 30.0 + (1.5 * 40) + (w - 50.0) * 2.0;
    else if (w > 100 && w <= 150)
        p = 30.0 + (1.5 * 40) + (50 * 2.0) + (w - 100.0) * 2.25;
    else if (w > 150 && w <= 200)
        p = 30.0 + (1.5 * 40) + (50 * 2.0) + (50 * 2.25) + (w - 150.0) * 2.5;
    else if (w > 200 && w <= 1000)
        p = 30.0 + (1.5 * 40) + (50 * 2.0) + (50 * 2.25) + (50.0 * 2.5) + (w - 200.0) * 2.75;
    else if (w > 1000)
        p = 30.0 + (1.5 * 40) + (50 * 2.0) + (50 * 2.25) + (50.0 * 2.5) + (800.0 * 2.75) + (w - 1000.0) * 3.0;
    else
    {
        printf("Please enter a valid weight !\n");
        weightprice(d);
    }
    d->net = p;
    d->tax = (0.06 * p);
    d->total = d->net + d->tax;
    d->distance = 0.0;
}


void distanceprice(det* d)//documnet type
{
    float dis;
    float p = 0.0;
    printf("\nEnter the distance between source and destination : ");
    scanf("%f", &dis);
    if (dis > 0 && dis <= 50)
        p = 30;
    else if (dis > 50 && dis <= 150)
        p = 30 + (dis - 50) * 0.25;
    else if (dis > 150 && dis <= 400)
        p = 30 + 100 * 0.25 + (dis - 150) * 0.35;
    else if (dis > 400 && dis <= 800)
        p = 30 + 100 * 0.25 + 250 * 0.35 + (dis - 400) * 0.45;
    else if (dis > 800 && dis <= 1500)
        p = 30 + 100 * 0.25 + 250 * 0.35 + 400 * 0.45 + (dis - 800) * 0.5;
    else if (dis > 1500)
        p = 30 + 100 * 0.25 + 250 * 0.35 + 400 * 0.45 + 700 * 0.5 + (dis - 1500) * 0.525;
    else
    {
        printf("Please enter a valid distance !\n");
        distanceprice(d);
    }
    d->net = p;
    d->tax = (0.06 * p);
    d->total = d->net + d->tax;
    d->weight = 0.0;
    d->distance = dis;
}


void foodprice(det* d)
{
    printf("\nEnter the weight of food product: ");
    scanf("%f", &d->weight);
    float w = d->weight;
    float p = 0.0;
    if (w > 0 && w <= 10)
        p = 20.0;
    else if (w > 10 && w <= 50)
        p = 20.0 + (w - 10.0) * 1.0;
    else if (w > 50 && w <= 100)
        p = 20.0 + (1.0 * 40) + (w - 50.0) * 1.5;
    else if (w > 100 && w <= 150)
        p = 20.0 + (1.0 * 40) + (50 * 1.5) + (w - 100.0) * 1.75;
    else if (w > 150 && w <= 200)
        p = 20.0 + (1.0 * 40) + (50 * 1.5) + (50 * 1.75) + (w - 150.0) * 2.0;
    else if (w > 200 && w <= 1000)
        p = 20.0 + (1.0 * 40) + (50 * 1.5) + (50 * 1.75) + (50.0 * 2.0) + (w - 200.0) * 2.25;
    else if (w > 1000)
        p = 20.0 + (1.0 * 40) + (50 * 1.5) + (50 * 1.75) + (50.0 * 2.0) + (800.0 * 2.25) + (w - 1000.0) * 2.5;
    else
    {
        printf("Please enter a valid weight !\n");
        weightprice(d);
    }
    d->net = p;
    d->tax = (0.06 * p);
    d->total = d->net + d->tax;
    d->distance = 0.0;
}


void payment(det* d)
{
pay:printf("Please enter the mode of payment :\n1.Cash on Delivery\n2.Card\n3.Internet Banking\n4.Cancel Payment Request\n");
    int c;
    char t;
    int cp;
    char upiid[50];
    long long cardno;
    char cvv[10];
    int month;
    int year;
    char ch;
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Amount to be paid : Rs.%f\n", d->total);
        printf("press 1 to confirm or 0 to cancel:\n");
        scanf("%d", &cp);
        if (cp == 1)
        {
            printf("Please wait for the payment to be processed .....\n\n");
            Sleep(3000);
            printf("Payment Successful !!");
            printf("\nRedirecting to Homepage.....\n\n");
            Sleep(1500);
            home();
        }
        else if (cp == 0)
        {
            printf("Payment Unuccessful !!");
            home();
        }
        break;
    case 2:
        printf("Amount to be paid : Rs.%f\n", d->total);
        printf("Enter Card details :\n16 Digit Card Number :\n");
        scanf("%lld", &cardno);
        printf("\nEnter Expiry Date :\nMonth :\n");
        scanf("%d", &month);
        printf("\nYear : \n");
        scanf("%d", &year);
        printf("\nCVV Number :\n");
        int i;
        while (1) {
            if (i < 0) {
                i = 0;
            }
            ch = getch();
            if (ch == 13)//Ascii value of enter
                break;
            if (ch == 8) //Ascii value of backspace
            {
                putch('\b');
                putch(' ');
                putch('\b');
                i--;
                continue;
            }
            cvv[i++] = ch;
            ch = '*';
            putch(ch);
        }
        cvv[i] = '\0';//password will be converted to ****(masking the characters)
        printf("\n\npress 1 to confirm or 0 to cancel:\n");
        scanf("%d", &cp);
        if (cp == 1)
        {
            printf("Please wait for the payment to be processed .....\n\n");
            Sleep(3000);
            printf("Payment Successful !!");
            printf("\nRedirecting to Homepage.....\n\n");
            Sleep(1500);
            home();
        }
        else if (cp == 0)
        {
            printf("Payment Unuccessful !!");
            home();
        }
        break;
    case 3:
        printf("1.PhonePe\n2.Paytm\n3.GooglePay\n4.Back\n");
        scanf("%d", &c);
        printf("\nEnter upi id :\n");
        scanf("%s", upiid);
        printf("\n\npress 1 to confirm or 0 to cancel:\n");
        scanf("%d", &cp);
        if (cp == 1)
        {
            printf("Please wait for the payment to be processed .....\n\n");
            Sleep(3000);
            printf("Payment Successful !!");
            printf("\nRedirecting to Homepage.....\n\n");
            Sleep(1500);
            home();
        }
        else if (cp == 0)
        {
            printf("Payment Unuccessful !!");
            home();
        }
        break;
    case 4:
        home();
        break;
    default:
    {
        printf("Enter a vaild option (1 to 3) !!\n");
        goto pay;
    }
    }
}

void franchisee()
{
    printf("\n\t\t\t\t\tFriendly Couriers\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t   ADMIN MENU\n");
    printf("1.Office Details\n");
    printf("2.Manager Details\n");
    printf("3.Log Out\n");
    if (getch() == '1')
    {
        printf("Branch No : 1\n#5, Plot no 20,\n27th Cross Rd,Jp Techno Park,\nBangalore - 560012\n");
        printf("Branch No : 2\n#21, Plot no 15,\n28th Cross Rd,Koramangala,\nBangalore - 560095\n");
        printf("\npress 1 to log out\n");
        (getch() == '1') ? login() : home();
    }
    else if (getch() == '2')
    {
        printf("Branch No : 1\nManager:\nName : Shivakumar\nAge : 35\nPh N0 : 9546251562\nEmail Id: shivu@gmail.com\n");
        printf("Branch No : 2\nManager:\nName : Rajesh\nAge : 42\nPh N0 : 9941234562\nEmail Id: raju@gmail.com\n");
        printf("\npress 1 to log out\n");
        (getch() == '1') ? login() : home();
    }
    else if (getch() == '3')
    {
        printf("Logging out ......");
        Sleep(2000);
        printf("\nRedirecting to Homepage.....\n\n");
        Sleep(1500);
        home();
    }
    else
    {
        home();
    }
}

void employee()
{
    printf("\n\t\t\t\t\tFriendly Couriers\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t   EMPLOYEE MENU\n");
    printf("1.Salary Details\n");
    printf("2.Attendance Details\n");
    printf("3.Log Out\n");
    if (getch() == '1')
    {
        printf("Name : Likith Sagar \nBasic Pay : Rs.36000\nDA : Rs.10500\nPF : Rs.2500\nTake Home : Rs.49000\n");
        printf("\npress 1 to log out\n");
        (getch() == '1') ? login() : home();
    }
    else if (getch() == '2') {
        printf("Month  of : March\nNo of days : 31 days\nDays Worker : 28 days");
        printf("\npress 1 to log out\n");
        (getch() == '1') ? login() : home();
    }
    else if (getch() == '3')
    {
        printf("Logging out ......");
        Sleep(2000);
        printf("\nRedirecting to Homepage.....\n\n");
        Sleep(1500);
        home();
    }
    else
    {
        home();
    }
}
//terms and conditions of carriage
void tandc()
{
    FILE* f;
    char ch;
    f = fopen("tandc.txt", "r");//r-reading type
    if (f)//true
    {
        while ((ch = fgetc(f)) != EOF)
            putchar(ch);
    }
repeat:printf("\nPress 1 to move to home page !!\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("\nRedirecting to Homepage.....\n\n");
        Sleep(1500);
        home();
    }
    else
    {
        printf("Enter a valid option");
        goto repeat;
    }
    fclose(f);
}
