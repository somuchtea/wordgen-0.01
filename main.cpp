#include <iostream>
#include <vector>
using namespace std;
template <class T>
class graf
{
public:
    graf(int N)
    {
        n=N;
        ndgraf=new T*[n];
        for(int i=0;i<n;i++)
        {
           ndgraf[i]=new T[n];
        }
    }
    ~graf()
    {
        for(int i=0;i<n;i++)
        {
            delete []ndgraf[i];
        }
        delete []ndgraf;
    }
    void showgraf()
    {
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                cout<<ndgraf[i][k];
            }
            cout<<'\n';
        }
    }
    void setgraf()
    {
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                cin>>ndgraf[i][k];
            }

        }
    }
    void fsfilling()
     {
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                if(i==k)
                    ndgraf[i][k]=0;
                else{ndgraf[i][k]=1;}
            }

        }
    }

private:
    T **ndgraf,n;

};
int main()
{
    //int N;
    //cout<<"n"<<'\n';
    //cin>>N;
    vector<char*> v={"abcde"};
    //cout<<"names"<<'\n';
    //vert.push_back("abcde");
    for ( char* n : v ) {
        cout << n << '\n';
    }
    graf<bool> A(5);
    //A.setgraf();
    //A.fsfilling();
    //A.showgraf();
    return 0;
}









