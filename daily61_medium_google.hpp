/*
This problem was asked by Google.

Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/
#include <iostream>

int myPow0(int x, int y){
  int res = 1;

  for(int i=0;i<y;++i){
    res *= x;
  }
  return res;
}

int myPow1(int x, int y){
  if(y<=0){
    return 1;
  }
  return x * myPow1(x, --y);
}

// naive method of repeated multiplication
int myPow3(int x, int y){
  if(y<=0){
    return 1;
  }
  if(y % 2 == 1){
    return x * myPow3(x, y-1);
  }
  return x * x * myPow1(x, y-2);
}

int main() {
  std::cout << myPow0(2,10) << std::endl;
  std::cout << myPow1(2,10) << std::endl;
  std::cout << myPow3(5,1) << std::endl;
  std::cout << myPow3(2,11) << std::endl;
}
