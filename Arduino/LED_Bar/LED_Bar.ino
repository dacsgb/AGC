#include <SPI.h>        
#include <DMD.h>       
#include <TimerOne.h>  
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

#define DISPLAYS_ACROSS 3
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

char* texto = "GOD HELP US";

void ScanDMD(){dmd.scanDisplayBySPI();}

void setup(void){ 
  Serial.begin(115200);
  
  Timer1.initialize(1000);
  Timer1.attachInterrupt(ScanDMD);

  //clear/init the DMD pixels held in RAM
  dmd.selectFont(SystemFont5x7);
  dmd.clearScreen(false);
  delay(3000);
  dmd.clearScreen(true);
}


void loop() {
  //drawText(texto);
}

void drawText(char* text){
  int len = String(text).length();
  dmd.drawString( int((32*DISPLAYS_ACROSS - 6*len)/2),4, texto, len, GRAPHICS_NORMAL );
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
dmd.drawString( x,y, "Left", 4, GRAPHICS_NORMAL );
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
dmd.drawString( x,4, "Stopping", 8, GRAPHICS_NORMAL );
dmd.drawFilledBox(0,0,20,16,GRAPHICS_NORMAL);
dmd.drawFilledBox(76,0,96,16,GRAPHICS_NORMAL);
}