
#include <IRremote.h>

#define ON_OFF_KEY 0xFF629D
#define A_KEY 0xFF22DD
#define B_KEY 0xFF02FD
#define C_KEY 0xFFC23D
#define UP_KEY 0xFF9867
#define DOWN_KEY 0xFF38C7
#define LEFT_KEY 0xFF30CF
#define RIGHT_KEY 0xFF7A85
#define CENTER_KEY 0xFF18E7

int i=0;
int sensorPin=11;
int piezoPin = 6;

IRrecv irrecv(sensorPin);
int ledPin1=5;
int ledPin2=4;
int ledPin3=3;

decode_results results;
boolean isOn;

/**
 * 
 */
void setup() 
{
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(sensorPin,INPUT);
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();

}

/**
 * 
 */
void setColor(int red, int green, int blue)
{
  analogWrite(ledPin1, red);
  analogWrite(ledPin2, blue);
  analogWrite(ledPin3, green);
}

/**
 * 
 */
void loop() 
{
    if (irrecv.decode(&results)) 
    {
      Serial.println(results.value, DEC);
      irrecv.resume(); // Receive the next value
    }
    delay(100);
    if (results.value== ON_OFF_KEY)
    {
       isOn=true;
       Serial.print("ON/OFF");
    }
  
    if(isOn== true)
    {
 
    {

    if(results.value == A_KEY) //A5
    {
      tone(piezoPin,880,500);
    }
    
    else if (results.value== B_KEY) //B5
    {
      tone(piezoPin,987.77,500);
    }
    
    else if (results.value==C_KEY) //C6
    {
      tone(piezoPin,1046.50,500);
    }
    
    else if (results.value == UP_KEY) //D6
    {
      tone(piezoPin,1174.66,500);
    }
      
    else if (results.value == DOWN_KEY) //E6
    {
      tone(piezoPin,1318.51,500);
    }
    
    else if (results.value == LEFT_KEY) //F6
    {
      tone(piezoPin,1396.91,500);
    }
    
    else if (results.value == RIGHT_KEY) //G6
    {
      tone(piezoPin,1567.98,500);
    }   
    else if (results.value==CENTER_KEY)
    {
      randomSong();
    }


    }
    }

}



/**
 * 
 */
void marySong()
{
  char songNotes [] = {'e', 'd', 'c', 'd', 'e', 'e', 'E', 'd', 'd', 'D', 'e', 'g', 'G', 'e', 'd', 'c', 'd'}; //Character Array
  for(int i = 0; i < sizeof(songNotes); i++) //Loop through each index of array
  {
    switch(songNotes[i]) //Modified IF statements
    {
      case 'e':
      tone(piezoPin,1318.51,500);
      break;

      case 'd':
      tone(piezoPin,1174.66,500);
      break;

      case 'c':
      tone(piezoPin,1046.50,500);
      break;

      case 'g':
      tone(piezoPin,1567.98,500);
      break;

      case 'E':
      tone(piezoPin,1318.51,1000);
      delay(500);
      break;

      case 'D':
      tone(piezoPin,1174.66,1000);
      delay(500);
      break;

      case 'C':
      tone(piezoPin,1046.50,1000);
      delay(500);
      break;

      case 'G':
      tone(piezoPin,1567.98,1000);
      delay(500);
      break;
    }
    
    delay(500);
      
    }
}

/**
 * 
 */
void marioSong()
{
  char songNotes [] = {'E', 'E', 'R', 'E', 'R' ,'C', 'e', 'g', 'r' ,'g' ,'r' };

  for (int i = 0; i < 14; i++)
  {
    switch (songNotes[i])
    {
      case 'R':
        tone(piezoPin, 0, 250);
        break;

      case 'r':
        tone(piezoPin, 0, 500);
        break;

      case 'C':
        tone(piezoPin, 1046.50, 250);
        break;

      case 'E':
        tone(piezoPin, 1318.51, 250);
        break;

      case 'e':
        tone(piezoPin, 1318.51, 500);
        break;

      case 'd':
        tone(piezoPin, 1174.66, 500);
        break;

      case 'c':
        tone(piezoPin, 1046.50, 500);
        break;

      case 'g':
        tone(piezoPin, 1567.98, 500);
        break;


    }
    delay(500);
  }
}

