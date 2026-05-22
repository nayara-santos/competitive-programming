// 1 a n competidores
// cada comp leva a_i segundos
// para entregar 1 pizza
// tempo min para completar
// ent -> quant de pizzas que podem ser entregues
bool val(ll chute, ll p){
    ll ent = 0;
    for (ll i = 0; i < comp.size(); i++){
        ent += chute / comp[i];
        if (ent >= p) return true;
    }
    return ent >= p;
}
int main(){
    ll n, p, a; cin >> n >> p;
    for (ll i = 0; i < n; i++){
        cin >> a;
        comp.push_back(a);
    }
    // max eh p*a_i (1e9*1e9)
    ll i = 0, f = 1e18 + 10, m;
    while (i < f){
        m = (ll)((i + f) / 2);
        if (val(m, p)){
            f = m;
        }
        else {
            i = m + 1;
        }
    }
    cout << i << endl;
    return 0;
}