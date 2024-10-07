void setup(){
  size(400,600);
}
float x=200,y=300;
void draw(){
  background(255);
  stroke(0);
  line(200,100,x,y);
  ellipse(x,y,30,30);
  stroke(255,0,0);
  line(x,y,x,y+100);
  PVector d=new PVector(x-200,y-100).normalize();
  PVector d2=new PVector(0,1);
  float g=PVector.dot(d,d2);
  d.mult(100*g);
  stroke(0,255,0);
  line(x,y,x+d.x,y+d.y);
  PVector N=PVector.sub(d2.mult(100),d);
  stroke(0,0,255);
  line(x,y,x+N.x,y+N.y);
  v.x+=N.x/1000;
  v.y+=N.y/1000;
  x+=v.x;
  y+=v.y;
}
PVector v=new PVector();
void mouseDragged(){
  x=mouseX;
  y=mouseY;
}
