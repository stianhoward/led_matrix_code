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
//#define F     {B00000000,B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01000000,B01000000,B00000000}
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
Declare values to be used through the program
***********************/
int clock = 8;
int reset = 9;
int t,x,y,z;

const int numPatterns = 4;  //Look into a way to set this to a single setting
byte patterns[numPatterns][10]={space,b,s,space}; // Start/Finish with space to get copmlete scroll
//numPatterns = patterns.length()


void setup()
{
  DDRD=B11111111; //Enable digital ports 0-7
  DDRB=B00001100;
  DDRC=B00000;    //Set the analog pins to input sound bands

  //Enable communication with computer
  Serial.begin(9600);   //Enable this to start communication with PC over USB

  //Initialize and reset decade counter
  pinMode(clock,OUTPUT);
  pinMode(reset,OUTPUT);
  digitalWrite(reset,HIGH);
  delayMicroseconds(5);
  digitalWrite(reset,LOW);

  // Initialize welcome screen
  show(50);

  //Declare array for audio input storage
  int audioArray[5];
  byte displayArray[0];
}

void loop()
{
 //show(50);
 while(1) {
  importAudio(displayArray);
  displayData(40, displayArray);
 }
}

void show(int speed) {  //Look into how to pause on the letter.
  for(z=0;z<numPatterns-1;z++){
    for(x=0;x<10;x++){
      for(t=0;t<speed;t++){
        for(y=0;y<10;y++){
          PORTD = (patterns[z][y+x]);
          PORTB = B00001100 & (PORTD << 2);
          delayMicroseconds(800);
          if (y ==   9) {
            delay(5);
          }
          PORTD=B00000000;
          digitalWrite(clock,HIGH);
          delayMicroseconds(5);
          digitalWrite(clock,LOW);

        }
      }
    }
  }
  return;
}


//Take the byte displayArray, and display it, repeating 'speed' times
void displayData(int speed, byte displayArray){
  for(t=0;t<speed;t++){           // Display 'speed' times. Sets refresh rate
    for(y=0;y<10;y++){            // iterate through all 10 columns
      PORTD = (patterns[y/2]);    // 2 pixel wide columns. also scales down to 5 large array
      delayMicroseconds(800);
      PORTD=B00000000;
      digitalWrite(clock,HIGH);
      delayMicroseconds(5);
      digitalWrite(clock,LOW);
    }
  }

  return;
}


void importAudio(byte displayArray) {
  //Import values, and save to an int array
  int maxIn = 255;
  for (int i=0; i<5; i++){
    //audioArray[i] = analogRead(i);
    Serial.println(analogRead(i));
    int importValue = analogRead(i);


    if (importValue/maxIn <= 0.125 ){
      displayArray[i] = B10000000;
    } else if (importValue/maxIn <= 0.25){
      displayArray[i] = B11000000;
    } else if (importValue/maxIn <= 0.375){
      displayArray[i] = B11100000;
    } else if (importValue/maxIn <= 0.5){
      displayArray[i] = B11110000;
    } else if (importValue/maxIn <= 0.625){
      displayArray[i] = B11111000;
    } else if (importValue/maxIn <= 0.75){
      displayArray[i] = B11111100;
    } else if (importValue/maxIn <= 0.875){
      displayArray[i] = B11111110;
    } else {
      displayArray[i] = B11111111;
    }
  }


  return;
}
