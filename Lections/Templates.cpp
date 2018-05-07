#include <iostream>

using namespace std;

class CPoint
{
public:
	CPoint(int a, int b):x_(a),y_(b)
	{
		
	}
	CPoint(const CPoint& point):x_(point.x_),y_(point.y_)
	{
		cout << "Copied" << endl;
	}
	int X() const
	{
		return x_;
	}
	int Y() const
	{
		return y_;
	}
private:
	int x_;
	int y_;
};
bool operator>(const CPoint& a,const CPoint& b)
{
	int la = a.X()*a.X() + a.Y()*a.Y();
	int lb = b.X()*b.X() + b.Y()*b.Y();
	return (la > lb);
}
ostream& operator<<(ostream& str, const CPoint& a)
{
	str <<"Point: "<< a.X() << " " << a.Y();
	return str;
}

template<class T>
const T& max(const T& a,const T& b)
{
	return(a > b) ? a : b;
}

template<class T>
class CStack
{
private:
	T* array;
	size_t size_;
	size_t capacity_;
public:
	CStack(size_t capacity):capacity_(capacity), size_(0)
	{
		array = new T[capacity];
	}
	void push(T& val)
	{
		array[size_] = val;
		size_++;
		if(size_==capacity_)
		{
			T* arr = new T[2 * capacity_];
			memcpy(arr, array, size_);
			delete[]array;
			array = arr;
			capacity_ *= 2;
		}
	}
	T pop() const
	{
		

		size--;
		return array[size_+1];
	}
	bool empty() const
	{
		return size_ == 0;
	}
	~CStack()
	{
		delete[] array;
	}
};


int main()
{
	cout << max(2, 5)<<endl;
	CPoint p1(10, 5);
	CPoint p2(5, 8);
	cout << max<float>(20.1f, 5)<<endl;
	max(p1, p2);
	cout << max(p1, p2) << endl;

	system("pause");
}
