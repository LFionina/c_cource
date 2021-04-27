//{=============================================================================
//             (�) ������� ������� ����������, �. ������, 2021
//                 �������: ���������� "������� �������"
//}=============================================================================

# include "TXLib.h"
# include <stdlib.h>

void TitleScreen ();
void TitleFrameDraw (int x);
void TitleTextDraw (int t);

void BeginScreen ();
void ForestDraw (int t);
void GladeDraw (int t);
void SubtitlesDraw (int x, int y, const char text[]);
void SubTitlesDraw (int x, int y,
                    int sizeFont, const char nameFont[],
                    COLORREF colorFont,
                    const char text[]);
void BackGroundBeginScreen ();

void CenterScreen ();
void BearMove ();
void BearNoseEvesMove ();
void BackGroundCenterScreen ();

void FinishScreen ();
void HoneySteal (int x, int y);
void BeeComeOutHome ();
void BackGroundFinishScreen ();

void ScreamScreen ();

void BeeFly ();

void ForeGroundDraw ();

void BearDraw (int x, int y, double size,
               COLORREF colorEye, double dBetweenEyes, double radiusEyes,
               int noseY,
               int dBetweenEars,
               int dChestMove,
               int lHandX, int lHandY,
               int rHandX, int rHandY,
               int lFoodX, int lFoodY,
               int rFoodX, int rFoodY);

void TreeOneDraw (int x,  int y, double size,
                  double inclineX,
                  int widthTree, int heigthTree,
                  int pxLine,
                  int colorLine, int colorTree);

void HomeDraw    (double x, double y, int heightRoof,
                  int widthWindow, int heightWindow,
                  double size);

void FlowerDraw  (int x, int y, double size,
                  COLORREF colorPetal, COLORREF colorCenter);

void BushDraw (int x, int y, double size);
void BeeDraw  (int x, int y, double size);
void BarrelDraw (double x, double y, double size);
void BeeHomeDraw (int x, int y, double size);
void BeeHomeFinishDraw (int x, int y, double size);

void FinalScreen ();
void HomeBackground (int heightY);
void BearHeadDraw (int x, int y, double size);
void BeeHeadDraw (int x, int y, int size);
void TableDraw ();
void TeeDrink ();
void CupTee (int x, int y, int orientation);
void BearPawRight (int y);
void BeePawLeft (int y);

void ClearScreen();

//----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1200, 700);

    TitleScreen ();
    BeginScreen ();
    CenterScreen ();
    FinishScreen ();
    ScreamScreen ();
    FinalScreen ();

    return 0;
    }

//============================================================================
void TitleScreen ()
    {
    ClearScreen();

    TitleFrameDraw (50);

    int t = 0;
    while (t != 350)
        {
        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear ();

        TitleFrameDraw (50);
        TitleTextDraw (t);

        txSleep (100);
        t += 50;
        }

    txSleep (200);
    SubTitlesDraw (350, 350, 30, "Bookman Old Style", TX_YELLOW, "����������� ����������� ���������� �����");
    txSleep (500);

    SubTitlesDraw (360, 450, 30, "Bookman Old Style", TX_WHITE, "�����: ������� ������� (������, 2021)");
    txSleep (1000);
    }

//----------------------------------------------------------------------------
void TitleFrameDraw (int x)
    {
    txSetColor (TX_YELLOW, 3);
    txLine (       x,         x*2,        x+150,       x*2);
    txLine (1200 - x,         x*2, 1200 - x-150,       x*2);
    txLine (       x,   700 - x*2,        x+150, 700 - x*2);
    txLine (1200 - x,   700 - x*2, 1200 - x-150, 700 - x*2);

    txLine (       x*2,       x,          x*2,         x+150);
    txLine (1200 - x*2,       x,   1200 - x*2,         x+150);
    txLine (       x*2, 700 - x,          x*2,   700 - x-150);
    txLine (1200 - x*2, 700 - x,   1200 - x*2,   700 - x-150);

    txSetColor (TX_LIGHTCYAN);
    txSetFillColor (TX_LIGHTCYAN);
    txCircle (       (x + x/2),       (x + x/2), 15);
    txCircle (1200 - (x + x/2),       (x + x/2), 15);
    txCircle (       (x + x/2), 700 - (x + x/2), 15);
    txCircle (1200 - (x + x/2), 700 - (x + x/2), 15);
    }

//----------------------------------------------------------------------------
void TitleTextDraw  (int t)
    {
    txSetColor   (TX_YELLOW);
    txSelectFont ("Bookman Old Style", 50, 0, 0, 50);
    txTextOut    (           t, 250, "� � � � � � �");
    txTextOut    (1200 - 260-t, 250, "� � � � � � �");
    }

//============================================================================
void BeginScreen ()
    {
    ClearScreen();

    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "� ����� ����...");
    txSleep (500);

    ForestDraw (200);

    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "� ����� ����...   ����� �������...");
    txSleep (500);

    HomeDraw  (800, 350, 150, 160, 90, 1);
    txSleep (500);

    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "������ ������� �� ������� �������...");
    txSleep (500);

    GladeDraw (  0);
    txSleep (1000);


    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "������ ������, ����� ��������...");
    txSleep (500);

    BeeFly ();
    txSleep (500);
    }

