/*
 * Basic program to display a set of text, or bars according to an input signal.
 * The input signal is analyzed using FHT.
 *
 */


/***********************
Letter and script definitions
***********************/
#define space {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}
#define A     {B00000000,B00111100,B01000010,B01000010,B01000010,B01111110,B01000010,B01000010,B01000010,B00000000}
#define s     {B01000110,B10001001,B10001001,B10001001,B01110010,B00000000,B00000000,B00000000,B00000000,B00000000}
#define B     {B00000000,B01111100,B01000010,B01000010,B01111100,B01000010,B01000010,B01000010,B01111100,B00000000}
#define b     {B11111111,B10001000,B10001000,B10001000,B01110000,B00000000,B00000000,B00000000,B00000000,B00000000}
#define C     {B00000000,B00111110,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B00111110,B00000000}
#define c     {B01111000,B10000100,B10000100,B10000100,B01001000,B00000000,B00000000,B00000000,B00000000,B00000000}
#define D     {B00000000,B01111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B01111100,B00000000}
#define E     {B00000000,B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01000000,B01111110,B00000000}
#define F     {B00000000,B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01000000,B01000000,B00000000}
#define G     {B00000000,B00111100,B01000010,B01000010,B01000000,B01000111,B01000010,B01000010,B00111100,B00000000}
#define H     {B00000000,B01000010,B01000010,B01000010,B01111110,B01000010,B01000010,B01000010,B01000010,B00000000}
#define I     {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000}
#define J     {B00000000,B00011100,B00001000,B00001000,B00001000,B00001000,B01001000,B01001000,B00110000,B00000000}
#define K     {B00000000,B01000100,B01001000,B01010000,B01100000,B01010000,B01001000,B01000100,B01000010,B00000000}
#define L     {B00000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01111110,B00000000}
#define M     {B00000000,B01000100,B10101010,B10010010,B10010010,B10000010,B10000010,B10000010,B10000010,B00000000}
#define N     {B00000000,B01000010,B01100010,B01010010,B01001010,B01001010,B01001010,B01000110,B01000010,B00000000}
#define O     {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000}
#define P     {B00000000,B00111100,B01000010,B01000010,B01000010,B01111100,B01000000,B01000000,B01000000,B00000000}
#define Q     {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001}
#define R     {B00000000,B00111100,B01000010,B01000010,B01000010,B01111100,B01000100,B01000010,B01000010,B00000000}
#define S     {B00000000,B00111100,B01000010,B01000000,B01000000,B00111100,B00000010,B01000010,B00111100,B00000000}
#define T     {B00000000,B11111110,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000}
#define U     {B00000000,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000}
#define V     {B00000000,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000}
#define W     {B00000000,B10000010,B10000010,B10000010,B10000010,B10010010,B10010010,B10101010,B01000100,B00000000}
#define X     {B00000000,B01000010,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B01000010,B00000000}
#define Y     {B00000000,B10000010,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000}
#define Z     {B00000000,B01111110,B00000010,B00000100,B00001000,B00010000,B00100000,B01000000,B01111110,B00000000}
/*
#define 0 {B00000000,B00111100,B01000110,B01001010,B01001010,B01001010,B01010010,B01100010,B00111100,B00000000}
#define 1 {B00000000,B00001000,B00011000,B00001000,B00001000,B00001000,B00001000,B00001000,B00011100,B00000000}
#define 2 {B00000000,B00111100,B01000010,B00000100,B00001000,B00010000,B00100000,B01000000,B01111110,B00000000}
#define 3 {B00000000,B01111110,B00000010,B00000010,B00011100,B00000010,B00000010,B01000010,B00111100,B00000000}
#define 4 {B00000000,B00000100,B00001100,B00010100,B00100100,B01000100,B01111110,B00000100,B00000100,B00000000}
#define 5 {B00000000,B01111110,B01000000,B01000000,B00111100,B00000010,B00000010,B00000010,B01111100,B00000000}
#define 6 {B00000000,B00111100,B01000000,B01000000,B01111100,B01000010,B01000010,B01000010,B00111100,B00000000}
#define 7 {B00000000,B01111110,B00000010,B00000100,B00001000,B00010000,B00010000,B00010000,B00010000,B00000000}
#define 8 {B00000000,B00111100,B01000010,B01000010,B00111100,B01000010,B01000010,B01000010,B00111100,B00000000}
#define 9 {B00000000,B00111100,B01000010,B01000010,B01000010,B00111110,B00000010,B00000010,B00111100,B00000000
*/

