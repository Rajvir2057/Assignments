#include "Restaurant.h"
int main(){
    Restaurant a;
    Order one;
    Order two;
    Order three;
    Order four;
    Order five;
    Order six;
    //Initialization of order ID, name, table, and type
    one.initValues(101, 5, "Margherita Pizza", "DineIn");
    two.initValues(102, 3, "Caesar Salad", "DineIn");
    three.initValues(103, 8, "Spaghetti", "DineIn");
    four.initValues(201, -1, "Burger", "Uber");
    five.initValues(202, -1, "Soup of the day", "Uber");
    six.initValues(203, -1, "Pasta Special", "Uber");

    //Special initialization for Uber Orders
    four.setCustomerName("Alice");
    four.setDeliveryAddress("121 Main St");

    five.setCustomerName("Bob");
    five.setDeliveryAddress("122 Main St");

    six.setCustomerName("Carrie");
    six.setDeliveryAddress("123 Main St");

    

//R1
    a.addOrder(one);
    a.addOrder(two);
    a.placeDineInRegular (101);
    a.placeDineInRegular (102);

        //completes next order
    a.printState();
    a.completeNextOrder();
    a.printState();
    a.completeNextOrder();
    a.printState();

    std::cout<<"\nExpected : 101 removed -> 102 removed -> empty";
    delete &a;

//R2
    Restaurant b;
    b.addOrder(one);
    b.addOrder(two);
    b.addOrder(four);
    b.addOrder(five);

    b.placeDineInRegular(101);
    b.placeDineInRegular(102);
    b.placeUberOrder(201,5);
    b.placeUberOrder(202,10);

    b.printState();
    b.completeNextOrder();
    b.printState();
    b.completeNextOrder();
    b.printState();
    b.completeNextOrder();
    b.printState();
    
    std::cout<<"\nExpected : 202 removed -> 201 removed -> 101 removed";
    delete &b;

//R3
    //Creates a new restaurant
    Restaurant c;
    c.addOrder(one);
    c.addOrder(two);
    c.addOrder(four);

    //Places orders in their respective queues
    c.placeDineInRegular(101);
    c.placeDineInRush(102, 4);
    c.placeUberOrder(201, 7);

    c.printState();
    c.completeNextOrder();
    c.printState();
    c.completeNextOrder();
    c.printState();
    c.undoLastCompletion();
    c.printState();

    std::cout<<"\nExpected : 102 removed -> 201 removed" <<"-> undo removal of 201, 201 restored"
    <<"201 is moved to pendingRush";

    delete &c;

//R4
    Restaurant d;
    d.addOrder(four);
    d.addOrder(five);
    d.addOrder(six);
    d.placeUberOrder(201, 3);
    d.placeUberOrder(202, 9);
    d.placeUberOrder(203, 6);

    d.printState();
    d.completeNextOrder();
    d.printState();
    d.completeNextOrder();
    d.printState();
    d.completeNextOrder();
    d.printState();

    std::cout<<"\nExpected : 201 removed -> 203 removed -> 202 removed";

//R5
    Restaurant e;
    e.completeNextOrder();
    e.undoLastCompletion();
}