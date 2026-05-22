// anotava Time (1|2) +pontos
// resultado do jogo entre 1 e 2
int main(){
    int n, t, p; cin >> n;
    map<int, int> placar;
    string s;
    char c;
    for (int i = 0; i < n; i++){
        cin >> s >> t >> c >> p;
        placar[t] += p;
    }
    
    if (!placar.count(1)) placar[1] = 0;
    if (!placar.count(2)) placar[2] = 0;
    cout << placar[1] << " x " << placar[2] << endl;
    return 0;
}