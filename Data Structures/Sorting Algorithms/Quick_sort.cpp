#include<iostream>
using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[],int low, int high){
    int pivot = array[high];
    int i = low-1;

    for (int j=low; j<high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);  
    return i + 1;
}
void quicksort(int array[],int low,int high){

    if(low<high){
        int q = partition(array,low,high);
        quicksort(array,low,q-1);  // left
        quicksort(array,q+1,high); // right
    }

}

int main(){
    
    cout << "Enter the size of the array: ";
    int size; cin >> size;
    int array[size];
    cout << "Enter integers in any order: ";
    for(int i=0; i<size; i++){
        cin >> array[i];
    }
    cout << "Before sorting: \n";
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";

    quicksort(array,0,size-1);

    cout << "After sorting: \n";
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}
