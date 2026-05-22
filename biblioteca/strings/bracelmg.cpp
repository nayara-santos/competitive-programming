// achar se existe seq proibida em um bracelete circular
int main(){_
    int t; cin >> t;
    int passos, i, j, k, c, cr, ptam, btam;
    string proib, brac; 
    bool achou, achourev;
    for (int l = 0; l < t; l++){
        cin >> proib; cin >> brac;
        ptam = proib.size();
        btam = brac.size();
        passos = 0; i = -1; j = 0; k = ptam - 1; c = 0; cr = 0;
        achou = false; achourev = false;
        while (passos < btam - 1 + ptam && c < ptam && cr < ptam){
            if (passos >= btam) i = passos - brac.size();
            else i++;
            achou = brac[i] == proib[j];
            achourev = brac[i] == proib[k];
            if (achou || achourev){
                if (achou){
                    j++; 
                    c++;
                } 
                if (achourev){
                    if (i + 1 >= btam || k == 0) cr++;
                    else if (brac[i + 1] == proib[k - 1]){
                        k--;
                        cr++;
                    } else {
                        k = ptam - 1;
                        cr = 0;
                    }
                }
            } else {
                j = 0;
                k = ptam - 1;
                c = 0;
                cr = 0;
            }
            passos++;
        }
        if (c == ptam || cr == ptam) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}