#ifndef VECTOR_H
#define VECTOR_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

// iterator, will rename later if needed


namespace custom
{
    template <class T>
    class vector
    {
        #ifdef UNIT_TESTING
        friend int ::main(int argc, const char* argv[]);
        #endif

        // I like to put my private members at the top, though I have seen people put them at the bottem
        // let me know if one way is more correct
    private:
        int numCapacity;
        int numElements;
        T * buffer;

    public:

        // Constructors
        vector()
        {
            T * buffer = NULL;
            numElements = 0;
            numCapacity = 0;
        }

        vector(int numElements)
        {
            vector();
            this->numElements = numElements;
            this->numCapacity = numElements;
        }

        vector(int numElements, T t)
        {
            vector(numElemets);
            buffer[0] = t; 
        }
        vector(const vector & rhs)
        {
            this->numElements = rhs.numElements;
            this->numCapacity = rhs.numCapacity;
            for(int i = 0; i < numElements; i++)
            this->buffer[i] = rhs.buffer[i];    
        }

        // Destructor
        ~vector()
        {
            delete buffer;
        }

        // Functions
        int size()       { return numElements; }
        int capacity()   { return numCapacity; }
        bool empty()     { return !numElements; } /// Any number of elements above 0 count as true, which this function will return as false
        void clear()
        {
            T * newBuffer;
            numElements = 0;
            numCapacity = 0;
            buffer = newBuffer;
        }  

        void push_back(T t)
        {
            if (numElements == numCapacity)
            resize();
            buffer[numElements] = t;
        } 

        void resize()
        {
            numCapacity *= 2;
            T * newBuffer;
            for (int i = 0; i < numElements; i++)
            {
                newBuffer[i] = buffer[i];
            }
            buffer = newBuffer;
        }

        void resize(int number)
        {
            numCapacity = number;
            T * newBuffer;
            for (int i = 0; i < numElements; i++)
            {
                newBuffer[i] = buffer[i];
            }
            buffer = newBuffer;
        }



        // Operators
        vector <T> & operator =(vector <T> rhs)
        {
             numElements = rhs.numElements;
             numCapacity = rhs.numCapacity;
             buffer = new T[numCapacity];
            for(int i = 0; i < numElements; i++)
                buffer[i] = rhs.buffer[i];
            return *this;             
        }
        T & operator [](int index)
        {    
            return buffer[index];
        }

    class iterator;
    iterator begin()
    {
        return iterator(buffer);
    }
        
    iterator end()
    {
        T * newBuffer = buffer;
        for (int i = 0; i != numElements; i++)
            newBuffer++;
        return iterator(newBuffer);
    }

    };


    template <class T>
    class vector<T>::iterator
    {
        #ifdef UNIT_TESTING
            friend int ::main(int argc, const char* argv[]);
        #endif

     private:
        T * ptr;

     public:

        // constructors and destructor
        iterator()
        {
          ptr = NULL;
        }

        iterator(T * p)
        {
         ptr = p;
        }

        iterator (const iterator & rhs)
        {
         ptr = rhs.ptr;
        }
        ~iterator()
        {
            delete ptr;
        }

         // function

        T & operator *()
        {
            return * ptr;
        }

         //operators
        bool operator ==(iterator & rhs)
        {
            if (ptr == rhs.ptr)
            return true;
            return false;
        }

        bool operator !=(iterator & rhs)
        {
            if (ptr != rhs.ptr)
            return true;
            return false;
        }
        iterator & operator ++()
        {
            ptr++;
            return *this;
        }
        iterator & operator ++(int num)
        {
            ptr++;
            return *this;
        }
         iterator & operator --()
        {
            ptr--;
            return *this;
         }
        iterator & operator --(int num)
        {
           ptr--;
           return *this;
        }

    };
    #include "vector.cpp"
}
#endif