#include <iostream>
#include <cassert>
using namespace std;

namespace AED {

	template <class T>
	class sll_node_t {
	private:
		T              data_;
		sll_node_t<T>* next_;

	public:
		sll_node_t(void);
		sll_node_t(T data);
		~sll_node_t(void);

		void set_next(sll_node_t<T>* next);
		sll_node_t<T>* get_next(void) const;

		void set_data(const T& data);
		const T& get_data(void) const;

		ostream& write(ostream& os) const;
	};

	template <class T>
	sll_node_t<T>::sll_node_t():
	data_(),
	next_(NULL)
	{}

	template <class T>
	sll_node_t<T>::sll_node_t(T data) :
	data_(data),
	next_(NULL)
	{}

	template <class T>
	sll_node_t<T>::~sll_node_t(void) 
	{
		next_ = NULL;
	}

	template <class T>
	void sll_node_t<T>::set_next(sll_node_t<T>* next)
	{
		next_ = next;
	}

	template <class T>
	sll_node_t<T>* sll_node_t<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	void sll_node_t<T>::set_data(const T& data)
	{
		data_ = data;
	}

	template <class T>
	const T& sll_node_t<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	ostream& sll_node_t<T>::write(ostream& os) const
	{ return os << data_ << " ";
	}


  template<class T>
  class sll_q_t
  {
    private:
    sll_node_t<T>* head_;
    sll_node_t<T>* tail_;
    
    public:
    sll_q_t(void): head_(NULL), tail_(NULL) {}
    ~sll_q_t(void) {
      while (!empty()) {
		    sll_node_t<T>* aux = head_;
		    head_ = head_->get_next();
		    delete aux;
		  }
    }
    
    bool empty(void) const { return head_ == NULL; }
    sll_node_t<T>* head(void) const { return head_; }
    sll_node_t<T>* tail(void) const { return tail_; }
    
    void insert_tail(sll_node_t<T>* n) 
    { 
	if (tail_ != NULL) {
        tail_ -> set_next(n);
        tail_ = n;
      }
      else head_ = tail_ = n;
    }
    
    sll_node_t<T>* extract_head(void) 
    { assert(!empty());
      sll_node_t<T>* n = head_;
      head_ = head_->get_next();
      if (empty()) tail_ = NULL;
      return n;
    }
     
    ostream& write(ostream& os) const
    { sll_node_t<T>* aux = head_;
      while (aux != NULL) {
		    aux->write(os);
		    aux = aux->get_next();
		  }
		  os << endl;
		  return os;
	  }  
  };
  
  template<class T>
  class queue_sll_q_t
  {
    private:
    sll_q_t<T>    queue_;
    
    public:
    queue_sll_q_t(void): queue_() {}
    ~queue_sll_q_t(void) {}
    
    bool empty(void) const { return queue_.empty(); }
    
    void push(const T& d)
    { sll_node_t<T>* n = new sll_node_t<T>(d);
      queue_.insert_tail(n);
    }
    
    void pop(void)
    { 
	delete queue_.extract_head();
    }
    
    const T& front() { return queue_.head()->get_data(); }
    const T& back()  { return queue_.tail()->get_data(); }
    
    ostream& write(ostream& os = cout) { return queue_.write(os); }
    
  };
} // namespace AED


int main()
{ AED::queue_sll_q_t<int> Q;

  for (int i = 1; i <= 7; i++) {
    Q.push(i);
    cout << "Cola: ";
    Q.write();
  }

  cout << "front: " << Q.front() << endl;
  cout << "back: " << Q.back() << endl;
  
  while (!Q.empty()) {
    cout << "Cola: ";
    Q.write();
    Q.pop();
  }
  
  return 0;
}
