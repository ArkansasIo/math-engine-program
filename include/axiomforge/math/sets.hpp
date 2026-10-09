#pragma once
#include <set>
namespace axf::math {
template<class T> std::set<T> set_union(const std::set<T>&a,const std::set<T>&b){std::set<T>r=a;r.insert(b.begin(),b.end());return r;}
template<class T> std::set<T> set_intersection(const std::set<T>&a,const std::set<T>&b){std::set<T>r;for(const auto&x:a)if(b.contains(x))r.insert(x);return r;}
template<class T> std::set<T> set_difference(const std::set<T>&a,const std::set<T>&b){std::set<T>r;for(const auto&x:a)if(!b.contains(x))r.insert(x);return r;}
template<class T> bool is_subset(const std::set<T>&a,const std::set<T>&b){for(const auto&x:a)if(!b.contains(x))return false;return true;}
}
