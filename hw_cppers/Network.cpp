# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include "Network.h"
# include <vector>
#include <string>
#include <cctype>
using std::ifstream, std::getline, std::istringstream, std::cout, std::endl;


using std::string, std::vector;

Network::Network() : users({}), posts({}), tags({}) {}

void Network::loadFromFile(string fileName) {
    // TODO: load user and post information from file
    ifstream fin(fileName);
  if (!fin.is_open())
    throw std::invalid_argument("Can't open file bruh");

  string line = "";
  string word = "";
  string userid = "";

  unsigned int idpost = 0;
  string postuser = "";
  string posttext = "";

  while (getline(fin, line))
  {

    istringstream sin(line);

    sin >> word;

    if (word != "User" && word != "Post")
    {
      throw std::runtime_error("Not user or post");
    }
    else if (word == "User")
    {
      sin >> userid;
      try
      {
        addUser(userid);
      }
      catch (const std::invalid_argument &e)
      {
        throw std::runtime_error("something wrong with adduser");
      }
    }
    else if (word == "Post")
    {
      sin >> idpost >> postuser >> posttext;
      string temp = "";
      std::getline(sin, temp);
      posttext += temp;

      try
      {
        addPost(idpost, postuser, posttext);
      }
      catch (const std::invalid_argument &e)
      {
        throw std::runtime_error("something wrong with addpost");
      }
    }
  }
}



void Network::addUser(string userName) {
    // TODO: create user and add it to network
  int userNameL = userName.size();
  for (int i = 0; i < userNameL; i++) {
        userName[i] = tolower(userName[i]);
  }
  int usersL = users.size();
  for (int i = 0; i < usersL; i++) {
    if (userName == users[i]->getUserName()) {
      throw std::invalid_argument("user already exists");
    }
  }

  users.push_back(new User(userName));
  cout << "Added User " << userName << endl;
}


void Network::addPost(unsigned int postId, string userName, string postText) {
    // TODO: create post and add it to network
  bool userExists = false;

  for (unsigned int i = 0; i < users.size(); ++i)
  {
    if (userName == users.at(i)->getUserName())
    {
      userExists = true;
    }
  } 

  if (!userExists)
  {
    throw std::invalid_argument("Name doesn't exist brother");
  }
  for (unsigned int i = 0; i < posts.size(); ++i)
  {
    if (postId == posts.at(i)->getPostId())
    {
      throw std::invalid_argument("Post already exists bruh");
    }
  }

  Post *p = new Post(postId, userName, postText);
  bool found = false;

  for (unsigned int i = 0; i < users.size(); ++i)
  {
    if (userName == users.at(i)->getUserName())
    {
      posts.push_back(p);
      users[i]->addUserPost(p);
      found = true;
    }
  }
  if(!found){
    throw std::invalid_argument("user does not exist");
  }

  vector<string> alltags = p->findTags();
  for (unsigned int i = 0; i < alltags.size(); ++i)
  {
    bool numtags = false;

    for (unsigned int j = 0; j < tags.size(); ++j)
    {
      if (alltags.at(i) == tags.at(j)->getTagName())
      {
        numtags = true;
        tags.at(j)->addTagPost(p);
        break;
      }
    }

    if (numtags == true)
    {
      continue;
    }

    try
    {
      Tag *t = new Tag(alltags.at(i));
      tags.push_back(t);
      t->addTagPost(p);
    }
    catch (const std::invalid_argument &e)
    {
      continue;
    }
  }

  cout << "Added Post " << postId << " by " << userName << endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
    // TODO: return posts created by the given user
    if (userName.empty() == 1)
  {
    throw std::invalid_argument("Empty name bruv");
  }

  //bool in = false;
  for (unsigned int i = 0; i < users.size(); ++i)
  {
    if (userName == users.at(i)->getUserName())
    {
      return users.at(i)->getUserPosts();
    }
  }

  //if (in == false)
  //{
   throw std::invalid_argument("Name not here");
  //}
}

vector<Post*> Network::getPostsWithTag(string tagName) {
    // TODO: return posts containing the given tag
  if (tagName.empty())
  {
    throw std::invalid_argument("Empty name bru");
  }

  //bool check = false;
  for (unsigned int i = 0; i < tags.size(); ++i)
  {
    if (tagName == tags.at(i)->getTagName())
    {
      return tags.at(i)->getTagPosts();
    }
  }

  //if (check == false)
  //{
  throw std::invalid_argument("Tag not here");
  //}
}

vector<string> Network::getMostPopularHashtag() {
    // TODO: return the tag occurring in most posts
  if (tags.size() == 0)
  {
    return {};
  }


  vector<string> maxtags;
  int max = 0;
  int numpost = 0;

  for (unsigned int i = 0; i < tags.size(); ++i)
  {
    vector<Post *> temp = tags.at(i)->getTagPosts();
    numpost = temp.size();

    if (numpost > max)
    {
      max = numpost;
    }
  }

  for (unsigned int i = 0; i < tags.size(); ++i)
  {
    vector<Post *> temp = tags.at(i)->getTagPosts();
    numpost = temp.size();

    if (numpost == max)
    {
      maxtags.push_back(tags.at(i)->getTagName());
    }
  }

  return maxtags;
}

Network::~Network() {
    for (unsigned int i = 0; i < users.size(); ++i) {
        delete users.at(i);
    }

    for (unsigned int i = 0; i < tags.size(); ++i) {
        delete tags.at(i);
    }
    
    for (unsigned int i = 0; i < posts.size(); ++i) {
        delete posts.at(i);
    }
}
