// uma outra forma de achar diametro
void dfs(int V, int pV){
    vector<int> fValues;
    for(auto v: g[V]){
        if(v == pV) continue;
        dfs(v, V);
        fValues.push_back(f[v]);
    }
    sort(fValues.begin(),fValues.end());
    f[V] = 0;
    if(not fValues.empty()) f[V] = 1 + fValues.back();
    if(fValues.size() >= 2)
        h[V] = 2 + fValues.back() + fValues[fValues.size()-2];
    diameter = max(diameter, max(f[V], h[V]));
}

int main(){_
    int n, a, b; cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    cout << diameter << endl;

}