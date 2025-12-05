#include "Restaurant.h"

void Restaurant :: addOrder(const Order& o){

    orderBook_.addOrder(o);

}

bool Restaurant :: placeDineInRegular(int orderId){

    if(!orderBook_.findOrderById(orderId)){
        return false;
    } 
    // check case to see if we have orders in the restuarant.

    Order* order = orderBook_.findOrderById(orderId);

    order -> setStatus("PendingRegular");

    regularQueue_.enqueue(orderId);

    return true;
}

bool Restaurant :: placeDineInRush(int orderId, int priority){

    if(!orderBook_.findOrderById(orderId)){
        return false;
    } 
    // check case to see if we have orders in the restuarant.

    Order* order = orderBook_.findOrderById(orderId);

    order -> setStatus("PendingRush");

    rushQueue_.push(orderId, priority);

    return true;

}
bool Restaurant :: placeUberOrder(int orderId, int priority){

    orderBook_.findOrderById(orderId) -> setSource("Uber");
    return placeDineInRush(orderId, priority);

}

bool Restaurant :: completeNextOrder(){
    
    if(!rushQueue_.empty()){
        //do rushqueue
        Order * order = findOrderById(rushQueue_.top().id);
        if(order -> status() == "PendingRush"){
            order -> setStatus("Completed");
             rushQueue_.pop();
             return true;
        }

    }else {
        //do rushqueue
        if(regularQueue_.empty()){
            return false;
        }
        Order * order = findOrderById(regularQueue_.front());
        if(order -> status() == "PendingRegular"){
             order -> setStatus("Completed");
             regularQueue_.dequeue();
             return true;
        } 
    
    }
    return false;
    
}

bool Restaurant :: undoLastCompletion(){

    if(completedStack_.empty()){
        return false;

    }

    int lastId = completedStack_.top();
    completedStack_.pop();

    Order* order = orderBook_.findOrderById(lastId);

    if(order -> isRush()){
        order -> setStatus("PendingRush");

        rushQueue_.push(lastId, order -> priority());
    }
    else{
        order -> setStatus("PendingRegular");
        regularQueue_.enqueue(lastId);
    }

    return true;
}
void Restaurant :: printState() const {
    std :: cout << "Status:\n";
    int count = 0;
    for(Order i : orderBook_.all()) {
        // dont print the completed
        if (i.status() != "Completed") {
            std :: cout << "ID: " << i.id() << " of " << i.customerName() << " (" << i.source() << "): " << i.status() << std :: endl;
            count++;
        }

    } 
    if(count == 0){
        std :: cout << "All completed. Thank you for dining." << "\n";
    }
}

Order* Restaurant :: findOrderById(int id){
    if (orderBook_.findOrderById(id)){
        return orderBook_.findOrderById(id);
    }
    else{
        return nullptr;
    }
}