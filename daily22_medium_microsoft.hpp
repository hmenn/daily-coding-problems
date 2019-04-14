/*
Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> find_possible_recons(std::set<std::string>& dict, const std::string& word){
  std::vector<std::string> constructions;

  int i=1;
  int wordHeadIndex = 0;
  while(wordHeadIndex+i <= word.size()){

    std::string piece = word.substr(wordHeadIndex, i);
    //std::cout<<piece<<wordHeadIndex<<" - "<<i<<std::endl;

    auto it = dict.find(piece);
    if(it!= dict.end()){
      wordHeadIndex += i;
      i=0;
      constructions.push_back(piece);
    }

    ++i;
  }
  return constructions;
}

int main() {
  
  std::set<std::string> wordDict1 = {"quick", "brown", "the", "fox"};
  std::string str1 = "thequickbrownfox";

  std::cout<<"Example: "<<str1<<std::endl;
  std::vector<std::string> res1 = find_possible_recons(wordDict1, str1);

  for(const auto & r: res1){
    std::cout<<r<<std::endl;
  }

  std::cout<<std::endl<<"======="<<std::endl;

  std::set<std::string> wordDict2 = {"bed", "bath", "bedbath", "and", "beyond"};
  std::string str2 = "bedbathandbeyond";

  std::cout<<"Example: "<<str2<<std::endl;
  std::vector<std::string> res2 = find_possible_recons(wordDict2, str2);

  for(const auto & r: res2){
    std::cout<<r<<std::endl;
  }

  return 0;
}
