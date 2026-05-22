// seq de n flores 0 ou 1
// cada conv visita de l_i a r_i
// satisfacao eh qtd de 0*qtd de 1
// dispor as flores para max soma da satisfacao
int main(){_
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int l, r; cin >> l >> r; 
        l--; r--;
    }
    // eh so intercalar as flores
    int resp = 1;
    for (int i = 0; i < n; i++){
        cout << resp;
        resp = 1 - resp;
    }
    cout << endl;
    return 0;
}