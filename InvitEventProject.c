#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//Structure Creation
struct logIn
{
    char RegName[20];
    char RegUserName[30];
    int RegNumber;
    char RegPass[20];
} lgin;


// Function Declarations
void addorganizer();
void adminlogin();
void Orglogin();
void Orgregistration();
void Guelogin();
void Gueregistration();
void OrgDashBoard();
void CrtAcc();
void logout();
void events();
void addguest();
void contact();
int validatePassword(char password[]);
int validateEmail(char email[]);
void Gueregistration();
void createEvent();
void ongoingEvent();
void weddingOrg();
void birthdayOrg();
void companyOrg();
void f1venue();
void f2venue();
void bi1venue();
void bi2venue();
void com1venue();
void com2venue();
void ConOrg();
void HelCen();
void admProfile();
void gueProfile();
void orgProfile();
void hireSpkeaker();
void addSpeaker();
void spk_1();
void spk_2();
void spk_3();
void fedReport();
void feedBack();
void wed1date();
void wed2date();
void wed1time();
void wed2time();



//Main Function
int main()
{
    int stakeholder;
    while(1)
    {
        printf("\t---Invit Event---\n");
        printf("1. Admin Login\n");
        printf("2. Organizer Login\n");
        printf("3. Guest Login\n");
        printf("4. Create new account\n");
        printf("Enter choice: ");
        scanf("%d", &stakeholder);
        switch(stakeholder)
        {
        case 1:
            adminlogin();
            break;
        case 2:
            Orglogin();
            break;
        case 3:
            Guelogin();
            break;
        case 4:
            CrtAcc();
            break;
        default:
            printf("Invalid option\n");
        }
    }
}


//Password Validation Function
int validatePassword(char password[])
{
    int isUpper = 0, isLower = 0, isDigit = 0, isSpecial = 0;
    if (strlen(password) < 8)
    {
        return 0;
    }
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            isUpper = 1;
        }
        else if (islower(password[i]))
        {
            isLower = 1;
        }
        else if (isdigit(password[i]))
        {
            isDigit = 1;
        }
        else if (strchr("!@#$%^&*()-_=+[]{}|;:'\",.<>/?", password[i]))
        {
            isSpecial = 1;
        }
    }
    return isUpper && isLower && isDigit && isSpecial;
}


//Email Validation Function
int validateEmail(char email[])
{
    int atSymbol = 0, dotSymbol = 0;
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@') atSymbol = 1;
        if (email[i] == '.' && atSymbol) dotSymbol = 1;
    }
    return atSymbol && dotSymbol;
}


//Account Creation Function
void CrtAcc()
{
    int orggue;
    printf("\t---Welcome new mate!---\n");
    printf("1. Are you Organizer?\n");
    printf("2. Are you Guest?\n");
    printf("Enter choice: ");
    scanf("%d", &orggue);
    switch(orggue)
    {
    case 1:
        Orgregistration();
        break;
    case 2:
        Gueregistration();
        break;
    default:
        printf("Invalid choice! Try again.\n");
    }
}


