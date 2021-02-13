#include <bits/stdc++.h>
using namespace std;


class my_vector{

    private:
    int *data=new int[1000];
    int len=0;
    int default_size=1000;
    int l_c=0;

    public:

    my_vector(int size){
        len=size;
        delete [] data;
        data=new int[size];
    }

    my_vector(){
      len=default_size;
    }


    void resize_cap(int n_l){
        int *tmp_data=new int[n_l];
        for(int i=0;i<l_c;i++)tmp_data[i]=data[i];
        delete[] data;
        data=tmp_data;
    }

    int get_size(){
        return l_c;
    }


    void push(int v){
        if(l_c==len){
            resize_cap(len*2);
        }
        data[l_c++]=v;
    }

    void pop_back(){
        if(l_c==0){
            cout<<"Fatal Error Empty Vector";
            return ;
        }
        l_c--;
    }

    void print_vector(){
        for(int i=0;i<l_c;i++){
            cout<<data[i]<<" "; 
        }
        cout<<endl;
    }
};


int main(){
    my_vector x=my_vector(25);
    x.push(6);
    x.push(7);
    x.pop_back();
    x.push(9);
    x.print_vector();

    

}
