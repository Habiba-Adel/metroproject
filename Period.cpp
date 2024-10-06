#include "Period.h"

int Period::getTotalTrips()
{
    return totaltrips ;
}

void Period::setTotalTrips(int trips)
{
    totaltrips = trips;
}

vector<Stage>& Period::getStages()
{
    return stages;
}

void Period::addStage(Stage& stage)
{
    stages.push_back(stage);

}
