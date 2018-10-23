// The following is a simple stepper motor control procedures
# define EN 8 // stepper motor enable , active low
# define X_DIR 5 // X -axis stepper motor direction control
# define Y_DIR 6 // y -axis stepper motor direction control
# define Z_DIR 7 // z axis stepper motor direction control
# define X_STP 2 // x -axis stepper control
# define Y_STP 3 // y -axis stepper control
# define Z_STP 4 // z -axis stepper control

/*
// Function : step . function: to control the direction of the stepper motor , the number of steps .
// Parameters : dir direction control , dirPin corresponding stepper motor DIR pin , stepperPin corresponding stepper motor " step " pin , Step number of step of no return value.
*/
boolean x_tf;
boolean y_tf;
boolean z_tf;
uint8_t prompted =0;

void step (boolean dir, byte dirPin, byte stepperPin, int steps)
{
    
    digitalWrite (dirPin, dir);
    delay (50);
    for (int i = 0; i <steps; i ++) 
    {
        digitalWrite (stepperPin, HIGH);
        delayMicroseconds (800);
        digitalWrite (stepperPin, LOW);
        delayMicroseconds (800);
    }
    
}
/*
void arraySubtraction(){
  ypr[0]=
}*/

void setup () {   // The stepper motor used in the IO pin is set to output
    Serial.begin(115200);
    pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
    pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
    pinMode (Z_DIR, OUTPUT); pinMode (Z_STP, OUTPUT);
    pinMode (EN, OUTPUT);
    digitalWrite (EN, LOW);
    // define state of euler angles as 0,0,0
    
}


void loop () {
  
  uint8_t state[3]={0,0,0};
  x_tf = true;
  y_tf = true;
  z_tf = true;
  int bytes_read = 0;
  
  while (bytes_read < 3)
  {
    if (Serial.available() > 0)
    {
       state[bytes_read] = (uint8_t)Serial.read();
       bytes_read++;
    }
  }
  if(state[0]>100){
    state[0]-=100;
    x_tf=false;
  } 
  if(state[1]>100){
    state[1]-=100;
    y_tf=false;
  } 
  if(state[2]>100){
    state[2]-=100;
    z_tf=false;
  } 
  Serial.print(state[0]);
  Serial.print(" ");
  Serial.print(state[1]);
  Serial.print(" ");
  Serial.print(state[2]);
  Serial.println(" ");
 step(x_tf, X_DIR, X_STP, state[0]);
  step(y_tf, Y_DIR, Y_STP, state[1]);
  step(z_tf, Z_DIR, Z_STP, state[2]);
   
   
  //run functions
  //step(x_tf, X_DIR, X_STP, 200);
  //step(y_tf, Y_DIR, Y_STP, 200);
  //step(z_tf, Z_DIR, Z_STP, 200); 
  /*
    step (false, X_DIR, X_STP, 200); // X axis motor reverse 1 ring, the 200 step is a circle.
    //delay (1000);
    step (false, Y_DIR, Y_STP, 200); // y axis motor reverse 1 ring, the 200 step is a circle.
    step (false, Z_DIR, Z_STP, 200); // z axis motor reverse 1 ring, the 200 step is a circle.
    delay (1000);
    
    step (true, X_DIR, X_STP, 200); // X axis motor forward 1 laps, the 200 step is a circle.
    //delay (1000);
    step (true, Y_DIR, Y_STP, 200); // y axis motor forward 1 laps, the 200 step is a circle.
    step (true, Z_DIR, Z_STP, 200); // z axis motor forward 1 laps, the 200 step is a circle.
    delay (1000);
   */
    
    //save to lastArray
    /*
    lastArray[0]=ypr[0];
    lastArray[1]=ypr[1];
    lastArray[2]=ypr[2];
    */
  
   //delay(2000);
} 

