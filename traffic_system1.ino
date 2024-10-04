// C++ code
//
void setup()
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop()
{
  digitalWrite(4, HIGH);
  delay(30000); 
  digitalWrite(4, LOW);
  
  digitalWrite(5, HIGH);
  delay(3000); 
  digitalWrite(5, LOW);
  
  digitalWrite(6, HIGH);
  delay(30000); 
  digitalWrite(6, LOW);
}