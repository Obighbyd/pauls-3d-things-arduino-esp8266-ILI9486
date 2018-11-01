#include <SPI.h>
#include <Ucglib.h>
#include "me.h"

Ucglib_ILI9486_18x320x480_HWSPI ucg(/*cd=*/ 15, /*cs=*/ 0, /*reset=*/ 16);

void drawMe(uint16_t offsetX, uint16_t offsetY) {
  uint16_t w = 200;
  uint16_t h = 200;
  uint16_t i = 0;
  for (uint16_t y = 0; y < h; y++) {
    Serial.println(y);
    for (uint16_t x = 0; x < w; x++) {
      i = y * w + x;
      uint8_t b = me_bits[i / 8];
      if (b & 1 << (i % 8)) {
        ucg.setColor(0, x, y, 255);
      } else {
        ucg.setColor(0, 0, 0, 0);
      }
      ucg.drawPixel(offsetX + x, offsetY + y);
    }
    delay(10);
  }
  ucg.setPrintPos(offsetX, offsetY + h + 20);
  ucg.print("Follow:");
  ucg.setPrintPos(offsetX, offsetY + h + 40);
  ucg.print("@pauls_3d_things");
}
void setup(void)
{
  Serial.begin(9600);
  delay(1000);
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.setFont(ucg_font_courB14_mf);
  ucg.clearScreen();
  drawMe(60, 140);
}

uint32_t count = 0;

void loop(void)
{
  delay(1000);

  ucg.setColor(0, 0, 0, 0);
  ucg.drawBox(0, 0, 320, 20);

  ucg.setColor(255, 255, 255);
  ucg.setColor(1, 255, 0, 0);
  uint8_t fh = 20;
  
  ucg.setPrintPos(0, 1*fh);
  ucg.print(count);
  ucg.setPrintPos(50, 1*fh);
  ucg.print("3.5\" TFT-LCD, 320*480");

  
  ucg.setPrintPos(0, 2*fh);
  ucg.print("DSP -> D1MINI");
  ucg.setPrintPos(0, 3*fh);
  ucg.print("GND -> GND");
  ucg.setPrintPos(0, 4*fh);
  ucg.print("VCC -> 3V3");
  ucg.setPrintPos(0, 5*fh);
  ucg.print("CLK -> D5");
  ucg.setPrintPos(0, 6*fh);
  ucg.print("MOS -> D7");
  ucg.setPrintPos(0, 7*fh);
  ucg.print("RES -> D0");
  ucg.setPrintPos(0, 8*fh);
  ucg.print("DC  -> D8");
  ucg.setPrintPos(0, 9*fh);
  ucg.print("BLK -> 3V3");
  ucg.setPrintPos(0, 10*fh);
  ucg.print("MIS -> D6");


  count++;
}
