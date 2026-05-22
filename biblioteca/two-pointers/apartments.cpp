#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

// a -> tamanho desejado do apt
// b -> tamanho do apt
// candidato aceita se apt tem tamanho entre x - k e x + k

// 45 60 60 80
// 30 60 75

// 80 60 60 45
// 75 60 30

int main(){_
    ll k;
    int n, m, resp = 0; cin >> n >> m >> k;
    vector <ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()){
        if (b[j] < a[i] - k){
            i++;
        }
        else if (b[j] > a[i] + k){
            j++;
        }
        else {
            i++;
            j++;
            resp++;
        }
    }

    cout << resp << endl;
    return 0;
}