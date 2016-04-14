//*************************************************************
//*
//* Copyright (c) 2016 : wang liang
//* License : Distributed under the GNU General Public License
//* created on : 4/14/2016,  by wang liang (wliked@outlook.com)
//* 
//*************************************************************

class Singleton
{
 public:
    static Singleton* GetInstance(); 
    ~Singleton();
 private:	
	Singleton();    //private: forbidden it to be called by user
	Singleton(const Singleton& rhs);   //private: forbidden it to be called by user
	Singleton& operator=(const Singleton& rhs);   //private: forbidden it to be called by user
	static Singleton* instance;
	
	class GarbadeCollector     // a private embeded class of Singleton in order to delete instance
	{
	 public:
		~GarbadeCollector()
		{
		   if(NULL != instance)
           {
			   delete instance;
			   instance = NULL;
		   }			   
		}
	}	
	static GarbadeCollector gc; // when OS clean gc, OS will call gc's destructor function,so memory pointed by "instance" will be deleted
}

Singleton::Singleton()
{
	
}

Singleton* Singleton::GetInstance()
{
	if(NULL == instance)
	{
		lock();  //call boost to lock code zone
		if(NULL == instance)
		{
			instance = new Singleton();
		}
		unlock(); // call boost to unlock code zone
	}
    return instance;	
}

Singleton::~Singleton()
{
	
}

int main(int argc,char** argv)
{
	Singleton* instance = Singleton::GetInstance();
    return 0;	
}