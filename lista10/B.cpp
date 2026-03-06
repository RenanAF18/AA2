#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int NN = 2e6 + 1, K = 2, P = uniform_int_distribution<int>(256, 1e9)(rng);
const ll MOD[] = {1000893493, 1013782387};
ll ph[NN][K], hh[NN][K], IT;
void pre() { rep(i, 0, NN) rep(j, 0, K) ph[i][j] = i ? ph[i - 1][j] * P % MOD[j] : 1; }

struct hsh {
    int L;
    hsh() {}
    hsh(const string &s) {
        L = IT, IT += sz(s);
        rep(i, 0, sz(s)) rep(j, 0, K) {
            hh[L + i][j] = ((i > 0 ? hh[L + i - 1][j] * P : 0) + s[i]) % MOD[j];
        }
    }
    array<ll, K> operator()(int l, int r) {
        array<ll, K> ans;
        rep(j, 0, K) {
            ans[j] = hh[L + r][j] - (l > 0 ? hh[L + l - 1][j] * ph[r - l + 1][j] % MOD[j] : 0);
            if (ans[j] < 0) ans[j] += MOD[j];
        }
        return ans;
    }
};

int main(){
    pre();

    string s; cin >> s;
    string rev(s.rbegin(), s.rend());

    hsh hs(s);
    hsh hr(rev);

    int n = s.size();
    int melhorTam = 1, melhorPos = 0;

    auto buscaBinaria = [&](int inicio) {
        int menorTam = inicio, maiorTam = n;
        if(maiorTam % 2 != inicio % 2) maiorTam--;
        while(menorTam <= maiorTam){
            int tamAtual = (menorTam + maiorTam) / 2;
                if(tamAtual % 2 != inicio % 2) tamAtual--;

            bool achou = false;

            for(int i = 0; i <= n - tamAtual; i++){
                int posNaReversa = n - i - tamAtual;
                if(hs(i, i + tamAtual - 1) == hr(posNaReversa, posNaReversa + tamAtual - 1)){
                    achou = true;
                    if(tamAtual > melhorTam){ melhorTam = tamAtual; melhorPos = i; }
                    break;
                }
            }

            if(achou) menorTam = tamAtual + 2;
            else maiorTam = tamAtual - 2;
        }
    };

    buscaBinaria(1); // tamanhos ímpares
    buscaBinaria(2); // tamanhos pares

    cout << s.substr(melhorPos, melhorTam) << endl;
}