#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <set>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

const int INF = 10000010;

vector<vector<pair<int, int>>> g;
vector<bool> used;
vector<int> tin, tou, color;
set<pair<int, int>> input;
set<int> points;
stack <int> s;
int _time = 0, cnt = 0, a, b, to;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = tou[v] = _time++;
    for (size_t i = 0; i < g[v].size(); ++i) {
        to = g[v][i].first;
        if (to == p) continue;
        if (used[to]) {
            tou[v] = min(tou[v], tin[to]);
            if (tin[to] < tin[v])
                s.push(g[v][i].second);
        } else {
            s.push(g[v][i].second);
            dfs(to, v);
            tou[v] = min(tou[v], tou[to]);
            if (tou[to] >= tin[v]) {
                cnt++;
                while (s.top() != g[v][i].second) {
                    color[s.top()] = cnt;
                    s.pop();
                }
                color[g[v][i].second] = cnt;
                s.pop();
            }
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    //int sh = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        //if (input.count(make_pair(a, b))) continue;
        //input.insert(make_pair(a, b));
        //input.insert(make_pair(b, a));
        g[a - 1].push_back(make_pair(b - 1, i));
        g[b - 1].push_back(make_pair(a - 1, i));
        //sh++;
    }
    used.resize(n, false);
    tin.resize(n, INF);
    tou.resize(n, INF);
    color.resize(m, 0);
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            dfs(i);
        }
    cout << cnt << '\n';
    for (int i = 0; i < m; ++i) cout << color[i] << ' ';
    return 0;
}