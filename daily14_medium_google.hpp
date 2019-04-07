/*
This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.

Monte Carlo Method: https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/

*/

#include <iostream>
#include <math.h>

int main() {
  int sampleCount=10000;
  int interval=100;

  int inSquare=0, incCircle=0;

  float r = 10;

  srand(time(NULL));

  for(int j=0; j<interval;++j){
    for(int i=0; i<sampleCount;++i){
      float randomX = (rand()%101)/10.0;
      float randomY = (rand()%101)/10.0;

      float dist2Origin = std::sqrt((randomX*randomX) + (randomY*randomY));

      if(dist2Origin <= r){
        incCircle+=1;
      }

      inSquare+=1;
    }
  }
  
  std::cout<<"InCircle:"<<incCircle<<", InSquare:"<<inSquare<<std::endl;

  float pi = 4.0 * ((float)incCircle/inSquare);
  std::cout<<"Calculated pi="<<pi<<std::endl;

  return 0;
}
