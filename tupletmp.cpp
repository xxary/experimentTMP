#include<iostream>
#include <tuple>
#include<string>
//tupleの関数の要素を取得
template<size_t Index,typename Tuple,typename Functor>
auto tuple_at(const Tuple & tp1,const Functor& func)->
void{
    const auto& v = std::get<Index>(tp1);
    func(v);
}

//tuple_for_each
template<typename Tuple,typename Functor,size_t Index=0>
auto tuple_for_each(const Tuple &tpl,const Functor & f)->void{
    constexpr auto tuple_size = std::tuple_size_v<Tuple>;
    if constexpr(Index<tuple_size){
       tuple_at<Index>(tpl,f);
       tuple_for_each<Tuple,Functor,Index+1>(tpl,f);
    }
}

//tupleの中に値があるか
template<typename Tuple,typename Functor,size_t Index=0>
auto tuple_any_of(const Tuple& tpl,const Functor & f)->bool{
   constexpr auto tuple_size = std::tuple_size_v<Tuple>;
   if constexpr(Index < tuple_size){
      bool success = f(std::get<Index>(tpl));
      return success ?
         true:
         tuple_any_of<Tuple,Functor,Index+1>(tpl,f);
      } else {
          return false;
      }
}

int main(){
   auto tpl = std::make_tuple(1,true,std::string{"tuple!"});
   tuple_for_each(tpl,[](const auto& v){std::cout<<v<<"";});
   
   auto tuple = std::make_tuple(4,44.4f,4.0);
   auto has_value = tuple_any_of(tuple,[](auto v){return v==4;});
}
