/*
 * C++ Design Patterns: Singleton
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>

/*
 * Singleton
 * has private static variable to hold one instance of the class
 * and method which gives us a way to instantiate the class
 */
class Singleton
{
public:
  // The copy constructor and assignment operator
  // are defined as deleted, which means that you
  // can't make a copy of singleton.
  // 拷贝构造函数和赋值函数都被定义为delete,这意味着你不能使用复制一份单例
  //
  // 也可以把其放在私有属性里面来产生同样的效果
  // Note: you can achieve the same effect by declaring
  // the constructor and the operator as private
  Singleton( Singleton const& ) = delete;
  Singleton& operator=( Singleton const& ) = delete;

  static Singleton* get()
  {
    if ( !instance )//如果instance为空，创建对象，由于instance是静态属性，
    {               //创建一个对象后便不为空了，所有只会创建一个对象
      instance = new Singleton();
      //xigou c;
    }    
    return instance;
  }

  static void restart()//调用析构restart()方法对对象进行析构，因为上面对象是
  {                    //通过new关键字创建在堆上的，不会调用析构函数，堆上的数据必须手动释放
    if ( instance )
    {
      delete instance;
      //instance=nullptr;//自己加的一句
      std::cout<<"xigou successful"<<std::endl;
    }                 
  }

  class xigou{//上面是通过restart()方法进行手动调用，不太方便可以通过
  public:     //再创建一个类，通过这个类的析构函数对对象进行析构
    ~xigou(){ //只需要在34句后加上 xigou c;即可
      if(instance!=nullptr){
        delete instance;
        instance=nullptr;
        std::cout<<"xigou successful"<<std::endl;
      }
      
    }

  };

  void tell()
  {
    std::cout << "This is Singleton." << std::endl;
    // ...
  }
  // ...

private:
  Singleton() {}
  static Singleton *instance;
  // ...
};

Singleton* Singleton::instance = nullptr;


int main()
{
  Singleton::get()->tell();
  Singleton::restart();
  
  return 0;
}
