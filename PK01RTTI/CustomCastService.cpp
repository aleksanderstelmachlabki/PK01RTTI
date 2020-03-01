#include "CustomCastService.h"
#include <typeinfo>
#include <iostream>

template<typename DestinationType, typename SourceType>
DestinationType* CustomCastService::custom_dynamic_cast(SourceType* source)
{

	return typeid(*source) == typeid(DestinationType) ? static_cast<DestinationType*>(source) : nullptr;

}
