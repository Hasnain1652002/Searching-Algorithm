#include <iostream>
using namespace std;

int Linearsearch(int array[],int sizeA,int value){
    for(int i=0; i<sizeA; i++){
        if (array[i]  == value) return i;
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
    result = Linearsearch(array,sizeA,value);
    if(result == -1){
            cout<<"The value you enter is not present in your list";
        }else{  
            cout<<array[result]<<" is present at index "<<result+1<<endl;
        }

    return 0;
}