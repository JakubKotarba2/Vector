// Vector.cpp

#include "Vector.h"

using namespace std;

Vector::Vector(int dimension)
    : dim(dimension) {
    if (dim < 1)
        dim = 1;
    x = new double[dim];
}

Vector::Vector(const Vector& v) {
    dim = v.dim;
    x = new double[dim];
    for (int i = 0; i < dim; i++) {
        x[i] = v.x[i];
    }

} 

Vector& Vector::operator=(const Vector& v) {
    if (dim != v.dim) {
        delete[] x;
        dim = v.dim;
        x = new double[dim];
    }
    for (int i = 0; i < dim; i++) {
        x[i] = v.x[i];
    }
    return *this;
} 

Vector::~Vector() {
    std::cout << "removing vector : " << *this << std::endl;
    delete[] x;
}
std::ostream& operator<< (std::ostream& out, const Vector& v) {
    out << "(";
    for (int i = 0; i < v.dim - 1; ++i) {
        out << v.x[i] << ", ";
    }
    out << v.x[v.dim - 1] << ")";
    return out;
}

Vector& Vector::operator + (Vector& v) {
     static Vector temp(3);

    for (int i = 0; i < dim; i++)
    {
        temp.at(i + 1) = at(i + 1) + v.at(i + 1);
    }
    return temp;
}

Vector& Vector::operator - (Vector& v) {
    static Vector temp(3);

    for (int i = 0; i < dim; i++)
    {
        temp.at(i + 1) = at(i + 1) - v.at(i + 1);
    }
    return temp;
}

Vector& Vector::operator * (Vector& v) {
    static Vector temp(3);
    static Vector sum(1);
    int sum1 = 0;
    for (int i = 0; i < dim; i++)
    {
        temp.at(i + 1) = at(i + 1) * v.at(i + 1);
        sum1 += temp.at(i + 1);
    }
    sum.at(1) = sum1;
    return sum;
}

Vector& Vector::operator() (Vector& v) {
    static Vector temp;
    temp = operator + (v) * operator - (v);
    return temp;
}

bool Vector::operator == (Vector& v) {
    for (int i = 0; i < dim; i++) {
        if (at(i + 1) != v.at(i + 1)) {
            return false;
        }
    }
    return true;
}

bool Vector::operator != (Vector& v) {
    for (int i = 0; i < dim; i++)
    {
        if (at(i + 1) != v.at(i + 1)) {
            return true;
        }
    }
    return false;
}

bool Vector::operator > (Vector& v) {
    if (this->at(1) > v.at(1))
        return true;
    else if (this->at(1) == v.at(1)) {
        if (this->at(2) > v.at(2))
            return true;
    }
    return false;
}
 
bool Vector::operator < (Vector& v) {
    if (this->at(1) < v.at(1))
        return true;
    else if (this->at(1) == v.at(1)) {
        if (this->at(2) < v.at(2))
            return true;
    }
    return false;
}
 
bool Vector::operator >= (Vector& v) {
    if (this->at(1) >= v.at(1))
        return true;
    else if (this->at(1) == v.at(1)) {
        if (this->at(2) >= v.at(2))
            return true;
    }
    return false;
}
 
bool Vector::operator <= (Vector& v) {
    if (this->at(1) <= v.at(1))
        return true;
    else if (this->at(1) == v.at(1)) {
        if (this->at(2) <= v.at(2))
            return true;
    }
    return false;
}

Vector& Vector::operator += (Vector& v) {
    for (int i = 0; i < dim; i++){
        this->at(i + 1) += v.at(i + 1);
    }
    return *this;
}

Vector& Vector::operator -= (Vector& v) {
    for (int i = 0; i < dim; i++) {
        this->at(i + 1) -= v.at(i + 1);
    }
    return *this;
}

Vector& Vector::operator *= (int v) {
    for (int i = 0; i < dim; i++) {
        this->at(i + 1) *= v;
    }
    return *this;
}

double& Vector::operator[] (int index) {
    return x[index - 1];
} 