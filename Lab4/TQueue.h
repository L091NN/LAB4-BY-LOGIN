#ifndef __TQUEUE_H__
#define __TQUEUE_H__

template <class ElemType>
class TQueue
{
	long long int push_index;
	long long int pop_index;
	int full_size;
	ElemType *Data;
public:
	TQueue(int size = 100)
	{
		full_size = size;
		push_index = 0;
		pop_index = 0;
		Data = new ElemType[full_size];
		for (int i = 0; i < full_size; i++)
		{
			Data[i] = {};
		}
	}
	TQueue(const TQueue &Q)
	{
		full_size = Q.full_size;
		push_index = Q.push_index;
		pop_index = Q.pop_index;
		for (int i = 0; i < full_size; i++)
		{
			Data[i] = Q.Data[i];
		}

	}
	~TQueue()
	{
		delete[]Data;
	}
	bool is_empty()
	{
		if (push_index == pop_index) return 1;
		return 0;
	}
	bool is_full()
	{
		if (pop_index + full_size - 1 == push_index) return 1;
		return 0;
	}
	void push(ElemType Elem)
	{
		if (is_full) throw ("Queue is full!");
		Data[push_index++ % full_size] = Elem;
	}
	ElemType pop()
	{
		if (is_empty)throw ("Queue is empty!");
		return Data[pop_index++ % full_size];
	}
	ElemType top()
	{
		if (is_empty)throw ("Queue is empty!");
		return Data[pop_index % full_size];
	}
	int Get_full_size()
	{
		return full_size;
	}
	int size()
	{
		return push_index - pop_index;
	}
	TQueue<ElemType>& operator=(const TQueue <ElemType> &Q)
	{
		if (this != &Q)
		{
			if (full_size != Q.full_size)
			{
				delete[]Data;
				full_size = Q.full_size;
				Data = new ElemType[full_size];
			}
			push_index = Q.push_index;
			pop_index = Q.pop_index;
			for (int i = 0; i < full_size; i++)
			{
				Data[i] = Q.Data[i];
			}

		}

		return *this;
	}
};


#endif
