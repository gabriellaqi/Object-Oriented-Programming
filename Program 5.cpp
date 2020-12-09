#include <iostream>
#include <string>

using namespace std;

// Jingnan Qi Assignment 5

class Currency
{
public:
    double amount;

    //constructors
    Currency() : amount(0)
    {}
    Currency(int d, int c)
    {
        amount = d + (c * 0.01);
    }
    Currency(double amt)
    {
        amount = amt;
    }

    //access functions
    int getDollars()
    {
        return static_cast<int>(amount);
    }

    int getCents()
    {
        return static_cast<int>((amount - getDollars()) * 100);
    }

    Currency Add(Currency c);
    Currency Multiply(double amt);
    bool EqualTo(Currency c)
    {
        return (amount == c.amount);
    }

    bool GreaterThan(Currency c)
    {
        return amount > c.amount;
    }
    //mutator/modifier functions
    void setDollars(int d)
    {
        amount = d + (getCents() * 0.01);
    }

    void setCents(int c)
    {
        amount = getDollars() + (c * 0.01);
    }

    void AddTo(Currency c);

    //input and output functions
    void Read();
    void Write();
};

Currency Currency::Add(Currency c)
{
    Currency result;

    result.amount = amount + c.amount;

    return result;
}

Currency Currency::Multiply(double amt)
{
    Currency result;

    result.amount = amount * amt;

    return result;
}

void Currency::AddTo(Currency c)
{
    amount += c.amount;
}

void Currency::Read()
{
    cin >> amount;
}

void Currency::Write()
{
    cout << amount;
}

class InventoryItem
{
private:
    string itemName;
    int itemNum,
        quantity;
    double price;

public:
    //constructors 
    InventoryItem() : itemName(), itemNum(0), price(0.0), quantity(0)
    {}
    InventoryItem(string n, int iNum, Currency up, int q)
    {
        itemName = n,
            itemNum = iNum,
            price = up.amount,
            quantity = q;
    }

    //access functions 
    string getName()
    {
        return itemName;
    }

    double getItemNum()
    {
        return itemNum;
    }

    Currency getUnitPrice()
    {
        return price;
    }

    int getQuantity()
    {
        return quantity;
    }

    Currency getTotalValue()
    {
        return price * quantity;
    }

    //modifier functions
    void setName(string n)
    {
        itemName = n;
    }

    void setItemNum(int iNum)
    {
        itemNum = iNum;
    }

    void setUnitPrice(Currency u)
    {
        price = u.amount;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    //input/output functions 
    void Read();
    void Write();
};

void InventoryItem::Read()
{
    Currency unitPrice;

    cin >> itemName;
    cout << "Item Number: ";
    cin >> itemNum;
    cout << "Unit Price: ";
    cin >> price;
    cout << "Quantity: ";
    cin >> quantity;
}

void InventoryItem::Write()
{
    cout << "For the inventory item data processed\nItem Name: "
        << itemName
        << "\nItem Number: "
        << itemNum
        << "\nUnit Price: "
        << price
        << "\nQuantity: "
        << quantity
        << "\nTotal value of items in inventory: "
        << price * quantity;
}

//InventoryItem class
int main()
{
    InventoryItem i;
    Currency unitPrice,
        totalVal,
        sumVal;
    int countItem = 0,
        totalQ = 0;
    string ynResponse;

    do {
        cout << "Enter the following item information\nItem Name: ";
        i.Read();
        countItem++;
        totalQ += i.getQuantity();
        unitPrice = i.getUnitPrice();
        totalVal = unitPrice.Multiply(i.getQuantity());
        sumVal = sumVal.Add(totalVal);
        cout << "Do you have more inventory item data to process? (yes/no): ";
        cin >> ynResponse;
        while ((ynResponse != "yes") && (ynResponse != "no")) {
            cout << "Invalie response, please enter \"yes\" or \"no\": ";
            cin >> ynResponse;
        }
    } while (ynResponse == "yes");

    cout << "\nFor the inventory item data processed\nNumber of different item: "
        << countItem
        << "\nTotal number of items: "
        << totalQ
        << "\nTotal value of items in inventory: ";
    sumVal.Write();
    cout << endl;

    return 0;
}