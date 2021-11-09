#pragma once
#include<iostream>
#include<assert.h>
#include<algorithm>
#include<string>
namespace mzp
{

	template<class T>
	class vector
	{
	
	
		
	public:
		typedef T* iterator;
		typedef T* const_iterator;
		iterator begin()
		{
			return _strat;
		}

		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _strat;
		}

		const_iterator end() const
		{
			return _finish;
		}
		
		//构造函数
		vector()
			:_strat(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		// 析构函数
		~vector()
		{
			delete[] _strat;
			_strat = _finish = _endofstorage = nullptr;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}


			if (n < size())
			{
				_finish = _strat + n;
			}
			else
			{
				while (_finish != _strat + n)
				{
					*_finish = val;
					++_finish;
				}

			}
		}
		

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* temp = new T[n];
				/*memcpy(temp, _strat, sizeof(T)*size());*/

				//下面的for循环为类型萃取技术--模板的特化
				for (size_t i = 0; i < sz; i++)
				{
					temp[i] = _strat[i];
				}
				delete[] _strat;

				_strat = temp;
				_finish = _strat + sz;
				_endofstorage = _strat + n;
			}
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _strat [pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _strat[pos]
		}



		size_t size()
		{
			return _finish - _strat;
		}


		size_t capacity()
		{
			return _endofstorage - _strat;
		}

		void  checkcapacity()
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
		}

		void push_back(const T& x)
		{
			checkcapacity();

			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(_finish > _strat);
			--_finish;
		}
		void insert(iterator& pos, const T& x)
		{
			assert(pos >= _strat && pos <= _finish);
				//增容时可能会造成迭代器失效，使pos失效
				size_t posi = pos - _strat;
				checkcapacity();
				pos = posi + _strat;
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;

			}
			*pos = x;
			_finish++;

		}

		void erase(iterator pos)
		{
			assert(pos >= _strat&&pos < _finish);
			auto it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			--_finish;
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_strat(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(last - first);
			while (first!=last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_strat,v._strat);
			std::swap(_finish,v._finish);
			std::swap(_endofstorage,v._endofstorage);

		}


		vector(const vector<T>& v)
			:_strat(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector temp(v.begin(), v.end());
			swap(temp);
		}

		vector<T>& operator=(vector<T> v)
		{
			this->swap(v);
			return *this;

		}
	private:
		iterator _strat;
		iterator _finish;
		iterator _endofstorage;
	};
}