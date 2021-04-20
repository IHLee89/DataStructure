#pragma once
#include <cstddef>
#include <iostream>

namespace std
{
	template <typename _Ty>
	class QAllocator
	{
	public:
		static_assert(!is_const_v<_Ty>, "const ���ø� Ÿ���� ����� �� �����ϴ�");
	
		using value_type = _Ty;

		// �Ʒ� �׸� ��� ���� ��
		//using void_pointer = void*;
		//using const_void_pointer = const void*;
		//using size_type = size_t;
		//using difference_type = ptrdiff_t;	// pointer�� �Ÿ� (x86 int, x64 long long)
		//constexpr QAllocator(const QAllocator&) noexcept = default;
	
		// C++ 17 ���� ��� ���� �ǰ�
		//using pointer = _Ty*;
		//using const_pointer = const _Ty*;
		//using reference = _Ty&;
		//using const_reference = const _Ty&;
		//
		//template <typename U>
		//struct rebind {using other = QAllocator<U>};
		//
		//pointer allocate(size_type _count, const_void_pointer)
		//{
		//	return allocate(_count);
		//}
	public:
		constexpr QAllocator() noexcept {}
		template <class _Other>
		constexpr QAllocator(const QAllocator<_Other>&) noexcept {}
	
	public:
		size_t max_size() const noexcept { return static_cast<size_t>(-1) / sizeof(_Ty); }

		// �޸� ���� �Ҵ�
		_Ty* allocate(const size_t _count)
		{
			return static_cast<_Ty*>(operator new(sizeof(_Ty) * _count));
		}
	
		// �޸� ����
		void deallocate(_Ty* const _ptr, const size_t _count)
		{
			//std::cout << "deallocate " << _count << std::endl;
			operator delete(_ptr);
		}
	
		// ������ ȣ��
		template <class _Objty, class... _Types>
		void construct(_Objty* const _ptr, _Types&&... _args)
		{
			//std::cout << "construct " << *_ptr << " " << _Objty(forward<_Types>(_args)...) << std::endl;
			new (_ptr) _Objty(forward<_Types>(_args)...);
		}

		// �Ҹ��� ȣ��
		template <class _Objty>
		void destroy(_Objty* const _ptr)
		{
			//std::cout << "destroy " << *_ptr << std::endl;
			_ptr->~_Objty();
		}
	};
}