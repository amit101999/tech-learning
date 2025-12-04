#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
    int price ;
    string name;

    Product(string name , int price){
        this->price = price;
        this->name = name;
    }
};

class Cart {
    private:
    vector<Product *>prd;

    public:
    void addProduct(Product *p){
        prd.push_back(p);
    }

    int CalculteTotal(){
        int total = 0;
        for(Product *p :prd){
                total += p->price;
        }
        return total;
    }
};


class PrintInvoice {
    private:
    Cart *c;

    public:
    PrintInvoice(Cart *c){
        this->c = c;
    }

    void printInvoiceData(){
        cout<<"shopping data"<<"\n";
        cout<<" total is $"<<c->CalculteTotal()<<endl;
    }
};

class SaveToDB {
    private:
    Cart *c;

    public:
    SaveToDB(Cart *c){
        this->c = c;
    }

    void save(){
        cout<<" Datat saving to db"<<endl;
    }

};

int main(){
    Product *p1 = new Product("apple" , 120);
    Product *p2 = new Product("mongo" ,80);
    Cart *c = new Cart();
     c->addProduct(p1);
     c->addProduct(p2);

    PrintInvoice *print = new PrintInvoice(c);
    print->printInvoiceData();

    SaveToDB *sb = new SaveToDB(c);
    sb->save();

    return 0;
}