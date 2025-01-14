
//{============================================================================
//!@mainpage
//!
//!@brief ���������� ������ ����������� "����"</p>
//!
//!
//!
//!��� ���������� ���� ������� � �������� �������� ����� �++
//!
//!
//!
//!@par �������
//!     - @ref DrawHowse()
//!     - @ref DrawSun()
//!     - @ref DrawCloud()
//!     - @ref DrawGirl()
//!     - @ref DrawBoy()
//!     - @ref DrawCat()
//!     - @ref DrawFlower()
//!     - @ref DrawGrib()
//!     - @ref DrawTree()
//!     - @ref DrawKust()
//!     - @ref DrawRain()
//!
//!
//!@author  ������� ������� �����������, �� �. �������� </p>
//!
//!@date 2021
//}============================================================================

#include "TXLib.h"

void DrawHowse          (int x, int y, double sizex, double sizey, COLORREF stenaColor,COLORREF kryshaColor,
                         COLORREF oknoColor, double krysha, double okno, double truba, double dym, double door);

void DrawSun            (int x, int y, double sizex, double sizey, COLORREF sunColor, int rays,int eyes,
                         int smile, int eyebrows, int rumyna);

void DrawCloud          (int x, int y, double sizex, double sizey, COLORREF cloudColor);

void DrawGirl           (int x, int y, double sizex, double sizey, COLORREF headColor, COLORREF hearColor, COLORREF torsoColor,
                         double rhand, double lhand, double legs, double crazy, double smile, double eyes, double platie, double topleftleg,
                         double toprightleg, double nos, double hear);

void DrawBoy            (int x, int y, double sizex, double sizey, COLORREF headColor, COLORREF hearColor, COLORREF torsoColor, double rhand,
                         double lhand, double legs, double crazy, double smile, int eyes, double topleftleg, double toprightleg, double nos,
                         double hear, double brovy);

void DrawCat            (int x, int y, double sizex, double sizey, COLORREF catColor,COLORREF eyesColor,
                         double legs, double hvost, double ushky, double usy, double smile, double eyes);

void DrawFlower         (int x, int y, double sizex, double sizey, COLORREF lepestkiColor,COLORREF serdcevinaColor,
                         int list, int naklon);

void DrawGrib           (int x, int y, double sizex, double sizey, COLORREF shlypkaColor,COLORREF nogkaColor);
void DrawTree           (int x, int y, double sizex, double sizey, COLORREF treeColor, int wind);
void DrawKust           (int x, int y, double sizex, double sizey);
void DrawRain           (int x, int y, double sizex, double sizey, COLORREF cloudColor, int luzha, int rain);

//{============================================================================
//!
//! ������ ���
//!
//!
//!
//!@param x                 x-���������� �������� ������ ���� ����� ����
//!@param y                 y-���������� �������� ������ ���� ����� ����
//!@param sizex             ������ ���� �� ��� �
//!@param sizey             ������ ���� �� ��� Y
//!@param stenaColor        ���� ���� ����
//!@param kryshaColor       ���� ����� ����
//!@param oknoColor         ���� ���� ����
//!@param krysha            ��������� ������ ����� �� ��� �
//!@param okno              ��������� ������ ���� �� ��� �
//!@param truba             ��������� ������ ����� �� ��� Y
//!@param dym               ��������� ������� ����
//!@param door              ��������� � ��������� �����
//!
//!@par ������ �������������
//!
//!@code
//!         DrawHowse (600, 400, 1, 1, RGB(255, 255, 224), RGB(139, 0, 0), RGB(0, 0, 0), 0, 0, 0, 0, 0);
//!@endcode
//!
//}============================================================================

