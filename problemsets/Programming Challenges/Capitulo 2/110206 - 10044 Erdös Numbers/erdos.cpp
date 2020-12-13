/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Erdos Number */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#define INFINITY 1000000000

using namespace std;

vector< vector <string> > data;

map<string, int> erdos;


void read_data(int p) {
    
    int i, j;
    string line;
    string word;
    vector <string> v;
    bool got;
    
    for (i = 0; i < p; i++) {
        getline(cin, line);
        
        v.clear();
        j = 0;
        while (line[j] != ':') {
            word.erase();
            got = false;
            while (line[j] == ' ')
                j++;
            while ((got == false) || (line[j] != ',')) {
                if ((line[j] == ':') || (line[j] == '\0'))
                    break;
                if (line[j] == ',')
                    got = true;
                word += line[j];
                j++;
            }
            if (line[j] == '\0')
                break;
            if (line[j] == ',')
                j++;
            
            if (got == true) {
                v.push_back(word);
                if (erdos.find(word) == erdos.end())
                    erdos[word] = INFINITY;
            }
        }
        data.push_back(v);
    }
} 

int find_min(int line) {
    
    vector<string>::iterator s;
    map<string, int>::iterator i;
    int min = INFINITY;
    
    for (s = data[line].begin(); s != data[line].end(); s++) {
        i = erdos.find(*s);
        if (i->second < min)
            min = i->second;
    }
    
    return(min);
}


int main() {

    int scenarios, s;
    int p, n;
    int i, j;
    bool changed;
    int min;
    string name;
    map<string, int>::iterator mit;
    
    cin >> scenarios;
    for (s = 1; s <= scenarios; s++) {
        
        data.clear();
        erdos.clear();
        erdos["Erdos, P."] = 0;
        
        cin >> p >> n;
        getchar();
        
        read_data(p);
        
        changed = true;
        min = 0;
        while (changed == true) {
            changed = false;
            for (i = 0; i < data.size(); i++)
                if (min == find_min(i))
                    for (j = 0; j < data[i].size(); j++) {
                        mit = erdos.find(data[i][j]);
                        if (mit->second > min+1) {
                            mit->second = min+1;
                            changed = true;
                        }
                    }
            min++;
        }
        
        cout << "Scenario " << s << endl;
        for (i = 0; i < n; i++) {
            getline(cin, name);
            cout << name << ' ';
            mit = erdos.find(name);
            if (mit == erdos.end())
                cout << "infinity" << endl;
            else if (mit -> second == INFINITY)
                cout << "infinity" << endl;
            else
                cout << mit->second << endl;
        }
    }
    
    return 0;
}
