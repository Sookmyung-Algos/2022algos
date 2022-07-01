#include<iostream>

#include<vector>

#include<cmath>

 

#define endl "\n"

using namespace std;

 

int N, M;

vector<int> Arr;

vector<int> Segment_Tree;

vector<pair<int, int>> Cmd;

 

int Min(int A, int B) { if (A < B) return A; return B; }

 

void Input()

{

    cin >> N >> M;

    for (int i = 0; i < N; i++)

    {

        int a; cin >> a;

        Arr.push_back(a);

    }

    for (int i = 0; i < M; i++)

    {

        int a, b; cin >> a >> b;

        Cmd.push_back(make_pair(a, b));

    }

}

 

int Make_SegmentTree(int Node, int Start, int End)

{

    if (Start == End)

    {

        Segment_Tree[Node] = Arr[Start];

        return Segment_Tree[Node];

    }

 

    int Mid = (Start + End) / 2;

    int Left_Result = Make_SegmentTree(Node * 2, Start, Mid);

    int Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);

    Segment_Tree[Node] = Min(Left_Result, Right_Result);

    

    return Segment_Tree[Node];

}

 

int Query(int Node, int Start, int End, int Left, int Right)

{

    if (Right < Start || Left > End) return 2e9;

    if (Left <= Start && End <= Right) return Segment_Tree[Node];

    

    int Mid = (Start + End) / 2;

    int Left_Result = Query(Node * 2, Start, Mid, Left, Right);

    int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);

    return Min(Left_Result, Right_Result);

}

 

void Solution()

{

    int Tree_Height = ceil(log2(N));

    int Tree_Size = (1 << (Tree_Height + 1));

    Segment_Tree.resize(Tree_Size);

 

    Make_SegmentTree(1, 0, N - 1);

    for (int i = 0; i < Cmd.size(); i++)

    {

        int Index = Cmd[i].first - 1;

        int Index2 = Cmd[i].second - 1;

        

        cout << Query(1, 0, N - 1, Index, Index2) << endl;

    }

}

 

void Solve()

{

    Input();

    Solution();

}

 

int main(void)

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

 

//    freopen("Input.txt", "r", stdin);

    Solve();

 

    return 0;

}
