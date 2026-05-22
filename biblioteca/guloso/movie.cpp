// dado o inicio e fim de cada filme, qual eh o maximo numero de filmes
bool ordenar(pair<int, int> a, pair<int, int> b){
    if (a.s != b.s) return a.s < b.s;
    else return a.f < b.f;
}
int main(){_
    int n, num; cin >> n;
    vector<pair<int, int>> movie(n);
    pair<int, int> at;
    for (int i = 0; i < n; i++) cin >> movie[i].f >> movie[i].s;
    sort(movie.begin(), movie.end(), ordenar);
    at.f = movie[0].f;
    at.s = movie[0].s;
    num = 1;
    for (int i = 1; i < n; i++){
        if (at.s <= movie[i].f){
            num++;
            at.f = movie[i].f;
            at.s = movie[i].s;
        }   
    }
    cout << num << endl;
    return 0;
}