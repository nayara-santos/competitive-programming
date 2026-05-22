// pessoa vai e volta por um corredor com n lampadas
// na i-esima passada ele mexe apenas em interruptores divisiveis por i
// na volta nenhum eh mexido
// estado da ultima lampada -> ligada se o num de divisores for impar (quadrado perfeito)
bool quad_perf(ll n){
    ll i, f, m;
    i = 0;
    f = n;
    while (i < f){
        m = (i + f) / 2;
        if (n > m*m){
            i = m + 1;
        }
        else {
            f = m;
        }
    }
    if (i * i == n) return true;
    else return false;
}
int main(){_
    ll n; cin >> n;
    while (n != 0){
        if (quad_perf(n)) cout << "yes" << endl;
        else cout << "no" << endl;
        cin >> n;
    }
    return 0;
}