void DrawHowse(int x, int y, double sizex, double sizey, COLORREF stenaColor, COLORREF kryshaColor, COLORREF oknoColor,
                double krysha, double okno, double truba, double dym, double door)
{
    txSetColor     (TX_BLACK);
    txSetFillColor (stenaColor);
    txRectangle    (x + ( 50 - 50)*sizex, y + (350 - 350)*sizey, x + (250 - 50)*sizex, y + (550 - 350)*sizey);
    txRectangle    (x + (250 - 50)*sizex, y + (350 - 350)*sizey, x + (400 - 50)*sizex, y + (550 - 350)*sizey);

    txSetColor     (oknoColor);
    txSetFillColor (oknoColor);
    txRectangle    (x + (100 - 50)*sizex + okno, y + (400 - 350)*sizey, x + (200 - 50)*sizex + okno, y + (500 - 350)*sizey);


    txSetColor     (stenaColor, 3);
    txSetFillColor (stenaColor);
    txLine         (x +(150 - 50)*sizex + okno, y + (400 - 350)*sizey, x + (150 - 50)*sizex + okno, y + (500 - 350)*sizey);
    txLine         (x +(100 - 50)*sizex + okno, y + (450 - 350)*sizey, x + (200 - 50)*sizex + okno, y + (450 - 350)*sizey);

    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle    (x + (80 - 50)*sizex, y + (220 - 350)*sizey - truba, x + (120 - 50)*sizex, y + (350 - 350)*sizey);

    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);

    if (dym > 0)
    {
        for (int t = 1; t <= 3; t++)
        {
            txEllipse (x + (90 - 50)*sizex - t*30, y + (200 - 350)*sizey - t*30 - dym, x + (110 - 50)*sizex + t*30, y + (210 - 350)*sizey - t*30 - dym);
        }
    }

    txSetColor     (TX_BLACK);
    txSetFillColor (kryshaColor);
    POINT triangleHouse[3]= {{ROUND(x + ( 50 - 50)*sizex), ROUND(y + (350 - 350)*sizey)},
                             {ROUND(x + (150 - 50)*sizex), ROUND(y + (250 - 350)*sizey - krysha)},
                             {ROUND(x + (250 - 50)*sizex), ROUND(y + (350 - 350)*sizey)}};
    txPolygon (triangleHouse, 3);

    POINT skatHouse[4]= {{ROUND(x + (150 - 50)*sizex), ROUND(y + (250 - 350)*sizey - krysha)},
                         {ROUND(x + (250 - 50)*sizex), ROUND(y + (350 - 350)*sizey)},
                         {ROUND(x + (400 - 50)*sizex), ROUND(y + (350 - 350)*sizey)},
                         {ROUND(x + (300 - 50)*sizex), ROUND(y + (250 - 350)*sizey)}};
    txPolygon (skatHouse, 4);

    txSetColor     (TX_BLACK);
    txSetFillColor (kryshaColor);
    if (door > 0 )
    {
        txRectangle    (x + (360 - 50)*sizex, y + (400 - 350)*sizey, x + (430 - 50)*sizex, y + (550 - 350)*sizey);
        txSetFillColor (TX_BLACK);
        txRectangle    (x + (290 - 50)*sizex, y + (400 - 350)*sizey, x + (360 - 50)*sizex, y + (550 - 350)*sizey);

    }
    else txRectangle   (x + (290 - 50)*sizex, y + (400 - 350)*sizey, x + (360 - 50)*sizex, y + (550 - 350)*sizey);
}

//{============================================================================
//!
//! ������ ������
//!
//!@param x                 x-���������� ������ ������ ���������� ������ (������ ������� �� ���� �����������)
//!@param y                 y-���������� ������ ������ ���������� ������ (������ ������� �� ���� �����������)
//!@param sizex             ������ ������ �� ��� �
//!@param sizey             ������ ������ �� ��� Y
//!@param cloudColor        ���� ������
//!
//!
//!@par ������ �������������
//!
//!@code
//!         DrawCloud ( 50, 150, 1, 1, TX_LIGHTCYAN);
//!@endcode
//!
//}============================================================================


void DrawCloud (int x, int y, double sizex, double sizey, COLORREF cloudColor)
{
    txSetColor     (cloudColor);
    txSetFillColor (cloudColor);

    txCircle (x + (150 - 150)*sizex, y + (100 - 100)*sizey, 40*sizex);
    txCircle (x + (190 - 150)*sizex, y + (100 - 100)*sizey, 40*sizex);
    txCircle (x + (230 - 150)*sizex, y + (100 - 100)*sizey, 40*sizex);
}

//{============================================================================
//!
//! ������ �����
//!
//!@param x                 x-���������� ������ ������ ���������� ������ (������ ������� �� ���� �����������)
//!@param y                 y-���������� ������ ������ ���������� ������ (������ ������� �� ���� �����������)
//!@param sizex             ������ ������ �� ��� �
//!@param sizey             ������ ������ �� ��� Y
//!@param cloudColor        ���� ������
//!@param luzha             ������ ����
//!@param rain              ������ �����
//!
//!
//!@par ������ �������������
//!
//!@code
//!         DrawRain (350, 100, 2, 2, TX_BLUE, 1, 5);
//!@endcode
//!
//}============================================================================

void DrawRain (int x, int y, double sizex, double sizey, COLORREF cloudColor, int luzha, int rain)
{
    txSetColor     (cloudColor,3);
    txSetFillColor (cloudColor);

    txCircle (x + (150 - 150)*sizex, y + (100 - 100)*sizey, 40*sizex);
    txCircle (x + (190 - 150)*sizex, y + (100 - 100)*sizey, 40*sizex);
    txCircle (x + (230 - 150)*sizex, y + (100 - 100)*sizey, 40*sizex);

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            if ((i + j)%2) txLine (x + 30*i, y + 100*j + rain, x + 30*i,y + 130*j + rain);
        }
    }
    if (luzha > 0)
    {
        txEllipse (380, 450, 400 + luzha ,480 );
        txEllipse (280, 550, 300 + luzha ,580 );
        txEllipse (580, 500, 600 + luzha ,530 );
    }
}

