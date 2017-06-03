// const int hit = 6;
const int buttonHit = 6;
const int button = 7;
// const int led = 2;
const int ledButton 2;
// const int led1 = 3;
// const int led2 = 4;
// const int led3 = 5;
const int livePointIndicator1 = 3;
const int livePointIndicator2 = 4;
const int livePointIndicator3 = 5;

int lives = 3;
// int state = 0;
int readButton = 0;
int gameRunning = false;

void setup()
{
  pinMode(hit, INPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(lives, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  // reset live points
  lives = 3;

  // read button
  readButton = digitalRead(button);
  if (readButton == HIGH)
  {
    // start game
    gameRunning = true;
  }
  
  // else if (lives = 0)
  // {
  //   gameRunning = false;
  // }

  while(gameRunning)
  {
  // read button hit
    readButton = digitalRead(buttonHit);
    if (readButton == HIGH)
    {
      digitalWrite(led, HIGH);
      // delay(1500); waktu delay program ga merespon apa-apa
      delay(500);
    }
    else
    {
      digitalWrite(led, LOW);
    }
  
    // decrease lives
    readButton = digitalRead(hit);
    if (readButton == HIGH)
    {
      lives -= 1;
    }

    // start checking live points
    if (lives == 3) // use lives == 3 not lives = 3
    {
      digitalWrite(livePointIndicator1, HIGH);
      digitalWrite(livePointIndicator2, HIGH);
      digitalWrite(livePointIndicator3, HIGH);
    }
    else if (lives == 2)
    {
      digitalWrite(livePointIndicator1, LOW);
      digitalWrite(livePointIndicator2, HIGH);
      digitalWrite(livePointIndicator3, HIGH);
    }
    else if (lives == 1)
    {
      digitalWrite(livePointIndicator1, LOW);
      digitalWrite(livePointIndicator2, LOW);
      digitalWrite(livePointIndicator3, HIGH);
    }
    else if (lives == 0)
    {
      digitalWrite(livePointIndicator1, LOW);
      digitalWrite(livePointIndicator2, LOW);
      digitalWrite(livePointIndicator3, LOW);

      // set game over
      gameRunning = false;
    }

    // end checking live points
  }
}
