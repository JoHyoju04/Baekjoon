/*
< 1700 : ��Ƽ�� �����ٸ� >
-������ ��

i) �ش� ��Ⱑ �÷��׿� �����ִ°�
ii) �÷��׿� �� ���� �ִ°�
iii) �÷��׿� �� ���� ���� ���

 - i) �� ii) ���� ��� �ܼ�Ʈ�� �� �ʿ䰡 �����Ƿ� continue �ؼ� ���� ��⸦ Ȯ��

- iii) ��� �ܼ�Ʈ�� �����մϴ�.
  a) �ܼ�Ʈ�� �����ϴµ� � �ܼ�Ʈ�� �����ϴ����� Ž���� ����
  b) �׸����ϰ� �����ϸ� ���Ŀ� �� �ѹ��� ���� ���� ��⸦ ���ų� ���� �������� ���� ��⸦ ���� ���� ����
  c) b���� ã�� ��⸦ �÷��׿��� ���� ��� �����̾��� ��⸦ ����

*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100 + 1;
int N, K;
int schedule[MAX], plug[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
        cin >> schedule[i];

    int result = 0;

    for (int i = 0; i < K; i++)
    {
        bool pluggedIn = false;
        //�ش� ��Ⱑ �����ִ��� Ȯ��
        for (int j = 0; j < N; j++)
            if (plug[j] == schedule[i])
            {
                pluggedIn = true;
                break;
            }
        if (pluggedIn)
            continue;

        //����ִ� ���� Ȯ��

        for (int j = 0; j < N; j++)
            if (!plug[j])
            {
                plug[j] = schedule[i];
                pluggedIn = true;
                break;
            }
        if (pluggedIn)
            continue;
        //���� ���߿� �ٽ� ���ǰų� ������ ������ �ʴ� ��� ã��

        int idx, deviceIdx = -1;

        for (int j = 0; j < N; j++)

        {
            int lastIdx = 0;
            for (int k = i + 1; k < K; k++)
            {
                if (plug[j] == schedule[k])
                    break;
                lastIdx++;
            }
            if (lastIdx > deviceIdx)
            {
                idx = j;
                deviceIdx = lastIdx;
            }
        }
        result++;
        //�ռ� ã�� ��Ⱑ �����ִ� ���� ���� ���� �����̿��� ��⸦ ����
        plug[idx] = schedule[i];
    }
    cout << result << "\n";
    return 0;
}