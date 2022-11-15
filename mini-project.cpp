// Developer: Tanmay Sharma
// Roll No:   94
// Enroll No: 0801CS211094

// Subject:   C++ program to get user authentication using file Handling

// Following functions are used in this program:
/*
1. login();
2. registration();
3. forgot_password();
4. delete_account();
5. searchingLineNumber();
5. ifstream
6. ofstream

*/

#include <bits/stdc++.h>
using namespace std;

// declaring functions we'll be using all time for our program
void login();
void registration();
void forgot_password();
void delete_account();

int main()
{

    // choice variable
    int choice;

    // user interface code of the program
    cout << endl
         << endl;
    cout << "\t\t   ____________________________________" << endl
         << endl;
    cout << "\t\tWelcome to the password management service!" << endl;
    cout << "\t\t   ____________________________________" << endl
         << endl;
    cout << "\t\t   __  __  __  __  MENU  __  __  __  __" << endl;
    cout << "\t\t   ____________________________________" << endl;
    cout << endl;
    cout << "\t\t   Enter your choice from below options: " << endl
         << endl;
    cout << "\t\t|   1. Login " << endl;
    cout << "\t\t|   2. Registration " << endl;
    cout << "\t\t|   3. Forgot password " << endl;
    cout << "\t\t|   4. Delete User account " << endl;
    cout << "\t\t|   5. Exit " << endl
         << endl;
    cout << "\t\t   option: ";

    // inputting the choice from the user from the 4 options available
    cin >> choice;
    switch (choice)
    {
    case 1:
        // if option 1, then it'll call login() function
        login();
        break;
    case 2:
        // if option 2, then it'll call registration() function
        registration();
        break;
    case 3:
        // if option 3, then it'll call forgot_password() function
        forgot_password();
        break;
    case 4:
        // if option 4, then it'll call delete_account() function
        delete_account();
        break;
    case 5:
        // if option 5, then it'll exit the program
        cout << "\nThank you for being here!" << endl;
        exit(0);

    default:
        system("clear");
        cout << "Enter valid option!" << endl;
        main();
        break;
    }

    return 0;
}

// login() function
void login()
{
    bool authentication = false; // authentication variable

    string userName, password, id, pass; // variables to input user name, password and check from the file
    system("clear");
    cout << "Enter your username and password below :->" << endl;
    cout << "\t\t  USERNAME: ";
    cin >> userName;
    cout << "\t\t  PASSWORD: ";
    cin >> password;

    // ifstream, that'll check the user name and password using a while loop and doing this we're opening our file
    ifstream input("records.txt");

    // it'll search like:
    //</User name> </Password>
    //  if available, then set the authentication value as 'true'
    while (input >> id >> pass)
    {

        if (id == userName && pass == password)
        {
            authentication = true;
            system("clear");
        }
    }
    input.close();
    cout << endl;
    if (authentication)
    {
        cout << "Record for " << userName << " is found!" << endl;
    }
    else // record for particular username and password NOT found!
    {
        cout << "MESSAGE:  ** Check Username and Password or Register **";
    }
    main();
}

// registration() function
void registration()
{
    // variables that'll set values and store them inside the file
    string registerUserName, registerPassword, rId, rPass;
    system("clear");

    cout << "\t\t Register UserName: ";
    cin >> registerUserName;
    cout << "\t\t Register Password: ";
    cin >> registerPassword;

    // ofstream, is used for writing records inside the file
    // ios::app used for appending the values inside the file just below another
    ofstream adding("records.txt", ios::app);

    // this code adds user name and password in format below:
    //</User name> </Password>
    // in the file
    adding << registerUserName << ' ' << registerPassword << endl;
    system("clear");

    cout << "Your Registration is successful!";
    main();
}

