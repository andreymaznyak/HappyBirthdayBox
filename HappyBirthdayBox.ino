#define l5  0b00111110
#define l4  0b00111100
#define l3  0b00001110
#define l2  0b00111000
#define i1  0b00001010
#define i2  0b00010010
#define i3  0b00100010
#define t0  0b00000010
#define t1  0b00000100
#define t2  0b00001000
#define t3  0b00010000
#define t4  0b00100000
#define e1  0b00101010
#define d1  0b00110000
#define d2  0b00011110
#define d3  0b00010010
#define y1  0b00011010
#define y2  0b00101110
#define b1  0b00111010

#define param_mas_size(x) x, sizeof(x)

#define led(str, col)  PORTB = 0x00; PORTC = 0x00; PORTD = 0x00; PORTC = str & 0b00111111; PORTB = (((str & 0b11000000) >> 4)|((~col & 0b11000000) >> 6)); PORTD = (~col << 2) 

#define Delay(x) _delay_ms(x)
#define SPEED 18


#define speakerPin 12

// note values for two octave scale
// divide them by powers of two to generate other octaves
#define __A     = 14080
#define __AS    = 14917.2
#define __B     = 15804.3
#define __C     = 16744
#define __CS    = 17739.7
#define __D     = 18794.5
#define __DS    = 19912.1
#define __E     = 21096.2
#define __F     = 22350.6
#define __FS    = 23679.6
#define __G     25087.7
#define __GS    26579.5
#define __A2    28160
#define __A2S   29834.5
#define __B2    31608.5
#define __C2    33488.1
#define __C2S   35479.4
#define __D2    37589.1
#define __D2S   39824.3
#define __E2    42192.3
#define __F2    44701.2
#define __F2S   47359.3
#define __G2    50175.4
#define __G2S   53159
#define __A3    56320

//octaves  - corresponds to piano octaves
//float oct8 = 4;
//float oct7 = 8;
//float oct6 = 16;
//float oct5 = 32;
#define oct4 64
//float oct3 = 128;
#define oct2 256
//float oct1 = 512;
//float oct0 = 1024;

//rhythm values
//int wh = 1024;
//int h  = 512;
//int dq = 448;
//int q = 256;
//int qt = 170;
//int de = 192;
//int e = 128;
//int et = 85;
//int dsx = 96;
//int sx = 64;
//int thx = 32;

// major scale just for demo, hack this




void playTone(int tone, int duration) {

  PORTB = 0b00000011;
  
  for (long i = 0; i < duration * 1000L; i += tone * 2) {

    PORTD = 0b11111100;
    PORTC = 0b00111100;
            
    digitalWrite(speakerPin, HIGH);

    delayMicroseconds(tone);

    PORTD = 0b00001111;
    digitalWrite(speakerPin, LOW);

    delayMicroseconds(tone);

  }

}

void playNote(char note, int duration) {

  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',

                  'c', 'd', 'e', 'f', 'g', 'a', 'b',

                  'x', 'y'
                 };

  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                  956,  834,  765,  593,  468,  346,  224,

                  655 , 715
                };

  int SPEE = 5;

  // play the tone corresponding to the note name

  for (int i = 0; i < 17; i++) {

    if (names[i] == note) {
      int newduration = duration / SPEE;
      playTone(tones[i], newduration);

    }

  }

}

void sound_HappyBithday() {


  int length = 28; // the number of notes

  char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

  int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16 };

  int tempo = 150;


  for (int i = 0; i < length; i++) {

    if (notes[i] == ' ') {
      
      delay(beats[i] * tempo); // rest
      
    } else {

      playNote(notes[i], beats[i] * tempo);

    }

    // pause between notes

    delay(tempo);

  }
}
struct mas {
  char * data;
  unsigned short int count;
};

char symbol_length(char symbol){
  if(symbol == 'd' || symbol == 'm'  || symbol == 'j' || symbol == 'i'){
     return 6;
  }else{
     return 4;
  }
     
}

struct mas get_char_mask(char symbol){
  struct mas result;
  switch(symbol) {
    case 'a': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l4;
      result.data[1] = i1;
      result.data[2] = l4;
      result.data[3] = 0x00;
      break;  
    case 'r': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = i1;
      result.data[2] = l3;
      result.data[3] = 0x00;
      break;
    case 'o': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = i3;
      result.data[2] = l5;
      result.data[3] = 0x00;
      break;
    case 'm': 
      result.count = 6;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = t1;
      result.data[2] = t2;
      result.data[3] = t1;
      result.data[4] = l5;
      result.data[5] = 0x00;
      break;
    case 'c': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = i3;
      result.data[2] = i3;
      result.data[3] = 0x00;
      break;
    case 'd': 
      result.count = 6;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = d1;
      result.data[1] = d2;
      result.data[2] = d3;
      result.data[3] = d2;
      result.data[4] = d1;
      result.data[5] = 0x00;
      break;        
    case 'n': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = t2;
      result.data[2] = l5;
      result.data[3] = 0x00;
      break;
    case 'j': 
      result.count = 6;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = t2;
      result.data[2] = l5;
      result.data[3] = t2;
      result.data[4] = l5;
      result.data[5] = 0x00;
      break;
    case 'e': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = e1;
      result.data[2] = e1;
      result.data[3] = 0x00;
      break;
    case 'i': 
      result.count = 6;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = t3;
      result.data[2] = t2;
      result.data[3] = t1;
      result.data[4] = l5;
      result.data[5] = 0x00;
      break;
    case 's': 
      result.count = 6;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = t4;
      result.data[2] = l5;
      result.data[3] = t4;
      result.data[4] = l5;
      result.data[5] = 0x00;
      break;
    case 't': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = t0;
      //result.data[1] = t0;
      result.data[1] = l5;
      //result.data[3] = t0;
      result.data[2] = t0;
      result.data[3] = 0x00;
      break;
    case 'q': 
      result.count = 6;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = t2;
      result.data[2] = l5;
      result.data[3] = i3;
      result.data[4] = l5;
      result.data[5] = 0x00;
      break;
    case 'l': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l4;
      //result.data[1] = t1;
      result.data[1] = t0;
      //result.data[3] = t1;
      result.data[2] = l4;
      result.data[3] = 0x00;
      break;
    case 'b': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = l5;
      result.data[1] = e1;
      result.data[2] = b1;
      result.data[3] = 0x00;
      break;          
    case 'y': 
      result.count = 4;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = y2;
      result.data[1] = y1;
      result.data[2] = l5;
      result.data[3] = 0x00;
      break;
    //case ' ':
    default :  
      result.count = 3;
      result.data = (char*) malloc (sizeof(char) * result.count);
      result.data[0] = 0x00;
      result.data[1] = 0x00;
      result.data[2] = 0x00;
      //result.data[3] = 0x00;
      break;
               
  }