//{============================================================================
//!
//! ������ ������
//!
//!@param x                 x-���������� ������ ������
//!@param y                 y-���������� ������ ������
//!@param sizex             ������ ������ �� ��� �
//!@param sizey             ������ ������ �� ��� Y
//!@param sunColor          ���� ������
//!@param rays              ��������� ����� ������� ������
//!@param eyes              �������� ���� ������
//!@param smile             ������ ������
//!@param eyebrows          ��������� ��������� ������ �� ��� �
//!@param rumyna            ��������� ��� ������
//!
//!
//!@par ������ �������������
//!
//!@code
//!         DrawSun   (850, 105, 1, 1, TX_YELLOW, 1, 1, 0, 1, 0);
//!@endcode
//!
//}============================================================================

void DrawSun (int x, int y, double sizex, double sizey, COLORREF sunColor, int rays, int eyes, int smile, int eyebrows, int rumyna)
{
    txSetColor     (sunColor, 3);
    txSetFillColor (sunColor);

    txCircle (x + (850 - 850)*sizex, y + (100 - 100)*sizey, 40*sizex);

    txLine (x + (780 - 850)*sizex + rays, y + (100 - 100)*sizey,        x + (920 - 850)*sizex - rays, y + (100 - 100)*sizey);
    txLine (x + (850 - 850)*sizex,        y + ( 30 - 100)*sizey + rays, x + (850 - 850)*sizex,        y + (170 - 100)*sizey - rays);
    txLine (x + (780 - 850)*sizex - rays, y + ( 30 - 100)*sizey - rays, x + (920 - 850)*sizex + rays, y + (170 - 100)*sizey + rays);
    txLine (x + (920 - 850)*sizex - rays, y + ( 30 - 100)*sizey - rays, x + (780 - 850)*sizex + rays, y + (170 - 100)*sizey + rays);

    txSetColor     (TX_BLACK, 1);
    txSetFillColor (TX_WHITE);
    txEllipse      (x + (820 - 850)*sizex, y + (80 - 100)*sizey*eyes, x + (840 - 850)*sizex, y + (100 - 100)*sizey);
    txEllipse      (x + (860 - 850)*sizex, y + (80 - 100)*sizey*eyes, x + (880 - 850)*sizex, y + (100 - 100)*sizey);

    txSetFillColor (RGB(0, 0, 255));
    txEllipse      (x + (825 - 850)*sizex, y + (85 - 100)*sizey*eyes, x + (835 - 850)*sizex, y + ( 95 - 100)*sizey);
    txEllipse      (x + (865 - 850)*sizex, y + (85 - 100)*sizey*eyes, x + (875 - 850)*sizex, y + ( 95 - 100)*sizey);

    txLine (x + (845 - 850)*sizex, y + ( 105 - 100)*sizey, x + (855 - 850)*sizex, y + (105 - 100)*sizey);

    txLine (x + (823 - 850)*sizex, y + (  85 - 100 - 10*eyebrows)*sizey, x + (837 - 850)*sizex, y + ( 85 - 100 - 10*eyebrows)*sizey);
    txLine (x + (863 - 850)*sizex, y + (  85 - 100 - 10*eyebrows)*sizey, x + (877 - 850)*sizex, y + ( 85 - 100 - 10*eyebrows)*sizey);

    txSetColor     (RGB(255, 0, 0), 1);
    txSetFillColor (RGB(255, 0, 0));
    POINT smileSun[3]= {{ROUND(x + (833 - 850)*sizex), ROUND(y + (120 - 100)*sizey)},
                        {ROUND(x + (867 - 850)*sizex), ROUND(y + (120 - 100)*sizey)},
                        {ROUND(x + (850 - 850)*sizex), ROUND(y + (130 - 100 - 10*smile)*sizey)}};
    txPolygon (smileSun, 3);

    txSetColor     (RGB(238, 130, 238), 1);
    txSetFillColor (RGB(238, 130, 238));
    txEllipse      (x + (820 - 850)*sizex, y + (105 - 100 + 10*rumyna)*sizey, x + (830 - 850)*sizex, y + (115 - 100)*sizey);
    txEllipse      (x + (870 - 850)*sizex, y + (105 - 100 + 10*rumyna)*sizey, x + (880 - 850)*sizex, y + (115 - 100)*sizey);
}

