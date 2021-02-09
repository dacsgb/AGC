
#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Arial_Black_16_ISO_8859_1.h"

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 3
#define DISPLAYS_DOWN 1
#define SIZE_X DISPLAYS_ACROSS*32
#define SIZE_Y DISPLAYS_DOWN*16
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);


void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}


void setup(void)
{
      dmd.clearScreen( true );
   //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
   Timer1.initialize( 3000);           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

   //clear/init the DMD pixels held in RAM
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
  Serial.begin(57600);
}

char Response;
//int i=0;
void loop()
{
  if (Serial.available() >= 0)
    {
      Response=Serial.read();
    }
  else Response='~';

      if(Response=='d')
        {
          dmd.clearScreen(true);
          Right();
        }
      else if(Response=='a')
        {
          dmd.clearScreen(true);
          Left();
        }
      else if(Response=='s')
        {    
          dmd.clearScreen(true);
          Stopping();
        }
      else if (Response =='w')
        {
          dmd.clearScreen(true);
          Name();
        }
}

void Right()
{
  int i=8;
  int j =0;
  int x=(SIZE_X-25)/2;
  int y=4;
dmd.selectFont(SystemFont5x7);
dmd.drawString( x,y, "Right", 5, GRAPHICS_NORMAL );
while(i>=0)
  {
    dmd.drawLine(i,abs(i-8),i,i+8,GRAPHICS_NORMAL);
    delay(1);
    i=i-1;  
  }
}


void Left()
{
  int i= 87;
  int j= 0;
  int x=(SIZE_X-20)/2;
  int y=4;
dmd.selectFont(SystemFont5x7);
dmd.drawString( x,y, "Left", 5, GRAPHICS_NORMAL );
while(i<=96 && j<=8)
  {
    dmd.drawLine(i,j,i,16-j,GRAPHICS_NORMAL);
    delay(1);
    i=i+1; 
    j=j+1; 
  }
}

void Stopping()
{
int x=25;
int y=4;
dmd.selectFont(SystemFont5x7);
dmd.drawString( x,4, "Stop", 5, GRAPHICS_NORMAL );
dmd.drawString( x+24,4, "ping", 5, GRAPHICS_NORMAL );
dmd.drawFilledBox(0,0,20,16,GRAPHICS_NORMAL);
dmd.drawFilledBox(76,0,96,16,GRAPHICS_NORMAL);
}

void Name()
{
int x=24;
int j=30;
int k=30;
int y=4;
dmd.selectFont(SystemFont5x7);
dmd.drawString( x,y, "ENDEA", 5, GRAPHICS_NORMAL );
dmd.drawString( x+j,y, "VOR", 5, GRAPHICS_NORMAL );
}
