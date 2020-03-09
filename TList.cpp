#include <iostream>
#include <list>
#include <vector>
#include<iterator>
using namespace std;

template <class T>
void showlist(list <T> g)
{
    list <T> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

bool isClose(double a, double b)
{
    return (abs(a - b) < 1.e-6);
}

void main()
{
    double l_endTime = 1000.;
    vector<double > a = {400.00000000000001, 500.};
    vector<double > b = {200., 400.000, 600.};

    list<double > l_time;
    for (vector<double >::iterator it = a.begin(); it < a.end(); it++)
    {
        l_time.push_back(*it);
    }
    for (vector<double >::iterator it = b.begin(); it < b.end(); it++)
    {
        l_time.push_back(*it);
    }
    std::copy(b.begin(), b.end(), std::back_inserter(l_time));
    l_time.push_back(l_endTime);

    showlist(l_time);
    l_time.sort();
    showlist(l_time);
    bool l_removed = false;
    l_time.unique(isClose);
    showlist(l_time);

    system("pause");
}