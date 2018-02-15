#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
template <class T>
class graf
{
public:
    graf(string s)
    {
        n=s.size();
        names=s;
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
        cout<<" ";
        //for(int r=0;r<names.size();r++)
        for(int r:names)
            cout<<names[r];
        cout<<'\n';
        for(int i=0;i<n;i++)
        {
            cout<<names[i];
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
    void randfilling()
    {
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                if(i==k)
                    ndgraf[i][k]=0;
                else{ndgraf[i][k]=rand()%2;}
            }

        }
    }
private:
    T **ndgraf,n;
    string names;

};
int main()
{
    srand(time(0));
    string s;
    cout<<"names"<<'\n';
    cin>>s;
    graf<int> A(s);
    //A.setgraf();
    A.randfilling();
    A.showgraf();
    return 0;
}









