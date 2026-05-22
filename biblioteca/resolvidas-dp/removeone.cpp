// array a com n inteiros
// remover no max um elemento do array
// calcular o tam max do subarray continuo
// estritamente crescente do array que sobrou
int main(){_ 
    int n; cin >> n;
    ll dp_l[n], dp_r[n], num[n];
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    dp_l[0] = 1; dp_r[n-1] = 1;
    for (int i = 1; i < n; i++){
        if (num[i-1] < num[i]) dp_l[i] = 1 + dp_l[i-1];
        else dp_l[i] = 1;
    }
    for (int i = n - 2; i >= 0; i--){
        if (num[i] < num[i+1]) dp_r[i] = 1 + dp_r[i+1];
        else dp_r[i] = 1;
    }
    // 1 2 5 3 4
    // 1 2 3 1 2 -> dp_l
    // 3 2 1 2 1 -> dp_r
    // i = 3
    ll resp = 1;
    if (n == 2) resp = dp_l[n-1];
    for (int i = 2; i < n; i++){
        if (num[i] > num[i-2]){
            resp = max({resp, dp_l[i-1], dp_l[i-2] + dp_r[i]});
        } else {
            resp = max(resp, dp_l[i-1]);
        }
    }
    cout << max(resp, dp_l[n-1]) << endl;
    return 0;
}