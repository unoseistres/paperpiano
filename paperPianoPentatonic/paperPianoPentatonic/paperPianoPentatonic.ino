// paper piano: here we divide an octave into the notes of the pentatonic scale

int sensorPin = A0;    // input pin
unsigned int sensorValue = 0;   // variable to store the value coming from the sensor
unsigned int sensorAvg = 0;
int step = 0;
int offset = 2; // if key readings are very close together in value, decrease this to 3 or so

// pentatonic scale- A4-A5
int pianoInput = 11;
int octave = 3; // default is 1. Change to 2 or 4 for higher octaves!
float scale[] = {440*octave, 495*octave, 556.875*octave, 660*octave, 742.5*octave}; // array storing frequencies for pentatonic scale

// REPLACE with readings from the 5 keys
float keyReadings[] = {276, 225, 195, 203, 171};

void setup() {
  // initialize serial communications at 2400 bps:
  Serial.begin(2400);
}

void loop() {

  // read the value from the sensor:
  sensorValue += analogRead(sensorPin);
  step = (step+1)%100;
  if(step == 0){
    sensorAvg = sensorValue/100;
    sensorValue = 0;
    Serial.println(sensorAvg);
  } 
  
  if(sensorAvg < 30){
    noTone(pianoInput);
  }
  else if(sensorAvg < keyReadings[4]+offset){
    tone(pianoInput, scale[4]);
  }
  else if(sensorAvg < keyReadings[3]+offset){
    tone(pianoInput, scale[3]);
  }
  else if(sensorAvg < keyReadings[2]+offset){
    tone(pianoInput, scale[2]);
  }
  else if(sensorAvg < keyReadings[1]+offset){ 
    tone(pianoInput, scale[1]);
  }
  else if(sensorAvg < keyReadings[0]+offset){
    tone(pianoInput, scale[0]);
  }  else{
 noTone(pianoInput);
  }
  
}


