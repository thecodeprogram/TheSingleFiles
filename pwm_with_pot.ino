/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 17.04.2020
*/


//First we declare the pins which we are going to make connections
//We will use the pwm_pin to sent the pwm signal out.
#define pwm_pin  1
#define analog_pin  A0
//Then we are going to declare our value variables. In these example we are going to declare two variables
//One of the is to hold analog value from potansiometer the other one is to hold pwm value.
int analog_value;
int pwm_value;

void setup() {
  // At setup section We have to set the pwm_pin as OUTPUT.
  //We will send the pwm signal via specified pin.
   pinMode(pwm_pin, OUTPUT);

   //And to print pwm value via serial port
   //we should enable the serial port 
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //First we have to read the analog value through potansiometer.
  //We will use this value to set the pwm value.
  analog_value = analogRead(analog_pin);

  //We will use the map function to scale the analog value
  //and set the pwm value variable. 
  //Analogwrite function makes the analog pwm output between 0 and 255
  //So here we will scale the analog value between 0 and 1023 to 
  //0 to 255.
  pwm_value = map(analog_value, 0, 1023, 0, 255);
  //With analogWrite function we will set the prepared pwm output
  //signals via the specified pwm_pin.
  analogWrite(pwm_pin, pwm_value);
  //Also we will write the value to the serial port to check
  //what is going on.
  Serial.println(pwm_value);
  delay(1);
}
