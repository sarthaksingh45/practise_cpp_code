#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompareFirst(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first > p2.first);
}

bool myCompareSecond(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.second < p2.second);
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vArr;
    int posi = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        vArr.push_back(make_pair(lastDigit, posi));
        n /= 10;
        posi++;
    }
    int maxNo = posi;

    sort(vArr.begin(), vArr.end(), myCompareFirst);

    // for(int i=0; i<maxNo; i++){
    //     cout<< vArr[i].first<<"("<<vArr[i].second<<")"<<" ";
    // }
    // cout<<endl;

    int count = vArr[0].second;

    if (count >= (maxNo / 2))
    {
        for (int i = 0; i < maxNo; i++)
        {
            vArr[i].second = (vArr[i].second + (maxNo - 1 - count)) % maxNo;
        }
    }
    else
    {
        for (int i = 0; i < maxNo; i++)
        {
            vArr[i].second = ((vArr[i].second - (count + 1)) + maxNo) % maxNo;
        }
    }

    sort(vArr.begin(), vArr.end(), myCompareSecond);

    // for(int i=0; i<maxNo; i++){
    //     cout<< vArr[i].first<<"("<<vArr[i].second<<")"<<" ";
    // }
    if (vArr[0].first % 2 == 0)
    {
        for (int i = maxNo - 1; i >= 0; i--)
        {
            cout << vArr[i].first;
        }
    }
    else
    {
        cout << "Not Even";
    }
    cout << endl;

    return 0;
}
