#define ANODE_R 9
#define ANODE_B 10
#define ANODE_G 11
#define SWITCH  12
#define TOUCH   14

int CH, R, G, B, dir;
bool buttonState, lastButtonState, touchState;

void setup() {
  // put your setup code here, to run once:
  pinMode(ANODE_R, OUTPUT);
  pinMode(ANODE_G, OUTPUT);
  pinMode(ANODE_B, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(TOUCH, INPUT);
  CH = ANODE_R;
  R = G = B = 0;
  dir = 1;
  buttonState = lastButtonState = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(SWITCH);
  if (buttonState == LOW && lastButtonState == HIGH)
  {
    changeChannel();
  }
  if (digitalRead(TOUCH) == HIGH)
  {
    updateLED();
  }
  lastButtonState = buttonState;
  delay(30);
}

void changeChannel() {
  if (CH == ANODE_R)
  {
    CH = ANODE_G;
  }
  else if (CH == ANODE_G)
  {
    CH = ANODE_B;
  }
  else
  {
    CH = ANODE_R;
  }
  dir = 1;
}

void updateLED() {
  if (CH == ANODE_R)
  {
    if (R >= 64)
    {
      dir = -1;
    }
    else if (R <= 0)
    {
      dir = 1;
    }
    R += dir;
    analogWrite(CH, R);
  }
  else if (CH == ANODE_G)
  {
    if (G >= 64)
    {
      dir = -1;
    }
    else if (G <= 0)
    {
      dir = 1;
    }
    G += dir;
    analogWrite(CH, G);
  }
  else
  {
    if (B >= 64)
    {
      dir = -1;
    }
    else if (B <= 0)
    {
      dir = 1;
    }
    B += dir;
    analogWrite(CH, B);
  }
}