// forgot_password() function
void forgot_password()
{
    char option;
    system("clear");
    cout << "Forgot password? Don't worry, select an option from below :->" << endl;
    cout << "\t\t 1. Search by your userName" << endl;
    cout << "\t\t 2. Go back to main MENU" << endl;
    cout << "\t\t OPTION: ";
    cin >> option;

    switch (option)
    {
    case '1':
    {
        // code to search the user name if available, then return it's password associated.
        bool authentication = false;
        string searchUserName, sUserName, sPass;

        // we're creating this 'displayPass' as sPass will iterate throughtout the file and it will change for more than single user. 'displayPass' will save the password and at the end will display it to the user
        string displayPass;

        cout << "Enter the userName which you remembered lastly :->" << endl;
        cout << "\t\t USERNAME: ";
        cin >> searchUserName;

        // searching user name from the file
        ifstream searching("records.txt");

        while (searching >> sUserName >> sPass)
        {

            if (sUserName == searchUserName)
            {
                authentication = true;
                //display pass storing current password value
                displayPass = sPass;
            }
        }
        searching.close();

        if (authentication)
        {
            cout << "Your account is found!" << endl;
            cout << "Your password is: " << displayPass;
        }
        else
        {
            cout << "We have NO record for this User name" << endl;
            cout << "** Kindly register yourself first **";
        }
        break;
    }

    case '2':
        system("clear");
        break;

    default:
        cout << "Wrong choice! try again **" << endl;
        break;
    }
    main();
}

// searchingLineNumber() function
//since, for deleting the account, we'll be needing line number for that particular file
//so, we created this function to get the line number
int searchingLineNumber(string to_be_searched_line)
{
    //string line_to_be_searched will be searched
    //searchingLine will be like a storing place that'll store current value of string from getline function
    string searchingLine;

    int countLine = 0;
    ifstream mFile("records.txt");

    if (mFile.is_open())
    {

        while (mFile.peek() != EOF)
        {

            getline(mFile, searchingLine);
            countLine++;
            //countLine value will be increase only when, we don't find the line, it'll break the loop if we found our line
            if (searchingLine == to_be_searched_line)
            {
                break;
            }
        }
        mFile.close();
    }
    return countLine;
}

// delete_account() function
void delete_account()
{

    char option;
    cout << "Sure, you want to delete your account?" << endl;
    cout << "Press 'y' for YES" << endl;
    cout << "Press 'n' for NO" << endl;
    cout << ": ";
    cin >> option;

    switch (option)
    {
    case 'y':
    {
        bool authentication = false;
        string searchUserName, searchPassword, sUserName, sPass;

        //we_want is the string which we'll send to searchingLineNumber to get the line of particular username and password
        string we_want;
        cout << "Enter your User Name and Password below :-> " << endl;
        cout << "\t\t  USERNAME: ";
        cin >> searchUserName;
        cout << "\t\t  PASSWORD: ";
        cin >> searchPassword;

        ifstream searching("records.txt");

        //seeking the pointer of file to the beginning of file, it'll make things much more easier
        searching.seekg(0, searching.beg);
        while (searching >> sUserName >> sPass)
        {

            if (sUserName == searchUserName && sPass == searchPassword)
            {
                we_want = searchUserName + " " + searchPassword;
                authentication = true;
            }
        }
        if (!authentication)
        {
            cout << "Wrong Information!";
            main();
        }
        searching.close();

        ifstream is("records.txt");
        ofstream ofs("outFile.txt", ios::out);

        char c;
        int line_number = 1;
        int line_to_delete = searchingLineNumber(we_want);
        while (is.get(c))
        {

            if (c == '\n')
            {
                line_number++;
            }
            if (line_number != line_to_delete)
            {
                ofs << c;
            }
        }
        ofs.close();
        is.close();
        remove("records.txt");
        rename("outFile.txt", "records.txt");
        cout << "Your account has been deleted!" << endl;
        break;
    }

    case 'n':
    {
        main();
    }
    default:
        cout << "Wrong option!" << endl;
        break;
    }
    exit(0);
}