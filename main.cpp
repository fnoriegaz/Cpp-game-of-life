#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

#include "Cells.hpp"


int main(int argc, char *argv[]){
  std::cout<<"The Game Of Life"<<std::endl;
  long int cols=atoi(argv[1]);
  long int rows=atoi(argv[2]);
  long int nt=atoi(argv[3]);
  float  *output = new float[(long int)cols*rows*nt];

  std::ofstream fid;

  Cells myCells(cols,rows);

  //initialize seed
  for(int y=1;y<(rows-1);y++){
    for(int x=1;x<(cols-1);x++){
      if(x==y) myCells.data[x+y*cols]=1.0;
      if(x==(rows-y-1)) myCells.data[x+y*cols]=1.0;
    }
  }

  //Iterate to update matrix state according to the rules
  for(long int t=0;t<nt;t++){
    myCells.rules(output+t*cols*rows,cols,rows);
    memcpy(myCells.data,output+t*cols*rows,cols*rows*sizeof(float));
  }

  //Save volume of evolution
  fid.open("output.bin", std::ios_base::binary);
  fid.write((char *)(output),(long int)cols*rows*nt*sizeof(float));
  fid.close();

  delete [] output;
  return 0;
}
