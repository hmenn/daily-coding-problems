/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
*/

#include <iostream>
#include <limits>
#include <vector>

void solution(int *data, int size, int k){

  int max = std::numeric_limits<int>::min();
  int secondMax = std::numeric_limits<int>::min();

  for(int i=0; i<size;++i){

    if(data[i] > max){
      secondMax = max;
      max = data[i];
    }else if(data[i] > secondMax){
      secondMax = data[i];
    }

    if(k==1){
      max=data[i];
      std::cout<<"Max:"<<max<<std::endl;
    }else if(i >= k-1){
      if(max == data[i-k]){
        max = secondMax;
        secondMax = data[i];
      }
      std::cout<<"Max:"<<max<<std::endl;
    }
  }
}

int main() {

  int data1[]={10,5,2,7,8,7};
  solution(data1,6,3);

  std::cout<<std::endl<<"====="<<std::endl;

  int data2[]={10,5,2,7,8,7};
  solution(data2,6,1);

  std::cout<<std::endl<<"====="<<std::endl;

  int data3[]={-1,-2,-3,-4,12,5,2,7,8,7,12};
  solution(data3,11,4);

}
