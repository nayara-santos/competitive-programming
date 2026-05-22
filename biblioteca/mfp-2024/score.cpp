// entrada: soma dos pontos
// saida: num de esportes que ganharam
int main(){
    int n; cin >> n;
    int resp = 0;
    queue<int> p;
    // pontos de cada medalha
    p.push(8); p.push(4); p.push(2);
    if (n % 2){
        resp++;
        n--;
    }
    int v = n;
    while (v){
        if (v < p.front()){
            p.pop();
        } else {
            v -= p.front();
            resp++;
        }
    }
    cout << resp << endl;
    return 0;
}