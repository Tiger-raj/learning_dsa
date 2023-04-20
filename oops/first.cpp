#include <bits/stdc++.h>
using namespace std;
class rectangle
{
private:
    int length;
    int breadth;

public:
    rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }
};
int main()
{
    class rectangle r1(10, 5);
    int area = r1.area();
    int perimeter = r1.perimeter();
    cout << "Area is : " << area << " and perimeter is : " << perimeter << endl;

    return 0;
}