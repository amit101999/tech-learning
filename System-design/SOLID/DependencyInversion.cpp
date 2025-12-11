#include<bits/stdc++.h>
using namespace std;

// this is an example of Dependency Inversion principle
// here what we have done why  a high level should not be allowed to talk directly to low level
// so we use interface here 
// here also we have low level database mysql , mongodb with save funtion we can not direclty implment 
// save in the main service classs instead we use a interface database that will create a sepration 
// between the main low level and high level

class Database{
    public:
    virtual  void save(string data) = 0;
};

class MongoDb : public Database{
    public:
    void save(string data){
        cout<<"mongo db query exceuted for :"<<" "<<data<<endl;
    }
};

class Mysql : public Database{
    public:
    void save(string data){
        cout<<"Mysql db query exceuted for :"<<" "<<data<<endl;
    }
};

class Service{
    private:
    Database *d;

    public :
    Service(Database *db){
        this->d = db;
    }

   void saveToDb(string user){
        d->save(user);
    }
};

int main(){
    Mysql *mysql = new Mysql();
    MongoDb *mongo = new MongoDb();

    Service *s1, *s2;
    s1 = new Service(mysql);
    s2= new Service(mongo);
    s1->saveToDb("AMIT");
    s2->saveToDb("ATUL");
    return 0;
}