  return result;
}

struct mas get_led_columns(char * string, char length_string){

   struct mas result;
   
   char count = 0;

   for(char i = 0; i < length_string; i++){
    count += symbol_length(string[i]);
   }
   
   char *mas = (char*) malloc (sizeof(char) * count);

   unsigned char current = 0; 
   for(char i = 0; i < length_string; i++){
    struct mas current_mask = get_char_mask(string[i]);
    for(char j = 0; j < current_mask.count; j++){
      mas[current] = current_mask.data[j];
      current++;
    }
    free(current_mask.data);
   } 
    
   result.data = mas;
   result.count = count; 
     
   return result;
}

void led_engine(struct mas mas){
  unsigned int cur_col = 0;
  unsigned int counter = 1;
  while(cur_col < mas.count){
    if(counter % SPEED == 0){
      cur_col++;
    }
    for(char cur_seq = 0; cur_seq < 8; cur_seq++){
      byte mask = (0x01 << cur_seq);
      led(mas.data[cur_col + cur_seq],mask);
      Delay(1);  
    }
    counter++;
  }
}

void led_string(char * string, char count){
  struct mas led_cols = get_led_columns(string, count);
  led_engine(led_cols);
  free(led_cols.data);
}
char notes[] = "EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb  GNFR E uaC aCD GNFR E 1 11   GNFR E uaC aCD L  D C   CC C CD EC ag  CC C CDE  CC C CD EC ag  EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb EC g u aF Fa  bAAAGFEC ag  EC g u aF Fa  bF FFEDCe ec  "; // a space represents a rest
float beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 1
                  2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 4, //Page 2
                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, //Page4
                  1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 5
                  1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2
                }; //Page 6

void sound_mario()
{
  // Mario
  
  /*
  * This example uses a piezo speaker to play melodies.  It sends
  * a square wave of the appropriate frequency to the piezo, generating
  * the corresponding tone.
  *
  * The calculation of the tones is made following the mathematical
  * operation:
  *
  *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
  *
  * where the different tones are described as in the table:
  *
  * note          frequency       period  timeHigh
  * c           261 Hz          3830  1915
  * d           294 Hz          3400  1700
  * e           329 Hz          3038  1519
  * f           349 Hz          2864  1432
  * g           392 Hz          2550  1275
  * a           440 Hz          2272  1136
  * b           493 Hz          2028  1014
  * C             523 Hz          1912  956
  *
  * http://www.arduino.cc/en/Tutorial/Melody
  */
  int tempo = 95;
  int length = 295; // the number of notes

  char names[] = {' ', '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'i', 'N', 'R', 'u',  '1', 'L', 'k'}; // [i = b flat] [N = G flat] [R = D#] [u = g#] [1 = C oct. 5] [L = E flat]
  int tones[] = {0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 329, 349, 391, 440, 493, 523, 587, 659, 698, 783, 880, 987, 466, 740, 622, 415, 1046, 622u, 227};
  PORTB = 0b00000011;
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      // play the tone corresponding to the note name
      for (int i_2 = 0; i_2 < 34; i_2++) {
        if (names[i_2] == notes[i]) {
          for (long i_3 = 0; i_3 < (beats[i] * tempo) * 1000L; i_3 += tones[i_2]) {
            PORTD = 0b11111100;
            PORTC = 0b00111100;
            //
            
            tone(speakerPin, tones[i_2]);
            delayMicroseconds(tones[i_2]);
            
            
            PORTD = 0b00001111;
            //delay(500);
            //PORTC = 0b00111100;
            //PORTB = 0x00;
          }
          noTone(speakerPin);
        }
      }
    }

    // pause between notes
    delay(tempo / 2);
  }
  //free(beats);
}


void setup()
{
  DDRD = 0b11111100;
  DDRC = 0b00111111;
  DDRB = 0b00111111;
  PORTD = 0b11111100;
  PORTC = 0b00111111;
  PORTB = 0b00001111;
  
}



void loop()
{
  led_string(param_mas_size(" roma c dnem rojdeniy"));
  sound_HappyBithday();  
  sound_HappyBithday(); 
  sound_HappyBithday(); 
  led_string(param_mas_size(" roma c dnem rojdeniy"));
  
  sound_mario();
  
}
