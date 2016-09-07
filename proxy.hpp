#include<iostream>
#include<string>

using namespace std;

//  代理模式：远程代理 保护代理 虚拟代理 智能引用

class Image
{
public:
	Image(string name) : image_name(name) {}
	virtual ~Image() {}
	virtual void show() {}
protected:
	string image_name;
};

class BigImage : public Image
{
public:
	BigImage(string name) : Image(name) {}
	~BigImage() {} 
	void show() { cout << "bigimagename: " << image_name << endl; }
};

class ImageProxy : public Image
{
public:
	ImageProxy(string name) : Image(name), ptr_bigimage(0) {}
	~ImageProxy() { delete ptr_bigimage; }
	void show() { 
		if(ptr_bigimage == 0)
			ptr_bigimage = new BigImage(image_name);
		ptr_bigimage->show();
	}
private:
	BigImage *ptr_bigimage;
};



template<class T>
class auto_ptr
{
public:
	explicit auto_ptr(T *p = 0) : pointee(p) {}
	auto_ptr(auto_ptr<T>& rhs) : pointee(rhs.release()) {}
	~auto_ptr() { delete pointee; }
	auto_ptr<T>& operator=(auto_ptr<T> &rhs)
	{
		if(*this != rhs) reset(rhs.release());
		return *this;
	}
	
	T& operator*() const { return *pointee; }
	T* operator->() const { return pointee; }
	T* get() const {return pointee; }
	void reset(T *p = 0) 
	{
		if(pointee != p)	
		{
			delete pointee;
			pointee = p;
		}	
	}

	T* release()
	{
		T* newp = pointee;
		pointee = 0;
		return newp;
	}
private:
	T *pointee;
};

template<class T>
class smart_ptr
{
public:
	smart_ptr(T *p = 0) : pointee(p), use(new int(1)) {}
	smart_ptr(const smart_ptr<T> &rhs) : pointee(rhs.pointee), use(rhs.use)
	{ ++*use; }
	~smart_ptr() { decur(); }
	smart_ptr& operator=(const smart_ptr<T> &rhs)
	{
		++*use;
		decur();
		pointee = rhs.pointee;
		use = rhs.use;
		return *this;
	}
	T* operator->() { return pointee; }
	T& operator*() { return *pointee; }
	const T* operator->() const { return pointee; }
	const T& operator*() const { return *pointee; }
	
	void count() const { return *use; }
private:
	T *pointee;
	int *use;
	void decur()
	{
		if(--*use == 0)
		{
			delete use;
			delete pointee;
		}
	}
};



