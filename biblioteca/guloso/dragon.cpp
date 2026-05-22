int h, n, m;
void va(){
    h = (int)(h/2) + 10;
    n--;
}
void ls(){
    h -= 10;
    m--;
}
int main(){_
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        cin >> h >> n >> m;
        // calcular teto: h + 10 - 1 / 10
        while (n > 0 && ceil(h/10.0) > m) va();
        while (m > 0 && h > 0) ls();
        if (h > 0) cout << "NO" << endl; 
        else cout << "YES" << endl;
    }
    return 0;
}