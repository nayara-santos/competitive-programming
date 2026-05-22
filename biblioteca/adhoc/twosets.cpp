// Dividir os numeros 1,2,..,n
// em dois sets de soma igual
int main(){_
    // 1 2 3 4 -> (1 4) | (2 3) -> 10
    // 1 2 3 4 5 6 7 8 -> (1 8) (2 7) | (3 6) (4 5) -> 32
    // 1 2 3 4 5 6 -> (1 6) (2 5) (3 4) -> 21
    // 1 2 3 4 5 6 7 -> (1 6) (2 5) | (3 4) 7 -> 28
    // 1 2 3 4 5 6 7 8 9 -> (1 9) (2 8)
    // 1 2 3 4 5 6 7 8 9 10 11 -> (1 10) (2 9) (3 8) | (4 7) (5 6) 11
    ll n; cin >> n;
    ll soma = ((1 + n)*n) / 2;
    if (n <= 2){
        cout << "NO" << endl;
        return 0;
    }
    if (soma % 2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (n % 2){
        cout << (n + 1) / 2 << endl;
        for (ll i = 1; i <= (n + 1) / 4; i++){
            cout << i << " " << n - i << " ";
        }
        cout << endl;
        cout << n / 2 << endl;
        for (ll i = (n + 1) / 4 + 1; i < (n + 1) / 2; i++){
            cout << i << " " << n - i << " ";
        }
        cout << n << endl;
    } else {
        cout << n / 2 << endl;
        for (ll i = 1; i <= n / 4; i++){
            cout << i << " " << n - i + 1 << " ";
        }
        cout << endl;
        cout << n / 2 << endl;
        for (ll i = n / 4 + 1; i <= n / 2; i++){
            cout << i << " " << n - i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}