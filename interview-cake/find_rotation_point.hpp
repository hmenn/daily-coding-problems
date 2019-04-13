/*
InterviewCake : https://www.interviewcake.com/question/cpp/find-rotation-point

Now I have a vector of words that are mostly alphabetical, except they start somewhere in the middle of the alphabet, reach the end, and then start from the beginning of the alphabet. In other words, this is an alphabetically ordered vector that has been "rotated."

Write a function for finding the index of the "rotation point," which is where I started working from the beginning of the dictionary. This vector is huge (there are lots of words I don't know) so we want to be efficient here.
*/
#include <iostream>
#include <vector>
#include <string>

int find_rotation_point(const std::vector<std::string>& words, int startIndex, int endIndex){
  //std::cout<<startIndex<<" "<<endIndex<<std::endl;
  if(startIndex+1 == endIndex){
    return endIndex;
  }

  int middleIndex = (startIndex + endIndex) / 2;

  if(words[middleIndex] < words[0]){
    return find_rotation_point(words,startIndex, middleIndex);
  }else{
    return find_rotation_point(words,middleIndex, endIndex);
  }
}

int find_rotation_iterative(const std::vector<std::string>&words){
  int index=0;
  for(auto i=0; i<words.size();++i){
    if(words[i]<words[index]){
      index = i;
    }
  }
  return index;
}

int main() {
  
  int index;

  const std::vector<std::string> words {
    "ptolemaic",
    "retrograde",
    "supplant",
    "undulate",
    "xenoepist",
    "asymptote",  // <-- rotates here!
    "babka",
    "banoffee",
    "engender",
    "karpatka",
    "othellolagkage",
  };

  
  index = find_rotation_iterative(words);
  std::cout<<"Find Rotation for words - Iterative: Idx:"<<index<<", Word:"<<words[index]<<std::endl;

  index = find_rotation_point(words, 0, words.size()-1);
  std::cout<<"Find Rotation for words - Binary Search: Idx: "<<index<<", Word:"<<words[index]<<std::endl; 


  std::vector<std::string> words2 = {"k","v","a","b","c","d","e","g","i" };

  index = find_rotation_point(words2, 0, words2.size()-1);
  std::cout<<"Find Rotation for words2 - Binary Search: Idx: "<<index<<", Word:"<<words2[index]<<std::endl;


  std::vector<std::string> words3 = {"a","b","c","d","e","g","i" };

  index = find_rotation_point(words3, 0, words3.size()-1);
  std::cout<<"Find Rotation for words3 - Binary Search: Idx: "<<index<<", Word:"<<words3[index]<<std::endl;
  return 0;
}
