#include"Cells.hpp"
#include<omp.h>


Cells::Cells(long int cols, long int rows){

  this->cols=cols;
  this->rows=rows;
  this->data = new float[cols*rows];

}

Cells::~Cells(){
  delete [] this->data;

}

void Cells::rules(float *output, long int cols, long int rows){

  float neighbours=0;
  omp_set_num_threads(omp_get_max_threads());
  #pragma omp parallel for
  for(long int iy=1;iy<(rows-1);iy++){
    for(long int ix=1;ix<(cols-1);ix++){

      neighbours=chkNeighb(iy,ix);

      // 1.Any live cell with fewer than two live neighbours dies, as if
      // by underpopulation
      if(data[iy*cols + ix]==1.0 && neighbours<2.0){
        output[iy*cols + ix]=0.0;
      }

      // 2.Any live cell with two or three live neighbours lives on to
      // the next generation
      if(data[iy*cols + ix]==1.0 && (neighbours==2.0 || neighbours==3.0)){
        output[iy*cols + ix]=1.0;
      }

      // 3.Any live cell with more than three neighbours dies, as if by
      // overpopulation
      if(data[iy*cols + ix]==1.0 && neighbours>3.0){
        output[iy*cols + ix]=0.0;
      }

      // 4.Any dead cell with exactly three live neighbours becomes a
      // live cell, as if by reproduction
      if(data[iy*cols + ix]==0.0 && neighbours==3.0){
        output[iy*cols + ix]=1.0;
      }

    }

  }

}

float Cells::chkNeighb(long int iy, long int ix){

  float accum=0;

  if(data[(iy-1)*cols + (ix-1)]==1.0) accum+=1.0;
  if(data[(iy-1)*cols + ix]==1.0) accum+=1.0;
  if(data[(iy-1)*cols + (ix+1)]==1.0) accum+=1.0;

  if(data[iy*cols + ix-1]==1.0) accum+=1.0;
  if(data[iy*cols + ix+1]==1.0) accum+=1.0;

  if(data[(iy+1)*cols + (ix-1)]==1.0) accum+=1.0;
  if(data[(iy+1)*cols + ix]==1.0) accum+=1.0;
  if(data[(iy+1)*cols + (ix+1)]==1.0) accum+=1.0;

  return accum;
}
