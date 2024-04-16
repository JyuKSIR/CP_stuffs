#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int val;
    int d = -1;
    node *p = NULL;
    bool visited = false;
    bool visited2 = false;
    node(int a)
    {
        val = a;
    }
};
vector<vector<node *>> list;
void addEdge(int a, int b)
{
    list[a].push_back(list[b][0]);
    list[b].push_back(list[a][0]);
}

void reboot(int n)
{
    for (int i = 0; i <= n; i++)
    {
        list[i][0]->p = NULL;
        list[i][0]->visited = false;
    }
}

vector<node *> getList(int a)
{
    return list[a];
}

bool isCycle1(int t, int n)
{

    vector<node *> ll = getList(t);
    for (auto v : ll)
    {
        if (!v->visited)
        {
            v->visited = true;
            v->p = list[t][0];
            bool check = isCycle1(v->val, n);
            if (check)
                return true;
        }
        if (v->val == n)
        {

            if (list[t][0]->p != NULL && list[t][0]->p->val != n)
            {
                return true;
            }
        }
    }
    return false;
}
node *nearestCycle(int s, int n)
{
    queue<node *> q;
    q.push(list[s][0]);
    list[s][0]->visited2 = true;
    list[s][0]->d = 0;
    if (isCycle1(list[s][0]->val, list[s][0]->val))
        return list[s][0];
    reboot(n);
    while (q.size() != 0)
    {
        auto u = q.front();
        q.pop();
        auto ll = getList(u->val);
        for (auto v : ll)
        {
            if (!v->visited2)
            {
                v->visited2 = true;
                q.push(v);
                v->d = u->d + 1;
                if (isCycle1(v->val, v->val))
                    return v;
                reboot(n);
            }
        }
    }
    return NULL;
}

int distanceOf(int s, int e)
{
    queue<node *> q;
    list[s][0]->d = 0;
    list[s][0]->visited = true;
    if (s == e)
        return 0;
    q.push(list[s][0]);
    while (q.size() != 0)
    {
        auto u = q.front();
        q.pop();
        auto ll = getList(u->val);
        for (auto v : ll)
        {
            if (!v->visited)
            {
                v->visited = true;
                v->d = u->d + 1;
                if (v->val == e)
                    return v->d;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        list.clear();
        int n, m, v;
        cin >> n >> m >> v;
        for (int i = 0; i <= n; i++)
        {
            vector<node *> tempo;
            tempo.push_back(new node(i));
            list.push_back(tempo);
        }

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            addEdge(a, b);
        }

        int dmv = distanceOf(m, v);
        reboot(n);
        // cout << "Distance of m and v->" << dmv << endl;
        if (dmv == -1)
            cout << "YES" << endl;
        else if (dmv == 0)
            cout << "NO" << endl;
        else
        {
            node *p = nearestCycle(v, n);
            int dnc = p->d;
            int esc = p->val;
            // cout << "distance for nearest cycle->" << dnc << " and point "<<esc<<endl;
            if (p == NULL)
                cout << "NO" << endl;
            else
            {
                reboot(n);
                // cout << "(v,p->val)->" << v << ", " << p->val << endl;
                int d2 = distanceOf(m, esc);
                // cout << "Distannce to escape point for marcel->" << d2 << endl;
                if (d2 > dnc)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
}