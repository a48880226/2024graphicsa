void setup(){
  size(400,600);
  c=new PVector(200,100);
  p=new PVector(200,130);
}
PVector c,p;
void draw(){
  background(255);
  ellipse(c.x,c.y,10,10);
  ellipse(p.x,p.y,10,10);
}
