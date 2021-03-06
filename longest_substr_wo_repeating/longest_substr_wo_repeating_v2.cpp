//usr/bin/env g++ --std=c++14 add_two_numbers_v2.cpp -o add_two_numbers; ./add_two_numbers; rm add_two_numbers; exit
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      std::map<char, int> substr {};
      int longest = s.empty() ? 0 : 1;
      int dup=0;
      for (int i=0; i<s.size(); ++i) {
        auto chr = s[i];
        auto loc = substr.find(chr);
        if (loc != substr.end()) {
          dup =  std::max(dup, loc->second);
        } 
        substr[chr] = i+1;
        longest = std::max(longest, i-dup+1);
      }
      return longest;
    }
};

int main (int argc, char** argv) {

  vector<string> tests {
    "",
    "a",
    "aa",
    "aba",
    "abacaba",
    "abc"
  };
  Solution s;

  for (auto& test : tests) {
    cout << "test: \"" << test << "\""<< endl;
    auto len = s.lengthOfLongestSubstring(test);
    cout << "result: " << len << endl;
  }
  return 0;
}
