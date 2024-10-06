#include "User.h"
#include<iostream>
#include <string>
#include <unordered_map>
#include"MetroSystem.h"
#include"Subscription.h"

using namespace std;
unordered_map<std::string, User> User::users;


Subscription User::getCurrent()  {
    return current;
}

void User::setCurrent( Subscription& newCurrent) {
    current = newCurrent;
}

vector<Subscription> User::getHistory()  {
    return history;
}

void User::setHistory( vector<Subscription>& newHistory) {
    history = newHistory;
}




//
//string User::getCurrentDate()
//{
//    time_t now = time(0);
//    tm* ltm = localtime(&now);
//    char date[11];
//    snprintf(date, sizeof(date), "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
//    return string(date);
//}
//// Constructor implementation
//User::User(string user, string pass, string email, string regDate)
//    : username(user), password(pass), email(email), registrationDate(regDate), isLoggedIn(false) {}
//
//// Static method to register a new user
//void User::registerUser(string name, string pass, string confirmpass, string email) {
//    if (users.find(name) != users.end()) {
//        cout << "User already exists!" << endl;
//        return;
//    }
//    if (pass != confirmpass) {
//        cout << "Passwords do not match!" << endl;
//        return;
//    }
//    if (email.find('@') == string::npos) {
//        cout << "Invalid email address!" << endl;
//        return;
//    }
//    if (pass.length() < 6) {
//        cout << "Password must be at least 6 characters long!" << endl;
//        return;
//    }
//    string regDate = getCurrentDate();
//    users[name] = User(name, pass, email, regDate);
//    cout << "User registered successfully on " << regDate << "!" << endl;
//}
//
//// Static method to login a user
//bool User::login(string username, string password) {
//    auto it = users.find(username);
//    if (it != users.end() && it->second.getPassword() == password) {
//        it->second.setIsLoggedIn(true);
//        cout << "Login successful!" << endl;
//        return true;
//    }
//    else {
//        cout << "Invalid username or password!" << endl;
//        return false;
//    }
//}
//
//// Static method to logout a user
//void User::logout(string username) {
//    auto it = users.find(username);
//    if (it != users.end() && it->second.getIsLoggedIn()) {
//        it->second.setIsLoggedIn(false);
//        cout << "Logout successful!" << endl;
//    }
//    else {
//        cout << "User not logged in or does not exist!" << endl;
//    }
//}
//
//// Method to display user information
//void User::displayInfo() const {
//    cout << "Username: " << username << endl;
//    cout << "Email: " << email << endl;
//    cout << "Registration Date: " << registrationDate << endl;
//    cout << "Logged In: " << (isLoggedIn ? "Yes" : "No") << endl;
//}
//
//// Getter for isLoggedIn
//bool User::getIsLoggedIn() const {
//    return isLoggedIn;
//}
//
//// Setter for isLoggedIn
//void User::setIsLoggedIn(bool loggedIn) {
//    isLoggedIn = loggedIn;
//}
//
//// Getter for password
//string User::getPassword() const {
//    return password;
//}
////setter for email
//void User::setPassword(const string& newPassword)
//{
//    password = newPassword;
//}
//// Getter for email
//string User::getEmail() const {
//    return email;
//}
//// Setter for email
//void User::setEmail(const string& newEmail) {
//    email = newEmail;
//}
//
//// Update username
//void User::updateUsername(std::string newUsername) {
//    if (newUsername.empty()) {
//        cout << "Username cannot be empty!" << endl;
//        return;
//    }
//    if (users.find(newUsername) != users.end()) {
//        cout << "Username already taken!" << endl;
//        return;
//    }
//    users.erase(username);
//    username = newUsername;
//    users[username] = *this;
//    cout << "Username updated successfully!" << endl;
//}
//// Update email
//void User::updateEmail(std::string newEmail) {
//    if (newEmail.find('@') == std::string::npos) {
//        cout << "Invalid email address!" << endl;
//        return;
//    }
//    email = newEmail;
//    cout << "Email updated successfully!" << endl;
//}
//// Update password
//void User::updatePassword(string newPassword, string confirmPassword) {
//    if (newPassword.length() < 6) {
//        cout << "Password must be at least 6 characters long!" << endl;
//        return;
//    }
//    if (newPassword != confirmPassword) {
//        cout << "Passwords do not match!" << endl;
//        return;
//    }
//    password = newPassword;
//    cout << "Password updated successfully!" << endl;
//}



//////////////////////////////////////////////////////////////////////////////////////////////////////
//void User::request_unactivesubs() {
//    if (metroSystem.all_users_with_currentsubs[username].active)
//    {
//        //true that means it is active so i will toggle it
//        metroSystem.all_users_with_currentsubs[username].active = false;
//    }
//    else
//    {
//        cout << "Your subscription is already not active! ^^ \n";
//        return;
//    }
//
//}


