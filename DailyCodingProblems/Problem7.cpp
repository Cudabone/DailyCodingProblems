#include <thread>
#include <chrono>
#include "Problems.h"

template<typename ReturnType, typename... Args>
void InvokeFunction( int milliseconds, std::function<ReturnType(Args...)> func, Args&&... args )
{
	std::this_thread::sleep_for( std::chrono::milliseconds( milliseconds ) );
	func(std::forward<Args>(args)...);
}
template<typename ReturnType>
void InvokeFunction( int milliseconds, std::function<ReturnType> func )
{
	std::this_thread::sleep_for( std::chrono::milliseconds( milliseconds ) );
	func();
}

void Problem7::RunTest()
{
	std::function<void(std::string)> func = [] (std::string a) { std::printf( "%s", a.c_str() ); };
	std::function<void()> func2 = std::bind( func, "Hey2\n" );
	InvokeFunction( 1000, func, std::string("Hey\n") );
	InvokeFunction( 1000, func2 );
}