// Problema: quantidade de subcadeias da string que podem ser rearranjadas como palindromo, considerando que as letras podem ir de a ate h
// m(subcadeia) = m(atual) XOR m(anterior)
// subcadeia ideal P (todas as letras sao pares ou existe apenas uma impar)
// P = m(atual) XOR m(anterior)
// m(anterior) = m(atual) XOR P -> se a subcadeia resultante da xor for um estado que ja existiu, a conta bate, entao a subcadeia formada com base no estado anterior e no atual eh palindromo
int main(){
    ll n; cin >> n;
    string s; cin >> s;
    map<uint8_t, ll> freq;
    uint8_t atual = 0, anterior;
    ll resp = 0;
    freq[0] = 1;
    for (ll i = 0; i < n; i++){
        ll pos = s[i] - 'a';
        atual = atual ^ (1 << pos);
        // qtd de vezes que atual ja apareceu
        resp += freq[atual]; 
        for (ll i = 0; i < 8; i++){
            // se atual ou anterior fosse ll, eu tenho que dar o shift com 1ll << i
            anterior = atual ^ (1 << i);
            resp += freq[anterior];
        }
        freq[atual]++;
    }
    cout << resp << endl;
    return 0;
}