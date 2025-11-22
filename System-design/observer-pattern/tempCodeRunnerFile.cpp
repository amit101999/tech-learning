
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

