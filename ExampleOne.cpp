# include "LFioninaLib.h"
# include "TXLib.h"
# include <stdlib.h>

int main()
    {
    txCreateWindow (1200, 700);
    SubTitlesDraw ( 50, 20, 40, "Arial", TX_WHITE, "������ 1: ��������� ���� � ������� �����������");

    TreeOneDraw   (100, 100, 1, 0, 30, 30, 2,  50, 20);
    SubTitlesDraw ( 50, 200, 20, "Arial", TX_WHITE, "����: ������ 1, �������� ����� 0, ������ 30, ������ 30");

    TreeOneDraw   (100, 300, 1, 20, 70, 50, 2,  50, 20);
    SubTitlesDraw ( 50, 500, 20, "Arial", TX_WHITE, "����: ������ 1, �������� ����� +20, ������ 70, ������ 50");

    TreeOneDraw   (600, 100, 0.5, -10, 60, 30, 2,  50, 120);
    SubTitlesDraw (550, 200, 20, "Arial", TX_WHITE, "����: ������ 0.5, �������� ����� -10, ������ 60, ������ 30");

    TreeOneDraw   (600, 300, 0.8, 0, 60, 40, 2,  170, 180);
    SubTitlesDraw (550, 500, 20, "Arial", TX_WHITE, "����: ������ 0.8, �������� ����� 0, ������ 60, ������ 40");
    return 0;
    }
