#ifndef cppfix
#define cppfix

//__extension__ typedef int __guard __attribute__((mode (__DI__)));

//void* operator new(size_t size);
void* operator new[](size_t size);
//void operator delete(void * ptr);

/*void* operator new(size_t size)
{
	return malloc(size);
}*/

void* operator new[](size_t size)
{
	return malloc(size);
}

/*void operator delete(void * ptr)
{
	free(ptr);
}*/

#endif 