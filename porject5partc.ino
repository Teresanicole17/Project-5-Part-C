// Project 5 - Traffic Light with Pedestrian Crossing

#define westButton 3
#define eastButton 13
#define pedButton 7

#define westRed 2
#define westYellow 4
#define westGreen 5

#define eastRed 12
#define eastYellow 11
#define eastGreen 10

#define pedLight 8

#define yellowBlinkTime 500

boolean trafficWest = true;

int flowTime = 2000;
int changeDelay = 1000;
int walkTime = 5000;

// ---------------- PEDESTRIAN FUNCTION ----------------
void pedestrianCross() {
  // stop traffic on both sides
  
  digitalWrite(westGreen, LOW);
  digitalWrite(westYellow, HIGH);
  delay(changeDelay);

  
  digitalWrite(westYellow, LOW);
  digitalWrite(westRed, HIGH);
}
else
{
  digitalWrite(eastGreen, LOW);
  digitalWrite(eastYellow, HIGH);

  
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastRed, HIGH);
  
}

digitalWrite(westRed, HIGH);
digitalWrite(eastRed, HIGH);
  delay(changeDelay);

  // turn on pedestrian LED
  digitalWrite(pedLight, HIGH);
  delay(walkTime);

  // turn off pedestrian LED
  digitalWrite(pedLight, LOW);

  // return traffic to whichever side had priority before pedestrian crossing
  if (trafficWest == true) {
    digitalWrite(westRed, LOW);
    digitalWrite(westGreen, HIGH);

    digitalWrite(eastRed, HIGH);
    digitalWrite(eastGreen, LOW);
  } else {
    digitalWrite(eastRed, LOW);
    digitalWrite(eastGreen, HIGH);

    digitalWrite(westRed, HIGH);
    digitalWrite(westGreen, LOW);
  }
}
// ----------------------------------------------------

void setup() {
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(pedButton, INPUT);

  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);

  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  pinMode(pedLight, OUTPUT);

  // initial traffic state
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);

  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);

  digitalWrite(pedLight, LOW);
}

void loop() {
  // pedestrian request
  if (digitalRead(pedButton) == LOW) {
    pedestrianCross();

    // wait for button release
    while (digitalRead(pedButton) == LOW) {
    }
    delay(200);
  }

  // request west traffic flow
  if (digitalRead(westButton) == LOW) {
    if (trafficWest != true) {
      trafficWest = true;
      delay(flowTime);

      digitalWrite(eastGreen, LOW);
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);

      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay);


      digitalWrite(westYellow, HIGH);
      delay(changeDelay);

      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westGreen, HIGH);
      
      while (digitalRead(westButton) == LOW) {
      }
      delay(200);
    }
  }

  // request east traffic flow
  if (digitalRead(eastButton) == LOW) {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);

      digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);

      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay);

      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);

      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH);

      while (digitalRead(eastButton) == LOW) {
      }
      delay(200);
    }
  }
}
