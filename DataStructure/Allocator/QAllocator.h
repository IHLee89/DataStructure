#pragma once
#include <cstddef>
#include <iostream>

namespace std
{
	template <typename Ty>
	class QAllocator
	{
	public:
		static_assert(!is_const_v<Ty>, "const 템플릿 타입은 사용할 수 없습니다");
	
		using value_type = Ty;

		// 아래 항목 없어도 빌드 됨
		//using void_pointer = void*;
		//using const_void_pointer = const void*;
		//using size_type = size_t;
		//using difference_type = ptrdiff_t;	// pointer간 거리 (x86 int, x64 long long)
		//constexpr QAllocator(const QAllocator&) noexcept = default;
	
		// C++ 17 부터 사용 중지 권고
		//using pointer = Ty*;
		//using const_pointer = const Ty*;
		//using reference = Ty&;
		//using const_reference = const Ty&;
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
		Ty* allocate(const size_t _count)
		{
			std::cout << "allocate " << _count << std::endl;
			return static_cast<Ty*>(operator new(sizeof(Ty) * _count));
		}
	
		void deallocate(Ty* const _ptr, const size_t _count)
		{
			std::cout << "deallocate " << _count << std::endl;
			operator delete(_ptr);
		}
	
		size_t max_size() const noexcept { return static_cast<size_t>(-1) / sizeof(Ty); }

		template <class _Objty, class... _Types>
		void construct(_Objty* const _ptr, _Types&&... _args)
		{
			std::cout << "construct " << *_ptr << " " << _Objty(forward<_Types>(_args)...) << std::endl;
			new (_ptr) _Objty(forward<_Types>(_args)...);
		}

		template <class _Objty>
		void destroy(_Objty* const _ptr)
		{
			std::cout << "destroy " << *_ptr << std::endl;
			_ptr->~_Objty();
		}

		//bool operator==(const allocator<Ty>& _other)
		//{
		//	return true;
		//}
		//
		//bool operator!=(const allocator<Ty>& _other)
		//{
		//	return false;
		//}
	};
}