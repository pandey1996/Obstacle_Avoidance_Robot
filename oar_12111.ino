#include <FirebaseArduino.h>

#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "token_or_secret"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

int trigPin = 9;      
int echoPin = 10;     

int revleft4 = 4;       
int fwdleft5 = 5;       
int revright6 = 6;      
int fwdright7 = 7;      

long duration, distance;

void setup() {
  
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  delay(random(500,2000));   
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         
  pinMode(echoPin, INPUT);          
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58.2;   
  delay(10);
  if (distance > 19)            
  {
    digitalWrite(fwdright7, HIGH);                    
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(fwdright7, LOW);                  
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(500);
    digitalWrite(fwdright7, LOW);              
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    delay(500);
    digitalWrite(fwdright7, LOW);                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);  #include <FirebaseArduino.h>

#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "token_or_secret"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

int trigPin = 9;      
int echoPin = 10;     

int revleft4 = 4;       
int fwdleft5 = 5;       
int revright6 = 6;      
int fwdright7 = 7;      

long duration, distance;

void setup() {
  
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  delay(random(500,2000));   
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         
  pinMode(echoPin, INPUT);          
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58.2;   
  delay(10);
  
  if(Firebase.get("op")==0)
  {

    if (distance > 19)            
    {
        digitalWrite(fwdright7, HIGH);                    
        digitalWrite(revright6, LOW);
        digitalWrite(fwdleft5, HIGH);                                
        digitalWrite(revleft4, LOW);                                                       
    }

    if (distance < 18 )
    {
        digitalWrite(fwdright7, LOW);                  
        digitalWrite(revright6, LOW);
        digitalWrite(fwdleft5, LOW);                                
        digitalWrite(revleft4, LOW);
        delay(500);
        digitalWrite(fwdright7, LOW);              
        digitalWrite(revright6, HIGH);
        digitalWrite(fwdleft5, LOW);                                
        digitalWrite(revleft4, HIGH);
        delay(500);
        digitalWrite(fwdright7, LOW);                
        digitalWrite(revright6, LOW);
        digitalWrite(fwdleft5, LOW);                                
        digitalWrite(revleft4, LOW);  
        delay(100);  
        digitalWrite(fwdright7, HIGH);       
        digitalWrite(revright6, LOW);   
        digitalWrite(revleft4, LOW);                                 
        digitalWrite(fwdleft5, LOW);  
        delay(500);
    }
  }
  else
  {
      if(Firebase.get("left")==1)
      {
            Firebase.setFloat("right",0);
            digitalWrite(fwdright7, HIGH);       
            digitalWrite(revright6, LOW);   
            digitalWrite(revleft4, LOW);                                 
            digitalWrite(fwdleft5, LOW);  
            delay(500);
      }
      else if(Firebase.get("right")==1)
      {
            Firebase.setFloat("left",0);
            digitalWrite(fwdright7, HIGH);       
            digitalWrite(revright6, LOW);   
            digitalWrite(revleft4, LOW);                                 
            digitalWrite(fwdleft5, LOW);  
            delay(500);
      }
      else if(Firebase.get("left")==1 && Firebase.get("right")==1){
            digitalWrite(fwdright7, LOW);       
            digitalWrite(revright6, LOW);   
            digitalWrite(revleft4, LOW);                                 
            digitalWrite(fwdleft5, LOW);  
            delay(500);
      }
  }
}

    delay(100);  
    digitalWrite(fwdright7, HIGH);       
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft4, LOW);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(500);
  }

}
