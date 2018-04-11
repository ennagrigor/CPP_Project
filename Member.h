#include <vector>
#include <iostream>

using namespace std;

class Member{
    vector<Member*> followers;
    vector<Member*> following;
    static int counter;

    public:
    Member();
    ~Member();
    void follow(Member &name);
    int numFollowers();
    int numFollowing();
    void unfollow(Member &name);
    static int count();
};