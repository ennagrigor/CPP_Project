#include <vector>
#include <iostream>
#include "Member.h"

using namespace std;

int Member :: counter = 0; //counter to know how many members are
    
Member :: Member(){ //constructor
    counter++;
}   

Member :: ~Member(){ //destructor
    counter--;
    for(int i=0; i<followers.size(); i++){
        followers[i]->unfollow(*this);
    }
    for(int i=0; i<following.size(); i++){
        unfollow(*following[i]);
    }
}

void Member :: follow (Member &name){  //method to follow another member

    Member *p = &name;    

    if(p==this) return;

    for(int i=0; i<following.size(); i++){
        if (following[i] == p) return;
    }
    following.push_back(p);
    name.followers.push_back(this);
}

int Member :: numFollowers (){ // returns the number of members that follow me
     return followers.size();
}

int Member :: numFollowing (){ // returns the number of members that I follow
    return following.size();
}

void Member :: unfollow(Member &name){ //method to unfollow another member
    if(&name==this) return;

    for(int i=0; i<following.size(); i++){
        if(following[i] == &name){
            following.erase(following.begin()+i);
            for(int j=0; j<following[i]->followers.size(); j++){
                if(following[i]->followers[j] == this){
                    following[i]->followers.erase(following[i]->followers.begin()+j);
                }
            }
            
        }
    }
}

int Member :: count(){  // returns the number of members
    return counter;
}