//----------------------------------------------------------------------------
void ForestDraw (int tSleep)
    {
    int t = 45;
    while (t <= 700)
        {
        TreeOneDraw (50 + t, 50 + t%2*10, t%2 + 1, t%100/25 * 10 , 50 + t%10, t%35 + 10, 2,  50, t%80);
        t += 75;
        if (tSleep != 0)
            txSleep (tSleep);
        }
    }

//----------------------------------------------------------------------------
void GladeDraw (int tSleep)
    {
    int stepBush = 210;
    while (stepBush <= 700)
        {
        BushDraw    (500 + stepBush, 350 + stepBush%2*10, stepBush%2 + 1 );
        stepBush += 75;
        if (tSleep != 0)
            txSleep (tSleep);
        }

    for (int flowerX = 1; flowerX <= 5; flowerX++)
        {
        FlowerDraw  (100 + flowerX/2*70, 350, 1.3, TX_LIGHTMAGENTA, TX_ORANGE      );
        FlowerDraw  (140 + flowerX/2*50, 380, 1  , TX_LIGHTCYAN   , TX_YELLOW      );
        FlowerDraw  ( 80 + flowerX/2*90, 420, 1  , TX_YELLOW      , TX_LIGHTMAGENTA);
        FlowerDraw  (905 + flowerX/2*95, 555, 1.5, TX_BLUE        , TX_ORANGE      );
        FlowerDraw  (900 + flowerX/3*95, 600, 1  , TX_LIGHTMAGENTA, TX_ORANGE      );
        FlowerDraw  (800 + flowerX/2*70, 570, 1.2, TX_WHITE       , TX_YELLOW      );
        }

    BeeHomeDraw (630, 450, 1);
    BeeHomeDraw (530, 480, 2);
    BeeHomeDraw (580, 510, 2);
    }

//-----------------------------------------------------------------------------
void SubTitlesDraw (int x, int y,
                    int sizeFont, const char nameFont[],
                    COLORREF colorFont,
                    const char text[])
    {
    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle    (x, y, x + 500, y + 65);
    txSetColor     (colorFont);
    txSelectFont   (nameFont, sizeFont);
    txTextOut      (x + 10, y + 15, text);
    }
//----------------------------------------------------------------------------
void BeeFly ()
    {
    txBegin ();
    int vX = 5;
    int t = 0;
    while (t <= 11)
        {
        BeeDraw (150 + vX*t, 250 + vX*(t%2), 1  );
        BeeDraw (250 - vX*t, 350 + vX*(t%2), 1  );
        BeeDraw (800 + vX*t, 450 + vX*(t%2), 1.5);
        BeeDraw (950 - vX*t, 550 + vX*(t%2), 1.2);
        BeeDraw (900 + vX*t, 500 + vX*(t%2), 1.5);
        txSleep (150);

        ClearScreen();

        BackGroundBeginScreen ();
        SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "������ ������, ����� ��������...");

        t++;
        }
    t = 0;
    while (t <= 11)
        {
        BeeDraw (200 - vX*t, 250 + vX*(t%2), 1  );
        BeeDraw (200 + vX*t, 350 + vX*(t%2), 1  );
        BeeDraw (850 - vX*t, 450 + vX*(t%2), 1.5);
        BeeDraw (900 + vX*t, 550 + vX*(t%2), 1.2);
        BeeDraw (950 - vX*t, 500 + vX*(t%2), 1.5);
        txSleep (150);

        ClearScreen();

        BackGroundBeginScreen ();
        SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "������ ������, ����� ��������...");

        t++;
        }
    txEnd();
    }

//============================================================================
void CenterScreen ()
    {
    ClearScreen();

    BackGroundCenterScreen ();

    SubTitlesDraw (580, 590, 30, "Bookman Old Style", TX_YELLOW, "��� � ������� ���������� �����...");
    txSleep (500);

    BearMove ();

    BearNoseEvesMove ();
    }

//----------------------------------------------------------------------------
void BackGroundCenterScreen ()
    {
    HomeDraw    (900, 250, 150, 160, 90, 0.7);
    ForestDraw  (0);

    BeeHomeDraw (300, 400, 1.5);
    BeeHomeDraw (200, 480, 2  );
    BeeHomeDraw (380, 510, 3  );

    FlowerDraw  (115, 555, 1.5, TX_BLUE        , TX_ORANGE);
    FlowerDraw  (100, 580, 1.2, TX_LIGHTMAGENTA, TX_ORANGE);
    FlowerDraw  (170, 570, 1.3, TX_WHITE       , TX_YELLOW);
    FlowerDraw  (340, 650, 1.2, TX_YELLOW      , TX_WHITE);
    FlowerDraw  (300, 660, 1.2, TX_YELLOW      , TX_WHITE);
    }

