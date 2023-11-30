#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct userData {
    string FirstName, LastName, Address, Section, YearLevel;
};

void DataDisplay (userData u);
userData newUser (string fileName);
userData LoadUserData (string fileName);
void saveUser(string fileName, userData u);
string ChangeData(int input);
string AskUserInput(string question);

int main()
{
    userData user;
    int input;
    string fileName;

    cout << "Welcome! Do you have an existing account?\n[1]Yes\n[2]No\n";
    cin >> input;

    switch(input) {

    case 1:
        {
        fileName = AskUserInput("Please enter your last name: \n");

        ifstream file(fileName + ".txt");
        if(file)
        {
            user = LoadUserData(fileName);
        }
        else
        {
            user = newUser(fileName);
        }
        break;
        }
    case 2:
        {
        user = newUser(fileName);
        break;
        }
     default:
         {
        cout << "What are you trying to enter here?\n";
        return 0;
         }
    }

    DataDisplay(user);

    cout << "\nData successfully displayed! Would you like to make any changes?\n[1]Yes\n[2]No\n";
    cin >> input;

    switch(input)
    {
    case 1:
        {
        cout << "\nWhich information would you like to make changes to?\n[1]First name\n[2]Last name\n[3]Address\n[4]Year level\n[5]Section\n";
        cin >> input;

        switch(input)
        {
        case 1:
            {
            ofstream file;

            cout << "\nEnter first name: \n";
            cin >> user.FirstName;
            file << user.FirstName << endl;

            break;
            }
        case 2:
            {
            ofstream file;

            cout << "Enter last name: \n";
            cin >> user.LastName;
            file << user.LastName << endl;
            break;
            }
        case 3:
            {
            ofstream file;

            cout << "Enter address: " << endl;
            cin >> user.Address;
            file << user.Address << endl;
            break;
            }
        case 4:
            {
            ofstream file;

            cout << "Enter year level: \n";
            cin >> user.YearLevel;
            file << user.YearLevel << endl;
            break;
            }
        case 5:
            {
            ofstream file;

            cout << "Enter your section: \n";
            cin >> user.Section;
            file << user.Section << endl;
            break;
            }
        default:
            {
            cout << "\nWhat are you trying to enter?\n";
            return 0;
            }
        }
        }
    DataDisplay(user);

    case 2:
        {
        cout << "\nWould you like to save your data?\n[1]Yes\n[2]No\n";
        cin >> input;

        switch(input)
        {
        case 1:
            {
            fileName = user.LastName;
            saveUser(fileName, user);
            break;
            }
        case 2:
            {
            return 0;
            break;
            }
        default:
            {
            cout << "\nAgain, what are you trying to enter?\n";
            return 0;
            }
        }
        }

    default:
        {
            cout << "\nWrong input again! There are only 2 numbers here!!\n";
           return 0;
        }
    }

    return 0;
}

void DataDisplay(userData u)
{
    cout << "\nFirst name: " << u.FirstName << endl;
    cout << "Last name: " << u.LastName << endl;
    cout << "Address: " << u.Address << endl;
    cout << "Year level: " << u.YearLevel << endl;
    cout << "Section: " << u.Section << endl;
}

userData newUser(string fileName)
{
    userData user;

    ofstream file;

    cout << "\n=== Make a new account ===\n";

    cout << "\nEnter first name: \n";
    cin >> user.FirstName;
    file << user.FirstName << endl;

    cout << "Enter last name: \n";
    cin >> user.LastName;
    file << user.LastName << endl;

    cout << "Enter address: " << endl;
    cin >> user.Address;
    file << user.Address << endl;

    cout << "Enter year level: \n";
    cin >> user.YearLevel;
    file << user.YearLevel << endl;

    cout << "Enter your section: \n";
    cin >> user.Section;
    file << user.Section << endl;

    return user;
}

userData LoadUserData(string fileName)
{
    userData u;
    ifstream file(fileName + ".txt");

        getline(file, u.FirstName);
        getline(file, u.LastName);
        getline(file, u.Address);
        getline(file, u.YearLevel);
        getline(file, u.Section);

    file.close();

    return u;
}

void saveUser(string fileName, userData u)
{
    ofstream file(fileName + ".txt");

    file << u.FirstName << endl;
    file << u.LastName << endl;
    file << u.Address << endl;
    file << u.YearLevel << endl;
    file << u.Section << endl;

    file.close();

    cout << "Your file has been successfully saved.\n";
}

string AskUserInput(string question)
{
    cout << question;

    string input;

    getline(cin >> ws, input);
    return input;
}
