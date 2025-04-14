#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

class Dashboard {
public:
    void displayKPIs() {
        cout << "Number of Orders: 100" << endl;
        cout << "Successful Deliveries: 90" << endl;
        cout << "Pending Tasks: 10" << endl;
    }

    void showMap() {
        cout << "Showing live map..." << endl;
    }

    void sendAlerts() {
        cout << "Checking for alerts..." << endl;
    }
};

class Order {
public:
    string orderID;
    string customerName;
    string contactInformation;
    string deliveryAddress;
    vector<string> orderDetails;
    string status;
    string preferredDeliveryTime;
    string customerFeedback;
    string deliveryPersonnel;
    string estimatedDeliveryTime;
    string deliveryRoute;
    

    Order(string id, string name, string address, double rating, string time, string priority) {
        orderID = id;
        customerName = name;
        deliveryAddress = address;
        customerFeedback = to_string(rating);
        preferredDeliveryTime = time;
        status = "Pending";
        contactInformation = "N/A";
        deliveryPersonnel = "Not assigned";
        estimatedDeliveryTime = "N/A";
        deliveryRoute = "N/A";
    }
    Order() = default;
};

class OrderManagement {
private:
    vector<Order> orders;

    vector<Order>::iterator findOrder(const string& orderID) {
        return find_if(orders.begin(), orders.end(),
            [&orderID](const Order& order) { return order.orderID == orderID; });
    }

public:
    void createOrder(const Order& newOrder) {
        if (findOrder(newOrder.orderID) != orders.end()) {
            cout << "Error: Order ID " << newOrder.orderID << " already exists!" << endl;
            return;
        }
        orders.push_back(newOrder);
        cout << "Order created: " << newOrder.orderID << endl;
    }

    void editOrder(const string& orderID, const string& newStatus) {
        auto it = findOrder(orderID);
        if (it != orders.end()) {
            it->status = newStatus;
            cout << "Order " << orderID << " status updated to " << newStatus << endl;
        } else {
            cout << "Order not found!" << endl;
        }
    }

    void deleteOrder(const string& orderID) {
        auto it = findOrder(orderID);
        if (it != orders.end()) {
            orders.erase(it);
            cout << "Order " << orderID << " deleted." << endl;
        } else {
            cout << "Order not found!" << endl;
        }
    }

    void displayAllOrders() {
        if (orders.empty()) {
            cout << "No orders available." << endl;
            return;
        }
        for (const auto& order : orders) {
            cout << "Order ID: " << order.orderID << ", Status: " << order.status << endl;
        }
    }

    void trackOrder(const string& orderID) {
        auto it = findOrder(orderID);
        if (it != orders.end()) {
            cout << "Order " << orderID << " is currently " << it->status << endl;
        } else {
            cout << "Order not found!" << endl;
        }
    }

    void displayOrderDetails(const string& orderID) {
        auto it = findOrder(orderID);
        if (it != orders.end()) {
            cout << "Order ID: " << it->orderID << endl;
            cout << "Customer Name: " << it->customerName << endl;
            cout << "Contact Information: " << it->contactInformation << endl;
            cout << "Delivery Address: " << it->deliveryAddress << endl;
            cout << "Order Details: " << endl;
            for (const auto& item : it->orderDetails) {
                cout << "  " << item << endl;
            }
            cout << "Status: " << it->status << endl;
            cout << "Delivery Personnel: " << it->deliveryPersonnel << endl;
            cout << "Estimated Delivery Time: " << it->estimatedDeliveryTime << endl;
            cout << "Delivery Route: " << it->deliveryRoute << endl;
            cout << "Customer Feedback: " << it->customerFeedback << endl;
        } else {
            cout << "Order not found!" << endl;
        }
    }

    vector<Order> getOrders() const {
        return orders;
    }
};

class RouteOptimization {
public:
    void suggestRoute(const OrderManagement& orderManagement) {
        const auto& orders = orderManagement.getOrders();
        if (orders.empty()) {
            cout << "No orders available for route optimization." << endl;
            return;
        }

        for (const auto& order : orders) {
            cout << "Order ID: " << order.orderID << endl;
            cout << "Customer Name: " << order.customerName << endl;
            cout << "Delivery Address: " << order.deliveryAddress << endl;
            cout << "Preferred Delivery Time: " << order.preferredDeliveryTime << endl;
            cout << "Status: " << order.status << endl;
            cout << "Suggested Route: Via Main Road" << endl;
            cout << "Estimated Travel Time: 30 minutes" << endl;
            cout << "Traffic Conditions: Moderate" << endl;
            cout << "Weather Conditions: Clear" << endl;
            cout << "-----------------------------------" << endl;
        }
    }
};

class Notification {
public:
    void sendErrorAlert(const string& message) {
        cout << "Error Alert: " << message << endl;
    }

    void notifyOrderChange(const string& orderID) {
        cout << "Order " << orderID << " has been modified." << endl;
    }

    void alertDeliveryDelay(const string& orderID) {
        cout << "Delivery delay for order " << orderID << ". Please check." << endl;
    }
};

