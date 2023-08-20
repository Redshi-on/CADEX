#include <iostream>
#include <iomanip>
#include "3d.h"
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <memory>
using namespace std;



int main(){
    int n, sum = 0;
    n = 10;

    vector<Graph*> vec;
    vector<Circle*> cir;
    for (auto i=0; i < n; i++){
        
        vec.push_back(new Circle(rand()%5,rand()%5,rand()%5));
        vec.push_back(new Ellipse(rand()%5,rand()%5,rand()%5,rand()%5));
        vec.push_back(new Spin(rand()%5,rand()%5,rand()%5,rand()%5,rand()%5));
    }
    for(auto& ps : vec){
        ps->Point(M_PI/4);
        ps->derivative(M_PI/4);
        const type_info& ti{typeid(*ps)};
        if ( ti.hash_code() == typeid(Circle).hash_code()){
            cir.push_back(dynamic_cast<Circle*>(ps));
        }
        
    }

    sort(cir.begin(),cir.end(),[](const auto& lh, const auto& rh)
    {
        return lh->rd() < rh->rd();
    });

    for(auto& ps : cir){
        ps->show();
        sum += ps->rd(); 
    }

    cout<<"Sum radius = "<<sum<<endl;
    return 0;
} 

