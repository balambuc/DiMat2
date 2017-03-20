#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool hh (vector<int> &v);
bool nemNov(int i, int j) {return i>j;}

int main()
{
    cout << "Fokszamsor: (bevitel vege nemszam karakter)" << endl;
    vector<int> v;
    int s;
    cin >> s;
    while (!cin.fail()){
        v.push_back(s);
        cin >> s;
    }
    sort(v.begin(), v.end(), nemNov);
    if(hh(v))
        cout << "Igen";
    else
        cout << "Nem";
    return 0;
}

bool hh (vector<int> &v)
{
    int n = v[0];

    if(n==0)
        return v[v.size()-1]==0;

    v.erase(v.begin());
    for(int i=0; i<n;++i)
        --v[i];
    sort(v.begin(), v.end(), nemNov);
    return (hh(v));
}

