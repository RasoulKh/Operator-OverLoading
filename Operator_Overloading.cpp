#include <iostream>
#include <string>
#include <list>
using namespace std;

/* Operator OverLoading */

struct Youtubechannel {
    /* User-Difined Data type*/
    int NumberofSubscriber;
    string Name;

    Youtubechannel(string name, int numberofSubscriber){
        Name = name;
        NumberofSubscriber = numberofSubscriber;
    }
    bool operator == (const Youtubechannel& channel) const{
        return this->Name == channel.Name;
    } 
};

struct Collection {
    list <Youtubechannel> Channel;
    
    void operator += (Youtubechannel& channel) {
        this->Channel.push_back(channel);
    }
    void operator -= (Youtubechannel& channel) {
        this->Channel.remove(channel);
    }
};

ostream& operator << (ostream& COUT, Youtubechannel& ytchannel) {
    COUT << "Name: " << ytchannel.Name << endl;
    COUT << "Subscribers: " << ytchannel.NumberofSubscriber << endl;
    return COUT;
}


ostream& operator << (ostream& COUT, Collection& my_collection){
    for(Youtubechannel ytChannel : my_collection.Channel)
        COUT << ytChannel << endl;
    
    return COUT;

}
//*********************************//
//***********   Main   ************//
//*********************************//
int main(){

    Youtubechannel yt1 = Youtubechannel("Rasoul", 2100);
    Youtubechannel yt2 = Youtubechannel("John", 7100);
    
    Collection myCollection;
    myCollection += yt1;
    myCollection += yt2;

    cout << myCollection;


    return 0;
}

