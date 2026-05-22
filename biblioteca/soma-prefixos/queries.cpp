signed main(){_
    ll n, q, a, b, sum; cin >> n; cin >> q;
    vector<ll> x(n), soma(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    soma[0] = x[0];
    for (int i = 1; i < n; i++){
        soma[i] = soma[i-1] + x[i];
    }
    for (int i = 0; i < q; i++){
        cin >> a; cin >> b;
        a--;
        b--;
        if (!a) cout << soma[b] << endl;
        else cout << soma[b] - soma[a - 1] << endl;
    }
    return 0;
}