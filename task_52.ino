
//
class pedestrianlight{
  public:
  	int p_greenLed;
    int p_redLed;
	
	pedestrianlight(){
    	p_greenLed = 13;
    	p_redLed = 11; 
    }
  void setup(){
    
		pinMode(p_greenLed, OUTPUT);
   	 	pinMode(p_redLed, OUTPUT);
    	
    	Serial.begin(115200);
  }
  void pedestrianRedOn(){
  	digitalWrite(p_redLed,HIGH);
  
  }
  void pedestrianRedOff(){
  	digitalWrite(p_redLed,LOW);
    
  }
  void pedestrianGreenOn(){
  	digitalWrite(p_greenLed,HIGH);
  
  }
  void pedestrianGreenOff(){
  	digitalWrite(p_greenLed,LOW);
  }
};

//object
pedestrianlight signal;

void setup()
{
  signal.setup();
}
void loop()
{
   char data = Serial.read();
  switch(data){
  	case 'R':
    	signal.pedestrianRedOn();
    	break;
    case 'r':
    	signal.pedestrianRedOff();
    	break;
    case 'G':
    	signal.pedestrianGreenOn();
    	break;
    case 'g':
    	signal.pedestrianGreenOff();
    	break;
    default:
    	break;
  }
}