//Admin Login Function
void adminlogin()
{
    char username[30], password[20];
    int found = 0;
    FILE *fp = fopen("admin.dat", "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open admin file. Please ensure the file exists.\n");
        return;
    }
    printf("\t-- Admin Log In --\n");
    printf("Email: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    while (fscanf(fp, "%s %d %s %s", lgin.RegName, &lgin.RegNumber, lgin.RegUserName, lgin.RegPass) != EOF)
    {
        if (strcmp(username, lgin.RegUserName) == 0 && strcmp(password, lgin.RegPass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found)
    {
        printf("\nLogin Successful! Welcome, %s.\n", lgin.RegName);
        AdminDashBoard();
    }
    else
    {
        printf("\nLogin Failed! Invalid email or password.\n");
    }
}


//Admin Dashboard function
void AdminDashBoard()
{
    int admindash;
    printf("\t***Dashboard***\n");
    printf("1. Profile\n");
    printf("2. Events\n");
    printf("3. Add Guests\n");
    printf("4. Add Organizer\n");
    printf("5. Add Speaker\n");
    printf("6. Contact\n");
    printf("7. Feedback Report\n");
    printf("8. Log out\n");
    printf("Enter choice: ");
    scanf("%d", &admindash);
    switch (admindash)
    {
    case 1:
        admProfile();
        break;
    case 2:
        events();
        break;
    case 3:
        addguest();
        break;
    case 4:
        addorganizer();
        break;
    case 5:
        addSpeaker();
        break;
    case 6:
        contact();
        break;
    case 7 :
        fedReport();
        break;
    case 8 :
        logout();
        break;
    default:
        printf("Invalid choice\n");

    }
}


//Add Speaker function
void addSpeaker()
{

}


//Feedback Report function only can access admin
void fedReport()
{
    FILE *fp = fopen("feedback.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    char feedback[256];
    printf("Feedback Report:\n");
    printf("-----------------\n");
    while (fgets(feedback, sizeof(feedback), fp) != NULL)
    {
        printf("%s", feedback);
    }
    fclose(fp);
    printf("\nEnd of Feedback Report.\n");
}


//Organizer Registration Function
void Orgregistration()
{
    FILE *fp = fopen("organizer.dat", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter Name: ");
    scanf("%s", lgin.RegName);
    printf("Enter Mobile: ");
    scanf("%d", &lgin.RegNumber);
    do
    {
        printf("Enter email address: ");
        scanf("%s", lgin.RegUserName);
        if (!validateEmail(lgin.RegUserName))
        {
            printf("Invalid email format. Please enter a valid email.\n");
        }
    }
    while (!validateEmail(lgin.RegUserName));
    do
    {
        printf("Create a Password: ");
        scanf("%s", lgin.RegPass);
        if (!validatePassword(lgin.RegPass))
        {
            printf("Password must be: 8 characters, one uppercase letter, one number, and one special character.\n");
        }
    }
    while (!validatePassword(lgin.RegPass));

    fprintf(fp, "%s %d %s %s\n", lgin.RegName, lgin.RegNumber, lgin.RegUserName, lgin.RegPass);
    fclose(fp);
    printf("\nRegistration Successful\n");
}


//Organizer Login function
void Orglogin()
{
    char username[30], password[20];
    int found = 0;
    FILE *fp = fopen("organizer.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    printf("Email: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    while (fscanf(fp, "%s %d %s %s", lgin.RegName, &lgin.RegNumber, lgin.RegUserName, lgin.RegPass) != EOF)
    {
        if (strcmp(username, lgin.RegUserName) == 0 && strcmp(password, lgin.RegPass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found)
    {
        printf("Login Successful! Welcome\n");
        OrgDashBoard();
    }
    else
    {
        printf("Login Failed! Invalid username or password.\n");
    }
}

//Organizer Dashboard Function
void OrgDashBoard()
{
    int orgdash;
    printf("\t***Dashboard***\n");
    printf("1. Profile\n");
    printf("2. Events\n");
    printf("3. Add Guests\n");
    printf("4. Hire Speaker\n");
    printf("5. Contact\n");
    printf("6. Feedback\n");
    printf("7. Log out\n");
    printf("Enter choice: ");
    scanf("%d", &orgdash);
    switch (orgdash)
    {
    case 1:
        orgProfile();
        break;
    case 2:
        events();
        break;
    case 3:
        addguest();
        break;
    case 4:
        hireSpeaker();
        break;
    case 5:
        contact();
        break;
    case 6:
        feedBack();
        break;
    case 7:
        logout();
        break;
    default:
        printf("Invalid choice\n");
    }
}

//Feedback function organizer & guest can access
void feedBack()
{
    FILE *fp = fopen("feedback.dat", "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    char feedback[256];
    printf("Please enter your feedback (up to 255 characters):\n");

    fflush(stdin); // Clear any leftover input
    fgets(feedback, sizeof(feedback), stdin);

    fprintf(fp, "%s", feedback);
    fclose(fp);
    printf("Thank you for your feedback!\n");
}

// Guest login function
void Guelogin()
{
    char username[30], password[20];
    int found = 0;
    FILE *fp = fopen("guest.dat", "r");  // Read mode to check for login
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Email: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Read each line and compare with input
    while (fscanf(fp, "%s %d %s %s", lgin.RegName, &lgin.RegNumber, lgin.RegUserName, lgin.RegPass) != EOF)
    {
        if (strcmp(username, lgin.RegUserName) == 0 && strcmp(password, lgin.RegPass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found)
    {
        printf("Login Successful! Welcome, %s.\n", username);
        GueDashBoard();  // After successful login, redirect to guest dashboard
    }
    else
    {
        printf("Login Failed! Invalid username or password.\n");
    }
}

//Guest Dashboard Function
void GueDashBoard()
{
    int guedash;
    printf("\t***Dashboard***\n");
    printf("1. Profile\n");
    printf("2. Events\n");
    printf("3. Contact\n");
    printf("4. Feedback\n");
    printf("5. Log out\n");
    printf("Enter choice: ");
    scanf("%d", &guedash);
    switch (guedash)
    {
    case 1:
        gueProfile();
        break;
    case 2:
        ongoingEvent();
        break;
    case 3:
        contact();
        break;
    case 4:
        feedBack();
        break;
    case 5:
        logout();
        break;
    default:
        printf("Invalid choice\n");
    }
}

//Guest Registration Function
void Gueregistration()
{
    FILE *fp = fopen("guest.dat", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter Name: ");
    scanf("%s", lgin.RegName);
    printf("Enter Mobile: ");
    scanf("%d", &lgin.RegNumber);

    do
    {
        printf("Enter email address: ");
        scanf("%s", lgin.RegUserName);
        if (!validateEmail(lgin.RegUserName))
        {
            printf("Invalid email format. Please enter a valid email.\n");
        }
    }
    while (!validateEmail(lgin.RegUserName));

    do
    {
        printf("Create a Password: ");
        scanf("%s", lgin.RegPass);
        if (!validatePassword(lgin.RegPass))
        {
            printf("Password must be: 8 characters, one uppercase letter, one number, and one special character.\n");
        }
    }
    while (!validatePassword(lgin.RegPass));

    fprintf(fp, "%s %d %s %s\n", lgin.RegName, lgin.RegNumber, lgin.RegUserName, lgin.RegPass);
    fclose(fp);
    printf("\nRegistration Successful\n");
}

//Admin profile Function
void admProfile()
{
    char email[30], password[20];
    int found = 0;
    printf("Enter your registered email: ");
    scanf("%s", email);
    printf("Enter your password: ");
    scanf("%s", password);
    FILE *fp = fopen("admin.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    while (fscanf(fp, "%s %d %s %s", lgin.RegName, &lgin.RegNumber, lgin.RegUserName, lgin.RegPass) != EOF)
    {
        if (strcmp(email, lgin.RegUserName) == 0 && strcmp(password, lgin.RegPass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found)
    {
        printf("\n\t---Admin Profile---\n");
        printf("Name: %s\n", lgin.RegName);
        printf("Mobile: %d\n", lgin.RegNumber);
        printf("Email: %s\n", lgin.RegUserName);
    }
    else
    {
        printf("\nNo matching profile found! Please check your email and password.\n");
    }
}

//Guest profile function
void gueProfile()
{
    char email[30], password[20];
    int found = 0;
    printf("Enter your registered email: ");
    scanf("%s", email);
    printf("Enter your password: ");
    scanf("%s", password);
    FILE *fp = fopen("guest.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    while (fscanf(fp, "%s %d %s %s", lgin.RegName, &lgin.RegNumber, lgin.RegUserName, lgin.RegPass) != EOF)
    {
        if (strcmp(email, lgin.RegUserName) == 0 && strcmp(password, lgin.RegPass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found)
    {
        printf("\n\t---Guest Profile---\n");
        printf("Name: %s\n", lgin.RegName);
        printf("Mobile: %d\n", lgin.RegNumber);
        printf("Email: %s\n", lgin.RegUserName);
    }
    else
    {
        printf("\nNo matching profile found! Please check your email and password.\n");
    }
}

void orgProfile()
{
    char email[30], password[20];
    int found = 0;
    printf("Enter your registered email: ");
    scanf("%s", email);
    printf("Enter your password: ");
    scanf("%s", password);
    FILE *fp = fopen("organizer.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    while (fscanf(fp, "%s %d %s %s", lgin.RegName, &lgin.RegNumber, lgin.RegUserName, lgin.RegPass) != EOF)
    {
        if (strcmp(email, lgin.RegUserName) == 0 && strcmp(password, lgin.RegPass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found)
    {
        printf("\n\t---Organizer Profile---\n");
        printf("Name: %s\n", lgin.RegName);
        printf("Mobile: %d\n", lgin.RegNumber);
        printf("Email: %s\n", lgin.RegUserName);
    }
    else
    {
        printf("\nNo matching profile found! Please check your email and password.\n");
    }
}


//Event Function
void events()
{
    int event;
    printf("\n\t---Events---");
    printf("\n1. Create Event");
    printf("\n2. Ongoing Event\n");
    scanf("%d", &event);
    switch(event)
    {
    case 1:
        createEvent();
        break;
    case 2:
        ongoingEvent();
        break;
    }
}

//Create Event Function
void createEvent()
{
    int optcrev;
    printf("\n1.Wedding Event\n");
    printf("2.Birthday Party\n");
    printf("3.Company Event\n");
    scanf("%d", &optcrev);
    switch(optcrev)
    {
    case 1:
        weddingOrg();
        break;
    case 2:
        birthdayOrg();
        break;
    case 3:
        companyOrg();
        break;
    default:
        printf("Invalid choice\n");
    }
}

//Wedding event venue & schedule function
void weddingOrg()
{
    int wedVenue;
    printf("\n\t---Venue List---\n");
    printf("1.Sena Malancha\n");
    printf("2.Aziz Manzil-Party Place & Banquet Hall\n");
    scanf("%d", &wedVenue);
    switch(wedVenue)
    {
    case 1:
        wed1date();
        break;
    case 2:
        wed2date();
        break;
    default:
        printf("\nInvalid Choice\n");
    }
}

void wed1date(){
    int wed_1;
    printf("\n1. 12/12/2024\n");
    printf("2. 15/12/2024\n");
    printf("3. 20/12/20224\n");
    if(wed_1 == 1 || wed_1 == 2 || wed_1 == 3){
        wed1time();
    }
    else{
        printf("\nInvalid Choice\n");
    }
}

void wed2date(){
    int wed_1;
    printf("\n1. 12/12/2024\n");
    printf("2. 15/12/2024\n");
    printf("3. 20/12/20224\n");
    if(wed_1 == 1 || wed_1 == 2 || wed_1 == 3){
        wed2time();
    }
    else{
        printf("\nInvalid Choice\n");
    }
}


void wed1time()
{
    int wed1tm;
    printf("\t---Time---\n");
    printf("1. (1:30 - 4:00)pm\n");
    printf("2. (7:30 - 10:00)pm\n");
    scanf("%d", &wed1tm);
    switch(wed1tm)
    {
    case 1:
        printf("\nBooking Successfull. Thank you.\n");
    case 2:
        printf("\nSuccessfully Booked. Thank you.\n");
    }
}
void wed2time()
{
    int wed2tm;
    printf("\t---Time---\n");
    printf("1. (2:00 - 5:00)pm\n");
    printf("2. (8:00 - 11:00)pm\n");
    scanf("%d", &wed2tm);
    switch(wed2tm)
    {
    case 1:
        printf("\nBooking Successfull. Thank you.\n");
    case 2:
        printf("\nSuccessfully Booked. Thank you.\n");
    }
}

//Birthday event venue & schedule Function
void birthdayOrg()
{
    int biVenue;
    printf("\n\t---Venue List---\n");
    printf("1.Secret Garden Event Spaces\n");
    printf("2.Skyline Restaurant and Party Center\n");
    scanf("%d", &biVenue);
    switch(biVenue)
    {
    case 1:
        bi1venue();
        break;
    case 2:
        bi2venue();
        break;
    default:
        printf("\nInvalid Choice\n");
    }
}
void bi1venue()
{
    int bi1tm;
    printf("\t---Time---\n");
    printf("1. (1:30 - 4:00)pm\n");
    printf("2. (7:30 - 10:00)pm\n");
    scanf("%d", &bi1tm);
    switch(bi1tm)
    {
    case 1:
        printf("\nBooking Successfull. Thank you.\n");
    case 2:
        printf("\nSuccessfully Booked. Thank you.\n");
    }
}
void bi2venue()
{
    int bi2tm;
    printf("\n\t---Time---\n");
    printf("1. (2:00pm - 5:00)pm\n");
    printf("2. (8:00pm - 11:00)pm\n");
    scanf("%d", &bi2tm);
    switch(bi2tm)
    {
    case 1:
        printf("\nBooking Successfull. Thank you.\n");
    case 2:
        printf("\nSuccessfully Booked. Thank you.\n");
    }
}

//Company event venue & schedule Function
void companyOrg()
{
    int comVenue;
    printf("\n\t---Venue List---\n");
    printf("1.Bangabandhu International Conference Center\n");
    printf("2.Pan Pacific Sonargaon Dhaka Hotel\n");
    scanf("%d", &comVenue);
    switch(comVenue)
    {
    case 1:
        com1venue();
        break;
    case 2:
        com2venue();
        break;
    default:
        printf("\nInvalid Choice\n");
    }
}
void com1venue()
{
    int com1tm;
    printf("\n\t---Time---\n");
    printf("1. (1:30 - 4:00)pm\n");
    printf("2. (7:30 - 10:00)pm\n");
    scanf("%d", &com1tm);
    switch(com1tm)
    {
    case 1:
        printf("\nBooking Successfull. Thank you.\n");
    case 2:
        printf("\nSuccessfully Booked. Thank you.\n");
    }
}
void com2venue()
{
    int com2tm;
    printf("\t---Time---\n");
    printf("1. (2:00 - 5:00)pm");
    printf("2. (8:00 - 11:00)pm");
    scanf(" %d", &com2tm);
    switch(com2tm)
    {
    case 1:
        printf("\nBooking Successfull. Thank you.\n");
    case 2:
        printf("\nSuccessfully Booked. Thank you.\n");
    }
}

//Hire Speaker function
void hireSpeaker()
{
    int hrspk;
    printf("\n1. K M Hasan Ripon\n");
    printf("2. MD. Solaiman Ahmed Jeshan\n");
    printf("3. Md. Hasibur Rahaman\n");
    scanf("%d", &hrspk);
    switch(hrspk)
    {
    case 1:
        spk_1();
        break;
    case 2:
        spk_2();
        break;
    case 3:
        spk_3();
        break;
    default:
        printf("\nWrong choice\n");
    }
}
//Speaker 1 function
void spk_1()
{
    printf("\n\t---K M Hasan Ripon---\n");
    printf("\t\t(Executive Director, Bangladesh Skill Development Institute)\n");
}
//Speaker 2 function
void spk_2()
{
    printf("\n\t---MD. Solaiman Ahmed Jeshan---\n");
    printf("\t\t(Founder & Speaker, JishanBD Learning & Consultancy)\n");
}
//Speaker 3 function
void spk_3()
{
    printf("\n\t---Md. Hasibur Rahaman---\n");
    printf("\t\t(Founder & Chairman, Bangladesh Youth organization for Skill Development - BYOSD)\n");
}

//Ongoing event Function
void ongoingEvent()
{
    /*FILE *fp = fopen("ongoingEvent.dat", "r");
    if(fp ==NULL){
        printf("\nError finding file!\n");
    }
    fscanf()*/
}

//Guest add function can access Organizer
void addguest()
{
    Gueregistration();
}

//Organizer add function can access admin
void addorganizer()
{
    Orgregistration();
}

//Contact function, for contacting with admin
void contact()
{
    int cont;
    printf("\n1. Contact Organizer\n");
    printf("2. Software Help Center\n");
    scanf("%d", &cont);
    switch(cont)
    {
    case 1:
        ConOrg();
        break;
    case 2:
        HelCen();
        break;
    default:
        printf("\nInvalid choice\n");
    }
}
//Contact with organizer function
void ConOrg()
{
    printf("Email: organizer@gmail.com");
    printf("Contact: 01933447732");
}
//Contact with help center function
void HelCen()
{
    printf("Email: invitevent@gmail.com");
    printf("Hotline: 9124289");
}

//Log out & Back to main() function
void logout()
{
    printf("\nLogging out...Please wait!\n");
    return;
}