//{============================================================================
//!
//! ������ �������
//!
//!@param x                 x-���������� ������� �������� �������
//!@param y                 y-���������� ������� �������� �������
//!@param sizex             ������ ������� �� ��� �
//!@param sizey             ������ ������� �� ��� Y
//!@param headColor         ���� ������ �������
//!@param hearColor         ���� ����� �������
//!@param torsoColor        ���� ������ �������
//!@param rhand             �������� ������ ���� �����/����
//!@param lhand             �������� ����� ���� �����/����
//!@param legs              ���������� ����� ��� �� ��� �
//!@param crazy             ��������� ������� ���� �� ��� Y
//!@param smile             ��������� ������ �������
//!@param eyes              �������� ����
//!@param platie            �������� ������ �� ��� �
//!@param topleftleg        ������� ������ ����� �����
//!@param toprightleg       ������� ������ ������ �����
//!@param nos               �������� ���� �� ��� �
//!@param hear              �������� ����� �� ��� �
//!
//!@par ������ �������������
//!
//!@code
//!         DrawGirl  (300, 500, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30), RGB(255, 0, 255), 0, 0, 0, 0, 5, 1, 1, 0, 0, 0, 0);
//!@endcode
//!
//}============================================================================

void DrawGirl (int x, int y, double sizex, double sizey, COLORREF headColor, COLORREF hearColor, COLORREF torsoColor,
                double rhand, double lhand, double legs, double crazy, double smile, double eyes, double platie, double topleftleg,
                double toprightleg, double nos, double hear)
{
    txSetColor     (headColor, 3);
    txSetFillColor (headColor);
    txCircle       (x + (700 - 700)*sizex, y + (450 - 480)*sizey, 30*sizex);

    txSetColor     (hearColor, 3);
    txSetFillColor (hearColor);
    txEllipse      (x + (680 - 700)*sizex - hear, y + (420 - 480)*sizey, x + (720 - 700)*sizex - hear, y + (430 - 480)*sizey);
    txEllipse      (x + (650 - 700)*sizex - hear, y + (410 - 480)*sizey, x + (680 - 700)*sizex - hear, y + (440 - 480)*sizey);
    txEllipse      (x + (640 - 700)*sizex - hear, y + (430 - 480)*sizey, x + (670 - 700)*sizex - hear, y + (460 - 480)*sizey);
    txEllipse      (x + (720 - 700)*sizex - hear, y + (410 - 480)*sizey, x + (750 - 700)*sizex - hear, y + (440 - 480)*sizey);
    txEllipse      (x + (730 - 700)*sizex - hear, y + (430 - 480)*sizey, x + (760 - 700)*sizex - hear, y + (460 - 480)*sizey);

    txSetColor     (torsoColor, 3);
    txSetFillColor (torsoColor);
    POINT triangleGirl[3]={{ROUND(x + (700 - 700)*sizex),          ROUND(y + (480 - 480)*sizey)},
                           {ROUND(x + (670 - 700)*sizex - platie), ROUND(y + (540 - 480)*sizey)},
                           {ROUND(x + (730 - 700)*sizex - platie), ROUND(y + (540 - 480)*sizey)}};
    txPolygon      (triangleGirl, 3);

    txLine (x + (690 - 700)*sizex, y + (540 - 480)*sizey,               x + (690 - 700)*sizex + legs, y + (570 - 480)*sizey        );
    txLine (x + (670 - 700)*sizex, y + (570 - 480)*sizey - topleftleg,  x + (690 - 700)*sizex + legs, y + (570 - 480)*sizey        );
    txLine (x + (730 - 700)*sizex, y + (570 - 480)*sizey - toprightleg, x + (710 - 700)*sizex - legs, y + (570 - 480)*sizey        );
    txLine (x + (710 - 700)*sizex, y + (540 - 480)*sizey,               x + (710 - 700)*sizex - legs, y + (570 - 480)*sizey        );
    txLine (x + (700 - 700)*sizex, y + (480 - 480)*sizey,               x + (660 - 700)*sizex,        y + (500 - 480)*sizey + rhand);
    txLine (x + (700 - 700)*sizex, y + (480 - 480)*sizey,               x + (740 - 700)*sizex,        y + (500 - 480)*sizey + lhand);

    txSetColor     (TX_LIGHTCYAN , 3);
    txSetFillColor (TX_LIGHTCYAN);
    txEllipse      (x + (680 - 700)*sizex, y + (445 - 480)*sizey*eyes + crazy, x + (690 - 700)*sizex, y + (455 - 480)*sizey*eyes + crazy);
    txEllipse      (x + (710 - 700)*sizex, y + (445 - 480)*sizey*eyes - crazy, x + (720 - 700)*sizex, y + (455 - 480)*sizey*eyes - crazy);

    txSetColor     (TX_BLUE, 3);
    txSetFillColor (TX_BLUE);
    txEllipse      (x + (683 - 700)*sizex, y + (448 - 480)*sizey*eyes + crazy, x + (687 - 700)*sizex, y + (452 - 480)*sizey*eyes + crazy);
    txEllipse      (x + (713 - 700)*sizex, y + (448 - 480)*sizey*eyes - crazy, x + (717 - 700)*sizex, y + (452 - 480)*sizey*eyes - crazy);

    txLine         (x + (699 - 700)*sizex - nos, y + (455 - 480)*sizey, x + (701 - 700)*sizex - nos, y + (455 - 480)*sizey);

    txSetColor     (TX_RED, 3);
    txSetFillColor (TX_RED);
    txLine         (x + (690 - 700)*sizex, y + (465 - 480)*sizey, x + (700 - 700)*sizex, y + (465 - 480)*sizey + smile);
    txLine         (x + (710 - 700)*sizex, y + (465 - 480)*sizey, x + (700 - 700)*sizex, y + (465 - 480)*sizey + smile);
}

