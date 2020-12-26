#include <iostream>
#include <string>

using namespace std;

// Jingnan Qi Assignment 6

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

    Currency operator++() 
    {
        ++d;
        return Currency(d));
    }

    Currency operator++(int) 
    {
        d++;
        return Currency(d);
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
    bool operator==(Currency c)
    {
        return (amount == c.amount);
    }

    bool operator>(Currency c)
    {
        return amount > c.amount;
    }

    bool operator<(Currency c)
    {
        return amount < c.amount;
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

    //input and output
    friend istream& operator>>(istream& s, Currency& c);
    friend ostream& operator<<(ostream& s, const Currency& c);
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

ostream& operator<<(ostream& s, const Currency& c) 
{
    s << c.amount; 
    return s;
}

istream& operator>>(istream& s, Currency& c) 
{
    double temp; 
    s >> temp;
    c.amount = temp;
    return s;
}

class InventoryItem
{
private:
    string itemName;
    int itemNum,
        quantity;
    Currency price;

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
        return price.Multiply(quantity);
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
};

void GetItems(InventoryItem list[], int& count);
void Sort(InventoryItem list[], int count, char order);

void GetItems(InventoryItem list[], int& count)
{
    int value;
    InventoryItem item;
    count = 0;

    cout << "How many values are to be sorted? ";
    cin >> value;

    while (count < value) {
        cout << "Enter following information for Item " << count + 1;
        item.Read();
        list[count] = item;
        count++;
    }
}

void Sort(InventoryItem list[], int count, char order)
{
    for (int i = (count - 1); i > 0; i--) 
        for (int j = 0; j < i; j++) 
            if ((list[j].getTotalValue() > list[j + 1].getTotalValue()) 
                && (order == 'A' || order == 'a'))
                swap(list[j], list[j + 1]);
            else if ((list[j].getTotalValue() < list[j + 1].getTotalValue()) 
                && (order == 'D' || order == 'd'))
                swap(list[j], list[j + 1]);
}

void InventoryItem::Read()
{
    cout << "\nItem Name: ";
    cin >> itemName;
    cout << "Item Number: ";
    cin >> itemNum;
    cout << "Unit Price: ";
    cin >> price;
    cout << "Quantity: ";
    cin >> quantity;
}

int main()
{
    InventoryItem itemList[100];
    char adResponse = 'A';
    int count;

    GetItems(itemList, count);

    do {
        cout << "\nSpecify sort order, \"A\" for ascending, \"D\" for descending: ";
        cin >> adResponse;
    } while ((adResponse != 'A') && (adResponse != 'a') 
        && (adResponse != 'D') && (adResponse != 'd'));
    
    Sort(itemList, count, adResponse);

    for (int i = 0; i < count; i++) 
        cout << "\nItem Name: "
        << itemList[i].getName()
        << "\t"
        << "Item Number : "
        << itemList[i].getItemNum()
        << "\t"
        << "Unit Price: "
        << itemList[i].getUnitPrice()
        << "\nQuantity: "
        << itemList[i].getQuantity()
        << "\t"
        << "Total Item Value: "
        << itemList[i].getTotalValue()
        << endl;

    return 0;
}