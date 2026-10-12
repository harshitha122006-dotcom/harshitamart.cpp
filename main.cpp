#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cctype>

using namespace std;

// ==========================================
// User Class
// ==========================================
class User
{
private:
    string username;
    string password;

public:

    // Constructor
    User(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    // Getter functions
    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }
};

// ==========================================
// Login and Registration System Class
// ==========================================
class UserSystem
{
private:
    vector<User> users;

public:

    // --------------------------------------
    // Username Validation
    // --------------------------------------
    bool validateUsername(string username)
    {
        if (username.length() < 3 || username.length() > 20)
        {
            cout << "Username must contain 3 to 20 characters." << endl;
            return false;
        }

        regex pattern("^[A-Za-z0-9_]+$");

        if (!regex_match(username, pattern))
        {
            cout << "Username can contain only letters, numbers and underscore." << endl;
            return false;
        }

        return true;
    }

    // --------------------------------------
    // Password Validation
    // --------------------------------------
    bool validatePassword(string password)
    {
        if (password.length() < 8)
        {
            cout << "Password must contain at least 8 characters." << endl;
            return false;
        }

        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSpecial = false;

        for (char ch : password)
        {
            if (isupper(static_cast<unsigned char>(ch)))
            {
                hasUpper = true;
            }
            else if (islower(static_cast<unsigned char>(ch)))
            {
                hasLower = true;
            }
            else if (isdigit(static_cast<unsigned char>(ch)))
            {
                hasDigit = true;
            }
            else
            {
                hasSpecial = true;
            }
        }

        if (!hasUpper)
        {
            cout << "Password must contain an uppercase letter." << endl;
            return false;
        }

        if (!hasLower)
        {
            cout << "Password must contain a lowercase letter." << endl;
            return false;
        }

        if (!hasDigit)
        {
            cout << "Password must contain a number." << endl;
            return false;
        }

        if (!hasSpecial)
        {
            cout << "Password must contain a special character." << endl;
            return false;
        }

        return true;
    }

    // --------------------------------------
    // Check Username Already Exists
    // --------------------------------------
    bool usernameExists(string username)
    {
        for (User user : users)
        {
            if (user.getUsername() == username)
            {
                return true;
            }
        }

        return false;
    }

    // --------------------------------------
    // Register New Individual User
    // --------------------------------------
    void registerUser()
    {
        string username;
        string password;
        string confirmPassword;

        cout << "\n============================" << endl;
        cout << "       USER REGISTRATION" << endl;
        cout << "============================" << endl;

        cout << "\nCreate Username: ";
        cin >> username;

        // Validate username
        if (!validateUsername(username))
        {
            cout << "Registration Failed!" << endl;
            return;
        }

        // Check duplicate username
        if (usernameExists(username))
        {
            cout << "Username already exists!" << endl;
            cout << "Please choose another username." << endl;
            return;
        }

        cout << "Create Password: ";
        cin >> password;

        // Validate password
        if (!validatePassword(password))
        {
            cout << "Registration Failed!" << endl;
            return;
        }

        cout << "Confirm Password: ";
        cin >> confirmPassword;

        // Check password confirmation
        if (password != confirmPassword)
        {
            cout << "Passwords do not match!" << endl;
            cout << "Registration Failed!" << endl;
            return;
        }

        // Create User Object
        User newUser(username, password);

        // Store user object
        users.push_back(newUser);

        cout << "\nRegistration Successful!" << endl;
        cout << "Account created for: " << username << endl;
    }

    // --------------------------------------
    // Login
    // --------------------------------------
    void login()
    {
        string username;
        string password;

        cout << "\n============================" << endl;
        cout << "          USER LOGIN" << endl;
        cout << "============================" << endl;

        cout << "\nEnter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        // Search for matching user
        for (User user : users)
        {
            if (user.getUsername() == username &&
                user.getPassword() == password)
            {
                cout << "\nLogin Successful!" << endl;
                cout << "Welcome, " << username << "!" << endl;

                return;
            }
        }

        cout << "\nLogin Failed!" << endl;
        cout << "Invalid username or password." << endl;
    }
};

// ==========================================
// Main Function
// ==========================================
int main()
{
    UserSystem system;

    int choice;

    do
    {
        cout << "\n================================" << endl;
        cout << "       INDIVIDUAL USER SYSTEM" << endl;
        cout << "================================" << endl;

        cout << "\n1. Register New User";
        cout << "\n2. Login";
        cout << "\n3. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                system.registerUser();
                break;

            case 2:
                system.login();
                break;

            case 3:
                cout << "\nThank you!" << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}