//----------------------------------------------------------------------------
void BearMove ()
    {
    txBegin ();

    int t = 5;
    double sizeBear = 1;
    BackGroundCenterScreen ();
    while (t <= 55)
        {
        txSetFillColor (TX_BLACK);
        txClear ();
        BackGroundCenterScreen ();

        SubTitlesDraw (580, 590, 30, "Bookman Old Style", TX_YELLOW, "����� ����� ����� � �����...");

        BarrelDraw (850+25*sizeBear - t*5, 220+50*sizeBear + t*5, sizeBear/2);
        BearDraw   (850             - t*5, 220             + t*5, sizeBear, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 42 + t%10, 19, 47 - t%10);

        txSleep    (300);

        t += 5;
        sizeBear += 0.1;
        }

    txEnd();
    }

//----------------------------------------------------------------------------
void BearNoseEvesMove ()
    {
    txBegin ();

    ClearScreen();

    BackGroundCenterScreen ();

    SubTitlesDraw (580, 590, 30, "Bookman Old Style", TX_YELLOW, "������� ��� � ������...");

    BarrelDraw     (850 + 25*2.1 - 55*5, 220 + 50*2.1 + 55*5, 2.1/2);

    int t = 0;
    while (t <= 5)
        {
        BearDraw   (850 - 55*5, 220 + 55*5, 2.1, TX_YELLOW, 0, t%2 + 0.3, t%2 * 5, 30, 5, 25, 0, 25, 0, 21, 42 + 55%10, 19, 47 - 55%10);
        txSleep    (300);
        t += 1;
        }

    txEnd ();
    }

//============================================================================
void FinishScreen ()
    {
    ClearScreen();

    HoneySteal     (555, 455);
    BeeComeOutHome ();
    }

//----------------------------------------------------------------------------
void BackGroundFinishScreen ()
    {
    HomeDraw    (900, 250, 150, 160, 90, 0.7);
    ForestDraw  (0);

    BeeHomeDraw (300, 400, 1.5);
    BeeHomeDraw (200, 480, 2  );

    FlowerDraw  (115, 555, 1.5, TX_BLUE        , TX_ORANGE);
    FlowerDraw  (100, 580, 1.2, TX_LIGHTMAGENTA, TX_ORANGE);
    FlowerDraw  (170, 570, 1.3, TX_WHITE       , TX_YELLOW);
    FlowerDraw  (340, 650, 1.2, TX_YELLOW      , TX_WHITE);
    FlowerDraw  (300, 660, 1.2, TX_YELLOW      , TX_WHITE);

    BeeHomeFinishDraw (420, 500, 4);
    BarrelDraw  (737, 670, 1.5);
    BearDraw    (665, 495, 3.0 , TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 47, 19, 47);
    }

//----------------------------------------------------------------------------
void HoneySteal (int x, int y)
    {
    int t = 0;
    txBegin();

    while (t < 13)
        {
        ClearScreen();

        BackGroundFinishScreen ();

        txSetFillColor (RGB (252, 252, 108));
        if (t % 4 == 3)
            {
            txEllipse (x + t%4*80, y + t%4*20 , x + t%4*80 + 50, y + t%4*20 + 30);
            }
        else
            {
            txEllipse (x + t%4*80, y,           x + t%4*80 + 50, y          + 30);
            }
        POINT honey[6] = {{760, 540 - t/4  },
                         {774, 540 - t/4*5},
                         {810, 540 - t/4*4},
                         {846, 540 - t/4*5},
                         {864, 540 - t/4  },
                         {760, 540 - t/4  }};
        txPolygon (honey, 6);

        txSleep (550);
        t++;
        }
    txEnd();
    }

//----------------------------------------------------------------------------
void BeeComeOutHome   ()
    {
    txBegin ();

    int t = 0;
    while (t < 20)
        {
        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear        ();

        BackGroundFinishScreen ();
        SubTitlesDraw (910, 590, 30, "Bookman Old Style", TX_YELLOW, "...�-�-�-�-�-�...");

        txSetFillColor (RGB (252, 252, 108));
        POINT honey[6] = {{760, 540},
                         {774, 535},
                         {810, 530},
                         {846, 535},
                         {864, 540},
                         {760, 540}};
        txPolygon (honey, 6);

        txSetColor     (TX_RED);
        txSetFillColor (TX_RED);
        txEllipse (660 - t/2, 449      , 672 + t/2, 470 + t/2);
        BeeDraw   (500      , 580 - t*5, 0.5 + t/5);
        txSleep (150);
        t++;
        }

    txEnd();
    }

