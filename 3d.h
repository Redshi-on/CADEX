#include <iostream>
#include <cmath>

using namespace std;


class Graph{
    protected:
        double Ox,Oy,Oz;
        char * name;
    public:
        Graph(){

        }
        Graph(double x, double y, double z, const char *n){
            Ox = x;
            Oy = y;
            Oz = z;
            name = (char*)n;
        }
        ~Graph(){
            cout<<"Освобождение памяти"<<endl;
        }
        virtual void show(){
            cout<<name<<'\t'<<Ox<<'\t'<<Oy<<'\t'<<Oz<<'\t';
        }
        virtual void derivative(double t){
            cout<<name<<" f' = "; 
        }
        virtual void Point(double t) = 0;
        


};

class Circle: public Graph{
    protected:
        double radius;
    public:
        Circle(): Graph(0,0,0,"circle"){
            radius = 0;
        }
        Circle(double x,double y, double r) : Graph(x ,y ,0.0 ,"circle"){
            radius = r;
        }
        void show(){
            Graph::show();
            cout<<radius<<endl;
        }
        void derivative(double t){
            Graph::derivative(t);
            cout<<"( "<<-radius*sin(t)<<"; "<<radius*cos(t)<<")"<<endl;
        }
        void Point(double t){
            cout<<radius*cos(t) + Ox<<endl<<radius*sin(t) + Oy<<endl;
        }
        double rd(){
            return radius;
        }
};


class Ellipse: public Graph{
    private:
        double radius_one, radius_two;
    public:
        Ellipse(): Graph(0,0,0,"Ellipse"){
            radius_one = 0;
            radius_two = 0;
        }
        Ellipse(double x, double y, double r1, double r2): Graph(x,y,0,"Ellipse"){
            radius_one = r1;
            radius_two = r2;
        }
        void show(){
            Graph::show();
            cout<<radius_one<<'\t'<<radius_two<<endl;
        }
        void derivative(double t){
            Graph::derivative(t);
            cout<<"( "<<-radius_one*sin(t)<<"; "<<radius_two*cos(t)<<")"<<endl;
        }
        void Point(double t){
            cout<<radius_one*cos(t) + Ox<<endl<<radius_two*sin(t) + Oy<<endl;
        }
};

class Spin: public Graph{
    private:
        double radius, step;
    public:
        Spin(): Graph(0,0,0,"Spin"){
            radius = step = 0;
        }
        Spin(double x, double y, double z, double r, double s) : Graph(x,y,z,"Spin"){
            radius = r;
            step = s;
        }
        void show(){
            Graph::show();
            cout<<radius<<'\t'<<step<<endl;
        }
        void derivative(double t){
            Graph::derivative(t);
            cout<<"( "<<radius*(cos(t) - t*sin(t))<<"; "<<radius*(sin(t)-t*cos(t))<<"; "<<step<<")"<<endl;
        }
        void Point(double t){
            cout<<radius * t * cos(t) + Ox<<endl<<radius * t * sin(t) + Oy<<endl<<step+Oz<<endl;
        }
};

