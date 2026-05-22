// i-esimo amigo da bicileta para p_iesimo
// P eh uma permutacao
// percurso que bicicleta faz ate voltar para ele
// 2 3 1:
// 1 2 3; 2 3 1; 3 1 2
int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        int p[n];
        for (int j = 0; j < n; j++){
            cin >> p[j];
        }
        for (int j = 0; j < n; j++){
            cout << j + 1 << " ";           
            int l = j;
            for (int k = 0; k < n; k++){
                if (p[l] == j + 1) break;
                cout << p[l] << " ";
                l = p[l] - 1;
            }
            cout << endl;
        }
    }
    return 0;
}