//============================================================================
void ScreamScreen ()
    {
    ClearScreen();

    SubTitlesDraw (500, 350, 140, "Bookman Old Style", TX_LIGHTRED, "A-A-A-�");
    txSleep(1000);

    ClearScreen();

    SubTitlesDraw (200, 150, 180, "Arial", TX_WHITE, "O-O-o-�");
    txSleep(1000);

    ClearScreen();

    SubTitlesDraw (250, 200, 140, "Cornier New", TX_YELLOW, "��-��-��-��...");
    txSleep(1000);

    ClearScreen();

    BackGroundFinishScreen ();

    txSetColor     (RGB(130, 67, 255));
    txSetFillColor (RGB(130, 67, 255));
    txEllipse      (670, 370,  715 , 420 );

    txSetColor     (TX_WHITE);
    txSetFillColor (TX_YELLOW);
    txCircle (687, 398, 13);
    txCircle (640, 397, 13);

    txSetFillColor (TX_BLACK);
    txCircle (688, 399,  6);
    txCircle (640, 398,  6);
    txSleep(500);

    SubTitlesDraw (800, 400, 50, "Bookman Old Style", TX_YELLOW, "� ������ �� ����...");
    txSleep(1000);
    }

//----------------------------------------------------------------------------
void BackGroundBeginScreen ()
    {
    ForestDraw  (0);
    HomeDraw    (800, 350, 150, 160, 90, 1);
    GladeDraw   (0);
    }
//============================================================================
void FinalScreen ()
    {
    ClearScreen();

    HomeBackground (90);

    BearHeadDraw (300, 350, 6);
    BeeHeadDraw  (900, 400, 5);

    TableDraw ();
    TeeDrink  ();
    txSleep (500);

    ClearScreen();

    TitleFrameDraw (50);

    SubTitlesDraw (400, 300, 100, "Bookman Old Style", TX_YELLOW, "� � � � �");
    txSleep (500);
    }

//-----------------------------------------------------------------------------
void HomeBackground (int heightY)
    {
    txSetColor     (RGB (177, 137, 77));
    txSetFillColor (RGB (177, 137, 77));

    txRectangle (0, 0,              1200, heightY);
    txRectangle (0, heightY   +  5, 1200, heightY*2 +  5);
    txRectangle (0, heightY*2 + 10, 1200, heightY*3 + 10);
    txRectangle (0, heightY*3 + 15, 1200, heightY*4 + 15);
    txRectangle (0, heightY*4 + 20, 1200, heightY*5 + 20);

    txSetColor     (RGB (105, 81, 45));
    txSetFillColor (RGB (105, 81, 45));
    txRectangle (300,  0, 900, 235);

    txSetFillColor (RGB (185, 235, 225));
    txRectangle (320,  0, 590,  70);
    txRectangle (320, 80, 590, 215);
    txRectangle (610,  0, 880,  70);
    txRectangle (610, 80, 880, 215);
    }

//----------------------------------------------------------------------------
void BearHeadDraw (int x, int y, double size)
    {
    txSetColor     (RGB (0, 0, 0));

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x,           y + 22*size, 25*size);
    txSetFillColor (RGB (238, 209, 111));
    txCircle (x,           y + 10*size, 13*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - 15*size, y - 43*size, 10*size);
    txCircle (x + 15*size, y - 43*size, 10*size);

    txSetFillColor (RGB (238, 209, 111));
    txCircle (x - 14*size, y - 42*size,  8*size);
    txCircle (x + 14*size, y - 42*size,  8*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x,           y - 25*size, 25*size);

    txSetFillColor (TX_YELLOW);
    txCircle (x - 8*size, y - 33*size,  4*size);
    txCircle (x + 8*size, y - 33*size,  4*size);

    txSetFillColor (RGB (0, 0, 0));
    txCircle (x - 8*size, y - 31*size,  2*size);
    txCircle (x + 8*size, y - 31*size,  2*size);

    txSetColor     (RGB (0, 0, 0));
    txLine (x - 5*size, y - 25*size, x + 5*size, y - 25*size);
    txLine (x,          y - 20*size, x + 5*size, y - 25*size);
    txLine (x - 5*size, y - 25*size, x,          y - 20*size);
    txFloodFill (x, y - 23*size);

    txSetColor     (RGB (255, 0, 0));
    txArc (x - 10*size, y - 25*size, x + 10*size, y - 15*size, 200, 120);
    }

