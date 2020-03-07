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
MyVector<T>::MyVector()
{
  //Default contents to nullptr and reserve and size to 0
  m_data= nullptr;
  reserved_size = 0;
  data_size = 0;
}

// We're giving you this one for free
// and as a guide for the syntax.
template <typename T>
MyVector<T>::~MyVector()
{
    //Delete vector
    delete[] m_data;
}

template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
{
  //Check to make sure not making it equal to itself
  if(this != &source)
  {
    //Change size to size of input
    data_size = source.data_size;
    reserved_size = 2*data_size;

    //Delete current
    delete[] m_data;
  
    m_data = new T[data_size];

    //Iterate through for deep copy
    for(int i = 0; i < data_size; i++)
    {
      m_data[i] = source.m_data[i];
    }
  }
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
  //Assign data size to size of source and modify reserve
  data_size = source.data_size;
  reserved_size = data_size*2;

  //Iterate through for deep copy
  for(int i = 0; i < data_size; i++)
  {
    m_data[i] = source.m_data[i];
  }    
}

template <typename T>
T & MyVector<T>::operator[](int i)
{
  //Return object at i
  return m_data[i];
}

// Another example: remember when writing an implementation in hpp,
// return type first, then scope just before the function name.
template <typename T>
T & MyVector<T>::at(int index)
{
  //Check to see if within range
  if(index >= data_size || index < 0)
  {
    //Throw exception if out of range
    throw std::out_of_range("MyVector<T>::at() index is out of range");
  }
  else
  {
    //Return what's at index
    return m_data[index];
  }
}

template <typename T>
T & MyVector<T>::front()
{
  //Return the first element
  return m_data[0];
}

template <typename T>
T & MyVector<T>::back()
{
  //Return the last element
  return m_data[data_size]; 
}

template <typename T>
int MyVector<T>::capacity()
{
  //Return the maximum capacity
  return reserved_size;
}

template <typename T>
void MyVector<T>::reserve(int new_cap)
{
  //Increase maximum capacity to new value
  if(reserved_size < new_cap)
  {
    reserved_size = new_cap;
  }
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
  //Adjust reserve size to 2x data size
  reserved_size = data_size*2;
}
template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
  //Delete old array
  for(int i = 0; i < data_size; i++)
  {
    m_data[i] = nullptr;
  }

  //Adjust size to count
  data_size = count;
  
  //Adjust reseve size
  reserved_size = (count*2);
  
  //Assign each element to value
  for(int j = 0; j < data_size; j++)
  {
    m_data[j] = value;
  }    
}

template <typename T>
void MyVector<T>::clear()
{
  //Assign each element to nullptr
  for(int i = 0; i < data_size; i++)
  {
    m_data[i] = nullptr;
  }
  
  //Assign data_size to default
  data_size = 0;

  //Assign reserve size to default
  reserved_size = 0;
}

template <typename T>
void MyVector<T>::push_back(const T &x)
{
  //Increase size and reserve size
  data_size++;
  reserved_size = data_size*2;
  
  //Assign last value to x
  m_data[data_size - 1] = x;
}

template <typename T>
void MyVector<T>::pop_back()
{
  //Decrease size of array
  data_size--;

  //Adjust size of reserve
  reserved_size = data_size*2;
}

template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
  //Throw exception if input is out of range
  if(i >= data_size || i < 0)
  {
    throw std::out_of_range("MyVector<T>::insert() index is out of range");
  }
  else
  {
    //Increase size by 1 and adjust reserve size
    data_size++;
    reserved_size = data_size*2;

    //Shift elements right
    for(int j = data_size;j >= i; j--)
    {
      m_data[j] = m_data[j-1];
    }
    //Assign element to x
    m_data[i-1] = x;
  }    
}

template <typename T>
void MyVector<T>::erase(int i)
{
  //Throw exception if out of range
  if(i >= data_size || i < 0)
  {
    throw std::out_of_range("MyVector<T>::insert() index is out of range");
  }
  else
  {
    //Shift elements left
    for(int j = i; j < data_size; j++)
    {
      m_data[j] = m_data[j+1];
    }
    //Decrease size by 1
    data_size--;
    //Maintain reserve size 2x data size
    reserved_size = data_size*2;
  }
}

template <typename T>
int MyVector<T>::size()
{
  //Account for array starting at 0
  return data_size + 1;
}
