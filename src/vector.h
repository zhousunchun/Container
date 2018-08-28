#ifndef  VECTOR_H
#define  VECTOR_H

#include <iostream>
#include <cassert>
#include <cmath>
#include <complex>

template <typename  Type>
class Vector{
public:
    typedef Type* iterator;
    typedef const Type* const_iterator;

    Vector();
    Vector(const Vector<Type> &v);
    Vector(int length, const Type &x= Type(0));
    Vector(int length, const Type *array);
    ~Vector();
    //assignments
    Vector<Type> &operator = (const Vector<Type> &v);
    Vector<Type> &operator = (const Type &x);

    operator Type*();
    operator const Type*() const;

    //accessors
    Type & operator[](int i);
    const Type & operator[](int i) const;
    Type &operator() (int i);
    const Type &operator() (int i) const;

    // iterators
    iterator begin();
    const_iterator  begin() const;
    iterator end();
    const_iterator end() const;

    // others
    int size() const;
    int dim() const;
    Vector<Type> &resize(int length);

    // computed assignment
    Vector<Type> & operator += (const Type &);
    Vector<Type> & operator -= (const Type &);
    Vector<Type> & operator *= (const Type &);
    Vector<Type> & operator /= (const Type &);
    Vector<Type> & operator += (const Vector<Type> &);
    Vector<Type> & operator -= (const Vector<Type> &);
    Vector<Type> & operator *= (const Vector<Type> &);
    Vector<Type> & operator /= (const Vector<Type> &);
private:
    // data pointer for 0-offset indexing
    Type *pv0;
    Type *pv1;
    int nRow;
    void init(int length);
    void copyFromArray(const Type *v);
    void setByScalar(const Type &x);
    void destroy();
};


template <typename  Type>
void Vector<Type>::init(int length) {

    pv0 = new Type[length];
    assert(pv0 != nullptr);
    pv1 = pv0 - 1;
    nRow = length;
}

template <typename Type>
inline  void Vector<Type>::copyFromArray(const Type *v) {
    for(int i = 0; i<nRow; ++i)
    {
        pv0[0] = v[i];
    }
}

template <typename Type>
inline void Vector<Type>::setByScalar(const Type &x) {
    for(int i=0; i<nRow; ++i)
        pv0[i] = x;
}


template <typename Type>
void Vector<Type>::destroy() {
    if(pv0 == nullptr)
        return ;
    delete [] pv0;

    pv0 = nullptr;
    pv1 = nullptr;
}

template <typename Type>
Vector<Type>::Vector() :pv0(0), pv1(0),nRow(0)
{}

template <typename Type>
Vector<Type>::Vector( const Vector<Type> &v)
        :pv0(0),pv1(0),nRow(0)
{
    init(v.nRow);
    copyFromArray(v.pv0);
}

template <typename Type>
Vector<Type>::Vector(int length, const Type &x)
{
    init(length);
    setByScalar(x);
}

template <typename Type>
Vector<Type>::Vector(int length, const Type *array)
{
    init(length);
    copyFromArray(array);
}

template <typename Type>
Vector<Type>::~Vector() {
    destroy();
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector<Type> &v)
{
    if(pv0 == v.pv0)
        return *this;
    if(nRow == v.nRow)
        copyFromArray(v.pv0);
    else
    {
        destroy();
        init(v.nRow);
        copyFromArray(v.pv0);
    }
    return *this;
}

template <typename  Type>
inline Vector<Type>& Vector<Type>::operator=(const Type &x)
{
    setByScalar(x);
    return *this;
}

template <typename Type>
inline Type& Vector<Type>::operator[](int i)
{
#ifndef BOUNDS_CHECK
    assert(0<=i);
    assert(i<nRow);
#endif
    return pv0[i];
}

template <typename Type>
inline const Type& Vector<Type>::operator[](int i) const
{
#ifndef BOUNDS_CHECK
    assert(0<i);
    assert(i<nRow);
#endif

    return pv0[i];
}

template <typename Type>
inline const Type& Vector<Type>::operator() (int i) const
{
#ifndef BOUNDS_CHECK
    assert(0<i);
    assert(i<nRow);
#endif

    return pv0[i];
}

template <typename Type>
inline Type& Vector<Type>::operator() (int i)
{
#ifndef BOUNDS_CHECK
    assert(0<i);
    assert(i<nRow);
#endif

    return pv0[i];
}

/*
 * Iterators
 */
template <typename  Type>
inline typename Vector<Type>::const_iterator Vector<Type>::begin() const {
    return pv0;
}

template <typename Type>
inline typename Vector<Type>::iterator Vector<Type>::begin() {
    return pv0;
}


template <typename Type>
inline typename Vector<Type>::const_iterator Vector<Type>::end() const {
    return pv0+nRow;
}

template <typename Type>
inline typename Vector<Type>::iterator Vector<Type>::end() {
    return pv0+nRow;
}


template <typename  Type>
inline int Vector<Type>::size() const
{
    return nRow;
}

template <typename Type>
inline int Vector<Type>::dim() const {
    return nRow;
}

template <typename Type>
Vector<Type> &Vector<Type>::resize(int length) {
    if(nRow == length)
        return *this;
    destroy();
    init(length);
    return *this;
}

/*
 * Type conversion functions
 *
 */

template <typename Type>
inline Vector<Type>::operator Type*()
{
    return pv0;
}

template <typename Type>
inline Vector<Type>::operator const Type*() const
{
    return pv0;
}

#endif