//{============================================================================
//!
//! ������ ��������
//!
//!@param x                 x-���������� ������� �������� ��������
//!@param y                 y-���������� ������� �������� ��������
//!@param sizex             ������ �������� �� ��� �
//!@param sizey             ������ �������� �� ��� Y
//!@param headColor         ���� ������ ��������
//!@param hearColor         ���� ����� ��������
//!@param torsoColor        ���� �������� ��������
//!@param rhand             �������� ������ ���� �����/����
//!@param lhand             �������� ����� ���� �����/����
//!@param legs              ���������� ����� ��� �� ��� �
//!@param crazy             ��������� ������� ���� �� ��� Y
//!@param smile             ��������� ������ ��������
//!@param eyes              �������� ����
//!@param topleftleg        ������� ������ ����� �����
//!@param toprightleg       ������� ������ ������ �����
//!@param nos               �������� ���� �� ��� �
//!@param hear              �������� ����� �� ��� �
//!@param brovy             �������� ������ �� ��� �
//!
//!@par ������ �������������
//!
//!@code
//!         DrawBoy   (500, 500, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30), RGB(  0, 0, 255), 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 1);
//!@endcode
//!
//}============================================================================

void DrawBoy (int x, int y, double sizex, double sizey, COLORREF headColor, COLORREF hearColor, COLORREF torsoColor, double rhand,
              double lhand, double legs, double crazy, double smile, int eyes, double topleftleg, double toprightleg, double nos, double hear, double brovy)
{
    txSetColor      (headColor, 3);
    txSetFillColor  (headColor);
    txCircle        (x + (470 - 500)*sizex, y + (450 - 480)*sizey, 8*sizex);
    txCircle        (x + (530 - 500)*sizex, y + (450 - 480)*sizey, 8*sizex);
    txCircle        (x + (500 - 500)*sizex, y + (450 - 480)*sizey, 30*sizex);

    txSetColor      (hearColor,3);
    txSetFillColor  (hearColor);
    txEllipse       (x + (480 - 500)*sizex - hear, y + (420 - 480)*sizey, x + (520 - 500)*sizex - hear, y + (430 - 480)*sizey);

    txLine (x + (480 - 500)*sizex, y + (440 - 480)*sizey - brovy, x + (485 - 500)*sizex, y + (440 - 480)*sizey - brovy);
    txLine (x + (510 - 500)*sizex, y + (440 - 480)*sizey - brovy, x + (515 - 500)*sizex, y + (440 - 480)*sizey - brovy);

    txSetColor      (torsoColor,3);
    txSetFillColor  (torsoColor);
    txRectangle     (x + (470 - 500)*sizex, y + (480 - 480)*sizey,               x + (530 - 500)*sizex,        y + (540 - 480)*sizey        );
    txLine          (x + (490 - 500)*sizex, y + (540 - 480)*sizey,               x + (490 - 500)*sizex + legs, y + (570 - 480)*sizey        );
    txLine          (x + (470 - 500)*sizex, y + (570 - 480)*sizey - topleftleg,  x + (490 - 500)*sizex + legs, y + (570 - 480)*sizey        );
    txLine          (x + (530 - 500)*sizex, y + (570 - 480)*sizey - toprightleg, x + (510 - 500)*sizex - legs, y + (570 - 480)*sizey        );
    txLine          (x + (510 - 500)*sizex, y + (540 - 480)*sizey,               x + (510 - 500)*sizex - legs, y + (570 - 480)*sizey        );
    txLine          (x + (470 - 500)*sizex, y + (480 - 480)*sizey,               x + (430 - 500)*sizex,        y + (500 - 480)*sizey + rhand);
    txLine          (x + (530 - 500)*sizex, y + (480 - 480)*sizey,               x + (570 - 500)*sizex,        y + (500 - 480)*sizey + lhand);

    txSetColor      (TX_LIGHTCYAN , 3);
    txSetFillColor  (TX_LIGHTCYAN );
    txEllipse       (x + (480 - 500)*sizex, y + (445 - 480)*sizey*eyes + crazy, x + (490 - 500)*sizex, y + (455 - 480)*sizey*eyes + crazy);
    txEllipse       (x + (510 - 500)*sizex, y + (445 - 480)*sizey*eyes - crazy, x + (520 - 500)*sizex, y + (455 - 480)*sizey*eyes - crazy);

    txSetColor      (TX_BLUE, 3);
    txSetFillColor  (TX_BLUE);
    txEllipse       (x + (483 - 500)*sizex, y + (448 - 480)*sizey*eyes + crazy, x + (487 - 500)*sizex, y + (452 - 480)*sizey*eyes + crazy);
    txEllipse       (x + (513 - 500)*sizex, y + (448 - 480)*sizey*eyes - crazy, x + (517 - 500)*sizex, y + (452 - 480)*sizey*eyes - crazy);

    txLine         (x + (499 - 500)*sizex - nos, y + (455 - 480)*sizey, x + (501 - 500)*sizex - nos, y + (455 - 480)*sizey);

    txSetColor     (TX_RED, 3);
    txSetFillColor (TX_RED);
    txLine         (x + (490 - 500)*sizex, y + (465 - 480)*sizey + smile, x + (500 - 500)*sizex, y + (465 - 480)*sizey);
    txLine         (x + (510 - 500)*sizex, y + (465 - 480)*sizey - smile, x + (500 - 500)*sizex, y + (465 - 480)*sizey);

}