/**
 * 
 */
void twinkleSong()
{
  char songNotes [] = {'g', 'g', 'd', 'd', 'e', 'e', 'D', 'c', 'c', 'b', 'b', 'a', 'a', 'G'};

  for (int i = 0; i < 14; i++)
  {
    switch (songNotes[i])
    {
      case 'e':
        tone(piezoPin, 1318.51, 500);
        break;

      case 'd':
        tone(piezoPin, 1174.66, 500);
        break;

      case 'c':
        tone(piezoPin, 1046.50, 500);
        break;

      case 'g':
        tone(piezoPin, 1567.98, 500);
        break;

      case 'E':
        tone(piezoPin, 1318.51, 1000);
        delay(500);
        break;

      case 'D':
        tone(piezoPin, 1174.66, 1000);
        delay(500);
        break;

      case 'C':
        tone(piezoPin, 1046.50, 1000);
        delay(500);
        break;

      case 'G':
        tone(piezoPin, 1567.98, 500);
        delay(500);
        break;
    }
    delay(500);
  }
}

/**
 * 
 */
void checkButtonInputs()
{
  int i = 0;
  int pointCounter = 0;
  char songNotes [] = {'e', 'd', 'c', 'd', 'e', 'e', 'E', 'd', 'd', 'D', 'e', 'g', 'G', 'e', 'd', 'c', 'd'}; //Character Array

  while (i < 18) {
    if (irrecv.decode(&results)) {
      //Serial.println(results.value, DEC);
      irrecv.resume(); // Receive the next value

      delay(100);

      switch (results.value)
      {
        case A_KEY:
          if (songNotes[i] == 'A') {
            Serial.println("Correct");
            pointCounter++;
          }
          else {
            Serial.println("Wrong");
            pointCounter--;
          }
          i++;
          break;

        case B_KEY:
           if (songNotes[i] == 'B') {
            Serial.println("Correct");
            pointCounter++;
          }
          else {
            Serial.println("Wrong");
            pointCounter--;
          }
          i++;
          break;

        case C_KEY:
          if (songNotes[i] == 'C') {
            Serial.println("Correct");
            pointCounter++;
          }
          else {
            Serial.println("Wrong");
            pointCounter--;
          }
          i++;
          break;

        case UP_KEY:
          if (songNotes[i] == 'D') {
            Serial.println("Correct");
            pointCounter++;
          }
          else {
            Serial.println("Wrong");
            pointCounter--;
          }
          i++;
          break;
          
        case DOWN_KEY:
          if (songNotes[i] == 'E') {
            Serial.println("Correct");
            pointCounter++;
          }
          else {
            Serial.println("Wrong");
            pointCounter--;
          }
          i++;
          break;
          
        case LEFT_KEY:
           if (songNotes[i] == 'F') {
            Serial.println("Correct");
            pointCounter++;
          }
          else {
            Serial.println("Wrong");
            pointCounter--;
          }
          i++;
          break;

        case RIGHT_KEY:
          if (songNotes[i] == 'G') {
            Serial.println("Correct");
            pointCounter++;
          }
          else {
            Serial.println("Wrong");
            pointCounter--;
          }
          i++;
          break;
      }
      
    }
    delay(1);
  }
  Serial.print("Your score was " + pointCounter);
}



/**
 * 
 */
void randomSong()
{
  Serial.begin(9600);
  int randomSong = random(1,4); //Random numbers from 1 to 3
  int songGuess = 0; 

  if(randomSong == 1)
  {
    marySong();
    
  }
  else if(randomSong == 2)
  {
    marioSong();
    
  }
  else if(randomSong == 3)
  {
    twinkleSong();
  } 


  Serial.println("Mary Had A Little Lamb: 1");
  Serial.println("Mario Brothers: 2");
  Serial.println("Twinkle Twinkle Little Star: 3");
  Serial.println("Enter the number for the song that just played!");

  while(Serial.available() == 0) 
  {
    
  }

  songGuess = Serial.parseInt();

  if(songGuess == randomSong)
    {
      Serial.println("Correct!");
    }
    else
    {
      Serial.println("Incorrect!");
    }
}
