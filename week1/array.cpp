#include <iostream>
#include <iomanip>
 
int main ()
{
   int n[10]; // 定义一个包含 10 个整数的数组
 
   // 初始化数组元素          
   for (int i = 0; i < 10; i++) {
      n[i] = i + 100; // 设置元素 n[i] 为 i + 100
   }
   std::cout << "Element" << std::setw(13) << "Value" << std::endl;
 
   // 输出数组中每个元素的值                     
   for (int j = 0; j < 10; j++) {
      std::cout << std::setw(7)<< j << std::setw(13) << n[j] << std::endl;
   }

   return 0;
}