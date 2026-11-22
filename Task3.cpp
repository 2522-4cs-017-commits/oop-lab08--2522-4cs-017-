#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double basePrice;

public:
    Product(string n, double p) {
        name = n;
        basePrice = p;
    }

    string getName() const {
        return name;
    }

    virtual double price() const = 0;
    virtual ~Product() {}
};

class Book : public Product {
public:
    Book(string n, double p) : Product(n, p) {}
    double price() const override {
        return basePrice;
    }
};

class Electronics : public Product {
public:
    Electronics(string n, double p) : Product(n, p) {}
    double price() const override {
        return basePrice * 1.17;
    }
};

class Cart {
private:
    Product* items[10];
    int count;

public:
    Cart() {
        count = 0;
    }

    Cart& operator+=(Product* p) {
        if (count >= 10) {
            cout << "Cart is full!" << endl;
        } else {
            items[count] = p;
            count++;
        }
        return *this;
    }

    Product* operator[](int i) const {
        if (i < 0 || i >= count) {
            return nullptr;
        }
        return items[i];
    }

    double total() const {
        double sum = 0;
        for (int i = 0; i < count; i++) {
            sum += items[i]->price();
        }
        return sum;
    }

    friend ostream& operator<<(ostream& out, const Cart& c);

    ~Cart() {
        for (int i = 0; i < count; i++) {
            delete items[i];
        }
    }
};

ostream& operator<<(ostream& out, const Cart& c) {
    out << "Cart:" << endl;
    for (int i = 0; i < c.count; i++) {
        out << c.items[i]->getName() << ": Rs. " << c.items[i]->price() << endl;
    }
    out << "Total: Rs. " << c.total() << endl;
    return out;
}

int main() {
    Cart cart;

    cart += new Book("C++ Primer", 2500);
    cart += new Electronics("Headphones", 4000);
    cart += new Electronics("USB Drive", 1000);

    cout << cart;

    if (cart[1] != nullptr) {
        cout << "Second item: " << cart[1]->getName() << endl;
    }

    if (cart[5] == nullptr) {
        cout << "cart[5] does not exist" << endl;
    }

    return 0;
}