//----------------------------------------------------------------------------
void BeeHeadDraw (int x, int y, int size)
    {
    txSetFillColor (RGB (185, 235, 225));
    txSetColor     (RGB (50, 50, 0),2);
    txEllipse (x - 55*size, y + 20 , x, y + 20 - 20*size);
    txEllipse (x + 55*size, y + 20 , x, y + 20 - 20*size);

    txSetFillColor (RGB (30, 30, 0));
    txSetColor     (RGB (255, 255, 0),5);

    txCircle (x, y + 22*size, 25*size);

    txSetFillColor (RGB (255, 255, 0));
    POINT body[5] = {{x - 20*size, y + 7*size     },
                     {x + 20*size, y + 7*size     },
                     {x + 22*size, y + 7*size + 25},
                     {x - 22*size, y + 7*size + 25},
                     {x - 20*size, y + 7*size     }};
    txPolygon (body, 5);
    txRectangle (x - 24*size, y + 20*size, x + 24*size, y + 20*size +25);

    txSetColor     (RGB (50, 50, 0),2);
    txSetFillColor (RGB (230, 230, 0));
    txCircle (x, y - 25*size, 25*size);

    txSetColor     (RGB (50, 50, 0),2);
    txSetFillColor (RGB (30, 30, 0));
    txEllipse(x - 11*size, y - 50*size, x + 11*size, y - 50*size + 35);
    txCircle (x - 30, y - 60*size, 2*size);
    txCircle (x + 30, y - 60*size, 2*size);

    txSetColor     (RGB (50, 50, 0),4);
    txLine (x - 30, y - 60*size, x - 5, y - 24*size*2 );
    txLine (x + 30, y - 60*size, x + 5, y - 24*size*2 );

    txSetFillColor (TX_YELLOW);
    txCircle (x -  8*size, y - 33*size,  4*size);
    txCircle (x +  8*size, y - 33*size,  4*size);

    txSetFillColor (RGB (0, 0, 0));
    txCircle (x -  8*size, y - 31*size,  2*size);
    txCircle (x +  8*size, y - 31*size,  2*size);

    txSetColor     (RGB (0, 0, 0));
    txSetFillColor (RGB (0, 0, 0));
    POINT nose[5] = {{x,           y - 25*size},
                     {x +  2*size, y - 22*size},
                     {x,           y - 20*size},
                     {x - 10*size, y - 20*size},
                     {x,           y - 25*size}};
    txPolygon (nose, 5);

    txSetColor     (RGB (255, 0, 0));
    txArc (x - 10*size, y - 25*size, x + 10*size, y - 15*size, 200, 120);
    }

//-----------------------------------------------------------------------------
void TableDraw ()
    {
    txSetColor     (RGB (250, 250, 200));
    txSetFillColor (RGB (250, 250, 200));
    POINT table[7] = {{   0, 700},
                      {   0, 650},
                      { 100, 450},
                      {1100, 450},
                      {1200, 650},
                      {1200, 700},
                      {   0, 700}};
    txPolygon (table, 7);

    txSetColor     (RGB (  0,   0,  0), 2);
    txSetFillColor (RGB (208, 134, 34));
    txEllipse (500, 680, 700, 530);
    txEllipse (530, 680, 670, 530);
    txEllipse (570, 680, 630, 530);

    txSetColor     (RGB (250, 250, 200), 2);
    txSetFillColor (RGB (250, 250, 200));
    txRectangle (450, 680, 700, 665);
    txRectangle (450, 550, 700, 525);
    txSetColor     (RGB (  0,   0,   0), 2);
    txLine (535, 663, 665, 663);
    txLine (533, 550, 667, 550);

    txSetColor     (RGB (255, 255, 0));
    txSetFillColor (RGB (255, 255, 0));
    POINT honey[8] = {{533, 549},
                      {667, 549},
                      {667, 545},
                      {660, 541},
                      {600, 535},
                      {540, 541},
                      {533, 545},
                      {533, 549}};
    txPolygon (honey, 8);

    txSetColor     (RGB (120, 34,  95), 2);
    txSetFillColor (RGB (208, 92, 175));
    txEllipse (300, 470, 500, 510);
    txEllipse (350, 480, 450, 500);
    txEllipse (700, 470, 900, 510);
    txEllipse (750, 480, 850, 500);

    txSetColor     (RGB (0, 0, 0));
    txSetFillColor (RGB (177, 101, 54));
    txCircle (300 - 20*6, 360 + 8*6, 10*5);

    SubTitlesDraw (100, 645, 50, "Bookman Old Style", TX_BLACK, "� ����� ��� ���� ������, ��� ������ � ������ �������...");
    }

//-----------------------------------------------------------------------------
void TeeDrink()
    {
    int t = 390;
    for (int countTeeDrink = 1; countTeeDrink < 4; countTeeDrink++)
        {
        t = 390;
        while (t >= 260)
            {
            txSetColor     (TX_BLACK);
            txSetFillColor (TX_BLACK);
            txClear        ();

            HomeBackground (90);
            BearHeadDraw (300, 350, 6);
            BeeHeadDraw  (900, 400, 5);
            TableDraw ();

            CupTee (400 - (390-t)/3, t + 50,  1);
            BearPawRight(t);

            CupTee (800 + (390-t)/3, 440 - (390-t)/2, -1);
            BeePawLeft (t);
            txSleep (100);
            t -= 5;
            }

        t = 260;
        while (t <= 390)
            {
            txSetColor     (TX_BLACK);
            txSetFillColor (TX_BLACK);
            txClear        ();

            HomeBackground (90);
            BearHeadDraw (300, 350, 6);
            BeeHeadDraw  (900, 400, 5);
            TableDraw ();

            CupTee (400 - (390-t)/3, t + 50,  1);
            BearPawRight (t);

            CupTee (800 + (390-t)/3, 440 - (390-t)/2, -1);
            BeePawLeft (t);
            txSleep (100);
            t += 5;
            }
        txSleep (500);
        }
     }

