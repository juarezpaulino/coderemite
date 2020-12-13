/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#define sz(a) (int)((a).size())

const int MAX = 22;
const int MOD = 1E9;

int sub(int x, int y) {
    x-=y; if (x < 0) x+=MOD;
    return x;
}

int add(int x, int y) {
    x+=y; if (x >= MOD) x-=MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}


struct mat {
  typedef decay<decltype(MOD)>::type T;
    vector<vector<T>> a;
  int m, n;
    mat(int _m = MAX, int _n = MAX) : m(_m), n(_n) {
    if (m<MAX && n==MAX) n=m;
    a = vector<vector<T>>(m,vector<T>(n));
    }
    vector<T> &operator[](int x) { return a[x]; }
    mat operator*(mat &b) {
    assert(n==b.m);
        mat ret(m,b.n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < b.n; j++)
                for (int k = 0; k < n; k++)
//                    ret[i][j]+=(1LL * u[i][k] * b[k][j]);
                    ret[i][j] = add(ret[i][j],mul(a[i][k],b[k][j]));
        return ret;
    }
    mat &operator*=(mat &b) { return *this = *this*b; }
  vector<T> operator*(vector<T> b) {
    assert(n==sz(b));
    vector<T> ret(m);
    for (int i=0;i<m;i++)
      for (int k=0;k<sz(b);k++)
        ret[i]=add(ret[i],mul(a[i][k],b[k]));
    return ret;
  }
    static mat unit(int m) {
        mat ret(m,m);
        for (int i = 0; i < m; i++) ret[i][i] = 1;
        return ret;
    }
    mat operator^(int p) {
        mat ret = mat::unit(m), b=*this;
        for (; p; p/=2, b*=b) if (p&1) ret*=b;
        return ret;
    }
    mat &operator^=(int p) { return *this = *this^p; }
    mat operator~() {
        mat ret(n,m);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ret[j][i] = a[i][j];
        return ret;
    }
};

// Complete the solve function below.
vector<int> solve(int a, int b, int c, int d, int e, int f, int g, int h, long n) {
    int mx = 9;

    vector<int> ret(22,1);
    ret[2*mx] = ret[2*mx+2] = 0;
    ret[2*mx+1] = ret[2*mx+3] = 1;

    mat A(22);
    A[0][a-1]++;
    A[0][mx+b-1]++;
    A[0][mx+c-1]++;
    A[0][2*mx]++;
    A[mx][mx+e-1]++;
    A[mx][f-1]++;
    A[mx][g-1]++;
    A[mx][2*mx+2]++;
    for (int i = 1; i < mx; i++) A[i][i-1] = A[mx+i][mx+i-1] = 1;
    A[2*mx][2*mx] = A[2*mx][2*mx+1] = A[2*mx+1][2*mx+1] = d;
    A[2*mx+2][2*mx+2] = A[2*mx+2][2*mx+3] = A[2*mx+3][2*mx+3] = h;
    
    A = A^(n+1);
    ret = A*ret;
    return {ret[0],ret[mx]};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abcdefghn_temp;
        getline(cin, abcdefghn_temp);

        vector<string> abcdefghn = split_string(abcdefghn_temp);

        int a = stoi(abcdefghn[0]);

        int b = stoi(abcdefghn[1]);

        int c = stoi(abcdefghn[2]);

        int d = stoi(abcdefghn[3]);

        int e = stoi(abcdefghn[4]);

        int f = stoi(abcdefghn[5]);

        int g = stoi(abcdefghn[6]);

        int h = stoi(abcdefghn[7]);

        long n = stol(abcdefghn[8]);

        vector<int> result = solve(a, b, c, d, e, f, g, h, n);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
