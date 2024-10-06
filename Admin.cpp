#include "Admin.h"
#include"MetroSystem.h"
#include"SubscriptionPlan.h"

using namespace std;


//it will be edited 
// // it gives me an error and i can not solve it 
//void Admin::create_Subscription_Plan() {
//	SubscriptionPlan newone;
//	string key= newone.add_Subscription_Plan();
//	metroSystem.availablePlans[key] = newone;
//
//
//}


//
//void Admin::update_Subscription_Plan() {
//	
//		
//}
//
//
//
//void Admin::remove_Subscription_Plan() {
//
//
//	// first taking the name pf the plan and check if it existed in our plans or no 
//	cout << "Enter the name of the subscription plan you want to remove it. \n";
//	string name;
//	cin >> name;
//	bool flag = false;
//	for (auto it = metroSystem.availablePlans.begin(); it != metroSystem.availablePlans.end(); it++) {
//		if (it->first == name)
//		{
//			flag = true;
//			// we can after finding the name here to store the iterator for this name to decrease the time 
//		}
//	}
//	if (!flag)// it means the name not found
//	{
//		while (true) {
//			cout << "This name isnot found do you want to try again? just write ( y , n ) \n";
//			char answer;
//			cin >> answer;
//			if (answer == 'y' || answer == 'Y')
//			{
//				remove_Subscription_Plan();
//			}
//			else if (answer == 'n' || answer == 'N')
//				return;  // the same thing i can make him retrun to the admin services function list 
//			else
//			{
//				cout << "Invalid choice please write y or n only . \n";
//				continue;
//			}
//		}
//	}
//	else { //it means the name is existed so now we will remove it from the plans data structure 
//		auto iter=metroSystem.availablePlans.find(name);
//	    // i will not check if the iter equals to the end because i make this check before
//		metroSystem.availablePlans.erase(iter);
//		cout << "Congratulations the plan removed  !! ^^";
//	}
//
//
//}
//
//
////void Admin::edit_StageAmount() {
////	while (true) {
////		cout << "Enter the number of your choice:................... \n";
////		cout << "If you will change the price for just one stage write 1. \n";
////		cout << "If you want to change the price for all stages write 2. \n";
////		char choice;
////		cin >> choice;
////		if (choice == '1')
////		{
////			while (true) {
////				cout << "Enter the number of stage you want to edit its price:.............. \n";
////				char num;
////				cin >> num;
////				if()
////			}
////		}
////	}
////}