//-----------------------------------------------------------------------------
void BearPawRight(int y)
    {
    txSetColor     (RGB (0, 0, 0));
    txSetFillColor (RGB (177, 101, 54));
    txCircle (515 - (390-y)/3, y + 48, 50);
    }
//-----------------------------------------------------------------------------
void BeePawLeft(int y)
    {
    txSetFillColor (RGB (30, 30, 0));
    txSetColor     (RGB (50, 50, 0),2);
    txCircle (690 + (390-y)/3, 438 - (390-y)/2, 40);
    }

//-----------------------------------------------------------------------------
void CupTee(int x, int y, int orientation)
    {
    txSetColor     (RGB (120, 34,  95), 2);
    txSetFillColor (RGB (208, 92, 175));
    POINT cup[11] = {{x - 40*orientation, y + 50},
                     {x - 60*orientation, y - 50},
                     {x + 60*orientation, y - 50},
                     {x + 55*orientation, y - 25},
                     {x + 90*orientation, y - 25},
                     {x + 90*orientation, y + 30},
                     {x + 70*orientation, y + 30},
                     {x + 70*orientation, y - 10},
                     {x + 50*orientation, y - 10},
                     {x + 40*orientation, y + 50},
                     {x - 40*orientation, y + 50}};
    txPolygon (cup, 11);
    }

//============================================================================
void BearDraw (int x, int y, double size,
               COLORREF colorEye, double dBetweenEyes, double radiusEyes,
               int noseY, int dBetweenEars, int dChestMove,
               int lHandX, int lHandY, int rHandX, int rHandY,
               int lFoodX, int lFoodY,int rFoodX, int rFoodY)
    {
    txSetColor     (TX_WHITE);
    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - (dBetweenEars/2  )*size, y - 43*size, 10*size);
    txCircle (x + (dBetweenEars/2  )*size, y - 43*size, 10*size);

    txSetFillColor (RGB (238, 209, 111));
    txCircle (x - (dBetweenEars/2-1)*size, y - 42*size, 8*size);
    txCircle (x + (dBetweenEars/2-1)*size, y - 42*size, 8*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x, y - 25*size, 25*size);

    txSetFillColor (colorEye);
    txCircle (x - 8*size+dBetweenEyes, y - 33*size, 4*size*radiusEyes);
    txCircle (x + 8*size+dBetweenEyes, y - 33*size, 4*size*radiusEyes);

    txSetFillColor (RGB (0, 0, 0));
    txCircle (x - 8*size+dBetweenEyes, y - 31*size, 2*size*radiusEyes);
    txCircle (x + 8*size+dBetweenEyes, y - 31*size, 2*size*radiusEyes);

    txSetColor     (RGB (0, 0, 0));
    txLine (x - 5*size, y - 25*size+noseY, x + 5*size, y - 25*size+noseY);
    txLine (x,          y - 20*size+noseY, x + 5*size, y - 25*size+noseY);
    txLine (x - 5*size, y - 25*size+noseY, x,          y - 20*size+noseY);
    txFloodFill    (x,  y - 23*size+noseY);

    txSetColor     (TX_RED);
    txSetFillColor (TX_RED);
    txEllipse (x - 2*size, y - 15*size,     x + 2*size, y - 8*size);

    txSetColor     (RGB (255, 255, 255));
    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - lHandX*size, y + lHandY*size, 10*size);
    txCircle (x + rHandX*size, y + rHandY*size, 10*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - lFoodX*size, y + lFoodY*size, 10*size);
    txCircle (x + rFoodX*size, y + rFoodY*size, 10*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x, y + 25*size, 25*size);
    txSetFillColor (RGB (238, 209, 111));
    txCircle (x, y + 13*size+dChestMove, 13*size);
    }

//----------------------------------------------------------------------------
void TreeOneDraw (int x, int y, double size, double inclineX, int widthTree, int heigthTree,
                  int pxLine, int colorLine, int colorTree)
    {
    txSetColor     (RGB (0, 255-colorLine, 0), pxLine);
    txSetFillColor (RGB (0, 255-colorTree, 0)        );
    txLine (x + inclineX,         y                    , x - widthTree/2*size, y + heigthTree*size  );
    txLine (x + inclineX,         y                    , x + widthTree/2*size, y + heigthTree*size  );
    txLine (x - widthTree/2*size, y + heigthTree*size  , x + widthTree/2*size, y + heigthTree*size  );
    txFloodFill (x, y + heigthTree*size-5);

    txLine (x + inclineX/2,       y + heigthTree*size  , x - widthTree/2*size, y + heigthTree*2*size);
    txLine (x + inclineX/2,       y + heigthTree*size  , x + widthTree/2*size, y + heigthTree*2*size);
    txLine (x - widthTree/2*size, y + heigthTree*2*size, x + widthTree/2*size, y + heigthTree*2*size);
    txFloodFill (x, y + heigthTree/2*3*size);

    txLine (x + inclineX/4,       y + heigthTree*2*size, x + widthTree/2*size, y + heigthTree*3*size);
    txLine (x + inclineX/4,       y + heigthTree*2*size, x - widthTree/2*size, y + heigthTree*3*size);
    txLine (x - widthTree/2*size, y + heigthTree*3*size, x + widthTree/2*size, y + heigthTree*3*size);
    txFloodFill (x, y + heigthTree/2*5*size);

    txSetColor     (RGB (177, 101, 54));
    txSetFillColor (RGB (177, 101, 54));
    txRectangle (x - widthTree/5*size, y + heigthTree*3*size+1, x + widthTree/5*size, y + heigthTree*3*size+heigthTree/5);
    }

