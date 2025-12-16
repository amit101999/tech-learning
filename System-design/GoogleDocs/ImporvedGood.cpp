#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
   virtual string render() = 0;
    
};

class TextElement : public DocumentElement{
    private:
    string text;

    public:

    TextElement(string text){
        this->text = text;
    }

    public :
    string render(){
        return text;
    }
};

class ImageElement : public DocumentElement{
    private:
    string image ;

    public :
    ImageElement(string image){
        this->image = image;
    }

    string render(){
        return "The image path is : "+ image;
    }
};

// now here if we have multiple document member such as video , audio aur anything else we can 
// add here as class an inherite with the interface we have created above


class Document {

    private:
    vector<DocumentElement *>docs;

    public:
    void addElement(DocumentElement *d){
        docs.push_back(d);
    }

    string render(){
        string result ="";
        for(auto x : docs){
            result += x->render();
        }
        return result;
    }

};

class SaveData{
    public :
    virtual void save(const string& data) = 0;
};

class SaveToDB : public SaveData{
    public:

    void save(const string& data) override{
        cout<<"data saved to db is :"<<data<<endl;
    }
};

class SaveToFileStorage : public SaveData{
    public:
    
    void save(const string& data) override{
        cout<<"data saved to File Storage System : "<<data<<endl;
    }
};


class DocumentEditior{
    private:
    Document *d;
    SaveData *sd;
    string renderDocs;

    public:

    DocumentEditior(Document *docs , SaveData *sa){
        this->d = docs;
        this->sd = sa;
    }

    void addText(string text){
        d->addElement(new TextElement(text));
    }
    void addImage(string imagePath){
        d->addElement(new ImageElement(imagePath));
    }

    string renderDocument(){
        if(renderDocs.empty()){
            renderDocs = d->render();
        }
        return renderDocs;
    }

    void dataSave(){
        sd->save(renderDocument());
    }
};
// here also in future we can add mutiple types of staorage system single we have a single
// method that comes form abstract class


int main(){
    Document *d = new Document();
    SaveData* sd = new SaveToDB();

    DocumentEditior *editor = new DocumentEditior(d , sd);
    editor->addText("hello world");
    editor->addImage("Picture.jpg");

    cout<<editor->renderDocument();

    editor->dataSave();
    return 0;
}