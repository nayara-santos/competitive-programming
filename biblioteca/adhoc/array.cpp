// modificar o array tal que seja crescente, ou seja, cada elemento seja do valor anterior ou maior
// 3 2 5 1 7 -> 3 3 5 1 7 -> 3 3 5 2 7 -> 3 3 5 3 7 -> 3 3 5 4 7 -> 3 3 5 5 7
int main(){_
    int n; cin >> n;
    vector <ll> x(n);
    ll resp = 0;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 1; i < n; i++){
        if (x[i-1] > x[i]){
            resp += (x[i-1] - x[i]);
            x[i] = x[i-1];
        }
    }
    cout << resp << endl;
    return 0;
}