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

struct MyCollection {
    list <Youtubechannel> myChannel;
    
    void operator += (Youtubechannel& channel) {
        this->myChannel.push_back(channel);
    }
    void operator -= (Youtubechannel& channel) {
        this->myChannel.remove(channel);
    }
};

ostream& operator << (ostream& COUT, Youtubechannel& ytchannel) {
    COUT << "Name: " << ytchannel.Name << endl;
    COUT << "Subscribers: " << ytchannel.NumberofSubscriber << endl;
    return COUT;
}


ostream& operator << (ostream& COUT, MyCollection& my_collection){
    for(Youtubechannel ytChannel : my_collection.myChannel)
        COUT << ytChannel << endl;
    
    return COUT;

}

int main(){


    Youtubechannel yt1 = Youtubechannel("Rasoul", 2100);
    Youtubechannel yt2 = Youtubechannel("Saldina", 7100);
    
 //   cout << yt1 << yt2; //    operator<<(cout, yt1);

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;

    //myCollection -= yt2;

    cout << myCollection;


    return 0;
}

