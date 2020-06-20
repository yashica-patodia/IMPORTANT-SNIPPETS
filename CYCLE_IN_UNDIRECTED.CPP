stack <int> s;
int visited[N];

void dfs(int cur) {
    if(visited[cur] = 1) {
        vector<int> cycle;
        while(s.top() == cur) {
            cycle.push_back(s.top());
            s.pop();
        }
        cycle.push_back(cur);
        return;
    }

    if(visited[cur] == 2)
        return;

    s.push(cur);
    visited[cur] = 1;

    for(int u : graph[cur]) {
        dfs(u);
    }

    s.pop();
    visited[cur] = 2;
}