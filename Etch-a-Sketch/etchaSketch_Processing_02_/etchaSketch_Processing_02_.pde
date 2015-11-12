import processing.serial.*;

float drawX;
float drawY;

color bgColor = color( 255 ); // background
color penColor = color( 255, 100, 20 ); // color pen

Serial myPort; // serial port

void setup() {
   size( 800, 600 );
   background( bgColor ); //background color
   noStroke(); 
   fill( penColor );

   drawX = width/2; 
   drawY = height/2; 

   println(Serial.list()); 
   myPort = new Serial(this, Serial.list()[1], 9600);
   myPort.bufferUntil('n');
}

void draw() {
  ellipse(drawX, drawY, 20, 20);
}

//plays whenever data is recived #loopit
void serialEvent(Serial p) {
  char n = 'n';
  
  String inString = p.readStringUntil(n); // read the string
  println( inString ); //Prints arduino serial info - before parsing
  
  String newString = inString.substring(0,inString.length()-1);
    newString += ':';

   int [] numbers = new int[2];
    String [] strs = split(newString,':');
    println(int(trim(strs[0])) ); //Prints arduino serial info - before parsing
    println( int(trim(strs[1])) ); //Prints arduino serial info - before parsing
    
    
  
    drawX = map( int(trim(strs[0])), 0, 1023, 0, width);
      //can't read the int(strs[0]
    
    drawY = map( int(trim(strs[1])), 0, 1023, 0, height);
  
  //Problem Area ------------------------------------

  /*for ( int i=0; i < pairs.length; i++) {
    String data[] = split(pairs[i], 'n'); 
    
    if ( data.length == 2 ) {  //Problem Area --reading as else not the if
      String xString = trim( data[0] ); 
      String yString = trim( data[1] );

      //Problem Area ------------------------------------
        int x = int(xString);
        drawX = map( x, 0, 1023, 0, width);
        int y = int(yString);
        drawY = map( y, 0, 1023, 0, height);
    }
    else
    { 
      println("Hello");
    }
  }*/
}

void clearDrawing() {
   background( bgColor );
}

//Reference
//https://processing.org/discourse/beta/num_1266984239.html