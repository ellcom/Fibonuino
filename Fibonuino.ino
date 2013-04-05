//  Blink the fibinacci sequence to Meeh!
//  Elliot Adderton (elliot@ellcom.net) [http://ellcom.net]
//  April 2013 (V1)



// Define the LED pin
unsigned const int led = 13;
// Set up the vars for the fib seq & sort the base case
unsigned long last = 2;
unsigned long lastlast = 1;

void setup() {                
  pinMode(led, OUTPUT);
  Serial.begin(9600); 
}


void loop() {
  // Short 3sec delay before we get going
  delay(3000);
  
  // Base Case f(1) and f(2).
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
  // case 2
  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
  delay(1000); 
  
  // The rest of the cases
  for(;;){
    last = last+lastlast;
    lastlast = last-lastlast;
    
    Serial.print("Last-Last: ");
    Serial.print(lastlast);
    Serial.print(", Last: ");
    Serial.println(last);
    
    digitalWrite(led, HIGH);
    for(int i=0; i<last; i++){
      delay(1000);
    }
    digitalWrite(led, LOW);
    delay(1000); 
  }
}

// If you didn't understand what just happened read "The C Programming Language" by Kerighan and Richie
