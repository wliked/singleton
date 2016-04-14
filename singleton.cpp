//*************************************************************
//*
//* Copyright (c) 2016 : wang liang
//* License : Distributed under the GNU General Public License
//* created on : 4/14/2016,  by wang liang (wliked@outlook.com)
//*
//*************************************************************
#include "singleton.hpp"

Singleton::instance = NULL; //init the static member of singleton

Singleton* Singleton::GetInstance()
{
    if (NULL == instance)
    {
        lock();  //call boost to lock code zone
        if (NULL == instance)
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