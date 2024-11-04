# include <iostream>
# include <string>
# include <stdexcept>
# include "Post.h"
# include <sstream>

using std::string, std::vector, std::istringstream;

Post::Post(unsigned int postId, string userName, string postText) : postId(postId), userName(userName), postText(postText) {
    if (postId == 0 || userName == "" || postText == "") {
        throw std::invalid_argument("post constructor: invalid parameter values");
    }
}

unsigned int Post::getPostId() {
    return postId;
}

string Post::getPostUser() {
    return userName;
}

string Post::getPostText() {
    return postText;
}

vector<string> Post::findTags() {
    // TODO: extracts candidate tags based on occurrences of # in the post
   vector<string> v = {};

  istringstream sin(postText);

  string word = "";

  while (sin >> word)
  {
    if (word.at(0) != '#')
    {
      continue;
    }

    while (word.at(word.length() - 1) == '!' || word.at(word.length() - 1) == '.' || word.at(word.length() - 1) == ',' || word.at(word.length() - 1) == '?')
    {
      word = word.substr(0, word.length() - 1);
    }

    string newword = "";

    for (unsigned int i = 1; i < word.length(); ++i)
    {
      newword += tolower(word.at(i));
    }

    word = "#" + newword;

    bool in = false;

    for (unsigned int i = 0; i < v.size(); ++i)
    {
      if (v.at(i) == word)
      {
        in = true;
        break;
      }
    }

    if (in == false)
    {
      v.push_back(word);
    }

    in = false;
  }

  return v;

}
