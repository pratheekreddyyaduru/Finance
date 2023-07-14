#include <BleKeyboard.h> // Include the BleKeyboard library

//Initiating the pins and states
const int LED_Pin=2; //To detect connectivity status
const int but_1=23; //Volume down  or cam shutter
const int but_2=5; //Volume up or cam shutter
const int but_3=4; //Call pick/drop and media play/pause
int button_state1=0; //Status of but_1
int button_state2=0; //Status of but_2
int button_state3=0; //Status of but_3

BleKeyboard bleKeyboard; // Create an instance of the BleKeyboard class

void setup() {

  Serial.begin(115200); // Start the serial communication with a baud rate of 115200
  pinMode(LED_Pin,OUTPUT); // Instantiating connectivity LED

  //Declaring inout buttons
  pinMode(but_1,INPUT);
  pinMode(but_2,INPUT);
  pinMode(but_3,INPUT);

  Serial.println("Starting BLE work!"); // Print a message to the serial monitor
  bleKeyboard.begin(); // Begin the BLE keyboard
}

void loop() {
  if(bleKeyboard.isConnected()) { // Check if the keyboard is connected
    digitalWrite(LED_Pin,HIGH); //To show bluetooth is active

  // First button functionality
    button_state1=digitalRead(but_1);
    if(button_state1==1){
      Serial.println("Sending  VolumeD/shutter..."); // Print a message to the serial monitor
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN); // Send the Volume down key to the connected device       
    }

  // Second button functionality
    button_state2=digitalRead(but_2);
    if(button_state2==1){
      Serial.println("Sending VolumeU/shutter..."); // Print a message to the serial monitor
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP); //Send Volume up key to the connected device
    }

  // Third button functionality
    button_state3=digitalRead(but_3);
    if(button_state3==1){
      Serial.println("Sending play or pick..."); // Print a message to the serial monitor
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE); //Send Play/pick and Pause/drop to connected device
    }
    
  
  }
  delay(1000); // Wait for a second
}