/*
This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
  
  std::vector<std::set<int>> classes;
  std::vector<std::pair<int,int> > intervals;

  intervals.push_back(std::make_pair(30,75));
  intervals.push_back(std::make_pair(0,50));
  intervals.push_back(std::make_pair(60,150));
  intervals.push_back(std::make_pair(70,170));

  // brute force solution
  // check here for best solution: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
  for(const auto& interval: intervals){
    bool foundPlace=false;
    // check class setted times
    for(auto& classTimeInterval: classes){
      bool timeConflict=false;
      // if class time conflict with new ones
      // specify this class
      for(auto i=interval.first; i<=interval.second;++i){
        if(classTimeInterval.find(i) != classTimeInterval.end()){
          timeConflict = true;
          break;
        }
      }
      // if there is no time conflict
      // add new times into current class
      if(!timeConflict){
        foundPlace = true;
        for(auto i=interval.first; i<=interval.second;++i){
          classTimeInterval.emplace(i);
        }
      }
    }
    // couldn't find valid class, create new one
    if(!foundPlace){
      std::set<int> times;
      for(auto i=interval.first;    i<=interval.second;++i){
          times.emplace(i);
        }
      classes.push_back(times);
    }
  }

  std::cout<<"Required min: "<<classes.size()<<" class"<<std::endl;
}
