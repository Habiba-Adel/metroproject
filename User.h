#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>
#include"MetroSystem.h"
#include"Subscription.h"
#include<vector>


using namespace std;

class User {
public:

    string username;
private:
    // i use it to can acces the unordermap that is there
    string email;
    string password;
    string confirmPassword;
    string registrationDate;
    bool isLoggedIn;
   


    // Helper function to get the current date
    static string getCurrentDate();

public:
    // Global unordered_map to store user data
    static unordered_map<string, User> users;
   
    Subscription current;
    vector<Subscription>history;
    //// Constructor
    //User(string user, string pass, string email, string regDate);
    //User();

    // Static functions for user registration, login, and logout
    static void registerUser(string name, string pass, string confirmpass, string email);
    static bool login(string username, string password);
    static void logout(string username);

    // Function to display user information
    void displayInfo() const;

    // Getter and setter for isLoggedIn
    bool getIsLoggedIn() const;
    void setIsLoggedIn(bool loggedIn);

    // Getter and setter for password
    string getPassword() const;
    void setPassword(const string& newPassword);
    // Getter and setter for email
    string getEmail() const;
    void setEmail(const string& newEmail);

    // Update user details
    void updateUsername(string newUsername);
    void updateEmail(string newEmail);
    void updatePassword(string newPassword, string confirmPassword);

    // Getter and Setter for current subscription
    Subscription getCurrent() ;
    void setCurrent( Subscription& current);

    // Getter and Setter for history of subscriptions
    vector<Subscription> getHistory() ;
    void setHistory( vector<Subscription>& history);


    /////////////////////////////////////////////////////////////////////////////////////////////
    //user can request to make current subscription not active 
    void request_unactivesubs();
};
#endif