/***********************************************************************
 * Project      :     tiny32_PYR20_read
 * Description  :     Read value from PYR20 (W/m^2)
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/07/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu; //define object

uint8_t id = 1; //current address of PYR20, You can change here if it differance

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_PYR20_read ****\r\n");
  mcu.library_version();
  mcu.PYR20_begin(RXD2,TXD2);
  mcu.buzzer_beep(2); //buzzer 2 beeps
}

void loop()
{
  int16_t _pyranormeter = mcu.PYR20_read(id);
  if(_pyranormeter != -1)
  {
    Serial.printf("Info: Solar Radiation = %d W/m^2\r\n",_pyranormeter);
  }
  else
  {
    Serial.printf("Error: can't read sensor\r\n");
  }
  vTaskDelay(1000);
  
}