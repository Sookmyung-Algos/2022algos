#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
 
#define endl "\n"
#define MAX 100010
typedef long long ll;
using namespace std;
 
struct QUESTION
{
    int x;
    int y;
    int a;
    int b;
};
 
int N, Q;
ll Array[MAX];
vector<ll> SegmentTree;
vector<QUESTION> Cmd;
 
void Input()
{
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> Array[i];
    for (int i = 0; i < Q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--; y--; a--; 
        Cmd.push_back({ x, y, a, b });
    }
}
 
ll Make_SegmentTree(int Node, int Start, int End)
{
    if (Start == End) return SegmentTree[Node] = (ll)(Array[Start]);
    
    int Mid = (Start + End) / 2;
    ll Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
    ll Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
    
    return SegmentTree[Node] = Left_Result + Right_Result;
}
 
ll Section_Sum(int Node, int Start, int End, int Left, int Right)
{
    if (Right < Start || Left > End) return 0;
    if (Left <= Start && End <= Right) return SegmentTree[Node];
 
    int Mid = (Start + End) / 2;
    ll Left_Result = Section_Sum(Node * 2, Start, Mid, Left, Right);
    ll Right_Result = Section_Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
    return Left_Result + Right_Result;
}
 
void Update_Tree(int Node, int Start, int End, int Idx, ll Diff)
{
    if (Idx < Start || Idx > End) return;
    SegmentTree[Node] = SegmentTree[Node] + Diff;
    
    if (Start != End)
    {
        int Mid = (Start + End) / 2;
        Update_Tree(Node * 2, Start, Mid, Idx, Diff);
        Update_Tree(Node * 2 + 1, Mid + 1, End, Idx, Diff);
    }
}
 
void Solution()
{
    int Tree_Height = (int)ceil(log2(N));
    int Tree_Size = (1 << (Tree_Height + 1));
    SegmentTree.resize(Tree_Size);
    Make_SegmentTree(1, 0, N - 1);
 
    for (int i = 0; i < Cmd.size(); i++)
    {
        int x = Cmd[i].x;
        int y = Cmd[i].y;
        int a = Cmd[i].a;
        int b = Cmd[i].b;
        
        if (x > y) swap(x, y);
        cout << Section_Sum(1, 0, N - 1, x, y) << endl;
 
        ll Diff = b - Array[a];
        Array[a] = b;
        Update_Tree(1, 0, N - 1, a, Diff);
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
