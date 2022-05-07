#include <iostream>
#include <list>  // 연결리스트 사용
#include <string>

using namespace std;

int main()
{
    int m;  // 입력할 명령어의 개수를 나타내는 정수 M
    string str = "";
    string ans = "";  // 최종 문자열

    cin >> str;
    // 연결리스트에 원소 할당
    list<char> lst(str.begin(), str.end());

    // 커서 위치를 입력된 문자 제일 끝에 위치
    auto cursor = lst.end();
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        char cmd, c;
        cin >> cmd;  // 명령어 입력

        if (cmd == 'L')  // 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
        {
            if (cursor != lst.begin())
                cursor--;
        }
        else if (cmd == 'D')  // 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
        {
            if (cursor != lst.end())
                cursor++;
        }
        else if (cmd == 'B')  // 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
        {
            if (cursor != lst.begin())  // 커서가 문장의 맨 앞(왼쪽)이 아니라면
            {
                cursor--;
                cursor = lst.erase(cursor);  // 삭제
            }
        }
        else if (cmd == 'P')  // c라는 문자를 커서 왼쪽에 추가함
        {
            cin >> c;  // c 입력
            lst.insert(cursor, c);  // 문자 c 삽입
        }
    }

    // 연결리스트 출력
    for (cursor = lst.begin(); cursor != lst.end(); cursor++)
        cout << *cursor;
}
