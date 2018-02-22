#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
///praise the god's objects
template <class T>
class graf
{
public:
    graf(string s)
    {
        bool hey=0;
        size_t pos=s.find(" -o");
        if ( pos!= std::string::npos)
            {
                 isOrGraf=1;
                 s.erase(pos,pos+2);
            }
        else
            isOrGraf=0;
                 pos=s.find(" -h");
        if ( pos!= std::string::npos)
            {
                 hey=1;
                 s.erase(pos,pos+2);
            }


        n=s.size();
        names=s;
        adjacMatrix=new T*[n];
        for(int i=0;i<n;i++)
        {
           adjacMatrix[i]=new T[n];
        }
        //nullfilling();
        hey==1 ? setgraf() : randfilling() ; }

    graf(graf *A)//copy constructor
    {
        this->names=(*A).names;
        n=this->names.size();
        adjacMatrix=new T*[n];
        for(int i=0;i<n;i++)
        {
           adjacMatrix[i]=new T[n];
        }
        copyAdjm(A);

    }
//************************************************
    ~graf()
    {
        for(int i=0;i<n;i++)
        {
            delete []adjacMatrix[i];
        }
        delete []adjacMatrix;
    }
//************************************************
    void showgraf()
    {
        cout<<" ";
        for(unsigned int r=0;r<names.size();r++)
            cout<<"  "<<names[r];
        cout<<'\n';
        for(int i=0;i<n;i++)
        {
            cout<<names[i];
            for(int k=0;k<n;k++)
            {
                cout.width(3);
                cout<<adjacMatrix[i][k];
            }
            cout<<'\n';
        }
    }
//************************************************
    void setgraf()      {for(int i=0;i<n;i++){for(int k=0;k<n;k++){cin>>adjacMatrix[i][k];}}}
    void copyAdjm(graf *A)     {for(int i=0;i<n;i++){for(int k=0;k<n;k++){this->adjacMatrix[i][k]=(*A).adjacMatrix[i][k];}}}
    void nullfilling()  {for(int i=0;i<n;i++){for(int k=0;k<n;k++){adjacMatrix[i][k]=0;}}}
    void randfilling()  {for(int i=0;i<n;i++){for(int k=0;k<n;k++){
        if(i==k)
            adjacMatrix[i][k]=0;
        else{adjacMatrix[i][k]=rand()%2;}}}
    if(!isOrGraf)
    equaling();
    }
//************************************************

    void pavingWay(int length)
    {

        graf<T> B(this);
        int start=rand()%B.names.size();
        int i=start;
        cout<<names[i];
        for(int l=0;l<length;l++)
        {
            pair<int,int> a[B.n];
            int k=0,kmod=0;
            for(int j=0;j<B.n;j++)
            {
               if(B.adjacMatrix[i][j]!=0)
                {
                    bool piy_piy=0;
                    a[k].first=j;
                    a[k].second=B.adjacMatrix[i][j];
                    for(int fu=j-1;fu>-1;fu--)
                    {
                        if(B.adjacMatrix[i][j]==B.adjacMatrix[i][fu])
                            piy_piy=1;
                    }
                    if(piy_piy==0)
                        kmod++;
                    k++;
                    }
            }
            int conn=k;
            int hconn=(kmod/2)+kmod%2;
            //int maax=0;unsigned int miin=-1;
            pair<int,unsigned int> mimax[hconn];
            //find 1,2,3... min and max
            for(int j=0;j<hconn;j++)
            {
                mimax[j].first=0;mimax[j].second=-1;
                for(k=0;k<conn;k++)
                {
                    if(a[k].second>mimax[j].first)
                        {
                            j==0 ? mimax[j].first=a[k].second :
                            a[k].second<mimax[j-1].first?  mimax[j].first=a[k].second :k=k ;
                        }
                    if(a[k].second<mimax[j].second)
                        {
                            j==0 ? mimax[j].second=a[k].second :
                            a[k].second>mimax[j-1].second ? mimax[j].second=a[k].second :k=k ;
                        }
                }
            }
            //swap
            for(int j=0;j<hconn;j++)
            {
                for(k=0;k<conn;k++)
                {
                    bool iu=0;
                    if(a[k].second==mimax[j].first) {a[k].second=mimax[j].second;iu=1;}
                    if(a[k].second==mimax[j].second&&iu==0){a[k].second=mimax[j].first;}
                }
            }
            int summ=0;
            for(k=0;k<conn;k++)
                summ+=a[k].second;
            kmod=rand()%summ+1;
            //cout<<endl<<kmod<<"/"<<summ+1<<endl;
            bool left_toe=0;summ=0;
            for(k=0;k<conn&&left_toe==0;k++)
            {
                summ+=a[k].second;
                if(summ>=kmod)
                    left_toe=1;
            }
            k--;
            cout<<names[a[k].first];
            B.adjacMatrix[i][a[k].first]++;
            B.adjacMatrix[a[k].first][i]++;
            i=a[k].first;
            //B.showgraf();
        }
        cout<<endl;
    }
private:

    void equaling()     {for(int i=0;i<n;i++){for(int k=i;k<n;k++){adjacMatrix[k][i]=adjacMatrix[i][k];}}}
    T **adjacMatrix;int n;
    string names;
    bool isOrGraf;

};
int main()
{
    //while(true)
    srand(time(0));
    string s;
    getline(std::cin,s);
    graf<int> A(s);
    //A.showgraf();
    while(true)
    {A.pavingWay(rand()%6+4);
    Sleep(2000);}


    return 0;
}
