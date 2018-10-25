#include <FastLED.h>

#define COLOR_ORDER RGB  //if your colors look incorrect, change the color order here
#define NUM_LEDS    23  //change this number for the final LED count

#define lightData 7



CRGB leds[NUM_LEDS];

int bright = 255;

void setup() {
    delay(3000); // sanity delay
    FastLED.addLeds<WS2812, lightData, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 3000);
    FastLED.setBrightness(bright);

    Serial.begin(9600);

    fill_solid(leds, NUM_LEDS, CRGB(200,100,180)); //check that the lights work
    FastLED.show();
    delay(1000);
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
    FastLED.show();
    delay(1000);
}

int isOn[24];
 
//  *******************
//  *****MAIN CODE*****
//  *******************
void loop() {
  int i;
  for (i = 0; i < 24; i = i + 1) {
    int ran = random(1000);
    Serial.print("random:  "); Serial.println(ran);
    if (ran > 998 && isOn[i] == 0) {
      isOn[i] = 255;
      Serial.print(i); Serial.println(" is now ON!");
      leds[i] = CHSV (60, 255, isOn[i]);
      FastLED.show();
    }
    else{
      isOn[i] = 0;
    }
  }

  for (i = 0; i < 24; i = i + 1) {
    Serial.println(isOn[i]);
    if (isOn[i] > 0) {
      isOn[i] = isOn[i] - 30;
      leds[i] = CHSV (60, 255, isOn[i]);
      //Serial.print(i); Serial.print("-->"); Serial.println(isOn[i]);
      FastLED.show();
    }
    else{
      isOn[i] = 0;
      Serial.print(i); Serial.println(" is now OFF!");
    }
  }

 }
