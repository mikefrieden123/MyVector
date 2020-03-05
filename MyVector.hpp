/* Define all your MyVector-related functions here.
 * Also, define the swap function here.
 * You do not need to include the h file.
 * It included this file at the bottom.
 */

void get_identity(string &my_id)
{
  my_id = "mkf9mr";
}

template <typename T>
void MySwap(T &a, T &b)
{
  T temp;
  temp = a;
  a = b;
  b = temp;

  return;
}

template <typename T>
T & MyVector<T>::MyVector()
{
  m_data= nullptr;
  reserved_size = 0;
  data_size = 0;
}

// We're giving you this one for free
// and as a guide for the syntax.
template <typename T>
T & MyVector<T>::~MyVector()
{
    delete[] m_data;
}

template <typename T>
T & MyVector<T> & operator=(const MyVector<T> &source)
{
  if(this != source)
  {
    m_data = source.m_data;
  }
  return *this;
}

template <typename T>
T & MyVector<T>::MyVector(const MyVector<T> &source)
{
  MySwap(m_data, source.m_data)
  MySwap(data_size, source.data_size)    
}

template <typename T>
T & operator[](int i)
{
  return m_data[i];
}

// Another example: remember when writing an implementation in hpp,
// return type first, then scope just before the function name.
template <typename T>
T & MyVector<T>::at(int index)
{
    //Define the function here.
}

template <typename T>
T & MyVector<T>::front()
{
  return m_data[0];
}

template <typename T>
T & MyVector<T>::back()
{
  return m_data[data_size]; 
}

template <typename T>
T & MyVector<T>::int capacity()
{
  return reserved_size;
}

template <typename T>
T & MyVector<T>::void reserve(int new_cap)
{

}

template <typename T>
T & MyVector<T>::void shrink_to_fit()
{

}

template <typename T>
T & MyVector<T>::void assign(int count, const T &value)
{

}

template <typename T>
T & MyVector<T>::void clear()
{

}

template <typename T>
T & MyVector<T>::void push_back(const T &x)
{

}

template <typename T>
T & MyVector<T>::void pop_back()
{

}

template <typename T>
T & MyVector<T>::void insert(int i, const T &x)
{
  m_data[i] = x;
  data_size++;
}

template <typename T>
T & MyVector<T>::void erase(int i)
{

}

template <typename T>
T & MyVector<T>::int size()
{
  return data_size;
}

template <typename T>
T & MyVector<T>::int begin()
{
  return 0;
}

template <typename T>
T & MyVector<T>::int end()
{
  return size();
}
