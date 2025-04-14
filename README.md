# 🚚 Delivery Management System

An all-in-one **C++ Console Application** that streamlines the logistics of managing orders, optimizing delivery routes, sending alerts, and tracking real-time delivery performance.

---

## 📌 Features

- 📊 **Dashboard KPIs**  
  - Displays total orders, successful deliveries, and pending tasks  
  - Simulated live map & alert system

- 📦 **Order Management**  
  - Create, update, delete, and track orders  
  - View full order details  
  - Smart order input handling with validation

- 🗺️ **Route Optimization**  
  - Suggests optimal routes based on traffic, weather, and time  
  - Displays estimated travel time and delivery conditions

- 🚨 **Notification System**  
  - Sends error alerts  
  - Notifies changes in order status  
  - Alerts for delivery delays

- 🧑‍💻 **Interactive User Interface**  
  - Clean and clear menu-driven CLI  
  - Easy input prompts and data feedback

---

## 💡 Technologies Used

- **C++** (Standard Library)
- **Object-Oriented Programming (OOP)**
- **Data Structures:** Vectors, Strings
- **Modular Code Design**

---

## 🧱 Class Structure

- `Dashboard` - KPI overview, map simulation, alert triggers  
- `Order` - Stores customer and order-specific data  
- `OrderManagement` - Manages lifecycle of orders  
- `RouteOptimization` - Simulates route suggestion  
- `Notification` - Sends relevant alerts  
- `UserInterface` - CLI interaction and menu handling

---

## 🔧 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/delivery-management-system.git
2.Compile the code
    g++ -std=c++11 main.cpp -o delivery_system
3. Run the executable
    ./delivery_system
4. #sample Output
  === Delivery Management System ===
  1. View Dashboard
  2. Manage Orders
  3. Optimize Routes
  4. Notifications
  0. Exit

