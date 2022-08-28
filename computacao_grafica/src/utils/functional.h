//
//  functional.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#ifndef functional_hpp
#define functional_hpp

#include <functional>
#include <vector>

template<class T>
std::vector<T> map(const std::vector<T>& collection, std::function<T(const T&)> callback) {
    std::vector<T> newCollection = {};
    for(T element : collection)
      newCollection.push_back(callback(element));
    return newCollection;
}


#endif /* functionall_hpp */
