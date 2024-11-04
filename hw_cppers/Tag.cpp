# include <string>
# include <stdexcept>
# include "Tag.h"

using std::string, std::vector;

Tag::Tag(string tagName) : tagName(tagName), tagPosts() /* TODO: initialize */ {
    // TODO: implement constructor checks
  if (tagName.length() < 2)
  {
    throw std::invalid_argument("Too short");
  }
  if (tagName.at(0) != '#')
  {
    throw std::invalid_argument("No hash");
  }

  int value = int(tagName.at(1));

  if (value < 97 || value > 122)
  {
    throw std::invalid_argument("second is not lowercase");
  }

  int upper = 0;
  for (unsigned int i = 0; i < tagName.length(); ++i)
  {
    if (int(tagName.at(i)) >= 65 && int(tagName.at(i)) <= 90)
    {
      ++upper;
      break;
    }
  }

  if (upper == 1)
  {
    throw std::invalid_argument("Contains uppercase letter");
  }

  char last = tagName.at(tagName.length() - 1);
  char sec = tagName.at(tagName.length() - 2);

  if ((last == '!' || last == '.' || last == ',' || last == '?') && (sec == '!' || sec == '.' || sec == ',' || sec == '?'))
  {
    throw std::invalid_argument("Two consecutive punctuation");
  }
}

string Tag::getTagName()
{
  // TODO(student): implement getter
  return tagName;
}



vector<Post*>& Tag::getTagPosts() {
    // TODO: implement getter
    return tagPosts;
}

void Tag::addTagPost(Post* post) {
    // TODO: add post to tag posts
    if (post == nullptr)
    {
        throw std::invalid_argument("Invalid post");
    }
    tagPosts.push_back(post);

}
