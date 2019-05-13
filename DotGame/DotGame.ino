#include <MeggyJrSimple.h>

int x, y;

//struct Point;
//{
//  int x;
//  int y; 
//  int color;
//}



void setup() 
{
  MeggyJrSimpleSetup();
  x=0;
  y=0;
}



void loop()
{
  DrawPlayer();
  MovePlayer();
}
  
void DrawPlayer()
{
  DrawPx(x, y, 1);
  DisplaySlate();
}

void MovePlayer()
{
  CheckButtonsPress();
  if(Button_Left)
  {
    if(x>0)
    {
      ClearSlate();
      x--;
      DisplaySlate();
    }
  }
  if(Button_Right)
  {
    if(x<7)
    {
      ClearSlate();
      x++;
      DisplaySlate();
    }
  }
  if(Button_Up)
  {
    if(y<7)
    {
      ClearSlate();
      y++;
      DisplaySlate();
    }
  }
  if(Button_Down)
  {
    if(y>0)
    {
      ClearSlate();
      y--;
      DisplaySlate();
    }
  }
}
