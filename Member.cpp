#include <vector>
#include <iostream>
#include "Member.h"

using namespace std;

int Member :: counter = 0;
    
Member :: Member(){
    counter++;
}   

Member :: ~Member(){
    counter--;
    for(int i=0; i<followers.size(); i++){
        followers[i]->unfollow(*this);
    }
    for(int i=0; i<following.size(); i++){
        unfollow(*following[i]);
    }
}

void Member :: follow (Member &name){

    Member *p = &name;    
    for(int i=0; i<following.size(); i++){
        if (following[i] == p) return;
    }
    following.push_back(p);
    name.followers.push_back(this);
}

int Member :: numFollowers (){
     return followers.size();
}

int Member :: numFollowing (){
    return following.size();
}

void Member :: unfollow(Member &name){
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

int Member :: count(){ 
    return counter;
}