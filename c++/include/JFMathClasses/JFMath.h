#pragma once

struct JFMath
{
	/** Returns higher value in a generic way */
	template< class T >
	static CONSTEXPR FORCEINLINE T Max(const T A, const T B)
	{
		return (A >= B) ? A : B;
	}

	/** Returns lower value in a generic way */
	template< class T >
	static CONSTEXPR FORCEINLINE T Min(const T A, const T B)
	{
		return (A <= B) ? A : B;
	}
};