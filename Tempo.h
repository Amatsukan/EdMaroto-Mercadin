#ifndef TEMPO_H
#define TEMPO_H

class Tempo{
private:
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

#endif