#include <iostream>


//前項聲明

//class template 
template<typename C>
class Vector;


//function template 
template<typename C>
Vector<C> operator+(const Vector<C>& v1, const Vector<C>& v2);

template<typename C>
std::ostream& operator<<(std::ostream& os,const Vector<C>& v);

/*
 * Class Vector Declaration
*/


template<typename C>
class Vector 
{
    double X,Y;

public:

    //
    inline Vector(const double x , const double y);

    C x() const 
    {
        return x;
    }
    
    C y() const 
    {
        return y;
    }

    friend Vector<C> operator+ <C>(const Vector<C>&v1 ,const Vector<C>& v2);
    friend std::ostream& operator<<(std::ostream& os, const Vector<C>& v)
    {
        
        os << v.X << '\t' << v.Y << '\n';

        return os; 
    }
};



//模板函數定義

//Constructor 沒有返回類別
template<typename C>
inline Vector<C>::Vector(const double x, const double y)
    {
        X = x;
        Y = y;
    }



//類外定義函數

template <typename C>
inline Vector<C> operator+(const Vector<C>& v1,const Vector<C>& v2)
{
    return  Vector<C>(v1.X+v2.X,v1.Y+v2.Y);

}




