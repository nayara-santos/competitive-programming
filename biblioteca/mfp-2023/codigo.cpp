// mensagem c/ 7 bits e 1 bit de seg
// bit de seg: 
// 0 se qtd de 1's eh par
// 1 se qtd de 1's eh impar
// se houver contradicao, mensagem foi corrompida
int main(){_
    int s, qtd = 0;
    for (int i = 0; i < 7; i++){
        int b; cin >> b;
        if (b) qtd++;
    }
    cin >> s;
    if (qtd % 2){
        if (s) cout << "N?" << endl;
        else cout << "S" << endl;
    } else {
        if (s) cout << "S" << endl;
        else cout << "N?" << endl;
    }
    return 0;
}