/***********************
Define values for use in FHT methodology
***********************/
#define FHT_N 16  //Number of bins to calculate
#define SCALE 4   //precision

/***********************
Inport Libraries
***********************/
#include <FHT.h> // Including the FHT library to process the input signals.



/***********************
Declare values to be used through the program
***********************/
int clock = 8;
int reset = 9;
int t,x,y,z;

const int numPatterns = 4;  //Look into a way to set this to a single setting
byte patterns[numPatterns][10]={space,s,b,space}; // Start/Finish with space to get copmlete scroll
//numPatterns = patterns.length()


void setup()
{
  DDRD=B11111111; //Enable digital ports 0-7

  //Enable communication with computer
  // Serial.begin(115200)   //Enable this to start communication with PC over USB

  //Enabling audio importing
  TIMSK0 = 0;     // turn off timer0, disabling interrupts. REMOVE THIS FIRST IF FAILURE
  ADCSRA = 0xe5;  // set the adc to free running mode
  ADMUX = 0x40;   // use adc0
  DIDR0 = 0x01;   // turn off the digital input for adc0

  //Initialize and reset decade counter
  pinMode(clock,OUTPUT);
  pinMode(reset,OUTPUT);
  digitalWrite(reset,HIGH);
  delayMicroseconds(5);
  digitalWrite(reset,LOW);
}

void loop()
{
 show2(50);
 while(1) {
  importAudio();
 }
}

void show(int speed) {
  for(z=0;z<numPatterns-1;z++){
    for(x=0;x<10;x++){
      for(t=0;t<speed;t++){
        for(y=0;y<10;y++){
          PORTD = (patterns[z][y+x]);
          delayMicroseconds(800);

          PORTD=B00000000;
          digitalWrite(clock,HIGH);
          delayMicroseconds(5);
          digitalWrite(clock,LOW);

        }
      }
    }
  }
}

void show2(int speed) {
  for(z=0;z<numPatterns-1;z++){
    for(x=0;x<7;x++){
      for(t=0;t<speed;t++){
        for(y=0;y<10;y++){
          if (x<5){
            PORTD = (patterns[z][y+x] + patterns[z+1][y+x-7]);
          } else {
            PORTD = (patterns[z][y+x] + patterns[z+1][y+x-7] + patterns[z+2][x+y-14]);
          }
          //PORTD = patterns[z][y+x];
          delayMicroseconds(800);

          PORTD=B00000000;
          digitalWrite(clock,HIGH);
          delayMicroseconds(5);
          digitalWrite(clock,LOW);

        }
      }
    }
  }
}


void importAudio() {
  cli();  // UDRE interrupt slows this way down on arduino1.0
  for (int i = 0 ; i < FHT_N ; i++) {   // save specified number of samples
    while(!(ADCSRA & 0x10));  // wait for adc to be ready
    ADCSRA = 0xf5;            // restart adc
    byte m = ADCL;            // fetch adc data
    byte j = ADCH;
    int k = (j << 8) | m;     // form into an int
    k -= 0x0200;              // form into a signed int
    k <<= 6;                  // form into a 16b signed int
    fht_input[i] = k;         // put real data into bins
  }

  /*********************
  FHT audio processing.
  *********************/
  fht_window();     // window the data for better frequency response
  fht_reorder();    // reorder the data before doing the fht
  fht_run();        // process the data in the fht
  fht_mag_octave(); // take the output of the fht
  sei();

  /*********************
  Send data to computer for computer analysis.
  Enable with seerial in setup.
  *********************/
  // Serial.write(255);                  // send a start byte
  // Serial.write(fht_log_out, FHT_N/2); // send out the data
}
