// permutacao de inteiros 1,2,...,n tal que 
// nao tenham elementos adjacentes cuja diferenca eh 1
int main(){_
    ll n; cin >> n;
    if (n == 1){
        cout << 1 << endl;
    } else if (n <= 3){
        cout << "NO SOLUTION" << endl;
    } else if (n % 2){
        ll f1 = n / 2, i2 = f1 + 1, f2 = n-1;
        for (ll i = 0; i < f1; i++){
            cout << i + 1 << " ";
            cout << i2 + 1 << " ";
            i2++;
        }
        cout << f1 + 1 << endl;
    } else {
        ll j = n / 2;
        for (ll i = 0; i < n / 2; i++){
            cout << j + 1 << " ";
            cout << i + 1 << " ";
            j++;
        }
        cout << endl;
    }
    return 0;
}