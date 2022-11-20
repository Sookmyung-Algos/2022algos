#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[1025][1025];  // N이 1024만큼 주어지므로(N*N 행렬)
int n;  // 확인해야 하는 영역의 크기 n


int scdLarger(int x, int y) // 시작 위치 : x, y
{
    vector<int> v;
    // 2*2씩 나누어 찾기 때문에 인덱스를 2씩 늘려 기준을 잡는다.
    for (int i = x; i < x + 2; i++) 
        for (int j = y; j < y + 2; j++)
            v.push_back(p[i][j]);
    sort(v.begin(), v.end()); // v 처음부터 끝까지 오름차순 정렬
    return v[2]; // 2번째로 큰 수 반환
}
 
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j]; // N*N 배열 생성
        }
    }
    
    while (n > 1)
    {
        for (int i = 0; i < n; i+=2)
            for (int j = 0; j < n; j+=2){
                // 가로 세로 2칸씩 움직이며 p 갱신
                /// 그러면서 2번째로 큰 수를 찾는다.
                p[i/2][j/2] = scdLarger(i,j);
            }
        n /= 2;
    }
    cout << p[0][0] << '\n';
}
