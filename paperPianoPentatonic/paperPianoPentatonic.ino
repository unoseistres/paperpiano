/**
 * Paper Piano
 * A demonstration of the pentatonic scale using Arduino, conductive paint, and paper.
 * 
 * 
 * 
 * 
 */

// --------------------------------------------------------------------------------------
// Paper readings:
//   Change these settings based on the readings from the individual keys of the piano.
//   Place values in descending order regardless of key reading order.

#define   PP_KEY_1            377
#define   PP_KEY_2            340
#define   PP_KEY_3            311
#define   PP_KEY_4            279
#define   PP_KEY_5            247



// --------------------------------------------------------------------------------------
// Sound and sensitivity configuration:
//   These settings determine the sensitivity of values as well as the octave produced

#define   PP_OCTAVE           1         // Change to 2 or 4 for higher pitches
#define   PP_OFFSET           5         // Reduce this to 3 if measured values are close together
#define   PP_SILENT_CUTOFF    30        // Value below which should be considered no keys pressed



// --------------------------------------------------------------------------------------
// Scale configuration:
//   The default values create frequencies for the pentatonic scale.

#define   PP_TONE_1           440
#define   PP_TONE_2           495
#define   PP_TONE_3           556.875
#define   PP_TONE_4           660
#define   PP_TONE_5           742.5



// --------------------------------------------------------------------------------------
// Hardware configuration:
//   Change these settings based on the configuration of the hardware

#define   PP_ANALOG_INPUT     A0        // The analog input connected to the paper
#define   PP_SPEAKER_OUTPUT   11        // The output connected to the + of the speaker
#define   PP_SERIAL_BAUD      2400      // The bitrate for the serial port
#define   PP_READ_COUNT       100       // How many analog readings to take for average


// --------------------------------------------------------------------------------------
// Arduino code
//   No changes should be made below this line

void setup() {
  Serial.begin( PP_SERIAL_BAUD );
}

void loop() {
  
  uint32_t sensorValue = 0;
  
  // Take several analog readings to create average
  for ( int i = 0; i < PP_READ_COUNT; i++ ) {
    sensorValue += analogRead( PP_ANALOG_INPUT );
  }

  // Calculate average reading
  sensorValue /= PP_READ_COUNT;
  
  // Print out analog reading
  Serial.print( sensorValue );
  Serial.print( "\t" );

  // Produce tone based on analog input
  if ( sensorValue < PP_SILENT_CUTOFF ) {
    noTone( PP_SPEAKER_OUTPUT );
    Serial.println();
  }
  else if ( sensorValue < (PP_KEY_5 + PP_OFFSET) ) {
    tone( PP_SPEAKER_OUTPUT, PP_TONE_5 * PP_OCTAVE );
    Serial.println( "BUTTON 5" );
  }
  else if ( sensorValue < (PP_KEY_4 + PP_OFFSET) ) {
    tone( PP_SPEAKER_OUTPUT, PP_TONE_4 * PP_OCTAVE );
    Serial.println( "BUTTON 4" );
  }
  else if ( sensorValue < (PP_KEY_3 + PP_OFFSET) ) {
    tone( PP_SPEAKER_OUTPUT, PP_TONE_3 * PP_OCTAVE );
    Serial.println( "BUTTON 3" );
  }
  else if ( sensorValue < (PP_KEY_2 + PP_OFFSET) ) {
    tone( PP_SPEAKER_OUTPUT, PP_TONE_2 * PP_OCTAVE );
    Serial.println( "BUTTON 2" );
  }
  else if ( sensorValue < (PP_KEY_1 + PP_OFFSET) ) {
    tone( PP_SPEAKER_OUTPUT, PP_TONE_1 * PP_OCTAVE );
    Serial.println( "BUTTON 1" );
  }
  else {
    noTone( PP_SPEAKER_OUTPUT );
    Serial.println(  );
  }

  // Slows serial output scroll
  delay( 25 ); 

}

