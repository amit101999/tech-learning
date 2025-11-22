#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// interface -- purely abstract class

 class ISubscriber{
    public :
    virtual void update() = 0;
    virtual ~ISubscriber() = default;
};

 class IChannel{
    public:
    virtual void add(ISubscriber* sub) = 0;
    virtual void remove(ISubscriber* sub) = 0;
    virtual void notify() = 0;
    virtual ~IChannel() = default;
};

class Channel : public IChannel{
    private:
    vector<ISubscriber*> subs;
    string name;
    string latestVideo;

    public:
    Channel(string name){
        this->name = name;
    }

    void add(ISubscriber* sub) override {
        if (find(subs.begin(), subs.end(), sub) == subs.end()){
            subs.push_back(sub);
        }
    }
    void remove(ISubscriber* sub){
        auto it = find(subs.begin(), subs.end(), sub);
        if (it != subs.end()) subs.erase(it);
    }

    void notify(){
        for(ISubscriber* sub : subs){
            sub->update();
        }
    }

    void uploadVideo(string name){
    latestVideo = name;
    cout<<"New video uploaded is : "<< latestVideo <<"\n";
    notify(); 
    }

    string getLatestVideo(){
        return latestVideo;
    }
};
class Subscriber : public ISubscriber{
    private:
    string name ;
    Channel *ch;

    public:
    Subscriber(string name , Channel *ch){
        this->name = name;
        this->ch = ch;
    }

    void update() override {
        cout << name << " got notification: " << ch->getLatestVideo() << "\n";
    }
    
};

int main(){
    Channel* ch = new Channel("Coder Army");

    Subscriber* sub1 = new Subscriber("Amit" , ch);
    Subscriber* sub2 = new Subscriber("Atul" , ch);
    
    ch->add(sub1);
    ch->add(sub2);

    ch->uploadVideo("hello world");

    ch->remove(sub1);

    ch->uploadVideo("hello world part 2");

    return 0;

}