//----------------------------------------------------------------------------
void BushDraw (int x, int y, double size)
    {
    txSetColor     (RGB (0, 245, 0), 2);
    txSetFillColor (RGB (0, 200, 0));
    txCircle (x - 10*size, y, 18*size);
    txCircle (x + 10*size, y, 18*size);

    txSetFillColor (RGB (0, 250, 0));
    txCircle (x,           y, 20*size);

    txSetColor     (RGB (177, 101, 54));
    txLine (x, y + 20*size, x          , y);
    txLine (x, y + 20*size, x - 10*size, y);
    txLine (x, y + 20*size, x + 10*size, y);
    }

//----------------------------------------------------------------------------
void HomeDraw (double x, double y,    int heightRoof,
               int widthWindow, int heightWindow, double size)
    {
    txSetColor     (RGB (177, 137, 77));
    txSetFillColor (RGB (177, 137, 77));
    txRectangle (x, y,            x + 300*size, y -  30*size);
    txRectangle (x, y -  35*size, x + 300*size, y -  65*size);
    txRectangle (x, y -  70*size, x + 300*size, y - 100*size);
    txRectangle (x, y - 105*size, x + 300*size, y - 135*size);
    txRectangle (x, y - 140*size, x + 300*size, y - 170*size);

    txSetFillColor (RGB (105, 81, 45));
    txCircle (x +  20*size, y - 155*size, 18*size);
    txCircle (x + 280*size, y - 155*size, 18*size);
    txCircle (x +  20*size, y - 120*size, 18*size);
    txCircle (x + 280*size, y - 120*size, 18*size);
    txCircle (x +  20*size, y -  85*size, 18*size);
    txCircle (x + 280*size, y -  85*size, 18*size);
    txCircle (x +  20*size, y -  50*size, 18*size);
    txCircle (x + 280*size, y -  50*size, 18*size);
    txCircle (x +  20*size, y -  15*size, 18*size);
    txCircle (x + 280*size, y -  15*size, 18*size);

    txSetFillColor (RGB (114, 34, 54));
    POINT star[5] = {{int(x -  10*size), int(y - 175*size)               },
                     {int(x + 310*size), int(y - 175*size)               },
                     {int(x + 200*size), int(y - (175 + heightRoof)*size)},
                     {int(x + 100*size), int(y - (175 + heightRoof)*size)},
                     {int(x -  10*size), int(y - 175*size)}};
    txPolygon (star, 5);
    txSetFillColor (RGB (105, 81, 45));

    txRectangle (x + 70*size, y - 130*size, x + (70+widthWindow)*size, y - (130-heightWindow)*size);
    txSetColor  (RGB (105, 81, 45));
    txCircle (x + (70+widthWindow/16/2)*size,             y - (130-heightWindow/9/2)*size             , widthWindow/16*size);
    txCircle (x + (70+widthWindow/2)*size,                y - (130-heightWindow/9/2)*size             , widthWindow/16*size);
    txCircle (x + (70+widthWindow-widthWindow/16/2)*size, y - (130-heightWindow/9/2)*size             , widthWindow/16*size);

    txCircle (x + (70+widthWindow/16/2)*size,             y - (130-heightWindow/2)*size               , widthWindow/16*size);
    txCircle (x + (70+widthWindow-widthWindow/16/2)*size, y - (130-heightWindow/2)*size               , widthWindow/16*size);

    txCircle (x + (70+widthWindow/16/2)*size,             y - (130-heightWindow+heightWindow/9/2)*size, widthWindow/16*size);
    txCircle (x + (70+widthWindow/2)*size,                y - (130-heightWindow+heightWindow/9/2)*size, widthWindow/16*size);
    txCircle (x + (70+widthWindow-widthWindow/16/2)*size, y - (130-heightWindow+heightWindow/9/2)*size, widthWindow/16*size);
    txSetFillColor (RGB (185, 235, 225));


    txRectangle (x + (70+widthWindow/16)*size                , y - (130-heightWindow/9)*size                 , x + (70+widthWindow/2-widthWindow/16/2)*size, y - (130-heightWindow/2+heightWindow/9/2)*size);
    txRectangle (x + (70+widthWindow/16)*size                , y - (130-heightWindow/2-heightWindow/9/2)*size, x + (70+widthWindow/2-widthWindow/16/2)*size, y - (130-heightWindow  +heightWindow/9)*size  );
    txRectangle (x + (70+widthWindow/2+widthWindow/16/2)*size, y - (130-heightWindow/9)*size                 , x + (70+widthWindow  -widthWindow/16)*size  , y - (130-heightWindow/2+heightWindow/9/2)*size);
    txRectangle (x + (70+widthWindow/2+widthWindow/16/2)*size, y - (130-heightWindow/2-heightWindow/9/2)*size, x + (70+widthWindow  -widthWindow/16)*size  , y - (130-heightWindow  +heightWindow/9)*size  );
    }

