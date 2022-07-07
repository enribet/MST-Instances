//include the libraries and the header files
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>

/*
given a file of a mst problem in .txt format,
this code reads the nominal costs and
generates the scenarios by adding to the vector of nominal
costs a random unit vector, multiplied by a scalar factor beta. We consider three such factors 1, 2,
and 3, and generate three different numbers of scenarios: 10, 100, and 1000.
*/

//start main.
int main(int argc, char** argv) {
    //ARGV list:
    //0: executable
    //1: input file
    //2: number of scenarios
    //3: beta
    //4: output (.txt) filename

    char * input_name = argv[1];
    ifstream read(input_name);
    int nnodes;
    int n;
    read >> nnodes;
    read >> n;
    double* costs=new double[n];
    for (int i=0;i<n;i++){
        read >> costs[i];
    }
    int num_c= atoi(argv[2]);
    int seed=2;
    int beta= atoi(argv[3]);
    char * output_name = argv[4];//name (with path) of the output
    ofstream write(output_name);
    write << n << " " << num_c << endl;
    int c=0;
    double creal=0.;
    int min=0;
    double *chi = new double[n];
    double sum=0.;
    srand(seed);


    double ll;


    //num_c scenarios
    for (int i=0;i<num_c;i++){
        sum=0;
        for (int j=0;j<n;j++){
            creal= costs[j];
            chi[j]=(1.*rand()/RAND_MAX)*2-1.;
            sum+=chi[j]*chi[j];
        }
        for (int j=0;j<n;j++){
            chi[j]/=sqrt(sum);
            creal= costs[j];
            creal+= 1.*chi[j]*beta;//scale by a factor
            write << creal << " ";
        }
        write << endl;
    }


    delete[] costs;
    write.close();


    delete[] chi;

    return 0;

}
//end main


