#ifndef CUSTOMCASTSERVICE_H_
#define CUSTOMCASTSERVICE_H_

class CustomCastService
{

public:

	template<typename DestinationType, typename SourceType>
	static DestinationType* custom_dynamic_cast(SourceType* source);

private:

	CustomCastService() {}

};

#endif
