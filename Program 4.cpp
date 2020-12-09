#include <iostream>

using namespace std;

// Jingnan Qi Assignment 4

class Rectangle
{
private: 
    double length,
        width,
        area;

public: 
    //constructors 
    Rectangle(): length(0.0), width(0.0), area(0.0)
    {}
    Rectangle(double ln, double w)
    {
        length = ln,
        width = w,
        area = ln * w;
    }

    //access functions 
    double getLength()
    {
        return length;
    }

    double getWidth()
    {
        return width;
    }
    double getArea()
    {
        return area;
    }

    bool EqualAreaTo(Rectangle r)
    {
        return (area == r.area);
    }

    bool GreaterAreaThan(Rectangle r)
    {
        if (area > r.area)
            return true;
        return false;
    }

    bool LessAreaThan(Rectangle r)
    {
        if (area < r.area)
            return true;
        return false;
    }

    //modifier functions
    void setLength(double ln)
    {
        length = ln;
    }

    void setWidth(double w)
    {
        width = w;
    }

    //input/output functions 
    void Read(); 
    void Write(); 
};

void Rectangle::Read()
{
    cin >> length;
    cout << "Width: ";
    cin >> width;
    area = length * width;
}

void Rectangle::Write()
{
    cout << "Length: "
        << length
        << " Width: "
        << width
        << " and area "
        << area;
}

//Rectangle class
int main()
{
    Rectangle r1,
        r2;

    cout << "Enter parameters of first rectangle\nLength: ";
    r1.Read();
    cout << "Enter parameters of second rectangle\nLength: ";
    r2.Read();

    if (r1.LessAreaThan(r2)) {
        cout << "\nThe first rectangle with ";
        r1.Write();
        cout << "\nis smaller than the second rectangle with\n";
        r2.Write();
    }
    else {
        cout << "\nThe second rectangle with ";
        r2.Write();
        cout << "\nis smaller than or equal to the first rectangle with\n";
        r1.Write();
    }

    cout << endl;

    return 0;
}

