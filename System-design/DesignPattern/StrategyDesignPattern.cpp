#include <iostream>
using namespace std;

// Interfaces
class Talkable {
public:
    virtual void talk() = 0;
    virtual ~Talkable() {}
};

class Walkable {
public:
    virtual void walk() = 0;
    virtual ~Walkable() {}
};

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

// Talk behaviors
class TalkRobot1 : public Talkable {
public:
    void talk() override {
        cout << "from TalkRobot1" << endl;
    }
};

class TalkRobot2 : public Talkable {
public:
    void talk() override {
        cout << "from TalkRobot2" << endl;
    }
};

// Walk behaviors
class WalkRobot1 : public Walkable {
public:
    void walk() override {
        cout << "from WalkRobot1" << endl;
    }
};

class WalkRobot2 : public Walkable {
public:
    void walk() override {
        cout << "from WalkRobot2" << endl;
    }
};

// Fly behaviors
class FlyRobot1 : public Flyable {
public:
    void fly() override {
        cout << "from FlyRobot1" << endl;
    }
};

class FlyRobot2 : public Flyable {
public:
    void fly() override {
        cout << "from FlyRobot2" << endl;
    }
};

// Robot (composition)
class Robot {
private:
    Talkable* t;
    Walkable* w;
    Flyable* f;

public:
    Robot(Talkable* t, Walkable* w, Flyable* f)
        : t(t), w(w), f(f) {}

    void talk() { t->talk(); }
    void walk() { w->walk(); }
    void fly()  { f->fly(); }
};

int main() {
    Talkable* t1 = new TalkRobot1();
    Talkable* t2 = new TalkRobot2();

    Walkable* w1 = new WalkRobot1();
    Walkable* w2 = new WalkRobot2();

    Flyable* f1 = new FlyRobot1();
    Flyable* f2 = new FlyRobot2();

    Robot r1(t1, w1, f1);
    Robot r2(t2, w2, f2);

    r1.talk();
    r1.walk();
    r1.fly();

    cout << "----" << endl;

    r2.talk();
    r2.walk();
    r2.fly();

    return 0;
}
