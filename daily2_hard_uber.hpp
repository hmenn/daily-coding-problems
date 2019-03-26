/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> solution_with_division(std::vector<int> input){
  
  int totalProduct = 1;

  for(const auto &i: input){
    totalProduct *=i;
  }

  std::vector<int> newValues(input.size());
  for(int i=0; i< newValues.size();++i){
    newValues[i] = totalProduct / input[i];
  }

  return newValues;
}

std::vector<int> solution_with_division_moderncpp(std::vector<int> input){

  int totalProduct = std::accumulate(input.begin(), input.end(), 1, [](int a, int b){ return a*b; });

  std::vector<int> newValues(input.size());
  std::transform(input.begin(), input.end(), newValues.begin(), [totalProduct](int item){ return totalProduct/item; });

  return newValues;
}

int helper(std::vector<int>& data, int index, int beforeProduct, std::vector<int>& results){

  if(index == data.size()){
    return 1;
  }

  int newBeforeProd = beforeProduct * data[index];

  int retVal = helper(data, index+1, newBeforeProd, results);
 
  results[index] = beforeProduct * retVal;

  return retVal * data[index] ;

}

std::vector<int> solution_without_division(std::vector<int> input){

  std::vector<int> results(input.size());

  helper(input, 0, 1, results);

  return results;
}




int main() {
  std::vector<int> dataSet{1, 2, 3, 4, 5};

  // solution 1
  auto sol1 = solution_with_division(dataSet);
  std::for_each(sol1.begin(), sol1.end(), [](int item){
    std::cout<<item<<"-";
  });
  std::cout<<std::endl;

  
  auto sol2 = solution_with_division_moderncpp(dataSet);
  std::for_each(sol2.begin(), sol2.end(), [](int item){
    std::cout<<item<<"-";
  });
  std::cout<<std::endl;

  auto sol3 = solution_without_division(dataSet);
  std::for_each(sol3.begin(), sol3.end(), [](int item){
    std::cout<<item<<"-";
  });
  std::cout<<std::endl;


  std::vector<int> dataSet2{3,2,1};
  auto sol4 = solution_without_division(dataSet2);
  std::for_each(sol4.begin(), sol4.end(), [](int item){
    std::cout<<item<<"-";
  });
  std::cout<<std::endl;

  return 0;
}
