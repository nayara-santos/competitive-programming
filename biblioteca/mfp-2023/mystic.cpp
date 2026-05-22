// f = (g*m1*m2)/d^2
// valor de g com erro < 10^-6
int main(){
    ld m1, m2, x1, x2, f;
    cin >> m1 >> m2;
    cin >> x1 >> x2;
    cin >> f;
    ld d = abs(x2 - x1);
    ld g = (f * d * d) / (m1 * m2);
    cout << setprecision(6) << fixed;
    cout << g << endl;
    return 0;
}