//{============================================================================
//!
//! ������ ������
//!
//!@param x                 x-���������� ������� ������
//!@param y                 y-���������� ������� ������
//!@param sizex             ������ ������ �� ��� �
//!@param sizey             ������ ������ �� ��� Y
//!@param lepestkiColor     ���� ��������� ������
//!@param serdcevinaColor   ���� ���������� ������
//!@param list              �������� ������� ������
//!@param naklon            �������� ������ �� ��� �
//!
//!@par ������ �������������
//!
//!@code
//!         DrawFlower (200,  550, 1, 1, RGB(255, 0, 0), RGB(255, 255, 255), 1, 1);
//!@endcode
//!
//}============================================================================

void DrawFlower (int x, int y, double sizex, double sizey, COLORREF lepestkiColor,COLORREF serdcevinaColor, int list, int naklon)
{
    txSetColor     (lepestkiColor);
    txSetFillColor (lepestkiColor);
    txCircle       (x + (890 - 900)*sizex + naklon, y + (500 - 520)*sizey, 10*sizex);
    txCircle       (x + (910 - 900)*sizex + naklon, y + (500 - 520)*sizey, 10*sizex);
    txCircle       (x + (900 - 900)*sizex + naklon, y + (510 - 520)*sizey, 10*sizex);
    txCircle       (x + (900 - 900)*sizex + naklon, y + (490 - 520)*sizey, 10*sizex);

    txSetColor     (serdcevinaColor);
    txSetFillColor (serdcevinaColor);
    txCircle       (x + (900 - 900)*sizex + naklon, y + (500 - 520)*sizey, 10*sizex);

    txSetColor     (TX_GREEN, 3);
    txSetFillColor (TX_GREEN);
    txLine         (x + (900 - 900)*sizex + naklon, y + (520 - 520)*sizey, x + (900 - 900)*sizex, y + (570 - 520)*sizey);
    POINT triangleList[3]=  {{ROUND(x + (900 - 900)*sizex), ROUND(y + (570 - 520)*sizey)},
                             {ROUND(x + (880 - 900)*sizex), ROUND(y + (540 - 520)*sizey + list)},
                             {ROUND(x + (900 - 900)*sizex), ROUND(y + (550 - 520)*sizey)}};
    txPolygon      (triangleList, 3);
    POINT triangleListok[3]={{ROUND(x + (900 - 900)*sizex), ROUND(y + (570 - 520)*sizey)},
                             {ROUND(x + (920 - 900)*sizex), ROUND(y + (540 - 520)*sizey - list)},
                             {ROUND(x + (900 - 900)*sizex), ROUND(y + (550 - 520)*sizey)}};
    txPolygon      (triangleListok, 3);
}

