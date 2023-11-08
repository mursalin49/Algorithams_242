#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Nirob {
public:
    int s,r,w;

    Nirob(int s, int r, int w) {
        this->s = s;
        this->r = r;
        this->w = w;
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    vector<Nirob> v;

    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        Nirob ed(a, b, w);
        v.push_back(ed);
    }

    int dis[n + 1];

    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }

    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < v.size(); j++) {
            Nirob ed = v[j];
            int a = ed.s;
            int b = ed.r;
            int w = ed.w;
            if (dis[a] != INT_MAX && dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool cycle = false;

    for (int j = 0; j < v.size(); j++) {
        Nirob ed = v[j];
        int a = ed.s;
        int b = ed.r;
        int w = ed.w;
        if (dis[a] + w < dis[b]) {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        cout << "YES" << endl;

    }else
    {
         cout << "NO" << endl;
}

    return 0;
}
