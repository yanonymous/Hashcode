#include<iostream>
#include<conio.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;

vector <ll> b;

bool sortt(ll l, ll r){
    ll x=b[l];
    ll y=b[r];
    if(x>y)
        return 1;
    else
        return 0;
}

set<ll> allBooks;

int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("f.txt","r",stdin);
    freopen("outputs\\f_output.txt","w",stdout);

    ll books,libs,days;
    cin>>books>>libs>>days;

    for (int i = 0; i < books; i++)
    {
        ll score;
        cin>>score;
        b.push_back(score);
    }

    vector<vector<ll>>libooks;
    vector<pair<ll,pair<ll,ll>>> all;

    int nolibs=0;

    for (int i = 0; i < libs; i++)
    {
        ll noBooks,noSignUps,noShips;
        cin>>noBooks>>noSignUps>>noShips;

        all.push_back({noSignUps,{noShips,i}});

        libooks.push_back(vector<ll>());

        for (int k = 0; k < noBooks; k++)
        {
            ll bo;
            cin>>bo;

            if(allBooks.count(bo)!=0)
            libooks[i].push_back(bo);

            allBooks.insert(bo);
        }

        if(libooks[i].size())
            nolibs++;

        sort(libooks[i].begin(),libooks[i].end(),sortt);
    }

    sort(all.begin(),all.end());

    cout<<nolibs<<endl;

    for (auto i:all)
    {
        if (libooks[i.second.second].size()!=0)
        {
            cout<<i.second.second<<" "<<libooks[i.second.second].size()<<endl;
            for (auto j:libooks[i.second.second]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}