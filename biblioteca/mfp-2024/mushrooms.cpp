// cogumelos nas quinas
// calcular area do quadrado
int main(){
    int x, y;
    vector<pair<int, int>> coords;
    int larg = 0, alt = 0;
    cin >> x >> y;
    coords.push_back({x, y});
    for (int i = 0; i < 3; i++){
        cin >> x >> y;
        for (auto p: coords){
            if (x == p.f) larg = max(y, p.s) - min(y, p.s);
            else if (y == p.s) alt = max(x, p.f) - min(x, p.f);
            else coords.push_back({x, y});
        }
    }
    cout << larg * alt << endl;
    return 0;
}