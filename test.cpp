#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int , int> mpp;
    mpp[4] = 4;  
    mpp[1] = 1;                                                                                                                     
    mpp[3] = 3; 
    mpp[2] = 2;  

    auto it = mpp.begin();

    while(it != mpp.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    cout<<endl;

    auto itt = --mpp.end();
    while(1) {
        if(itt == mpp.begin())
        {
            cout << itt->first << " " << itt->second << endl;
            break;
        }
        cout << itt->first << " " << itt->second << endl;
        itt--;
    }                            
                                                               
}