class UserInterface {
private:
    void clearInputBuffer() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void createNewOrder(OrderManagement& orderManagement) {
        Order newOrder;
        cout << "Enter Order ID: ";
        getline(cin, newOrder.orderID);
        
        if (newOrder.orderID.empty()) {
            cout << "Error: Order ID cannot be empty!" << endl;
            return;
        }

        cout << "Enter Customer Name: ";
        getline(cin, newOrder.customerName);
        
        cout << "Enter Contact Information: ";
        getline(cin, newOrder.contactInformation);
        
        cout << "Enter Delivery Address: ";
        getline(cin, newOrder.deliveryAddress);
        
        cout << "Enter Order Details (comma separated): ";
        string details;
        getline(cin, details);
        istringstream iss(details);
        string item;
        while (getline(iss, item, ',')) {
            item.erase(0, item.find_first_not_of(" \t\n\r\f\v"));
            item.erase(item.find_last_not_of(" \t\n\r\f\v") + 1);
            if (!item.empty()) {
                newOrder.orderDetails.push_back(item);
            }
        }

        newOrder.status = "Pending";
        newOrder.preferredDeliveryTime = "N/A";
        newOrder.customerFeedback = "N/A";
        newOrder.deliveryPersonnel = "Not assigned yet";
        newOrder.estimatedDeliveryTime = "N/A";
        newOrder.deliveryRoute = "N/A";
        
        orderManagement.createOrder(newOrder);
    }

    void handleOrderManagement(OrderManagement& orderManagement) {
        int orderChoice;
        cout << "Manage Orders Menu:" << endl;
        cout << "1. Create Order" << endl;
        cout << "2. Edit Order" << endl;
        cout << "3. Delete Order" << endl;
        cout << "4. View All Orders" << endl;
        cout << "5. Track Order" << endl;
        cout << "6. View Order Details" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> orderChoice)) {
            cin.clear();
            clearInputBuffer();
            cout << "Invalid input. Please enter a number." << endl;
            return;
        }
        clearInputBuffer();

        string orderID, newStatus;
        switch (orderChoice) {
            case 1:
                createNewOrder(orderManagement);
                break;
            case 2:
                cout << "Enter Order ID to edit: ";
                getline(cin, orderID);
                cout << "Enter new status: ";
                getline(cin, newStatus);
                orderManagement.editOrder(orderID, newStatus);
                break;
            case 3:
                cout << "Enter Order ID to delete: ";
                getline(cin, orderID);
                orderManagement.deleteOrder(orderID);
                break;
            case 4:
                orderManagement.displayAllOrders();
                break;
            case 5:
                cout << "Enter Order ID to track: ";
                getline(cin, orderID);
                orderManagement.trackOrder(orderID);
                break;
            case 6:
                cout << "Enter Order ID to view details: ";
                getline(cin, orderID);
                orderManagement.displayOrderDetails(orderID);
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

public:
    void displayMenu() {
        cout << "\n=== Delivery Management System ===" << endl;
        cout << "1. View Dashboard" << endl;
        cout << "2. Manage Orders" << endl;
        cout << "3. Optimize Routes" << endl;
        cout << "4. Notifications" << endl;
        cout << "0. Exit" << endl;
    }

    void handleUserInput(Dashboard& dashboard, OrderManagement& orderManagement,
                        RouteOptimization& routeOptimization, Notification& notification) {
        int choice;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            clearInputBuffer();
            cout << "Invalid input. Please enter a number." << endl;
            return;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                dashboard.displayKPIs();
                dashboard.showMap();
                dashboard.sendAlerts();
                break;
            case 2:
                handleOrderManagement(orderManagement);
                break;
            case 3:
                routeOptimization.suggestRoute(orderManagement);
                break;
            case 4:
                notification.sendErrorAlert("Test Alert");
                break;
            case 0:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
};

int main() {
    Dashboard dashboard;
    OrderManagement orderManagement;
    RouteOptimization routeOptimization;
    Notification notification;
    UserInterface userInterface;

    // Add predefined orders
    vector<Order> predefinedOrders = {
        Order("201", "Rajesh Kumar", "15, MG Road, Bengaluru, Karnataka", 4.5, "09:00 AM - 12:00 PM", "High"),
        Order("202", "Priya Sharma", "87, Park Street, Kolkata, West Bengal", 2.3, "10:30 AM - 01:30 PM", "Medium"),
        Order("203", "Aarav Patel", "12, CG Road, Ahmedabad, Gujarat", 5.0, "08:00 AM - 11:00 AM", "High"),
        Order("204", "Sanya Gupta", "22, Marina Beach Road, Chennai, Tamil Nadu", 3.2, "11:00 AM - 02:00 PM", "Medium"),
        Order("205", "Manish Tiwari", "5, Hazratganj, Lucknow, Uttar Pradesh", 6.7, "07:30 AM - 10:30 AM", "High")
    };

    // Add predefined orders to the system
    for (const auto& order : predefinedOrders) {
        orderManagement.createOrder(order);
    }

    // Main application loop
    while (true) {
        userInterface.displayMenu();
        userInterface.handleUserInput(dashboard, orderManagement, routeOptimization, notification);
    }

    return 0;
}
