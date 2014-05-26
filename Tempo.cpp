#ifndef TEMPO_H
#define TEMPO_H

class Tempo{
      int s;
      int h;
      int m;     
public:
      // Tempo();
      Tempo(int H);
      // Tempo(int H,int M);
      // Tempo(int H,int M, int S);
      int returnInt();
      void adds(int S); 
      void addm(int M);
      void addh(int H);
      int gets(); 
      int getm();
      int geth();
         
};

int Tempo::gets(){
    return s;
} 
int Tempo::getm(){
    return m;
}
int Tempo::geth(){
    return h;
}

void Tempo::addh(int H){
    h+=H;   
}
void Tempo::addm(int M){
    for(int i = 0; i<=M; i++){
          if(m==60){
                    addh(1);
                    m=0;
          }
          m++;
    }   
}
void Tempo::adds(int S){
    for(int i = 0; i<=S; i++){
          if(s==60){
                    addm(1);
                    s=0;
          }
          s++;
    }
}

int Tempo::returnInt(){
    return (s)+(m*60)+(h*60*60);   
}

// Tempo::Tempo(){
// s=0;
// h=0;
// m=0;
// }

Tempo::Tempo(int H){
s=0;
h=H;
m=0;
}

// Tempo::Tempo(int H,int M){
// s=0;
// h=H;
// m=M;
// }

// Tempo::Tempo(int H, int M, int S){
// s=S;
// h=H;
// m=M;
// }

#endif