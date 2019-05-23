#include <MeggyJrSimple.h>

struct Point
{
  int x;
  int y;
  int color;
};

Point e1 = {1, 0, 1};
Point e2 = {1, 1, 1};
Point e3 = {1, 2, 1};
Point e4 = {1, 3, 1};
Point e5 = {1, 4, 1};
Point e6 = {1, 6, 1};
Point e7 = {1, 7, 1};
Point e8 = {3, 0, 1};
Point e9 = {3, 2, 1};
Point e10 = {3, 3, 1};
Point e11 = {3, 4, 1};
Point e12 = {3, 5, 1};
Point e13 = {3, 6, 1};
Point e14 = {3, 7, 1};
Point e15 = {5, 0, 1};
Point e16 = {5, 1, 1};
Point e17 = {5, 2, 1};
Point e18 = {5, 3, 1};
Point e19 = {5, 4, 1};
Point e20 = {5, 5, 1};
Point e21 = {5, 7, 1};
Point e22 = {7, 0, 1};
Point e23 = {7, 1, 1};
Point e24 = {7, 2, 1};
Point e25 = {7, 3, 1};
Point e26 = {7, 4, 1};
Point e27 = {7, 5, 1};
Point e28 = {7, 6, 1};
Point e29 = {7, 7, 1};

Point EnemyArray[] = {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29};

int xplayer;
int yplayer;
int xgoal = 6;
int ygoal = 7;

boolean GoalMade = false;


void setup() 
{
  MeggyJrSimpleSetup();
  xplayer=0;
  yplayer=0;
}


void loop()
{
  DrawPlayer();
  DrawEnemies();
  Goal();
  MovePlayer();
  Made();
  Lose();
  DisplaySlate();
  ClearSlate();
}
  
void DrawPlayer()
{
  DrawPx(xplayer, yplayer, Blue);
}

void MovePlayer()
{
  CheckButtonsPress();
  if(Button_Left)
  {
    if(xplayer>0)
    {
      ClearSlate();
      xplayer--;
      DisplaySlate();
    }
  }
  if(Button_Right)
  {
    if(xplayer<7)
    {
      ClearSlate();
      xplayer++;
      DisplaySlate();
    }
  }
  if(Button_Up)
  {
    if(yplayer<7)
    {
      ClearSlate();
      yplayer++;
      DisplaySlate();
    }
  }
  if(Button_Down)
  {
    if(yplayer>0)
    {
      ClearSlate();
      yplayer--;
      DisplaySlate();
    }
  }
}

void Goal()
{
  DrawPx(xgoal, ygoal, Green);
}

void Made()
{
  if(xplayer == 6 && yplayer == ygoal)
  {
    Tone_Start(1900, 100);
    xgoal = 0;
    ygoal = random(8);
  }
  if(xplayer == 0 && yplayer == ygoal)
  {
    Tone_Start(1900, 100);
    xgoal = 6;
    ygoal = random(8);
  }
}

void DrawEnemies()
{
  for(int i = 0; i < 29; i++)
  {
    DrawPx(EnemyArray[i].x, EnemyArray[i].y, EnemyArray[i].color);
  }
}


void Lose()
{
  for(int i = 0; i < 29; i++)
  {
    if(xplayer == EnemyArray[i].x && yplayer == EnemyArray[i].y)
    {
      Tone_Start(1900, 100);
      xplayer = 0;
      yplayer = 0;
      xgoal = 6;
      ygoal = random(8);
    }
  }
}
 
