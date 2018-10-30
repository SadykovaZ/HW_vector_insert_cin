#include "vector_.h"
vector_::vector_()
{
	this->arr = nullptr;
	this->size = 0;
}
vector_::~vector_()
{
	if (arr != nullptr)
		delete[] arr;
	this->arr = nullptr;
	this->size = 0;
}
vector_::vector_(const vector_ & v)
{

	this->size = v.size;
	if (this->size == 0) {
		this->arr = nullptr;
		return;
	}

	this->arr = new int[this->size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = v.arr[i];
	}

}
vector_::vector_(int size, int element)
{
	if (size <= 0)
		return;
	this->arr = new int[size];
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = element;
	}

}

bool vector_::empty() const
{
	return size == 0;
}

int vector_::getSize() const
{
	return size;
}
void vector_::clear()
{
	this->~vector_();
}

void vector_::push_back(int number)
{
	int *tmp = new int[this->size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = this->arr[i];
	}
	tmp[size++] = number;
	delete[] this->arr;
	this->arr = tmp;
}
void vector_::pop_back()
{
	if (this->size <= 0) return;
	if (this->size == 1) {
		this->~vector_();
		return;
	}

	int *tmp = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size--;
}
void vector_::erase(int index)
{
	if (this->size <= 0 || index < 0 || index >= this->size) return;

	int *tmp = new int[size - 1];
	for (int i = 0, j = 0; i < size - 1; i++, j++)
	{
		if (i == index) j++;
		tmp[i] = this->arr[j];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size--;
}
void vector_::insert(int index, int number)
{
	if (this->size <= 0 || index < 0 || index >= this->size) return;
	int *tmp = new int[size + 1];
	for (int i = 0, j = 0; i < size + 1; i++, j++)
	{
		if (i == index)
		{
			tmp[i] = number;
			j--;
		}
		else tmp[i] = this->arr[j];
	}
	delete[] this->arr;
	this->arr = tmp;
	this->size++;
}

int& vector_::operator[](int index) const
{
	return this->arr[index];
}

vector_ & vector_::operator=(const vector_ & obj)
{
	//защита от самопросваивания
	if (this == &obj)
		return *this;
	//если в obj. ничего нет, очищаем себя и выхожим
	if (obj.size == 0)
	{
		this->clear();
		return *this;
	}

	//это условие отработает только в том случае если размеры отличаются
	if (this->size != obj.size)
	{
		this->clear();
		this->arr = new int[obj.size];
		this->size = obj.size;
	}
	for (int i = 0; i < obj.size; i++)
	{
		this->arr[i] = obj.arr[i];
	}

	return *this;
}

vector_::vector_(vector_ && v)
{
	this->arr = v.arr;
	this->size = v.size;
	v.arr = nullptr;
	v.size = 0;
}

vector_ & vector_::operator=(vector_ && v)
{
	this->~vector_();
	this->arr = v.arr;
	this->size = v.size;
	v.arr = nullptr;
	v.size = 0;

	return *this;
}

vector_ & vector_::operator+=(const vector_ & v)
{
	if (v.getSize == 0) return *this;
	
	int *newArr = new int[this->size + v.size];
	for (size_t i = 0; i < this->size; i++)
	{
		newArr[i] = this->arr[i];
	}
	for (size_t i = 0, k=this->size; i < this->size; i++,k++)
	{
		newArr[k] = v.arr[i]; 
	}
	delete[]this->arr;
	this->arr = newArr;
	this->size += v.size;
	return *this;
}

ostream & operator<<(ostream & os, const vector_ & v)
{

	for (size_t i = 0; i < v.getSize(); i++)
	{
		os << v[i] << " ";
	}
	return os;
}

istream & operator>>(istream & is, vector_ & v)
{
	for (size_t i = 0; i < v.getSize(); i++)
	{
		is >> v[i];
	}
	return is;
}

vector_ operator+(const vector_ & a, const vector_ & b)
{
	vector_ n = a;
	n += b;
	return std::move(n);
}
