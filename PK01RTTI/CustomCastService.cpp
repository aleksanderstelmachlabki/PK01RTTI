#include "CustomCastService.h"
#include <typeinfo>
#include <iostream>

template<typename DestinationType, typename SourceType>
DestinationType* CustomCastService::custom_dynamic_cast(SourceType* source)
{

	DestinationType* result = nullptr;
	
	try
	{
	
		result = typeid(*source) == typeid(DestinationType) ? static_cast<DestinationType*>(source) : nullptr;
	
	}
	catch (std::bad_typeid & e)
	{
	
		std::cerr << e.what() << std::endl;
	
	}
	
	return result;

}
