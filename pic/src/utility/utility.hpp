#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace maxwell {

//============================================================================//
//  Data management
//============================================================================//
/// ifdef capacity /// template<typename Type>
/// ifdef capacity /// void Array::Reallocate(const uint cap)
/// ifdef capacity /// {
/// ifdef capacity ///     if (cap != capacity)
/// ifdef capacity ///     {
/// ifdef capacity ///         capacity = cap;
/// ifdef capacity ///         data = (Type *)realloc(data, capacity * sizeof(Type));
/// ifdef capacity ///     }
/// ifdef capacity /// }
template<typename Type>
void Array::Reallocate(const uint siz)
{
    if (size != siz)
    {
        size = siz;
        data = (Type *)realloc(data, size * sizeof(Type));
    }

    if (!size) { data = NULL; }
}

template<typename Type>
void Array::Copy(const uint siz, const Type & val)
{
    Reallocate(siz);
    copy(size, &val, 0, data, 1);
}

template<typename Type>
void Array::Copy(const uint siz, const Type * dat)
{
    Reallocate(siz);
    if (dat) { copy(size, dat, 1, data, 1); }
    else { data[0] = 0; copy(size, data, 0, data, 1); }
}

template<typename Type>
void Array::Copy(const Array & arr)
{
    Reallocate(arr.size);
    copy(size, arr.data, 1, data, 1);
}

//============================================================================//
//  Initialization
//============================================================================//
template<typename Type>
Array::Array(const uint siz, const Type & val): size(0), data(NULL)
{
    Copy(siz, val);
}

template<typename Type>
Array::Array(const uint siz, const Type * dat): size(0), data(NULL)
{
    if (dat) { Copy(siz, dat); }
    else { Reallocate(siz); }
}

//============================================================================//
//  Element mutate
//============================================================================//
template<typename Type>
Type & Array::operator[](const uint ind)
{
    /// FIXME /// what to do with negative?
    if (data && ind >= 0 && ind < size) { }
    else { Reallocate(); return ; }
    
    return data[ind]; 
}

//============================================================================//
//  Element access
//============================================================================//
template<typename Type>
const Type & Array::operator[](const uint i) const
{
    return (data && ind >= 0 && ind < size)? data[ind]: 0;
}

} // namespace maxwell

#endif // UTILITY_HPP
