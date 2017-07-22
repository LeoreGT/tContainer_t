#include <vector>
#include <list>
#include <typeinfo>

using namespace std;

template<typename T, class Container = vector<T*> >
class tContainer_t
{
  public:
    tContainer_t()  {}
    ~tContainer_t() {}
    bool     isEmpty() const                   {return (!m_numOfElements);};
    size_t   countElements() const             {return m_numOfElements;};
    bool     insertToEnd(const T* _newElement);
    const T* returnFirst() const               {return *m_container.begin();};
    const T* returnLast()const                 {return *m_container.rbegin();};
    const T* findByValue(const T& _value) const;

    const T* remove(const T& _element);
    void     removeAll();
    bool     removeAndDelete(const T& _value);
    void     removeAndDeleteAll();
    const T* operator[](size_t _index); //only works for list, not vector

  private:
    Container m_container;
    size_t    m_numOfElements;

    tContainer_t(const tContainer_t& _existingContainer) {} //copy CTOR not allowed
    const tContainer_t& operator=(const tContainer_t& _existingContainer) {} //operator= not allowed

    template <class T1>
    class CheckValue //sub-class only needs CTOR
    {
      public:
        CheckValue(const T1& _val):m_value(_val){} //sub-class CTOR
        bool operator()(const T1* _val){return *_val == m_value;} //returns comparison, only overloadede in this sub-class

      private:
        const T1 m_value;
    };

    template <class T1>
    struct DeletePtr
    {
      void operator()(T1* _p){delete _p;}
    };
};

/* -------------------------------------------------------------------------- */

template <class T, class Container>
const T* tContainer_t<T, Container>::findByValue(const T& _value) const
{
  typename Container::const_iterator it = find_if(m_container.begin(), m_container.end(), CheckValue<T>(_value));
  if(it != m_container.end())
  {
    return *it;
  }
  else
  {
    return NULL;
  }
}

/* -------------------------------------------------------------------------- */

template <class T, class Container>
bool tContainer_t<T, Container>::insertToEnd(const T* _newElement)
{
  if (!_newElement)
  {
    return false;
  }

  m_container.push_back((T*)_newElement), m_numOfElements++;
  return true;
}

/* -------------------------------------------------------------------------- */

template <class T, class Container>
const T* tContainer_t<T, Container>::remove(const T& _element)
{
  T* searchPointer = NULL;      //will return NULL if not found
  typename Container::iterator currentIt = find_if(m_container.begin(), m_container.end(), CheckValue<T>(_element));
                                //input             start                     end           predicate

  if(currentIt != m_container.end()) //loop until end
  {
    searchPointer = *currentIt;
    m_container.erase(currentIt);
    m_numOfElements--;
  }
  return searchPointer;              //return pointer of removed value
}

/* -------------------------------------------------------------------------- */

template <class T, class Container>
void tContainer_t<T, Container>::removeAll()
{
  m_container.clear();
  m_numOfElements = 0;
  // int i;
  // typename Container::const_iterator currentIt = m_container.begin();         //start at the front
  // for(i = 0; i < countElements() && currentIt != m_container.end(); ++i) //go over all iterators
  // {
  //   remove((const T*)&currentIt);
  // }
}

/* -------------------------------------------------------------------------- */

template <class T, class Container>
bool tContainer_t<T, Container>::removeAndDelete(const T& _value)
{
  const T* ptr = remove(_value);
  if(ptr)
  {
    delete ptr;
  }
  return (ptr == NULL) ? false : true;
}

/* -------------------------------------------------------------------------- */

template <class T, class Container>
void tContainer_t<T, Container>::removeAndDeleteAll()
{
  removeAll();
  for_each(m_container.begin(), m_container.end(), DeletePtr<T>());
}

/* -------------------------------------------------------------------------- */

template <class T, class Container>
const T* tContainer_t<T, Container>::operator[](size_t _index)
{
  int i;
  T* result;
  if (_index >= countElements())
  {
    return NULL;
  }

  if (typeid(m_container) == typeid(list<T*>))
  {
    typename Container::const_iterator currentIt = m_container.begin();
    for(i = 0; i < _index; ++i)
    {
      ++currentIt;
    }
    if(currentIt != m_container.end())
    {
      result = *currentIt;
    }
  }
  return result;
}

/* -------------------------------------------------------------------------- */