//{============================================================================
//!
//! ������ ����
//!
//!@param x                 x-���������� ������� �����
//!@param y                 y-���������� ������� �����
//!@param sizex             ������ ����� �� ��� �
//!@param sizey             ������ ����� �� ��� Y
//!@param shlypkaColor      ���� ������ �����
//!@param nogkaColor        ���� ���� �����
//!
//!@par ������ �������������
//!
//!@code
//!         DrawGrib ( 30, 500, 1, 1, TX_ORANGE, TX_YELLOW);
//!@endcode
//!
//}============================================================================

void DrawGrib (int x, int y, double sizex, double sizey, COLORREF shlypkaColor, COLORREF nogkaColor)
{
    txSetColor      (shlypkaColor);
    txSetFillColor  (shlypkaColor);
    txPie           (x - 10*sizex, y - 50*sizey, x + 50*sizex, y, 0, 180);
    txSetColor      (nogkaColor);
    txSetFillColor  (nogkaColor);
    txPie           (x + 10*sizex, y - 50*sizey, x + 30*sizex, y, 180, 180);
}

//{============================================================================
//!
//! ������ ������ (����)
//!
//!@param x                 x-���������� ������� ������
//!@param y                 y-���������� ������� ������
//!@param sizex             ������ ������ �� ��� �
//!@param sizey             ������ ������ �� ��� Y
//!@param treeColor         ���� ������
//!@param wind              ������ ������ �����/������
//!
//!@par ������ �������������
//!
//!@code
//!         DrawTree (280, 300, 1, 1, RGB(50, 205, 50), 0);
//!@endcode
//!
//}============================================================================

void DrawTree (int x, int y, double sizex, double sizey, COLORREF treeColor, int wind)
{
    txSetColor              (treeColor, 3);
    txSetFillColor          (treeColor);
    POINT triangleTre[3]=  {{ROUND(x - wind),            ROUND(y - 50*sizey + wind)},
                            {ROUND(x - 50*sizex - wind), ROUND(y + wind)},
                            {ROUND(x + 50*sizex),        ROUND(y - wind)}};
    txPolygon               (triangleTre, 3);
    POINT triangleTree[3]= {{ROUND(x - 75*sizex - wind), ROUND(y + 75*sizey + wind)},
                            {ROUND(x - wind),            ROUND(y + wind)},
                            {ROUND(x +  75*sizex),       ROUND(y + 75*sizey - wind)}};
    txPolygon               (triangleTree, 3);
    POINT triangleTreee[3]={{ROUND(x - 100*sizex), ROUND(y + 150*sizey)},
                            {x                   , ROUND(y + 75*sizey)},
                            {ROUND(x + 100*sizex), ROUND(y + 150*sizey)}};
    txPolygon               (triangleTreee, 3);
}

//{============================================================================
//!
//! ������ ����
//!
//!@param x                 x-���������� ������ �����
//!@param y                 y-���������� ������ �����
//!@param sizex             ������ ����� �� ��� �
//!@param sizey             ������ ����� �� ��� Y

//!
//!@par ������ �������������
//!
//!@code
//!         DrawKust (120, 400, 1, 1);
//!@endcode
//!
//}============================================================================
 void DrawKust(int x, int y, double sizex, double sizey)
{
    txSetColor     (RGB(0, 128, 0), 3);
    txSetFillColor (RGB(0, 128, 0));
    txCircle  (x + (350 - 350)*sizex, y + (350 - 350)*sizey, 50*sizex);
    txSetFillColor (RGB(0, 255, 0));
    txCircle  (x + (320 - 350)*sizex, y + (320 - 350)*sizey, 50*sizex);
    txSetFillColor (RGB(0, 128, 0));
    txCircle  (x + (290 - 350)*sizex, y + (350 - 350)*sizey, 50*sizex);
    txSetFillColor (RGB(0, 255, 0));
    txCircle  (x + (330 - 350)*sizex, y + (360 - 350)*sizey, 40*sizex);
}

