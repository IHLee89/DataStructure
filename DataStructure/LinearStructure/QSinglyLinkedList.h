#pragma once

namespace std
{
	template<class _Ty>
	class QSinglyLinkedListNode
	{
		using node = QSinglyLinkedListNode<_Ty>;
	public:
		QSinglyLinkedListNode(const _Ty& _data, node* _ptr)
			: data(_data), next(_ptr)
		{}

	public:
		_Ty data;
		node* next;
	};

	template<class _Ty>
	class QSinglyLinkedListIterator
	{
	public:
		using node = QSinglyLinkedListNode<_Ty>;

	public:
		QSinglyLinkedListIterator(QSinglyLinkedListNode<_Ty>* _ptr = nullptr)
			: cur(_ptr)
		{}

	public:
		inline QSinglyLinkedListIterator& operator++() // 전위 연산자
		{
			cur = cur->next;
			return *this;
		}
		
		inline QSinglyLinkedListIterator operator++(_Ty) // 후위 연산자
		{
			node* temp = cur;
			cur = cur->next;
			return temp;
		}

		inline _Ty& operator*()
		{
			return cur->data;
		}

		inline bool operator==(const QSinglyLinkedListIterator& _other)
		{
			return cur == _other.cur;
		}

		inline bool operator!=(const QSinglyLinkedListIterator& _other)
		{
			return cur != _other.cur;
		}

	private:
		node* cur;
	};

	template<class _Ty>
	class QSinglyLinkedList
	{
	public:
		using iterator = QSinglyLinkedListIterator<_Ty>;
		using node = QSinglyLinkedListNode<_Ty>;

	public:
		QSinglyLinkedList()
			: head(nullptr)
		{}

		~QSinglyLinkedList()
		{
			while (head != nullptr)
			{
				pop();
			}
		}

	public:
		iterator push_front(const _Ty& _data)
		{
			head = new node(_data, head);
			return begin();
		}

		void pop_front()
		{
			if (head != nullptr)
			{
				pop();
			}
		}

		_Ty& front()
		{
			return *begin();
		}

		const _Ty& front() const
		{
			return *begin();
		}

		iterator begin() { return iterator(head); }
		iterator end() { return iterator(nullptr); }

	private:
		void pop()
		{
			node* front = head;
			head = head->next;
			delete front;
		}

	private:
		node* head;
	};
}