// h1 cruza com h2 e produz flor de altura
// (h1 + h2) / 2
// achar altura da maior planta filha
// em configuracao otima
int main(){_
    ll n; cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll i = n / 2;
    ll hf = -1;
    for (int j = 0; j < i; j++){
        hf = max(hf, (h[j] + h[n - j - 1]) / 2);
    }
    cout << hf << endl;
    return 0;
}