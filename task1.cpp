#include <iostream>
#include <string>
#include <vector>
using namespace std;
//second modified

class Product {
public:
    int id;
    string name;
    double price;
    int stock;

    // TODO: Complete constructor
    Product(int i, string n, double p, int s) {
        // Your code here
        id=i;
        name=n;
        price=p;
        stock=s;
    }

    // TODO: Complete display method
    void display() {
        // Your code here
        cout<<"ID: "<<id<<" | "<<name<<" | price: "<<price<<" | stock: "<<stock;

    }
};

class OrderItem {
public:
    int productId;
    int quantity;

    // TODO: Complete constructor
    OrderItem(int pid, int qty) {
        // Your code here
        productId=pid;
        quantity=qty;
    }
};

class Customer {
public:
    int id;
    string name;
    string email;
    vector<int> orderIds;

    // TODO: Complete constructor
    Customer(int i, string n, string e) {
        // Your code here
        id=i;
        name=n;
        email=e;
    }

    // TODO: Complete display method
    void display() {
        // Your code here
        cout<<"Customer ID: "<<id<<" | Nama: "<<name<<"\n ";
        cout<<"Order History: ";
        for (int i = 0; i < orderIds.size(); i++)
        {
            cout<<orderIds[i];
        }
        

    }
};

class Order {
public:
    int id;
    int customerId;
    vector<OrderItem> items;
    double total;

    // TODO: Complete constructor
    Order(int i, int cid) {
        // Your code here
        id=i;
        customerId=cid;
    }

    // TODO: Complete calculateTotal
    void calculateTotal(vector<Product>& products) {
        // Your code here
        total=0;
        for (int i = 0; i < items.size(); i++)
        {
            for (int j = 0; j < products.size(); j++)
            {
                if (products[j].id==items[i].productId)
                {
                    total+=products[j].price*items[i].quantity;
                    break;
                }   
            }
        }
        
    }

    // TODO: Complete display
    void display(vector<Product>& products) {
        // Your code here
        cout<<"Order ID: "<<id<<" | Customer: "<<customerId<<" | Total: $"<<total<<"\n";
        for (int i = 0; i < items.size(); i++)
        {
            for (int j = 0; j < products.size(); j++)
            {
                if (items[i].productId==products[j].id)
                {
                    cout<<"- "<<products[j].name<<" (x"<<items[i].quantity<<") @ $"<<products[j].price<<"\n";
                    break;
                }
                
            }
            cout<< 
        }
        

        
    }
};

class ECommerceSystem {
public:
    vector<Product> products;
    vector<Customer> customers;
    vector<Order> orders;
    int nextProductId = 1;
    int nextCustomerId = 1;
    int nextOrderId = 1;

    // TODO: Complete addProduct
    void addProduct(string name, double price, int stock) {
        // Your code here
        products.push_back(Product(nextProductId++,name,price,stock));
    }

    // TODO: Complete addCustomer
    void addCustomer(string name, string email) {
        // Your code here
        customers.push_back(Customer(nextCustomerId++,name,email));
    }

    // TODO: Complete createOrder
    void createOrder(int customerId) {
        // Your code here
        orders.push_back(Order(nextOrderId++,customerId));

    }

    // TODO: Complete addToOrder
    void addToOrder(int orderId, int productId, int quantity) {
        // Your code here
        for (int i = 0; i < orders.size(); i++)
        {
            if (orders[i].id==orderId && orders[i].items[i].quantity<=products[i].stock)
            {
                
            }
            
        }
        
    }

    void displayAll() {
        cout << "\n=== PRODUCTS ===" << endl;

        cout << "\n=== CUSTOMERS ===" << endl;
        
        cout << "\n=== ORDERS ===" << endl;

    }
};

int main() {
    ECommerceSystem shop;

    // Sample data - don't modify
    shop.addProduct("Laptop", 999.99, 10);
    shop.addProduct("Mouse", 19.99, 50);
    shop.addCustomer("John Doe", "john@example.com");
    shop.addCustomer("Alice Smith", "alice@example.com");

    shop.createOrder(1);
    shop.addToOrder(1, 1, 1);
    shop.addToOrder(1, 2, 2);

    shop.createOrder(2);
    shop.addToOrder(2, 1, 1);

    shop.displayAll();

    return 0;
}