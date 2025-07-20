// Copyright QueueBitGames


#include "Characters/AbilitySystem/Data/AttributeInfo.h"

FSFAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	if (const FSFAttributeInfo* Info = AttributeInformation.Find(AttributeTag))
	{
		return *Info;
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this))
	}

	return FSFAttributeInfo();
}
