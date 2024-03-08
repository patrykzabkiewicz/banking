#ifndef OBJECT_H
#define OBJECT_H

class Object {
	virtual void pure() = 0;
public:
        void* operator new(size_t) 
	{
	// alloc memory for the base object
	MMA::mmalloc();
	}
        void operator delete(void*) 
	{
	MMA::mfree();
	}
}

#endif // OBJECT_H


