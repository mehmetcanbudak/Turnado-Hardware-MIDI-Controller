#include "EncoderSwitched.h"

EncoderSwitched encoder (5, 6, 4);
EncoderSwitched encoder2 (0, 1, 2);

void setup() 
{
  Serial.begin(9600);
  delay(500);
  
  encoder.onEncoderChange (processEncoderChange);
  encoder.onSwitchChange (processEncoderSwitchChange);
}

void loop() 
{
  encoder.update();

}

void processEncoderChange (EncoderSwitched &enc, int enc_value)
{
  if (enc == encoder)
  {
    Serial.print ("Enc1: ");
    Serial.println (enc_value);
  }
  else if (enc == encoder2)
  {
    Serial.print ("Enc2: ");
    Serial.println (enc_value);
  }
}

void processEncoderSwitchChange (EncoderSwitched &enc, uint8_t switch_state)
{
  if (enc == encoder)
  {
    Serial.print ("Enc1 switch: ");
    Serial.println (switch_state);
  }
  else if (enc == encoder2)
  {
    Serial.print ("Enc2 switch: ");
    Serial.println (switch_state);
  }
  
}
