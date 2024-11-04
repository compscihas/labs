# include <string>
# include <stdexcept>
# include "User.h"

using std::string, std::vector;

User::User(string userName) : userName(userName), userPosts(){
/* TODO: initialize */ 
    // TODO: implement constructor checks
    if(userName.empty()){
        throw std::invalid_argument("none");
    }
    int value = int(userName.at(0));
    if (value < 97 || value > 122){
        throw std::invalid_argument("not lowercase");
    }
    int upper = 0;
    for (unsigned int i = 0; i < userName.length(); ++i)
    {
        if (int(userName.at(i)) >= 65 && int(userName.at(i)) <= 90)
        {
            ++upper;
            break;
        }
    }

    if (upper == 1)
    {
        throw std::invalid_argument("Contains uppercase letter");
    }
}


string User::getUserName() {
    // TODO: implement getter
    return this->userName;
}

vector<Post*>& User::getUserPosts() {
    // TODO: implement getter
    return this->userPosts;
}

void User::addUserPost(Post* post) {
    // TODO: add post to user posts
    if (post == nullptr)
    {
        throw std::invalid_argument("null");
    }

    userPosts.push_back(post);

}