//{============================================================================
//!
//! ������ ����
//!
//!@param x                 x-���������� ������� �������� ����
//!@param y                 y-���������� ������� �������� ����
//!@param sizex             ������ ���� �� ��� �
//!@param sizey             ������ ���� �� ��� Y
//!@param catColor          ���� ����
//!@param eyesColor         ���� ���� ����
//!@param legs              �������� ��� ���� �� ��� �
//!@param hvost             �������� ������ ���� �����/������
//!@param ushky             �������� ���� ���� �����/����
//!@param usy               �������� ���� ���� �����/����
//!@param smile             ������ ���� ����/���
//!@param eyes              �������� ����
//!
//!@par ������ �������������
//!
//!@code
//!         DrawCat   (100, 500, 3, 3, RGB(255, 69, 0), RGB(0, 0, 255), 1, 1, 1, 1, 1, 0);
//!@endcode
//!
//}============================================================================
void DrawCat (int x, int y, double sizex, double sizey, COLORREF catColor,COLORREF eyesColor,
              double legs, double hvost, double ushky, double usy, double smile, double eyes)
{
    txSetColor     (RGB(0, 0, 0), 1);
    txSetFillColor (catColor);

    POINT hvostCat[3]= {{ROUND(x + (10 - 40)*sizex), ROUND(y + (40 - 30)*sizey)},
                        {ROUND(x + (16 - 40)*sizex), ROUND(y + (40 - 30)*sizey)},
                        {ROUND(x + (13 - 40)*sizex + hvost), ROUND(y + (10 - 30)*sizey)}};
    txPolygon (hvostCat, 3);

    txEllipse (x + (10 - 40)*sizex, y + (30 - 30)*sizey, x + (40 - 40)*sizex, y + (50 - 30)*sizey);

    POINT legCat[3]= {{ROUND(x + (15 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                      {ROUND(x + (21 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                      {ROUND(x + (18 - 40)*sizex + legs), ROUND(y + (60 - 30)*sizey)}};
    txPolygon (legCat, 3);
 /*
    POINT legsCatl[3]= {{ROUND(x + (30 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                        {ROUND(x + (36 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                        {ROUND(x + (33 - 40)*sizex - legs), ROUND(y + (60 - 30)*sizey)}};
                       {x + (33 - 40)*sizex + legs, y + (60 - 30)*sizey}};
    txPolygon (legsCat, 3);
*/
    POINT legCatl[3]= {{ROUND(x + (15 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                       {ROUND(x + (21 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                       {ROUND(x + (18 - 40)*sizex - legs), ROUND(y + (60 - 30)*sizey)}};
    txPolygon (legCatl, 3);

    POINT legsCatl[3]= {{ROUND(x + (30 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                        {ROUND(x + (36 - 40)*sizex), ROUND(y + (45 - 30)*sizey)},
                        {ROUND(x + (33 - 40)*sizex - legs), ROUND(y + (60 - 30)*sizey)}};
    txPolygon (legsCatl, 3);

    txCircle  (x + (40 - 40)*sizex, y + (30 - 30)*sizey, 10*sizex);

    POINT ushkiCat[3]={{ROUND(x + (30 - 40)*sizex), ROUND(y + (27 - 30)*sizey)},
                       {ROUND(x + (30 - 40)*sizex), ROUND(y + (15 - 30)*sizey + ushky)},
                       {ROUND(x + (35 - 40)*sizex), ROUND(y + (21 - 30)*sizey)}};
    txPolygon (ushkiCat, 3);

    POINT ushkyCat[3]={{ROUND(x + (45 - 40)*sizex), ROUND(y + (21 - 30)*sizey)},
                       {ROUND(x + (50 - 40)*sizex), ROUND(y + (15 - 30)*sizey + ushky)},
                       {ROUND(x + (50 - 40)*sizex), ROUND(y + (27 - 30)*sizey)}};
    txPolygon (ushkyCat, 3);

    txSetColor     (eyesColor, 3);
    txSetFillColor (eyesColor);
    txEllipse (x + (33 - 40 + 4*eyes)*sizex, y + (26 - 30 + 4*eyes)*sizey, x + (37 - 40)*sizex, y + (30 - 30)*sizey);
    txEllipse (x + (43 - 40 + 4*eyes)*sizex, y + (26 - 30 + 4*eyes)*sizey, x + (47 - 40)*sizex, y + (30 - 30)*sizey);

    txSetColor     (RGB(0, 0, 0), 3);
    txSetFillColor (RGB(0, 0, 0));
    txCircle  (x + (40 - 40)*sizex, y + (32 - 30)*sizey, 2*sizex);
    txLine (x + (45 - 40)*sizex, y + (33 - 30)*sizey, x + (52 - 40)*sizex, y + (29 - 30)*sizey + usy);
    txLine (x + (45 - 40)*sizex, y + (35 - 30)*sizey, x + (52 - 40)*sizex, y + (35 - 30)*sizey + usy);
    txLine (x + (35 - 40)*sizex, y + (33 - 30)*sizey, x + (27 - 40)*sizex, y + (29 - 30)*sizey + usy);
    txLine (x + (35 - 40)*sizex, y + (35 - 30)*sizey, x + (27 - 40)*sizex, y + (35 - 30)*sizey + usy);

    txSetColor     (RGB(255, 0, 0), 3);
    txSetFillColor (RGB(255, 0, 0));
    txPie (x + (35 - 40)*sizex, y + (33 - 30)*sizey, x + (45 - 40)*sizex, y + (38 - 30)*sizey, 225 - smile, 90 + smile);

}