//----------------------------------------------------------------------------
void BeeDraw (int x,int y, double size)
    {
    txSetFillColor (RGB (30, 30, 0));
    txSetColor     (RGB (255, 255, 0),3);
    txCircle  (x,          y - 5*size, 5*size);
    txEllipse (x - 5*size, y,          x + 5*size, y + 15*size);

    txSetColor     (RGB (255, 255, 0),2*size);
    txLine (x -  4*size, y +  5*size, x +  4*size, y +  5*size);
    txLine (x -  4*size, y + 10*size, x +  4*size, y + 10*size);

    txSetFillColor (RGB (185, 235, 225));
    txSetColor     (RGB (50, 50, 0),2);
    txEllipse (x - 15*size, y, x, y +  6*size);
    txEllipse (x + 15*size, y, x, y +  6*size);
    }

//----------------------------------------------------------------------------
void BeeHomeDraw (int x, int y, double size)
    {
    txSetFillColor (RGB (215, 210, 190));
    txSetColor     (RGB (102, 98, 80),2);
    txRectangle (x,           y,           x + 40*size, y + 35*size);
    txRectangle (x -  5*size, y,           x + 45*size, y -  5*size);
    txRectangle (x +  5*size, y + 35*size, x + 10*size, y + 40*size);
    txRectangle (x + 30*size, y + 35*size, x + 35*size, y + 40*size);

    txSetFillColor (RGB (102, 98, 80));
    txRectangle (x + 10*size, y + 30*size, x + 30*size, y + 27*size);
    txCircle    (x + 20*size, y + 20*size, 3*size);
    }

//----------------------------------------------------------------------------
void BeeHomeFinishDraw (int x, int y, double size)
    {
    txSetFillColor (RGB (252, 252, 108));
    txSetColor     (RGB (252, 252, 108),2);
    txEllipse   (x + 2*size, y - 8*size, x + 38*size, y + 12*size);

    txSetFillColor (RGB (215, 210, 190));
    txSetColor     (RGB (102, 98, 80),2);

    txRectangle (x,           y,           x + 40*size, y + 35*size);
    txRectangle (x,           y +  5*size, x -  5*size, y - 35*size);
    txRectangle (x +  5*size, y + 35*size, x + 10*size, y + 40*size);
    txRectangle (x + 30*size, y + 35*size, x + 35*size, y + 40*size);

    txSetFillColor (RGB (102, 98, 80));
    txRectangle (x + 10*size, y + 30*size, x + 30*size, y + 27*size);
    txCircle    (x + 20*size, y + 20*size, 3*size);
    }

//----------------------------------------------------------------------------
void FlowerDraw (int x, int y, double size, COLORREF colorPetal, COLORREF colorCenter)
    {
    txSetFillColor (RGB (12, 118, 30));
    txSetColor     (RGB (12, 118, 30),2);
    txEllipse (x - 13*size, y -  3*size, x + 13*size, y +  3*size);
    txLine    (x,           y,           x,           y - 48*size);

    txSetFillColor (RGB (20, 198, 50));
    txEllipse (x - 13*size, y - 23*size, x          , y - 20*size);
    txEllipse (x + 13*size, y - 13*size, x          , y - 10*size);

    txSetColor     (RGB (250, 220, 240));
    txSetFillColor (colorPetal);
    txCircle (x,          y - 43*size, 5*size);
    txCircle (x,          y - 60*size, 5*size);
    txCircle (x - 8*size, y - 48*size, 5*size);
    txCircle (x + 8*size, y - 48*size, 5*size);
    txCircle (x - 8*size, y - 55*size, 5*size);
    txCircle (x + 8*size, y - 55*size, 5*size);

    txSetFillColor (colorCenter);
    txCircle (x,          y - 51*size, 6*size);
    }

//----------------------------------------------------------------------------
void BarrelDraw (double x, double y, double size)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (255, 204, 102));
    txEllipse   (x,           y, x + 100*size,        y - 100*size);
    txEllipse   (x + 20*size, y, x + (100 - 20)*size, y - 100*size);
    txEllipse   (x + 40*size, y, x + (100 - 40)*size, y - 100*size);
    txSetFillColor (TX_BLACK);
    txRectangle (x, y,             x + 100*size, y - 15*size        );
    txRectangle (x, y - 100*size , x + 100*size, y - (100 - 15)*size);
    }

//-----------------------------------------------------------------------------
void ClearScreen()
    {
    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txClear        ();
    }
