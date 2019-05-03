#ifndef Cells_H
#define Cells_H

class Cells{

  private:
    long int cols;
    long int rows;
  public:
    float *data;

  public:
    Cells(long int cols, long int rows);
    ~Cells();
    void rules(float *output, long int cols, long int rows);
    float chkNeighb(long int iy, long int ix);

};

#endif
