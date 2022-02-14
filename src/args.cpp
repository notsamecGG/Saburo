enum class ArgumentType
{
    intarr, 
    charr,
};

class Arguments
{
public:
    void* access(const ArgumentType& type) const
    {
        void* return_type; 

        switch (type)
        {
        case ArgumentType::intarr:
            if (m_intarr == 0)
                throw("Int arr isn't initialized");
            return m_intarr;
            break;
        
        case ArgumentType::charr:
            if (m_charr == 0)
                throw("Char arr isn't initialized");
            return m_charr;
            break;

        default:
            throw "The type you passed in isn't valid.";
            break;
        }
    }

private:
    Arguments() 
    : m_intarr(0), m_charr(0) 
    { }

private:
    int  (*m_intarr)[];

    char (*m_charr)[];
};