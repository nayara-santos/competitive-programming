// corda ligava dois predios
// em formato de zigue zague
// corda forma 45° com predio
// entrada: 
// dist entre predios e metros que corre
// saida: x, y em que ela para
int main(){
    int D, M; cin >> D >> M;
    ld sen = sqrt(2) / 2.0;
    ld l = (ld) D / sen;
    ld x = 0, y;
    ld m = (ld) M;
    int trechos = 0;
    while (m >= l){
        m -= l;
        x += D;
        trechos++;
    }
    if (!(trechos % 2)){
        y = m * sen;
        x += y;
    } else {
        y = (l - m) * sen;
        x += D - y;
    }
    cout << setprecision(10) << fixed;
    cout << x << " " << y << endl;
    return 0;
}   