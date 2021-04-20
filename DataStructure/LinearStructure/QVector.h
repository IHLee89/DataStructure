#pragma once
#include "Allocator/QAllocator.h"

namespace std
{
	template <class _Ty>
	class QVectorIterator
	{
	public:
		QVectorIterator(_Ty* _ptr = nullptr)
			: pos(_ptr)
		{}

	public:
		inline _Ty& operator*()
		{
			return *pos;
		}

		inline int operator-(const QVectorIterator& _iter)
		{
			return pos - _iter.pos;
		}

		inline QVectorIterator& operator++()
		{
			++pos;
			return *this;
		}

		inline QVectorIterator operator++(_Ty)
		{
			QVectorIterator temp(*this);
			++pos;
			return temp;
		}

		inline bool operator==(const QVectorIterator& _other)
		{
			return pos == _other.pos;
		}

		inline bool operator!=(const QVectorIterator& _other)
		{
			return pos != _other.pos;
		}

	private:
		_Ty* pos;
	};

	template <class _Ty, class _Alloc = QAllocator<_Ty>>
	class QVector
	{
	public:
		QVector()
		{}

		QVector(initializer_list<_Ty> _initList, const _Alloc& _alloc = _Alloc())
		{}

		QVector(size_t _size, const _Ty& _val)
		{}

	};
}