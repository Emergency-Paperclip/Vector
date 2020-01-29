
template <class T>
class iterator
{
    #ifdef UNIT_TESTING
        friend int :: main(int argc, const char * argv[]);
    #endif

    private:
    T * pntr;

    public:
    

    // constructors and destructor
    iterator();
    iterator(T * p);
    iterator(const iterator & rhs);
    ~iterator();

    // function

    T operator *(iterator & rhs)
    {
        *rhs = NULL
    }

    //operators
    bool operator ==(iterator & rhs)
    {
        if (*pntr == *rhs)
            return true;
            return false;
    }
    bool operator !=(iterator & rhs)
    {
        if (*pntr != *rhs)
            return true;
            return false;
    }
    iterator & operator ++()
    {
        pntr += 1;
    }
    iterator & operator ++(int num)
    {
        pntr += num;
    }
    iterator & operator --()
    {
        pntr -= 1;
    }
    iterator & operator --(int num)
    {
        pntr -= num;
    }

    iterator()
    {
        pntr = "NULL";
    }

    iterator(T * p)
    {
        pntr = p;
    }

    iterator (const iterator & rhs)
    {
        pntr = rhs.pntr;
    }

    /*
    constructors

    Iterator()
    {
        pntr = "NULL";
    }

    Iterator(T * p)
    {
        pntr = p;
    }

    Iterator (const Iterator & rhs)
    {
        pntr = rhs.pntr;
    }

*/
};