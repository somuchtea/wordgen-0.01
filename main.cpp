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
        size_t pos=s.find(" -o");
        if ( pos!= std::string::npos)
            {
                 isOrGraf=1;
                 s.erase(pos,pos+2);
            }
        else
            isOrGraf=0;




        n=s.size();
        names=s;
        adjacMatrix=new T*[n];
        for(int i=0;i<n;i++)
        {
           adjacMatrix[i]=new T[n];
        }
        nullfilling();
    }
    ~graf()
    {
        for(int i=0;i<n;i++)
        {
            delete []adjacMatrix[i];
        }
        delete []adjacMatrix;
    }
    void showgraf()
    {
        cout<<" ";
        for(int r=0;r<names.size();r++)
            cout<<names[r];
        cout<<'\n';
        for(int i=0;i<n;i++)
        {
            cout<<names[i];
            for(int k=0;k<n;k++)
            {
                cout<<adjacMatrix[i][k];
            }
            cout<<'\n';
        }
    }
    void setgraf()      {for(int i=0;i<n;i++){for(int k=0;k<n;k++){cin>>adjacMatrix[i][k];}}}
    void nullfilling()  {for(int i=0;i<n;i++){for(int k=0;k<n;k++){adjacMatrix[i][k]=0;}}}
    void randfilling()  {for(int i=0;i<n;i++){for(int k=0;k<n;k++){
        if(i==k)
            adjacMatrix[i][k]=0;
        else{adjacMatrix[i][k]=rand()%2;}}}
    if(!isOrGraf)
    equaling();
    }
private:
    void equaling()     {for(int i=0;i<n;i++){for(int k=i;k<n;k++){adjacMatrix[k][i]=adjacMatrix[i][k];}}}
    T **adjacMatrix,n;
    string names;
    bool isOrGraf;

};
int main()
{
    while(true)
    {srand(time(0));
    string s;
    getline(std::cin,s);
    graf<int> A(s);
    A.randfilling();
    A.showgraf();}
    return 0;
}









