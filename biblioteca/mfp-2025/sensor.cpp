// valor do sensor diferente em relacao aos outros dois
int main(){
    ll t, k1, k2, k3, diff; cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> k1; cin >> k2; cin >> k3;
        if (k1 == k2) diff = k3;
        else if (k1 == k3) diff = k2;
        else diff = k1;
        cout << diff << "\n";
    }
    return 0;
}