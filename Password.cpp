#include "Password.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

Password::Password() {
  vector<string> pass_history = {"ChicoCA-95926"};
}
/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase){
  int lower = 0;
  int upper = 0;
  if (phrase.length() <= 1) {
    return false;
  }

  for (uint i = 0; i < phrase.length(); i++) {
    if (isupper(phrase[i])) {
      upper++;
    } else if (islower(phrase[i])) {
      lower++;
    }
  }
  return (lower > 0 && upper > 0);
}

void Password::set(string phrase) {
  if (phrase.length() < 8) {
    return;
  }
  if (phrase[0] == phrase[1] && phrase[1] == phrase[2] && phrase[2] == phrase[3]) {
    return;
  }
  bool has_upper = false;
  bool has_lower = false;
  for (uint i = 0; i < phrase.length(); i++) {
    if (isupper(phrase[i])) {
      has_upper = true;
    }
    if (islower(phrase[i])) {
      has_lower = true;
    }
  }
  if (!has_upper || !has_lower) {
    return;
  }
  pass_history.push_back(phrase);
}

bool Password::authenticate(string phrase) {
  return phrase == pass_history[pass_history.size()];
}