void setup(){
  size(400,600);
}
float x=200,y=300;
void draw(){
  background(255);
  line(200,100,x,y);
  ellipse(x,y,30,30);
}
void mouseDragged(){
  x=mouseX;
  y=mouseY;
}
