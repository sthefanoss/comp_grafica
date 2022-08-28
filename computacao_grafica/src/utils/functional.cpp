//
//  functional.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#include "functional.h"

template<class T>
std::vector<T> map(const std::vector<T>& collection, std::function<T(const T&)> callback)
