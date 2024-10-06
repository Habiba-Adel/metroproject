#pragma once
#include<string>
#include<vector>
#include"Stage.h"
using namespace std;

class Period
{
	vector<Stage>stages;
	int totaltrips;

public:	
	string name;

    // Getter for total trips
    int getTotalTrips() ;

    // Setter for total trips
    void setTotalTrips(int trips);

    // Getter for stages
     vector<Stage>& getStages() ;

    // Method to add a stage
    void addStage( Stage& stage);

  


};

