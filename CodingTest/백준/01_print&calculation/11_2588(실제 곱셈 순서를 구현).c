#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    //�����ڸ����� ����
    //�������� Ȱ�� 123�� ���
    // 123%10 ������ 3
    // 12%10 ������ 2
    // 1%10 ������ 1

    printf("%d\n", a * (b % 10));
    printf("%d\n", a * ((b / 10) % 10));
    printf("%d\n", a * ((b / 100) % 10));
    printf("%d\n", a * b);
    return 0;
}