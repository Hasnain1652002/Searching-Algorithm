// For Binary Search data must be sorted
#include <iostream>
using namespace std;

int Binarysearch(int array[],int sizeA,int value){
    int Start = 0;
    int End = sizeA;

    while (Start<=End){
        int Mid = (Start+End)/2;

        if (array[Mid] == value){ 
            return Mid;
        }else if (array[Mid] > value){ 
            End = Mid-1;
        }else {
            Start = Mid+1; 
        }      
    }

    return -1;
}

int main (){
    int sizeA;
    cout<<"Input Size of Array : ";
    cin>>sizeA;

    int array[sizeA];
    for(int i=0; i<sizeA; i++){
        cout<<"Element # "<<i+1<<" : ";
        cin>>array[i];
    }

    int value;
    cout<<"Input value : ";
    cin>>value;

    int result;
    result = Binarysearch(array,sizeA,value);
    if(result == -1){
            cout<<"The value you enter is not present in your list";
        }else{  
            cout<<array[result]<<" is present at index "<<result+1<<endl;
        }

    return 0;
}