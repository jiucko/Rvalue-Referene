#include <memory>
#include <iostream>
#include <vector>
using namespace std;
class MyString
{
private:
	char* _data;
	size_t _length;
	void _init_data(const char* s)
	{
		_data = new char[_length + 1];
		memcpy(_data, s, _length);
		_data[_length] = '\0';
	}
public:
	//default constructor
	MyString()
	{
		cout << "default constructor" << endl;
		_data = NULL;
		_length = 0;	
	}
	//destructor
	~MyString()
	{
		_data = NULL;
		_length = 0;
	}
	//constructor
	MyString(const char *s)
	{
		cout << "constructor" << endl;
		_length = strlen(s);
		_init_data(s);	
	}
	//copy constructor
	MyString(const MyString& s)
	{
		cout << "copy constructor" << endl;
		_length = s._length;
		_init_data(s._data);
		
	}
	//copy assignment 
	MyString& operator=(const MyString& s)
	{
		cout << "copy assignment" << endl;
		_length = s._length;
		_init_data(s._data);

		return *this;
	}
	//move constructor
	MyString(MyString&& s)
	{
		cout << "move constructor" << endl;
		_length = s._length;
		_init_data(s._data);
		 
		s._length = 0;
		s._data = NULL;
		
	}
	//move assignment
	MyString& operator=(MyString&& s)
	{
		cout << "move assignment" << endl;
		if (this != &s)
		{
			_length = s._length;
			_init_data(s._data);

			s._length = 0;
			s._data = NULL;
		}
		return *this;
	}
};


int main()
{
	//MyString str("Hello World!!");
	//MyString str1(str);
	//MyString str2 = str;
	//str2 = str1;
	//
	MyString a;
	a = MyString("Hello");

	vector<MyString> vec;
	vec.push_back(MyString("World"));

	return 0;
}
