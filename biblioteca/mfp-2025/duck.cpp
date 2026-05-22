// c_i+1 adjacente a i
// c_1 adjacente a N
// crianca p vai passando
// depois de passar k vezes grita goose p/ crianca
// posicao da crianca que escuta
int main(){
    int n, p, k; cin >> n >> p >> k;
    int pulos = k % (n-1);
    int i = 0, pos = p + 1, ant = p - 1;
    if (p == n) pos = 1;
    while (i != pulos){
        if (pos == n) pos = 1;
        else pos++;
        i++;
    }
    cout << pos << endl;
    return 0;
}