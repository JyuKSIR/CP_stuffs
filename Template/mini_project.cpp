#include <iostream>
#include <chrono>
using namespace std;

#define time_now chrono::high_resolution_clock::now()

int main(){
    
    auto start = time_now;

    int vertices = 1000, x=3, a=0 , sum_of_out_degree=0, sum_of_in_degree=0;

    int directed_graph[vertices][vertices]={};

    for(int i=0; i<vertices; i++){

        for(int j=0; j<vertices; j++){

            a = ((7*x)+4)%9;

            x=a;
            
            directed_graph[i][j] += a%2;
        }
    }

    for(int i=0; i<vertices; i++){

        for(int j=0; j<vertices; j++){

            if(directed_graph[i][j]){

                sum_of_out_degree++;

            }
            if(directed_graph[j][i]){

                sum_of_in_degree++;

            }

        }
    }

    cout << "\nSum of in degrees: " << sum_of_in_degree << "\n";

    cout << "Sum of out degrees: " << sum_of_out_degree << "\n";

    if(sum_of_in_degree == sum_of_out_degree){

        cout << "Sum of in-degrees and Sum of out-degrees are equal" << "\n";
    }

    auto end = time_now;

    auto difference = chrono::duration <double, milli> (end-start).count();

    cout << "Time Taken: " << difference << "ms" << "\n";

    return 0;
}
