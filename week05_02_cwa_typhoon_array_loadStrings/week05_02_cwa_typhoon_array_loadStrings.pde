int N=299;
PImage [] imgs=new PImage[299];
void setup(){
  size(800,800);
  String[] filenames=loadStrings("list.txt");
  for(int i=0;i<N;i++){
    imgs[i]=loadImage(filenames[i]);
  }
}
void draw(){
  background(imgs[frameCount%N]);
}
