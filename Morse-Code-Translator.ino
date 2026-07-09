const int button1=2;
const int button2=3;

unsigned long button1_pressStart;
unsigned long button1_pressRelease;
unsigned long button1_duration;

unsigned long button2_pressStart;
unsigned long button2_pressRelease;
unsigned long button2_duration;

unsigned long lastActionTime;

String MorseCode="";

bool submitted=false;

int previousButton1State=HIGH;
int previousButton2State=HIGH;

String currentLetter="";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);

  lastActionTime=millis();

  Serial.println("====================================");
Serial.println("      MORSE CODE TRANSLATOR");
Serial.println("====================================");
Serial.println("Button 1 : Enter dots and dashes");
Serial.println("  Short press -> .");
Serial.println("  Long press  -> -");
Serial.println();
Serial.println("Button 2 :");
Serial.println("  Short press -> End Letter");
Serial.println("  Long press  -> Space Between Words");
Serial.println();
Serial.println("Wait 4 seconds after your last input");
Serial.println("to automatically translate.");
Serial.println("====================================");
Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  int button1_read=digitalRead(button1);
  int button2_read=digitalRead(button2);

if (button1_read==LOW && previousButton1State==HIGH){
button1_pressStart=millis();
}


else if (button1_read==HIGH && previousButton1State==LOW){
  button1_pressRelease=millis();
  button1_duration=button1_pressRelease-button1_pressStart;

//Appending dots and dashes in MorseCode variable
if (button1_duration<=35){

}
else if (button1_duration>=100 && button1_duration<=250){
  MorseCode+=".";
  Serial.print(".");

}
else {
  MorseCode+="-";
  Serial.print("-");
}
lastActionTime=millis();
submitted=false;
}


if (button2_read==LOW && previousButton2State==HIGH){
  button2_pressStart=millis();

}
else if (button2_read==HIGH && previousButton2State==LOW){
  button2_pressRelease=millis();
  button2_duration=button2_pressRelease-button2_pressStart;

  if (button2_duration<35){

  }
  else if (button2_duration>=100 && button2_duration<=250){
    MorseCode+=" ";
    Serial.print(" ");
  }
  else{
    MorseCode+="/";
    Serial.print("/");
  }
  lastActionTime=millis();
  submitted=false;
}



if (!submitted && MorseCode != "" && millis()-lastActionTime>=5000){

  Serial.println();
  Serial.println("+++++++++++++++++++++++++++++");
  Serial.print("Translation:");


  String currentLetter = "";
  for (int i=0;i<MorseCode.length();i++){
    if (MorseCode.charAt(i)==' '){
      Serial.print(MorseCodeChar(currentLetter));
      currentLetter="";
      continue;


      }
    if (MorseCode.charAt(i)=='/'){
      Serial.print(" ");
      continue;
    }
    currentLetter+=MorseCode.charAt(i);

  }
  if (currentLetter!=""){
    Serial.print(MorseCodeChar(currentLetter));
  }
  Serial.println();
  Serial.println("+++++++++++++++++++++++++++++");

  lastActionTime=millis();
  submitted=true;
  MorseCode="";
}
previousButton1State=button1_read;
previousButton2State=button2_read;

}

char MorseCodeChar(String morse) {
  // Letters
  if (morse == ".-") return 'A';
  else if (morse == "-...") return 'B';
  else if (morse == "-.-.") return 'C';
  else if (morse == "-..") return 'D';
  else if (morse == ".") return 'E';
  else if (morse == "..-.") return 'F';
  else if (morse == "--.") return 'G';
  else if (morse == "....") return 'H';
  else if (morse == "..") return 'I';
  else if (morse == ".---") return 'J';
  else if (morse == "-.-") return 'K';
  else if (morse == ".-..") return 'L';
  else if (morse == "--") return 'M';
  else if (morse == "-.") return 'N';
  else if (morse == "---") return 'O';
  else if (morse == ".--.") return 'P';
  else if (morse == "--.-") return 'Q';
  else if (morse == ".-.") return 'R';
  else if (morse == "...") return 'S';
  else if (morse == "-") return 'T';
  else if (morse == "..-") return 'U';
  else if (morse == "...-") return 'V';
  else if (morse == ".--") return 'W';
  else if (morse == "-..-") return 'X';
  else if (morse == "-.--") return 'Y';
  else if (morse == "--..") return 'Z';

  // Numbers
  else if (morse == "-----") return '0';
  else if (morse == ".----") return '1';
  else if (morse == "..---") return '2';
  else if (morse == "...--") return '3';
  else if (morse == "....-") return '4';
  else if (morse == ".....") return '5';
  else if (morse == "-....") return '6';
  else if (morse == "--...") return '7';
  else if (morse == "---..") return '8';
  else if (morse == "----.") return '9';

  // Common punctuation
  else if (morse == ".-.-.-") return '.';   // Period
  else if (morse == "--..--") return ',';   // Comma
  else if (morse == "..--..") return '?';   // Question mark
  else if (morse == "-.-.--") return '!';   // Exclamation mark
  else if (morse == "-..-.") return '/';    // Slash
  else if (morse == "-.--.") return '(';    // Left parenthesis
  else if (morse == "-.--.-") return ')';   // Right parenthesis
  else if (morse == ".----.") return '\'';  // Apostrophe
  else if (morse == ".-..-.") return '"';   // Quotation mark
  else if (morse == "---...") return ':';   // Colon
  else if (morse == "-.-.-.") return ';';   // Semicolon
  else if (morse == "-...-") return '=';    // Equals
  else if (morse == ".-.-.") return '+';    // Plus
  else if (morse == "-....-") return '-';   // Hyphen
  else if (morse == "..--.-") return '_';   // Underscore
  else if (morse == ".--.-.") return '@';   // At sign

  return '\0'; // Unknown Morse code
}
