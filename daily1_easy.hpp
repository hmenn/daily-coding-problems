/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <set>

std::pair<int,int> findAddUpToK_1(int *input, int size, int k){
  std::set<int> dataSet(input, input+size);
  for(int i=0; i<size;++i){
    int required = k - input[i];

    if(dataSet.find(required) != dataSet.end()){
      return std::make_pair(input[i], required);
    }
  }

  return std::make_pair(-1, -1);
}

std::pair<int,int> findAddUpToK_2(int *input, int size, int k){

  std::set<int> dataSet;
  for(int i=0; i<size;++i){
    int required = k - input[i];

    if(dataSet.find(required) != dataSet.end()){
      return std::make_pair(input[i], required);
    }else{
      dataSet.emplace(input[i]);
    }
  }

  return std::make_pair(-1, -1);
}

int main() {
  int k=17;
  int input[]={10,15,3,1,2};

  // solution 1
  auto sol1 = findAddUpToK_1(input, 5, 17);
  std::cout<<"F:"<<sol1.first<<" ,S:"<<sol1.second<<std::endl;

  auto sol2 = findAddUpToK_2(input, 5, 17);
  std::cout<<"F:"<<sol2.first<<" ,S:"<<sol2.second<<std::endl;

}
