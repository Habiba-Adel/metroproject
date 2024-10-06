#pragma once 


#include<unordered_map>
#include"SubscriptionPlan.h"
#include<string>

using namespace std;



class MetroSystem
{

public:
	//the key is the name of the plan and the value will be the plan object 

	static unordered_map <string,SubscriptionPlan>availablePlans; // the admin can access it and update it

	//unordered_map <string,Subscription> all_users_with_currentsubs;  // each user name because it is unique and its current subscription
	//unordered_map<int, Stage>all_Stages; // number of each stage and its information about it 

 };

