const int RELAY_PIN1 = 2;  // the Arduino pin, which connects to the IN pin of relay
//const int RELAY_PIN2 =  4; 

String readString, A; 
// the setup function runs once when you press reset or power the board
void setup() 
{
  // initialize digital pin as an output.
  pinMode(RELAY_PIN1, OUTPUT);
  //pinMode(RELAY_PIN2, OUTPUT);
  Serial.begin(9600);
  //Serial.println("Enter millis in terms of 100, 200, 300, 400, 500, 600, 700, 800, 900 and 1000");
  //Serial.println("Enter millis for 2/2 and 3/2 separated by comma.");
  Serial.println("Enter 2/2 valve hold time (ms)");
}

// the loop function runs over and over again forever
void loop() 
{
  while (Serial.available()) {
    // Wait for User to Input Data
    delay(10); 
    if(Serial.available() >0){
      char c = Serial.read(); //getting one byte from a serial buffer
      readString += c; // make string readString
    }
  }

  if (readString.length() >0 ){
    Serial.println(readString); //display what was received
    A = readString.substring(0,4); //get the first four characters
    //B = readString.substring(5,8); // get the last three characters
    //printing what was received as values
    Serial.print("A:");
    Serial.println(A);  
    //Serial.print("B:"); 
    //Serial.println(B); 

    //Declaring all the info as numbers

    int n1; 
    //int n2; 

    char carray1[7]; 
    A.toCharArray(carray1, sizeof(carray1)); 
    n1 = atoi(carray1); 

    //char carray2[6]; 
    //B.toCharArray(carray2, sizeof(carray2)); 
    //n2 = atoi(carray2);
    Serial.print("n1:"); 
    Serial.println(n1);
    //Serial.print("n2:");
    //Serial.println(n2);
    
    digitalWrite(RELAY_PIN1, HIGH);
    delay(1000);
    digitalWrite(RELAY_PIN1, LOW);
    delay(n1);
    digitalWrite(RELAY_PIN1, HIGH);
    delay(500);
    digitalWrite(RELAY_PIN1, LOW);
    delay(n1);  
    digitalWrite(RELAY_PIN1, HIGH);
    delay(100);
    digitalWrite(RELAY_PIN1, LOW);
    delay(n1);
    digitalWrite(RELAY_PIN1, HIGH);
    delay(50);
    digitalWrite(RELAY_PIN1, LOW);
    readString="";
  }
  /*int A = Serial.parseInt();
  Serial.println(A);
  Serial.println(" ");
  //Read the data the user has input
  //Serial.read(); 
 // int A =  Serial.read(); 
  
  if( A>0 )
  {
  digitalWrite(RELAY_PIN, HIGH);
  delay(A);
  digitalWrite(RELAY_PIN, LOW);
  }*/
  
 
  
}
