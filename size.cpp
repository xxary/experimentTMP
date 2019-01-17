#include<iostream>
#include<vector>
#include<map>
template<typename T,typename S>
struct get_size_element
{
   S operator()(const T& x) const {return x.size();}
   get_size_element(int){}
};
struct one_type
{
   template<typename T>
   size_t operator()(const T&)const{return 1;}
   one_type(int){}
};
template<typename T>
get_size_element<T,typename T::size_type> test(const T* x)
{
   return 0;
}
one_type test(const void*){
   return 0;
}
template <typename T>
size_t return_size_element(const T& x)
{
   return test(& x)(x);
}

int main(){
   std::vector<int> v(12);
   std::map<int,double> m;
   double x;
   
   std::cout<<return_size_element(v)<<std::endl;
   std::cout<<return_size_element(m)<<std::endl;
   std::cout<<return_size_element(x)<<std::endl;
}
