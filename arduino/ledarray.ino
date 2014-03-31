void setup() {
   for(int x = 2; x < 14; x++) {
       pinMode(x, OUTPUT);
   }
}

void loop() {
  alignment();
  
  /* realistically, this is where you pull data.  for now
   * I've given you an array with 9 values that represent 
   * data that you would get from serial, or wherever
   * we end up getting it from.
   */

  //this data is for testing purposes
  //start with full battery, nothing seen
  int data[] = {1,0,1,0,0,0,0,0,0};
  parse_data(data);
  //full batteries, gate seen
  int data1[] = {1,0,1,0,0,1,0,0,0};
  parse_data(data1);
  //full batteries, path seen
  int data2[] = {1,0,1,0,0,0,0,1,0};
  parse_data(data2);
  //lipo batteries below half, buoy seen
  int data3[] = {0,1,1,0,0,0,0,0,1};
  parse_data(data3);
  //path seen
  int data4[] = {0,1,1,0,0,0,0,1,0};
  parse_data(data4);
  //hedge seen
  int data5[] = {0,1,1,0,1,0,0,0,0};
  parse_data(data5);
  //hedge seen, all batteries low
  int data6[] = {0,1,0,1,1,0,0,0,0};
  parse_data(data6);
  //path seen
  int data7[] = {0,1,0,1,0,0,0,1,0};
  parse_data(data7);
  //bin seen
  int data8[] = {0,1,0,1,0,0,1,0,0};
  parse_data(data8);
}

void parse_data(int* data) {
  battery_life(*(data+0), *(data+1));
  battery_life(*(data+2), *(data+3));
  hedge_seen(*(data+4));
  gate_seen(*(data+5));
  bin_seen(*(data+6));
  path_seen(*(data+7));
  buoy_seen(*(data+8));
  //wait for 10 seconds before parsing next data
  delay(10000);
}
/* LEDs that constantly stay on, for alignment purpose
 * If that's not needed anymore, let me know.  Will reassign to other tasks
 */
void alignment() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
}

/* Turns on pins on the right side of the array. Pins 4 and 7
 * are lipo battery life, pins 10 and 13 are lead acid.
 * Parameters: if battery life is high, input 1.  Else, 0.
 *    If value is for lipo battery, 1.  Else 0.
 */
void battery_life(int value, int lipo) {
  if(value && lipo) {
     digitalWrite(4, HIGH);
     digitalWrite(7, LOW);
  }
  else if(!value && lipo) {
     digitalWrite(4, LOW);
     digitalWrite(7, HIGH);
  }
  else if(value && !lipo) {
     digitalWrite(10, HIGH);
     digitalWrite(13, LOW);
  } else {
     digitalWrite(10, LOW);
     digitalWrite(13, HIGH); 
  }
}

/* Turns on pin 6 if a hedge is seen */
void hedge_seen(int value) {
   if(value) {
      digitalWrite(6, HIGH);
   } else {
      digitalWrite(6, LOW);
   } 
}

/* Turns on pin 8 if gate is seen */
void gate_seen(int value) {
   if(value) {
      digitalWrite(8, HIGH);
   } else {
      digitalWrite(8, LOW);
   } 
}

/* Turns on pin 9 if a bin is seen */
void bin_seen(int value) {
   if(value) {
      digitalWrite(9, HIGH);
   } else {
      digitalWrite(9, LOW);
   } 
}

/* Turns on pin 11 if a path is seen */
void path_seen(int value) {
   if(value) {
      digitalWrite(11, HIGH);
   } else {
      digitalWrite(11, LOW);
   } 
}

/* Turns on pin 12 if a buoy is seen */
void buoy_seen(int value) {
   if(value) {
      digitalWrite(12, HIGH);
   } else {
      digitalWrite(12, LOW);
   } 
}
