/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/
#include <iostream>
#include <string>
#include <vector>
#include <exception>

std::vector<std::string> dataVec= {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

int findDecodePossibilities(const std::string& str){

  if(str.length()==0){
    return 1;
  }

  char ch = str[0]; 
  if(std::stoi(str.substr(0,1))<0){ // check if its valid
    throw std::invalid_argument("invalid number");
  }

  int res = findDecodePossibilities(str.substr(1));
  if(str.size()>1 && std::stoi(str.substr(0,2))<26){
    res += findDecodePossibilities(str.substr(2));
  }

  return res;

}

int main() {

  int decodeCount = findDecodePossibilities("111");
  std::cout<<"Count:"<<decodeCount<<std::endl;

  decodeCount = findDecodePossibilities("1111");
  std::cout<<"Count:"<<decodeCount<<std::endl;

  decodeCount = findDecodePossibilities("127932");
  std::cout<<"Count:"<<decodeCount<<std::endl;

  return 0;
}
