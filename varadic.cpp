#include<string>
#include<complex>
#include<iostream>
#include<vector>

template<typename T>
void print(T arg)
{
    std::cout<<arg<<'\n';
}

template<typename T,typename... Types>
void print(T firstArg,Types... args)
{
    print(firstArg);
    print(args...);
}

template<typename... T>
void printDoubled(T const&... args)
{
    print((args+args)...);
}

template<typename C,typename... Idx>
void printElems(C const& coll,Idx... idx)
{
    print(coll[idx]...);
}

template<std::size_t... Idx,typename C>
void printIdx(C const& coll)
{
    print(coll[Idx]...);
}

int main()
{
    printDoubled(7.5+7.5,std::string("hello")+std::string("hello"),std::complex<float>(4.2)+std::complex<float>(4.2));
    std::vector<std::string> coll={"good","times","say","bye"};
    printElems(coll,2,0,3);
    printIdx<2,0,3>(coll);
}
